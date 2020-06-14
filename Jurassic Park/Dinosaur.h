#pragma once
#include<iostream>
#include"Enumerators.h" //!< includes the enumarators, so different types of data can be used
/**
* @brief Class that represents a dinosaur
*/
class Dinosaur
{
private: //!< declares data members
	char* name; //!< dynamic memory
	char gender;
	era dinosaurEra; 
	discharge dinosaurDischarge;
	char* type; //!< dynamic memory
	food dinosaurFood;

	void copy(const Dinosaur& other);//!< declares "big six"
	void destroy();

public:
	Dinosaur();
	Dinosaur(const Dinosaur& other);
	Dinosaur& operator=(const Dinosaur& other);
	~Dinosaur();

	Dinosaur(const char* newName, char newGender, era newDinosaurEra,
		     discharge newDinosaurDischarge, const char* newType);
	                                                        //!< setters and getters for the data in private
	void setName(const char* newName);
	const char* getName()const;

	void setGender(char newGender);
	char getGender()const;

	void setDinosaurEra(era newDinosaurEra);
	era getDinosaurEra()const;

	void setDinosaurDischarge(discharge newDinosaurDischarge);
	discharge getDinosaurDischarge()const;

	void setType(const char* newType);
	const char* getType()const;

	void setDinosaurFood(int newFood);
	food getDinosaurFood()const;

	friend std::ostream& operator<<(std::ostream& out, const Dinosaur& other);  //!< output operator
	friend std::istream& operator>>(std::istream& in, Dinosaur& other);         //!< input operator
};

