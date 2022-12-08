#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <memory>
#include <string>
#include <map>
#include "license.h"

class Person {
protected:
	std::string name;
	unsigned int wealth;
	std::map<std::string, std::unique_ptr<License>> licenses;
public:
	//Constructors
	Person(std::string name, unsigned int wealth = 0);

	//Destructor
	virtual ~Person() = default;

	//Methods
	unsigned int get_wealth() const;
	void work(std::string guild);
	virtual void work(unsigned int) = 0;
	void increase_wealth(unsigned int i);
	std::string get_name() const;
	bool pay_fee(unsigned int i);
	void receive_license(std::unique_ptr<License> l);
	void transfer_license(std::string l, std::shared_ptr<Person> p);
	bool eligible(std::string l) const;

	//print methods
	virtual std::ostream& print(std::ostream& o) const;
	friend std::ostream& operator<<(std::ostream& o, const Person& p);

	class Worker;
	class Superworker;
};

class Worker :public Person {
public:
	Worker(std::string, unsigned int = 0);
	void work(unsigned int i) override;
	std::ostream& print(std::ostream& o) const;
};

class Superworker :public Person {
private:
	unsigned int fee;
public:
	Superworker(unsigned int fee, std::string, unsigned int = 0);
	void work(unsigned int i) override;
	std::ostream& print(std::ostream& o) const;
};

#endif PERSON_H