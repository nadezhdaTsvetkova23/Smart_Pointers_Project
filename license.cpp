#include <iostream>
#include <string>
#include <memory>

#include "guild.h"
#include "license.h"
#include "person.h"

License::License(std::string name, unsigned int salary){
	if (name.empty() || salary <= 0)		
		throw std::runtime_error("illegal name or salary");
	//order of checks
	this->name = name;
	this->salary = salary;
	
}

std::string License::get_guildname() const
{
	return name;
}

unsigned int License::get_salary() const
{
	return salary;
}

bool License::valid() const
{
	return counter <= 3;
}

bool License::use()
{
	if (!this->valid()) {
		return false;
	}
	else {
		counter++;
		return true;
	}

}

std::ostream& License::print(std::ostream& o) const
{
	o << "[License for " << this->get_guildname() << ", Salary: "
		<< get_salary() << ", Used: " << counter << "]";
	return o;
}

std::ostream& operator<<(std::ostream& o, const License& l)
{
	return l.print(o);
}
