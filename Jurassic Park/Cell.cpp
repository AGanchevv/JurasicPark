#include "stdafx.h"
#include "Cell.h"

void Cell::increaseCellSize() //!< increases cell capacity
{
	this->capacity++;

	Dinosaur* variable = new Dinosaur[this->capacity]; //!< settes aside memory for one more dinosaur

	for (int i = 0; i < this->numberOfDinosaurs; i++)
	{
		variable[i] = this->dinosaurs[i];
	}

	this->destroy(); //!< deletes the old information
	this->dinosaurs = variable; //!< assignes values
}

void Cell::resinCellSize() //!< decreases cell capacity
{
	this->capacity--;

	if (this->numberOfDinosaurs < this->capacity) //!< if the number of dinosaurs is bigger than the capacity
	{                                             //!< there will be a memory leak
		Dinosaur* variable = new Dinosaur[this->capacity];

		for (int i = 0; i < this->capacity; i++)
		{
			variable[i] = this->dinosaurs[i];
		}

		this->destroy();
		this->dinosaurs = variable;
	}
}

void Cell::copy(const Cell & other) //!< copies all the data from one cell to another
{
	setCellSize(other.cellSize);
	setCapacity(other.capacity);
	setNumberOfDinosaurs(other.numberOfDinosaurs);
	setDinosaursEra(other.dinosaursEra);
	setDinosaursDischarge(other.dinosaursDischarge);
	setDinosaursClimate(other.dinosaursClimate);

	this->dinosaurs = new Dinosaur[this->capacity]; //!< dynamic memory

	for (int i = 0; i < capacity; i++)
	{
		this->dinosaurs[i] = other.dinosaurs[i];
	}
}

void Cell::destroy() //!< deletes data to prevent memory leak from happening
{
	delete[] this->dinosaurs;
}

Cell::Cell() //!< default constructor
{
	setCellSize(small);
	setCapacity(0);
	setNumberOfDinosaurs(0);
	setDinosaursEra(none);
	setDinosaursDischarge(nothing);
	setDinosaursClimate(land);
	this->dinosaurs = new Dinosaur[this->capacity];
}

Cell::Cell(const Cell & other) //!< copy constructor
{
	this->copy(other);
}

Cell & Cell::operator=(const Cell & other) //!< operator =
{
	if (this != &other)
	{
		this->copy(other);
	}
	return *this;
}

Cell::~Cell() //!< destructor
{
	this->destroy();
}

Cell::Cell(size newCellSize, era newDinosaursEra) //!< constructor with only given size and era
{
	setCellSize(newCellSize);
	setCapacity(0);
	setNumberOfDinosaurs(0);
	setDinosaursEra(newDinosaursEra);
	setDinosaursDischarge(nothing);
	setDinosaursClimate(land);
	this->dinosaurs = new Dinosaur[this->capacity];
}

Cell::Cell(size newCellSize, climate newDinosaursClimate) //!< constructor with only given size and climate
{
	setCellSize(newCellSize);
	setCapacity(0);
	setNumberOfDinosaurs(0);
	setDinosaursEra(none);
	setDinosaursDischarge(nothing);
	setDinosaursClimate(newDinosaursClimate);
	this->dinosaurs = new Dinosaur[0];
}
                                                //!< setters and getters
void Cell::setCellSize(size newCellSize)
{
	switch (newCellSize) //!< switch must be used to set value for enumerators
	{
	case 1:
	{
		this->cellSize = small;
		break;
	}
	case 2:
	{
		this->cellSize = middle;
		break;
	}
	case 3:
	{
		this->cellSize = big;
		break;
	}
	default:
	{
		this->cellSize = small;
		break;
	}
	}
}

size Cell::getCellSize() const
{
	return this->cellSize;
}

void Cell::setCapacity(int newCapacity)
{
	this->capacity = newCapacity;
}

int Cell::getCapacity() const
{
	return this->capacity;
}

