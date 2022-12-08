#ifndef GUILD_H
#define GUILD_H

#include <iostream>
#include <memory>
#include <map>
#include <vector>
#include <string>
#include "person.h"

class Guild {
private:
	std::string name;
	unsigned int fee;
	unsigned int salary;
	std::map<std::string, std::shared_ptr<Person>> members;
public:
	//Constructors
	Guild(std::string name, unsigned int fee, unsigned int sal, const std::vector<std::shared_ptr<Person>>& members = {});

	//Methods
	bool add_member(std::shared_ptr<Person> p);
	bool remove_member(std::string n);
	void grant_license(std::string n);
	bool offer_job(std::shared_ptr<Person> p) const;

	//print methods
	std::ostream& print(std::ostream& o) const;
	friend std::ostream& operator<<(std::ostream& o, const Guild& g);

};


#endif GUILD_H
