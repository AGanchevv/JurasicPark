#include "stdafx.h"
#include "Zoopark.h"
#include<fstream>

char typesOfFood[45] = "What do you want to add?(grass, meat, fish) ", quantityFood[22] = "Enter food quantity: ";
char oneOfTheListed[26] = "Choose one of the listed!", notSavedData[28] = "Dinosaur data is not saved!";
int randomBr = 0; //!< variable, which is used to randomize the size and climate in a cell
bool removeD = false; //!< removeD is variable, which is a flag to know if cin.get ot cin.sync should be used in order not
                                             //!< to lose the first character
void Zoopark::increaseZooparkSize() //!< increases coopark capacity by adding a free place for another cell
{
	this->capacityOfCells++;
	Cell* variable = new Cell[this->capacityOfCells];

	for (int i = 0; i < this->numberOfCells; i++)
	{
		variable[i] = this->cells[i];
	}

	delete[] this->cells;
	this->cells = variable;
}

void Zoopark::increaseStaff() //!< increases staff capacity by adding a free place for another worker
{
	this->capacityOfWorkers++;

	Staff* variable = new Staff[this->capacityOfWorkers];
	
	for (int i = 0; i < this->numberOfWorkers; i++)
	{
		variable[i] = this->workers[i];
	}

	delete[] this->workers;
	this->workers = variable;
}

void Zoopark::copy(const Zoopark & other) //!< copies all data from one zoopark to another
{
	setNumberOfCells(other.numberOfCells);
	setCapacityOfCells(other.capacityOfCells);
	this->cells = new Cell[this->capacityOfCells];

	for (int i = 0; i < this->capacityOfCells; i++)
	{
		this->cells[i] = other.cells[i];
	}
	setAmountGrass(other.amountGrass);
	setAmountMeat(other.amountMeat);
	setAmountFish(other.amountFish);
	setNumberOfWorkers(other.numberOfWorkers);
	setCapacityOfWorkers(other.capacityOfWorkers);
	this->workers = new Staff[this->capacityOfWorkers];

	for (int i = 0; i < this->capacityOfWorkers; i++)
	{
		this->workers[i] = other.workers[i];
	}
}

void Zoopark::destroy() //!< deletes all data so there is no memory leak
{
	delete[] this->cells;
	delete[] this->workers;
}

Zoopark::Zoopark() //!< default contructor
{
	setNumberOfCells(0);
	setCapacityOfCells(1);
	this->cells = new Cell[this->capacityOfCells];
	setAmountGrass(0);
	setAmountMeat(0);
	setAmountFish(0);
	setNumberOfWorkers(0);
	setCapacityOfWorkers(0);
	this->workers = new Staff[this->capacityOfWorkers];
}

Zoopark::Zoopark(const Zoopark & other) //!< copy constructor
{
	this->copy(other);
}

Zoopark & Zoopark::operator=(const Zoopark & other) //!< operator =
{
	if (this != &other)
	{
		this->copy(other);
	}
	return *this;
}

Zoopark::~Zoopark() //!< destructor
{
	this->destroy();
}

void Zoopark::setNumberOfCells(int newNumberOfCells) //!< setters and getters
{
	this->numberOfCells = newNumberOfCells;
}

int Zoopark::getNumberOfCells() const
{
	return this->numberOfCells;
}

void Zoopark::setCapacityOfCells(int newCapacityOfCells)
{
	this->capacityOfCells = newCapacityOfCells;
}

int Zoopark::getCapacityOfCells() const
{
	return this->capacityOfCells;
}

void Zoopark::setAmountGrass(int newAmountGrass)
{
	this->amountGrass = newAmountGrass;
}

int Zoopark::getAmountGrass() const
{
	return this->amountGrass;
}

void Zoopark::setAmountMeat(int newAmountMeat)
{
	this->amountMeat = newAmountMeat;
}

int Zoopark::getAmountMeat() const
{
	return this->amountMeat;
}

void Zoopark::setAmountFish(int newAmountFish)
{
	this->amountFish = newAmountFish;
}

int Zoopark::getAmountFish() const
{
	return this->amountFish;
}