void Cell::setNumberOfDinosaurs(int newNumberOfDinosaurs)
{
	this->numberOfDinosaurs = newNumberOfDinosaurs;
}

int Cell::getNumberOfDinosaurs() const
{
	return this->numberOfDinosaurs;
}

void Cell::setDinosaursDischarge(discharge newDinosaursDischarge)
{
	switch (newDinosaursDischarge) //!< switch must be used to set value for enumerators
	{
	case 1:
	{
		this->dinosaursDischarge = herbivorous;
		break;
	}
	case 2:
	{
		this->dinosaursDischarge = carnivorous;
		break;
	}
	case 3:
	{
		this->dinosaursDischarge = flying;
		break;
	}
	case 4:
	{
		this->dinosaursDischarge = aqueous;
		break;
	}
	case 5:
	{
		this->dinosaursDischarge = nothing;
		break;
	}
	default:
	{
		this->dinosaursDischarge = herbivorous;
		break;
	}
	}
}

discharge Cell::getDinosaursDischarge() const
{
	return this->dinosaursDischarge;
}

void Cell::setDinosaursClimate(climate newDinosaursClimate)
{
	switch (newDinosaursClimate) //!< switch must be used to set value for enumerators
	{
	case 1:
	{
		this->dinosaursClimate = land;
		break;
	}
	case 2:
	{
		this->dinosaursClimate = airborne;
		break;
	}
	case 3:
	{
		this->dinosaursClimate = water;
		break;
	}
	default:
	{
		this->dinosaursClimate = land;
		break;
	}
	}
}

climate Cell::getDinosaursClimate() const
{
	return this->dinosaursClimate;
}

void Cell::setDinosaursEra(era newDinosaursEra)
{
	switch (newDinosaursEra) //!< switch must be used to set value for enumerators
	{
	case 1:
	{
		this->dinosaursEra = trias;
		break;
	}
	case 2:
	{
		this->dinosaursEra = chalk;
		break;
	}
	case 3:
	{
		this->dinosaursEra = jura;
		break;
	}
	case 4:
	{
		this->dinosaursEra = none;
		break;
	}
	default:
	{
		this->dinosaursEra = trias;
		break;
	}
	}
}

era Cell::getDinosaursEra() const
{
	return this->dinosaursEra;
}

bool Cell::addDinosaur(const Dinosaur& other) //!< adds new dinosaur in cell
{
	int volume; //!< variable which saves the cell size 

	switch (this->getCellSize()) //!< switch to check cell maximum capacity
	{
	case 1:
	{
		volume = 1;
		break;
	}
	case 2:
	{
		volume = 3;
		break;
	}
	case 3:
	{
		volume = 10;
		break;
	}
	default:
	{
		volume = 1;
		break;
	}
	}
	//!< there must be different functions for the first and the other dinosaurs, because the first dinosaur determines the cell's era and discharge
	if (checkIndex(volume, other) && this->numberOfDinosaurs == 0) //!< verification if the cell is suitable for this dinosaur
	{                                                              //!< and the cell is empty
		firstDinosaurInCell(other); //!< enteres first dinosaur
		return true;
	}
	else if (checkIndex(volume, other) && compareDinosaurEra(other) && this->numberOfDinosaurs != 0) //!< verification if the cell is suitable for this dinosaur
	{                                                                   //!< and the cell is not empty
		anotherDinosaurInCell(other); //!< enteres dinosaur
		return true;
	}
	else
	{
		return false;
	}
}

