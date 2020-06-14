#pragma once
#include"Enumerators.h"
#include<iostream>
/**
 * @brief Class that represents a worker at the park
 */
class Staff
{
private: //!<  declares data members 
	char* workerName; //!< dynamic memory 
	int age;
	position workPosition;

	void copy(const Staff& other); //!< declares "big six" 
	void destroy();

public:
	Staff();
	Staff(const Staff& other);
	Staff& operator=(const Staff& other);
	~Staff();

	Staff(const char* newWorkerName, int newAge, position newWorkPosition); //!< constructor with all given information

	void setWorkerName(const char* newWorkerName); 
	const char* getWorkerName()const;

	void setAge(int newAge);
	int getAge()const;

	void setWorkPosition(position newWorkPosition);
	position getWorkPosition()const;

	friend std::ostream& operator<<(std::ostream& out, const Staff& other); //!< operator << 
	friend std::istream& operator>>(std::istream& in, Staff& other); //!< operator >> 
};