void Zoopark::setNumberOfWorkers(int newNumberOfWorkers)
{
	this->numberOfWorkers = newNumberOfWorkers;
}

int Zoopark::getNumberOfWorkers() const
{
	return this->numberOfWorkers;
}

void Zoopark::setCapacityOfWorkers(int newCapacityOfWorkers)
{
	this->capacityOfWorkers = newCapacityOfWorkers;
}

int Zoopark::getCapcityOfWorkers() const
{
	return this->capacityOfWorkers;
}

void Zoopark::setOutputFile(const char * newOutputFile) //!< setter for the file name in which the data will be saved
{
	if (newOutputFile != nullptr)
	{
		delete[] this->outputFile;
		this->outputFile = new char[strlen(newOutputFile) + 1];
		strcpy_s(this->outputFile, strlen(newOutputFile) + 1, newOutputFile);
	}
}

const char * Zoopark::getOutputFile() const
{
	return this->outputFile;
}

void Zoopark::notEnoughStaff() //!< shows there is enough food, but not enough staff
{
	std::cout << " " << std::endl;
	std::cout << "+-----------------------------------------------+" << std::endl;
	std::cout << "| There is enough food, but not enough staff!   |" << std::endl;
	std::cout << "+-----------------------------------------------+" << std::endl;
	std::cout << " " << std::endl;
}

bool Zoopark::enoughStaff() //!< verification if the staff is enough for the amount of dinosaurs
{
	int groundBr = 0, airBr = 0, waterBr = 0; //!< variables for dinosaurs
	int workersOnGround = 0, workersOnAir = 0, workersOnWater = 0, workersOnFood = 0; //!< variables for workers

	groundBr = numberDinosaursGround(); //!< finds amount of dinosaurs which live one the ground
	airBr = numberDinosaursAir(); //!< finds amount of dinosaurs which live in the air
	waterBr = numberDinosaursWater(); //!< finds amount of dinosaurs which live one the water

	workersOnGround = numberWorkersOnGround(); //!< finds amount of workers who look afther dinosaurs which live on the ground
	workersOnAir = numberWorkersOnAir(); //!< finds amount of workers who look afther dinosaurs which live in the air
	workersOnWater = numberWorkersOnWater(); //!< finds amount of workers who look afther dinosaurs which live on the water
	workersOnFood = numberWorkersOnFood(); //!< finds amount of workers who give dinosaurs food
	
	if (workersOnGround >= groundBr && workersOnAir >= airBr && workersOnWater >= waterBr && workersOnFood >= 1) 
	{                                          //!< verification if there are equal amount or more  proffesionals for each of 
		return true;                           //!<the specific dinosaurs and one food supplier
	}
	else
	{
		return false;
	}
}

void Zoopark::emplîyedFoodSupplier() //!< shows what kind of workers should be hired
{
	int workersOnFood = 0;
	workersOnFood = numberWorkersOnFood(); //!< finds amount of workers who give dinosaurs food

	if (workersOnFood >= 1) //!< case if there already is a food supplier
	{
		std::cout << " " << std::endl;
		std::cout << "+----------------------------------+" << std::endl;
		std::cout << "| Note: You must hire a specialist |" << std::endl;
		std::cout << "+----------------------------------+" << std::endl;
		std::cout << " " << std::endl;
	}
	else //!< case if there is not a food supplier
	{
		std::cout << " " << std::endl;
		std::cout << "+-------------------------------------------------------------------+" << std::endl;
		std::cout << "| Note: You must hire at least one specialist and one food supplier |" << std::endl;
		std::cout << "+-------------------------------------------------------------------+" << std::endl;
		std::cout << " " << std::endl;
	}
}

void Zoopark::appointStaff() //!< appoints staff
{
	emplîyedFoodSupplier();

	while (enoughStaff() == false) //!< loop stops when there is enough staff
	{
		Staff other;

		std::cout << "Enter a new worker!" << std::endl;
		std::cin >> other; //!< enters a new worker

		if (this->numberOfWorkers == this->capacityOfWorkers)
		{
			increaseStaff(); //!< increases capacity if needed
		}
		this->workers[this->numberOfWorkers] = other;
		this->numberOfWorkers++;
	}
}