void Cell::removeDinosaur(const char* other) //!< removes already existing in the cell dinosaur by given dinosaurs name
{
	int index = -1; //!< variable for the dinosaurs index

	for (int i = 0; i < this->capacity - 1; i++)
	{
		if (strcmp(this->dinosaurs[i].getName(), other) == 0) //!< verification if the given name matches with
		{                                                     //!< some dinosaurs name from the cell
			index = i; //!< index of the dinosaur with the same name
			break; //!< when the index is found there is no point from searching anymore, so "break" stops the loop
		}
	}
	
	if (index != -1) //!< verification if any dinosaur matched the searched name
	{
		for (int i = index; i < this->capacity - 1; i++) //!< the loop starts from the dinosaur with the searched name
		{
			this->dinosaurs[i] = this->dinosaurs[i + 1]; //!< rewrites every dinosaurs data with the next dinosaurs data
		}
	}

	this->numberOfDinosaurs--; //!< reduces dinosaurs number
	resinCellSize(); //!< decreases cell capacity
}

bool Cell::enoughSpace() //!< checks if there is enough space for new dinosaur
{
	int volume;

	switch (this->getCellSize()) //!< maximum cell capacity
	{
	case 1:
	{
		volume = 1;
		break;
	}
	case 2:
	{
		volume = 3;
		break;
	}
	case 3:
	{
		volume = 10;
		break;
	}
	default:
	{
		volume = 1;
		break;
	}
	}

	if (this->numberOfDinosaurs < volume) //!< checks if the current dinosaurs number is lower than max capacity
	{
		return true;
	}
	else
	{
		return false;
	}
}

Dinosaur * Cell::allDinosaurs() const //!< returns all dinosaurs
{
	return this->dinosaurs;
}

bool Cell::isDinosaurHere(const char* other) //!< searches by given name if the cage contains dinosaur
{
	for (int i = 0; i < this->capacity; i++)
	{
		if (strcmp(this->dinosaurs[i].getName(), other) == 0) //!< compares the given name with the current dinosaurs name
		{
			return true; //!< if it matches, the function returns true
		}
	}

	return false;
}

