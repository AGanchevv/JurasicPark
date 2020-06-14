#pragma once
#include"Dinosaur.h" //!< includes all needed headers
#include"Cell.h"
#include"Staff.h"
#include<time.h> //!< library used in the algorith for randomizing
#include<stdlib.h> //!<library used for clearing the console data
#include<iostream>
/**
* @brief Class that represents the zoopark and combines cells, workers, dinosaurs and provisions
*/
class Zoopark
{
private: //!< declares data members
	Cell * cells; //!< dynamic memory
	int numberOfCells;
	int capacityOfCells;
	int amountGrass;
	int amountMeat;
	int amountFish;
	Staff* workers; //!< dynamic memory
	int numberOfWorkers;
	int capacityOfWorkers;
	char* outputFile; //!< dynamic memory

	void increaseZooparkSize(); //!< increases cell capacity
	void increaseStaff(); //!< increases staff capacity

	void copy(const Zoopark& other); //!< declares "big six"
	void destroy();

public:
	Zoopark();
	Zoopark(const Zoopark& other);
	Zoopark& operator=(const Zoopark& other);
	~Zoopark();

	void setNumberOfCells(int newNumberOfCells); //!< setters and getters
	int getNumberOfCells()const;

	void setCapacityOfCells(int newCapacityOfCells);
	int getCapacityOfCells()const;

	void setAmountGrass(int newAmountGrass);
	int getAmountGrass()const;

	void setAmountMeat(int newAmountMeat);
	int getAmountMeat()const;

	void setAmountFish(int newAmountFish);
	int getAmountFish()const;

	void setNumberOfWorkers(int newNumberOfWorkers);
	int getNumberOfWorkers()const;

	void setCapacityOfWorkers(int newCapacityOfWorkers);
	int getCapcityOfWorkers()const;

	void setOutputFile(const char* newOutputFile);
	const char* getOutputFile()const;

	void notEnoughStaff(); //!< shows there is enough food, but not enough staff
	bool enoughStaff(); //!< verification if there is enough staff to look after the dinosaurs
	void employedFoodSupplier(); //!< shows what kind of workers should be hired
	void appointStaff(); //!< appoints staff

	void successfullyAddedFood(); //!< shows that the food was successfully added
	void notEnoughFood(); //!< shows there is enough staff, but not enough food
	bool enoughFood(); //!< verification if there is enough food for all the dinosaurs
	void addFoodByChoice(); //!< adds food by users choice
	void addFoodNecessary(); //!< adds food because it is necessary in order for dinosaurs to live


	void successfullyCreatedCell(); //!< shows that a cell is successfully created
	void createSpaceForNewCell(const Cell& other); //!< saves a cell in the zoopark memory
	void randomCells(); //!< creates cell with random size and climate
	void addCell(); //!< creates cell with whatever data the user chooses
	
	void twoOptionMenuDinosaur(); //!< shows two option menu for the user
	void addOrRemoveDinosaur(const Dinosaur& other, int index); //!< creates menu if the user want to add staff and food or remove the dinosaur
	void loadProvision(const Dinosaur& other, int index); //!< loads food or / and appoints staff to the zoopark
	void newCellForDinosaur(const Dinosaur& other, bool cell); //!< gives a chance to create and than checks again if it is suitable
	void addDinosaurInCell(); //!< adds a dinosaur in a suitable cell
	
	void removeDinosaurFromCell(); //!< removes a dinosaur by entering his name from the cell it is in
	void createStartingBase(); //!< creates random number of random empty cells

	int numberDinosaursGround(); //!< returns the number of dinosaurs which lives on the ground
	int numberDinosaursAir(); //!< returns the number of dinosaurs which lives in the air
	int numberDinosaursWater(); //!< returns the number of dinosaurs which lives in the water

	int numberWorkersOnGround(); //!< returns the number of workers who work on the ground
	int numberWorkersOnAir(); //!< returns the number of workers who work in the air
	int numberWorkersOnWater(); //!< returns the number of workers who work in the water
	int numberWorkersOnFood(); //!< returns the number of workers who supply the cells with food

	void parkRules(); //!< shows the rules in the begging
	void managmentSystem(); //!< shows managmest system
	void enterTheZoo(); //!< the first time a user enters into the zoo

	void notSavedDataStatus(); //!< shows that the dinosaur data is not saved 
	void successfullySavedData(); //!< shows that the data is saved successfully
	void successfullyRemoved(); //!< shows that the dinosaur is successfully removed
	void noDinosaurMatch(); //!< shows that the dinosaur was not found

	void save(); //!< saves data in a file

	friend std::ostream& operator<<(std::ostream& out, const Zoopark& other); //!< operator <<
	friend std::istream& operator>>(std::istream& in, Zoopark& other); //!< operator >>
};