void Zoopark::successfullyAddedFood() //!< shows that the food was successfully added
{
	std::cout << " " << std::endl;
	std::cout << "+-----------------------------------------------+" << std::endl;
	std::cout << "| Food was successfully added!                  |" << std::endl;
	std::cout << "+-----------------------------------------------+" << std::endl;
	std::cout << " " << std::endl;
}

void Zoopark::notEnoughFood() //!< shows there is enough staff, but not enough food
{
	std::cout << " " << std::endl;
	std::cout << "+-----------------------------------------------+" << std::endl;
	std::cout << "| There is enough staff, but not enough food!   |" << std::endl;
	std::cout << "+-----------------------------------------------+" << std::endl;
	std::cout << " " << std::endl;
}

bool Zoopark::enoughFood() //!< verification if there is enough food for every dinosaur
{
	int grassBr = 0, meatBr = 0, fishBr = 0; //!< variables in which are saved the needed amounts of food

	for (int i = 0; i < this->numberOfCells; i++) //!< goes through each cell
	{
		if (this->cells[i].getDinosaursDischarge() == 1) //!< checks the discharge of all the dinosaurs in the cell
		{
			grassBr += this->cells[i].getNumberOfDinosaurs() * 10; //!< gets the number of dinosaurs and multiplies it 10, because
		}                                                          //!< each dinosaur need at least 10 kg food
		if (this->cells[i].getDinosaursDischarge() == 2 || this->cells[i].getDinosaursDischarge() == 3)
		{
			meatBr += this->cells[i].getNumberOfDinosaurs() * 10;
		}
		if (this->cells[i].getDinosaursDischarge() == 4)
		{
			fishBr += this->cells[i].getNumberOfDinosaurs() * 10;
		}
	}

	if (this->amountGrass >= grassBr && this->amountMeat >= meatBr && this->amountFish >= fishBr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Zoopark::addFoodByChoice() //!< addes food to the wearhouse, because the user wants to add extra food
{
	int temp = 0; //!< variable for the food quantity
	char food[6]; //!< variable for user's food choice
	bool rightFood = false; //!< flag 

	while (rightFood == false) //!< the loop continues until the user chooses one of the listed options
	{
		std::cout << typesOfFood;
		std::cin >> food; //!< enteres food

		if (strcmp(food, "grass") == 0) //!< compares the input with the food options
		{
			rightFood = true;
		}
		if (strcmp(food, "meat") == 0)
		{
			rightFood = true;
		}
		if (strcmp(food, "fish") == 0)
		{
			rightFood = true;
		}
	}

	std::cout << quantityFood; //!<there is no restrictions for the food quantity, because there is 
	std::cin >> temp;                     //!< already enough food for each dinosaur and the user is just
	                                      //!< adding some extra food
	if (strcmp(food, "grass") == 0)
	{
		this->amountGrass += temp; //!< addes the entered quantity to the amount of food in this class
	}
	if (strcmp(food, "meat") == 0)
	{
		this->amountMeat += temp;
	}
	if (strcmp(food, "fish") == 0)
	{
		this->amountFish += temp;
	}

	successfullyAddedFood();
}

void Zoopark::addFoodNecessary() //!< addes food in order for dinosaurs to survive, beauce otherwise they can not 
{                                //!< be added to cell
	char food[6];
	bool rightFood = false;

	while (enoughFood() == false) //!< unlike the addFoodByChoice function there must be a loop, which goes on until there is enough food for every dinosaur, because in this function
	{                             //!< the user must enter at least the required minimum
	    while (rightFood == false) //!< the loop is similar as the loop for the addFoodByChoice function
	    {
			std::cout << typesOfFood;
	    	std::cin >> food;
	    
	    	if (strcmp(food, "grass") == 0)
	    	{
	    		rightFood = true;
	    	}
	    	if (strcmp(food, "meat") == 0)
	    	{
	    		rightFood = true;
	    	}
	    	if (strcmp(food, "fish") == 0)
	    	{
	    		rightFood = true;
	    	}
	    }                            //!< until there is enough food for every dinosaur, because in this function
		rightFood = false;           //!< the user must enter at least the required minimum
		int temp = 0;             

		std::cout << quantityFood;
		std::cin >> temp;

		if (strcmp(food, "grass") == 0) //!< verification if the input matches the food options
		{
			this->amountGrass += temp; //!< addes the entered quantity to the amount of food in this class
		}
		if (strcmp(food, "meat") == 0)
		{
			this->amountMeat += temp;
		}
		if (strcmp(food, "fish") == 0)
		{
			this->amountFish += temp;
		}
	}
}

void Zoopark::successfullyCreatedCell() //!< shows that a cell is successfully created
{
	std::cout << " " << std::endl;
	std::cout << "+-----------------------------------------------+" << std::endl;
	std::cout << "| STATUS: Cell was created successfully!        |" << std::endl;
	std::cout << "+-----------------------------------------------+" << std::endl;
	std::cout << " " << std::endl;
}

void Zoopark::createSpaceForNewCell(const Cell & other) //!< creates a new cell in the zoopark
{
	if (this->numberOfCells == this->capacityOfCells) //!< if needed the capacity is increasing
	{
		increaseZooparkSize();
	}

	this->cells[this->numberOfCells] = other; //!< saves the newest cell
	this->numberOfCells++;

	removeD = true;
}

void Zoopark::randomCells() //!<creates empty cells with randomized size and climate
{
	int cellSize = 0, cellClimate = 0; //!< variables, which are used in the alogirth for randomizing
	size sizeVariable = small; //!< variable type size 
	climate climateVariable = land; //!< variable type climate

	srand(time(NULL)); //!< randomization using current seconds, because of this time.h is included
	                   //!< but this only works once per second or so
	cellSize = rand() % (3 + randomBr) + 1; //!< srand can't be used multiple times in the program and expect
	randomBr++;                             //!< to gain different random values so each time in the function is added
	                                        //!< randomBr .That way every time the number on which rand() is used is 
	while (cellSize > 3)                    //!< defferent and the result is random number each time.
	{
		cellSize -= 3; //!< because each time randomBr is bigger and bigger there is a good change cellSize is going
	}                  //!< to be bigger than 3, but the sizes are only 3 options, so the loop subtracts 3, until
	                   //!< cellSize is avaible cell size
	if (cellSize == 1)
	{
		sizeVariable = small;
	}
	if (cellSize == 2)
	{
		sizeVariable = middle;
	}
	if (cellSize == 3)
	{
		sizeVariable = big;
	}

	cellClimate = rand() % (3 + randomBr) + 1; //!< the same thing is used as in cell size
	randomBr++;
	
	while(cellClimate > 3)
	{
		cellClimate -= 3;
	}

	if (cellClimate == 1)
	{
		climateVariable = land;
	}
	if (cellClimate == 2)
	{
		climateVariable = airborne;
	}
	if (cellClimate == 3)
	{
		climateVariable = water;
	}
	
	Cell variable(sizeVariable, climateVariable); //!< uses constructor to create a variable cell
	createSpaceForNewCell(variable);
}

void Zoopark::addCell() //!< creates cell with whatever data the user chooses
{
	char varSizeInWords[7], varClimateInWords[9]; //!< static memory variables to prevent memory leak from happening
	bool varSizeCheck = false, varClimateCheck = false; //!< flags
	size sizeVariable; //!< variable from type size
	climate climateVariable; //!< variable from type climate

	while (varSizeCheck == false) //!< the loop goes on until the user inputs the correct data
	{
		std::cout << "Enter cell size:(small, middle, big) ";
		std::cin >> varSizeInWords;

		if (strcmp(varSizeInWords, "small") == 0) //!< checks if the user's input matches any of the options
		{
			sizeVariable = small;
			varSizeCheck = true; //!< the flag is now true, because the value matches
		}
		if (strcmp(varSizeInWords, "middle") == 0)
		{
			sizeVariable = middle;
			varSizeCheck = true;
		}
		if (strcmp(varSizeInWords, "big") == 0)
		{
			sizeVariable = big;
			varSizeCheck = true;
		}

		if (varSizeCheck == false)
		{
			std::cout << oneOfTheListed << std::endl;
		}
	}

	while (varClimateCheck == false) //!< the same principle as the check for cell's size
	{
		std::cout << "Cells climate:(land, airborne, water) ";
		std::cin >> varClimateInWords;

		if (strcmp(varClimateInWords, "land") == 0)
		{
			climateVariable = land;
			varClimateCheck = true;
		}
		if (strcmp(varClimateInWords, "airborne") == 0)
		{
			climateVariable = airborne;
			varClimateCheck = true;
		}
		if (strcmp(varClimateInWords, "water") == 0)
		{
			climateVariable = water;
			varClimateCheck = true;
		}

		if (varClimateCheck == false)
		{
			std::cout << oneOfTheListed << std::endl;
		}
	}

	Cell variable(sizeVariable, climateVariable); //!< constructor with given size and climate
	createSpaceForNewCell(variable); //!< saves the created cell in the memory

	successfullyCreatedCell();
}

void Zoopark::twoOptionMenuDinosaur() //!< shows two option menu for the user
{
	std::cout << " " << std::endl;
	std::cout << "+----------------------------------------+" << std::endl;
	std::cout << "|          You have two options          |" << std::endl; //!< shows the user his options
	std::cout << "|----------------------------------------|" << std::endl;
	std::cout << "|1) Add food and staff for the dinosaurs |" << std::endl;
	std::cout << "|2) Remove this dinosaur                 |" << std::endl;
	std::cout << "+----------------------------------------+" << std::endl;
	std::cout << " " << std::endl;
}

void Zoopark::addOrRemoveDinosaur(const Dinosaur & other, int index) //!< gives the user a choice either the user must add food and staff
{                                                                    //!< or remove the dinosaur
	int choice = 0; //!< variable for user's choice
	bool addOrRemove = false; //!< flag

	twoOptionMenuDinosaur();

	while (addOrRemove == false)
	{
		std::cout << "Choice(1/2): ";
		std::cin >> choice;

		if (choice == 1 || choice == 2) 
		{
			addOrRemove = true; //!< if the input is correct the loop stops

			if (choice == 1)
			{
				addFoodNecessary(); //!< adds at least the minimum required amount of food
				appointStaff(); //!< adds the necessary workers

				successfullySavedData(); //!< shows the data is successfully saved
			}
			else
			{
				notSavedDataStatus();
				this->cells[index].removeDinosaur(other.getName()); //!< removes the dinosaur from the cage
			}
		}
		else
		{
			std::cout << "Choose one of the listed!" << std::endl;
		}
	}
	removeD = true;
}

void Zoopark::loadProvision(const Dinosaur& other, int index) //!< checks if food or workers must be added to the zoo
{                                                             //!< to make adding a dinosaur possible
	if (enoughFood() == false || enoughStaff() == false) //!< checks if something needs to be added
	{
		if (enoughFood() == false && enoughStaff() == true) //!< verification if only food should be added
		{
			notEnoughFood();

			addFoodNecessary(); //!< adds the minimum necessary amount
			successfullySavedData(); //!< shows that the data is succcessfully saved

			removeD = true;
		}
		else if (enoughFood() == true && enoughStaff() == false) //!< verification if only workers should be added
		{
			notEnoughStaff();

			appointStaff(); //!< appoints the minimum necessary amount
			successfullySavedData(); //!< shows that the data is successfully saved

			removeD = true;
		}
		else
		{
			addOrRemoveDinosaur(other, index); //!< gives user two options either to add staff and food                
		}                                      //!< or to remove the dinosaur
	}
}

void Zoopark::newCellForDinosaur(const Dinosaur & other, bool cell) //!< gives the user a chane to create a new cell
{                                                              //!< and then checks if it suitable fot the dinosaur
	char choice[4];                                            //!< and are there enough provision if not
	bool rigthChoice = false;                                  //!< they can be added
															   
	std::cout << "Do you want to create a new cell to put the dinosaurs?(yes/no)";

	while (rigthChoice == false) //!< the loop goes on until the user inputs the correct data
	{
		std::cin >> choice; //!< user inputs his choice

		if (strcmp(choice, "yes") == 0)
		{
			this->addCell(); //!< adds cell

			for (int i = 0; i < this->capacityOfCells; i++) //!< goes through all the cages
			{
				if (this->cells[i].addDinosaur(other) == true) //!< if a cage is suitable then the user must
				{                                              //!< load provisions 
					loadProvision(other, i);
					cell = true;
					break;
				}
			}

			if (cell == false) //!< that means the new cell is not suitable as well
			{
				notSavedDataStatus();
			}

			rigthChoice = true; //!< the flag is now true
		}
		else if (strcmp(choice, "no") == 0)
		{
			notSavedDataStatus();
			rigthChoice = true; //!< the flag is true
		}
		else
		{
			std::cout << "Choose one of the options: ";
		}
	}
}

void Zoopark::addDinosaurInCell() //!< adds dinosaur in cell if all the necessary conditions are met
{
	Dinosaur variable; //!< declare dinosaur
	bool newCellCheck = false; //!< flag

	std::cin.get(); //!< input dinosaur data
	std::cin >> variable;

	for (int i = 0; i < this->capacityOfCells; i++) //!< searches if a dinosaur can be added in any of the current cells
	{
		if (this->cells[i].addDinosaur(variable) == true)
		{
			removeD = false; //!< flag
			newCellCheck = true; //!< flag

			loadProvision(variable, i); //!< adds needed provisions otherwise deletes the dinosaur
			break;
		}
	}

	if (newCellCheck == false) //!< if this flag is still false that means there isn't suitable cage for the 
	{                          //!< dinosaur at the moment
		newCellForDinosaur(variable, newCellCheck); //!<gives the user the chanse to create a new cell and makes
	}                                               //!< all the checks again
}

void Zoopark::removeDinosaurFromCell() //!< removes a dinosaur from the cell it inhabits
{
	char dinosaurRemove[256]; //!< static variable to prevent memory leak from happening
	bool successfully = false; //!<flag that shows if the dinosaur is removed successfully

	std::cout << "Enter the name of the dinosaur you would like to remove: ";

	if (removeD == false) //!< this verification ensures that the first character from the dinosaur name is not dropped
	{
		std::cin.sync();
		removeD = true;
	}
	else
	{
		std::cin.get();
		removeD = true;
	}

	std::cin.getline(dinosaurRemove, 256);

	for (int i = 0; i < this->numberOfCells; i++) //!< goes through all the cells and searches for the dinosaur by 
	{                                             //!< the name the user entered
		if (this->cells[i].isDinosaurHere(dinosaurRemove) == true) //!< checks if the dinosaur is in the current cell
		{
			successfullyRemoved(); //!< shows that the data is successfully saved
			this->cells[i].removeDinosaur(dinosaurRemove); //!< removes dinosaur
			successfully = true; //!< the flag is now true, because the removal is successful
		}
	}

	if (successfully == false)
	{
		noDinosaurMatch(); //!< shows that the dinosaur was not found
	}
}

void Zoopark::createStartingBase() //!< creates random number empty cells with random size and climate 
{
	int randomNumberCells = 0; //!< variable to save the randomized number

	srand(time(NULL));
	randomNumberCells = rand() % 10 + 1;

	for (int i = 0; i < randomNumberCells; i++)
	{
		this->randomCells(); //!< creates random cell
	}
}

int Zoopark::numberDinosaursGround() //!< returns the number of dinosaurs, which live on the ground
{
	int br = 0; //!< variable to save the number

	for (int i = 0; i < this->numberOfCells; i++)
	{
		if (this->cells[i].getDinosaursDischarge() == 1 || this->cells[i].getDinosaursDischarge() == 2) 
		{                                                 //!< checks if the dinosaur discharge meets the condition
			br += this->cells[i].getNumberOfDinosaurs();
		}
	}

	return br;
}

int Zoopark::numberDinosaursAir() //!< returns the number of dinosaurs, which live in the air
{
	int br = 0;

	for (int i = 0; i < this->numberOfCells; i++)
	{
		if (this->cells[i].getDinosaursDischarge() == 3)
		{
			br += this->cells[i].getNumberOfDinosaurs();
		}
	}

	return br;
}

int Zoopark::numberDinosaursWater() //!< returns the number of dinosaurs, which live in the air
{
	int br = 0;

	for (int i = 0; i < this->numberOfCells; i++)
	{
		if (this->cells[i].getDinosaursDischarge() == 4)
		{
			br += this->cells[i].getNumberOfDinosaurs();
		}
	}

	return br;
}

int Zoopark::numberWorkersOnGround() //!< returns the number of workers, who specializes in caring for the
{                                    //!< dinosaurs on the ground
	int br = 0;

	for (int i = 0; i < this->numberOfWorkers; i++)
	{
		if (this->workers[i].getWorkPosition() == 1) //!< checks working position
		{
			br++;
		}
	}

	return br;
}

int Zoopark::numberWorkersOnAir() //!< returns the number of workers, who specializes in caring for the
{                                 //!< dinosaurs in the air
	int br = 0;

	for (int i = 0; i < this->numberOfWorkers; i++)
	{
		if (this->workers[i].getWorkPosition() == 2)
		{
			br++;
		}
	}

	return br;
}

int Zoopark::numberWorkersOnWater() //!< returns the number of workers, who specializes in caring for the
{                                   //!< dinosaurs in the water
	int br = 0;

	for (int i = 0; i < this->numberOfWorkers; i++)
	{
		if (this->workers[i].getWorkPosition() == 3)
		{
			br++;
		}
	}

	return br;
}

int Zoopark::numberWorkersOnFood() //!< returns the number of workers, who supply the cells with food
{
	int br = 0;

	for (int i = 0; i < this->numberOfWorkers; i++)
	{
		if (this->workers[i].getWorkPosition() == 4)
		{
			br++;
		}
	}

	return br;
}

void Zoopark::parkRules() //!< shows park rules
{
	std::cout << "+------------------------------------------------!Jurrasic Park rules!------------------------------------------------+" << std::endl;
	std::cout << "| 1)Every dinosaur needs at least 10kg food. The food depends on the dinosaur's discharge.                            |" << std::endl;
	std::cout << "| 2)Every dinosaur need at least one specialist to take care for them. Every worker specializes in differen climate.  |" << std::endl;
	std::cout << "| 3)There must be a food supplier to feed the dinosaurs.                                                              |" << std::endl;
	std::cout << "| 4)Every worker must be between 20 and 90 years old.                                                                 |" << std::endl;
	std::cout << "| 5)Only dinosaurs of the same discharge and era can live in one cell.                                                |" << std::endl;
	std::cout << "| 6)Flying dinosaurs consume meat.                                                                                    |" << std::endl;
	std::cout << "| 7)Every cell size has different capacity.(small - 1, middle - 3, big - 10)                                          |" << std::endl;
	std::cout << "+---------------------------------------------------------------------------------------------------------------------+" << std::endl;
	std::cout << " " << std::endl;
}

void Zoopark::managmentSystem() //!< shows managment system
{
	std::cout << " " << std::endl;
	std::cout << "+----------------------------------------------------------+" << std::endl;
	std::cout << "|                     MANAGMENT SYSTEM                     |" << std::endl;
	std::cout << "|----------------------------------------------------------|" << std::endl;
	std::cout << "| 1)| You can add a new dinosaurs                          |" << std::endl;
	std::cout << "|----------------------------------------------------------|" << std::endl;
	std::cout << "| 2)| You can build a new cell                             |" << std::endl;
	std::cout << "|----------------------------------------------------------|" << std::endl;
	std::cout << "| 3)| You can remove already existing dinosaur             |" << std::endl;
	std::cout << "|----------------------------------------------------------|" << std::endl;
	std::cout << "| 4)| You can load food into the wearhouse                 |" << std::endl;
	std::cout << "|----------------------------------------------------------|" << std::endl;
	std::cout << "| 5)| Exit                                                 |" << std::endl;
	std::cout << "|----------------------------------------------------------|" << std::endl;
	std::cout << "| 6)| Clear console(shows only rules and managment system) |" << std::endl;
	std::cout << "+----------------------------------------------------------+" << std::endl;
	std::cout << "Enter the command you want to execute(1-6): ";
}

void Zoopark::enterTheZoo() //!< creates starting base and shows 
{
	bool exit = false; //!< flag for exit
	int choice = 0;

	parkRules(); //!< shows the zoopark rules
	this->createStartingBase(); //!< creates random number empty cells with randomized size and climate

	while (exit == false)
	{
		managmentSystem(); //!< shows the console with commands from which the user selects

		std::cin >> choice;
		std::cout << " " << std::endl;

		switch (choice)
		{
		case 1:
		{
			this->addDinosaurInCell(); //!< adds dinosaur in cell 
			break;
		}
		case 2:
		{
			this->addCell(); //!< adds cell to the zoopark
			break;
		}
		case 3:
		{
			this->removeDinosaurFromCell(); //!< removes dinosaur from cell
			break;
		}
		case 4:
		{
			this->addFoodByChoice(); //!< adds extra food
			break;
		}
		case 5:
		{
			exit = true; //!< the flag is true to stop the loop
			save(); //!< saves all the data in the
			break;
		}
		case 6:
		{
			system("cls"); //!< clears the console
			parkRules(); //!< shows jurassic park rules

			break;
		}
		default:
		{
			std::cout << "Wrong input. Please choose one of the listed options!" << std::endl;
			break;
		}
		}
	}
}

void Zoopark::notSavedDataStatus() //!< shows the data is not saved
{
	std::cout << " " << std::endl;
	std::cout << "+-----------------------------------------+" << std::endl;
	std::cout << "| STATUS: " << notSavedData << "     |" << std::endl;
	std::cout << "+-----------------------------------------+" << std::endl;
	std::cout << " " << std::endl;
}

void Zoopark::successfullySavedData() //!< shows that the data is successfully saved
{
	std::cout << " " << std::endl;
	std::cout << "+---------------------------------------------+" << std::endl;
	std::cout << "| STATUS: Dinosaur data is successfully saved!|" << std::endl;
	std::cout << "+---------------------------------------------+" << std::endl;
	std::cout << " " << std::endl;
}

void Zoopark::successfullyRemoved() //!< shows that the dinosaur is successfully removed
{
	std::cout << " " << std::endl;
	std::cout << "+---------------------------------------------+" << std::endl;
	std::cout << "| STATUS: Dinosaur was successfully removed!  |" << std::endl;
	std::cout << "+---------------------------------------------+" << std::endl;
	std::cout << " " << std::endl;
}

void Zoopark::noDinosaurMatch() //!< shows that the dinosaur was not found
{
	std::cout << " " << std::endl;
	std::cout << "+-----------------------------------------------+" << std::endl;
	std::cout << "| STATUS: No dinosaur with such name was found! |" << std::endl;
	std::cout << "+-----------------------------------------------+" << std::endl;
	std::cout << " " << std::endl;
}

void Zoopark::save() //!< saves data in a file
{
	char fileName[256]; //!< static data to prevent from memory leak

	std::cout << "Enter a file name to save the data: ";

	std::cin.get();
	std::cin.getline(fileName, 256);
	setOutputFile(fileName); 

	std::fstream out(this->outputFile, std::ios::app); //!< output file is the file in which the data will be saved and 
	                                                   //!< ios::app is used to create the file if it doesn't already exist
	out << "Number of created cells: " << this->numberOfCells << std::endl
		<< "All cells:\n " << std::endl;
	 
	for (int i = 0; i < this->capacityOfCells; i++)
	{
		out << this->cells[i] << std::endl; //!< outputs all the data cells in the file
	}

	out.close();
}

std::ostream & operator<<(std::ostream & out, const Zoopark & other) //!< operator << 
{
	out << "Number of created cells: " << other.numberOfCells << std::endl
		<< "Capacity of created cells: " << other.capacityOfCells << std::endl
		<< "All cells: " << std::endl;

	for (int i = 0; i < other.capacityOfCells; i++) //!< goes through all the cells
	{
		out << other.cells[i] << std::endl;
	}

	return out;
}

std::istream & operator>>(std::istream & in, Zoopark & other) //!< operator >>
{
	std::cout << "Enter how many cells would you like to build: ";
	in >> other.numberOfCells; //!< number of cells

	other.capacityOfCells = other.numberOfCells;

	for (int i = 0; i < other.capacityOfCells; i++)
	{
		std::cout << "Enter a cell info: ";
		in >> other.cells[i];
	}

	return in;
}