bool Cell::compareDinosaurEra(const Dinosaur & other) //!< compares dinosaur era with cell's era
{
	if (other.getDinosaurEra() == 1 && this->dinosaursEra == 1) //!< case for trias
	{
		return true;
	}
	else if (other.getDinosaurEra() == 2 && this->dinosaursEra == 2) //!< case for chalk
	{
		return true;
	}
	else if (other.getDinosaurEra() == 3 && this->dinosaursEra == 3) //!< case for jura
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool Cell::checkIndex(int volume, const Dinosaur & other) //!< checks if a dinosaur can be added to the cell
{
	if (volume > this->numberOfDinosaurs) //!< compares cells max capacity with current dinosaurs number
	{                                                    //!< verifications if the climate is suitable for dinosaur's discharge
		if ((other.getDinosaurDischarge() == 1 || other.getDinosaurDischarge() == 2) && this->getDinosaursClimate() == 1) 
		{
			return true;
		}
		else if (other.getDinosaurDischarge() == 3 && this->getDinosaursClimate() == 2)
		{
			return true;
		}
		else if (other.getDinosaurDischarge() == 4 && this->getDinosaursClimate() == 3)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool Cell::firstDinosaurInCell(const Dinosaur & other) //!< enteres first dinosaur
{
	increaseCellSize(); //!< increases cell capacity

	setDinosaursEra(other.getDinosaurEra()); //!< sets the era in the cell
	setDinosaursDischarge(other.getDinosaurDischarge()); //!< sets the discharge in the cell

	this->dinosaurs[this->numberOfDinosaurs] = other;
	this->numberOfDinosaurs++;

	return true;
}

bool Cell::anotherDinosaurInCell(const Dinosaur & other) //!< enteres dinosaur
{
	if (other.getDinosaurEra() == this->dinosaursEra && other.getDinosaurDischarge() == this->dinosaursDischarge) //!< compares dinosaur's era and discharge with the era  and discharge from the dinosaurs in the cell
	{                                                                                                                      
		if (this->numberOfDinosaurs == this->capacity) //!< checks if the capacity must be increased
		{
			increaseCellSize(); //!< increases cell's capacity
		}

		this->dinosaurs[this->numberOfDinosaurs] = other;
		this->numberOfDinosaurs++;

		return true;
	}
	else //!< if the era or discharge don't compare
	{
		return false;
	}
}

std::ostream & operator<<(std::ostream & out, const Cell & other) //!< operator <<
{
	out << "Cell size: ";
	
	switch (other.cellSize)
	{
	case 1:
	{
		out << "small" << std::endl;
		break;
	}
	case 2:
	{
		out << "middle" << std::endl;
		break;
	}
	case 3:
	{
		out << "big" << std::endl;
		break;
	}
	default:
	{
		out << "wrong data" << std::endl;
		break;
	}
	}

	out << "Number of dinosaurs: " << other.numberOfDinosaurs << std::endl
		<< "Dinosaurs era in cage: ";

	switch (other.dinosaursEra)
	{
	case 1:
	{
		out << "trias" << std::endl;
		break;
	}
	case 2:
	{
		out << "chalk" << std::endl;
		break;
	}
	case 3:
	{
		out << "jura" << std::endl;
		break;
	}
	case 4:
	{
		out << "none" << std::endl;
		break;
	}
	default:
	{
		out << "wrong data" << std::endl;
		break;
	}
	}

	out << "Dinosaurs discharge: ";

	switch (other.dinosaursDischarge)
	{
	case 1:
	{
		out << "herbivorous" << std::endl;
		break;
	}
	case 2:
	{
		out << "carnivorous" << std::endl;
		break;
	}
	case 3:
	{
		out << "flying" << std::endl;
		break;
	}
	case 4:
	{
		out << "aqueous" << std::endl;
		break;
	}
	case 5:
	{
		out << "nothing" << std::endl;
		break;
	}
	default:
	{
		out << "wrong data" << std::endl;
		break;
	}
	}

	out << "Cell climate: ";

	switch (other.dinosaursClimate)
	{
	case 1:
	{
		out << "land" << std::endl;
		break;
	}
	case 2:
	{
		out << "airborne" << std::endl;
		break;
	}
	case 3:
	{
		out << "water" << std::endl;
		break;
	}
	default:
	{
		out << "wrong data" << std::endl;
		break;
	}	
	}

	out << "Dinosaurs: " << std::endl;

	for (int i = 0; i < other.getCapacity(); i++)
	{
			out << other.dinosaurs[i] << std::endl;
	}

	return out;
}

std::istream & operator>>(std::istream & in, Cell & other) //!< operator >> 
{
	int sizes, eras, discharges, climates; //!< because switch is used, the user choice must be saved as int
	char eraInWords[6], sizeInWords[7], dischargesInWords[12], climatesInWords[9]; //!< static memory is used, to prevent memory leak from happening
	bool sizesCheck = false, erasCheck = false, dischargesCheck = false, climatesCheck = false; //!< flags

	while (sizesCheck == false) //!< the loop goes on until the user inputs the correct data
	{
		std::cout << "Enter cell size:(small, middle, big) ";
		in >> sizeInWords;

		if (strcmp(sizeInWords, "small") == 0) //!< compares the input to the options
		{
			sizes = 1;
		}
		if (strcmp(sizeInWords, "middle") == 0)
		{
			sizes = 2;
		}
		if (strcmp(sizeInWords, "big") == 0)
		{
			sizes = 3;
		}

		if (sizes == 1 || sizes == 2 || sizes == 3) //!< verification if size matches one of the options
		{
			sizesCheck = true; //!< the flag is true to stop the loop

			switch (sizes)
			{
			case 1:
			{
				other.setCellSize(small); //!< sets size
				other.setCapacity(1); //!< sets capacity
				break;
			}
			case 2:
			{
				other.setCellSize(middle);
				other.setCapacity(3);
				break;
			}
			case 3:
			{
				other.setCellSize(big);
				other.setCapacity(10);
				break;
			}
			default:
			{
				other.setCellSize(small);
				other.setCapacity(1);
				break;
			}
			}
		}
		else
		{
			std::cout << "Enter one of the listed sizes!" << std::endl;
		}

	}
	
	while (erasCheck == false) //!< similar as the verification for the size above
	{
		std::cout << "Enter era:(trias, chalk, jura) ";
		in >> eraInWords;

		if (strcmp(eraInWords, "trias") == 0)
		{
			eras = 1;
		}
		if (strcmp(eraInWords, "chalk") == 0)
		{
			eras = 2;
		}
		if (strcmp(eraInWords, "jura") == 0)
		{
			eras = 3;
		}

		if (eras == 1 || eras == 2 || eras == 3)
		{
			erasCheck = true;

			switch (eras)
			{
			case 1:
			{
				other.setDinosaursEra(trias);
				break;
			}
			case 2:
			{
				other.setDinosaursEra(chalk);
				break;
			}
			case 3:
			{
				other.setDinosaursEra(jura);
				break;
			}
			case 4:
			{
				other.setDinosaursEra(none);
				break;
			}
			default:
			{
				other.setDinosaursEra(trias);
				break;
			}
			}
		}
		else
		{
			std::cout << "Enter one of the listed eras!" << std::endl;
		}

	}

	while (dischargesCheck == 0) //!< similar as the verification for the era above
	{
		std::cout << "Discharge:(herbivorous, carnivorous, flying, aqueous) ";
		in >> dischargesInWords;

		if (strcmp(dischargesInWords, "herbivorous") == 0)
		{
			discharges = 1;
		}
		if (strcmp(dischargesInWords, "carnivorous") == 0)
		{
			discharges = 2;
		}
		if (strcmp(dischargesInWords, "flying") == 0)
		{
			discharges = 3;
		}
		if (strcmp(dischargesInWords, "aqueous") == 0)
		{
			discharges = 4;
		}
		if (strcmp(dischargesInWords, "nothing") == 0)
		{
			discharges = 5;
		}

		if (discharges == 1 || discharges == 2 || discharges == 3 || discharges == 4 || discharges == 5)
		{
			dischargesCheck = true;

			switch (discharges)
			{
			case 1:
			{
				other.setDinosaursDischarge(herbivorous);
				break;
			}
			case 2:
			{
				other.setDinosaursDischarge(carnivorous);
				break;
			}
			case 3:
			{
				other.setDinosaursDischarge(flying);
				break;
			}
			case 4:
			{
				other.setDinosaursDischarge(aqueous);
				break;
			}
			case 5:
			{
				other.setDinosaursDischarge(nothing);
				break;
			}
			default:
			{
				other.setDinosaursDischarge(herbivorous);
				break;
			}
			}

		}
		else
		{
			std::cout << "Choose one of the listed!" << std::endl;
		}

	}

	while (climatesCheck == false) //!< similar as the verification for the discharge above
	{
		std::cout << "Cells climate: ";
		in >> climatesInWords;

		if (strcmp(climatesInWords, "land") == 0)
		{
			climates = 1;
		}
		if (strcmp(climatesInWords, "airborne") == 0)
		{
			climates = 2;
		}
		if (strcmp(climatesInWords, "water") == 0)
		{
			climates = 3;
		}

		if (climates == 1 || climates == 2 || climates == 3)
		{
			climatesCheck = true;

			switch (climates)
			{
			case 1:
			{
				other.setDinosaursClimate(land);
				break;
			}
			case 2:
			{
				other.setDinosaursClimate(airborne);
				break;
			}
			case 3:
			{
				other.setDinosaursClimate(water);
				break;
			}
			default:
			{
				other.setDinosaursClimate(land);
				break;
			}
			}
		}
	}

	for (int i = 0; i < other.getCapacity(); i++)
	{
		other.setNumberOfDinosaurs(other.getNumberOfDinosaurs() + 1); //!< each time adds memory for a new dinosaur

		if (i == 0) //!< the first dinosaur
		{
			in.get();
			in >> other.dinosaurs[i];
		}
		else
		{
			in >> other.dinosaurs[i];
		}
	}

	return in;
}
