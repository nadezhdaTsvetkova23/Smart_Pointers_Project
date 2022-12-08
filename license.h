#ifndef LICENSE_H
#define LICENSE_H

#include <iostream>
#include <memory>
#include <string>

class License {
private:
	std::string name;
	unsigned int salary;
	unsigned int counter = 0;
public:
	//Constructors
	License(std::string name, unsigned int salary);

	//Methods
	std::string get_guildname() const;
	unsigned int get_salary() const;
	bool valid() const;
	bool use();
	
	//print methods
	std::ostream& print(std::ostream& o) const;
	friend std::ostream& operator<<(std::ostream& o, const License& l);
};

#endif // !LICENSE_H
