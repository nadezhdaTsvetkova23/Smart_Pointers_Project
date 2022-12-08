#include <iostream>
#include <string>
#include <memory>
#include <set>

#include "guild.h"
#include "license.h"
#include "person.h"

Guild::Guild(std::string name, unsigned int fee, unsigned int sal, const std::vector<std::shared_ptr<Person>>& members) {
	
	this->name = name;
	this->fee = fee;
	this->salary = sal;

	if (name.empty() || fee <= 0 || salary <= 0)
		throw std::runtime_error("illegal name, fee or salary");
	for (std::size_t i = 0; i < members.size(); i++) {
		if(this->members.count(members.at(i)->get_name()))
			throw std::runtime_error("the person can't be more than one in the list");
		this->members[members.at(i)->get_name()] = members.at(i);
	}
}

bool Guild::add_member(std::shared_ptr<Person> p)
{
	for (auto it = members.begin(); it != members.end(); it++) {
		std::shared_ptr<Person> temp = it->second;
		if (temp == p)
			return false;
	}
	members[p->get_name()] = p;
	return true;
}

bool Guild::remove_member(std::string n)
{
	if (members.erase(n))
		return true;
	return false;
}

void Guild::grant_license(std::string n)
{
	if (members.find(n) == members.end())
		throw std::runtime_error("there's no such a member");

	for (auto it = members.begin(); it != members.end(); it++) 
		if (it->first == n && it->second->pay_fee(fee)) {
			it->second->receive_license(std::make_unique<License>(name, salary));
			return;
		}
			throw std::runtime_error("the member doesn't have enough money");
	//if (members.count(n) && members[n]->pay_fee(fee)) {
		//members[n]->receive_license(std::move(std::make_unique<License>(name, salary)));
	//}
}

bool Guild::offer_job(std::shared_ptr<Person> p) const
{
	if (members.count(p->get_name())) {		//p is part from the guild
		p->work(salary * 2);				//p works for double salary
		return true;
	}
	if (!members.count(p->get_name()) && p->eligible(name)){	//p is not a part from the guild, 
															//but has a license for the guild
		p->work(name);
		return true;
	}
	return false;
}

std::ostream& Guild::print(std::ostream& o) const
{
	bool first{ true };
	o << "[" << name << ", License fee: " << fee << ", Job salary: " << salary << ", {";
	for (const auto& m : members) {
		if (first) {
			o << m.first;
			first = false;
		}
		else
			o << ", " << m.first;
	}
	return o << "}]";
}

std::ostream& operator<<(std::ostream& o, const Guild& g)
{
	return g.print(o);
}
