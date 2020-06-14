#include "stdafx.h"
#include "Dinosaur.h"

void Dinosaur::copy(const Dinosaur & other) //!< copies all the data from one cell to another
{
	setName(other.name);
	setGender(other.gender);
	setDinosaurEra(other.dinosaurEra);
	setDinosaurDischarge(other.dinosaurDischarge);
	setType(other.type);
	setDinosaurFood(other.getDinosaurDischarge());
}

void Dinosaur::destroy() //!< deletes data to prevent memory leak from happening
{
	delete[] this->name;
	delete[] this->type;
}

Dinosaur::Dinosaur():name(nullptr), type(nullptr) //!< default constructor
{
	setName("Default name");
	setGender('m');
	setDinosaurEra(trias);
	setDinosaurDischarge(flying);
	setType("tyrannosaur");
	setDinosaurFood(getDinosaurDischarge());
}

Dinosaur::Dinosaur(const Dinosaur & other) //!< copy constructor
{
	this->copy(other);
}

Dinosaur & Dinosaur::operator=(const Dinosaur & other) //!< operator =
{
	if (this != &other) //!< if the condition is not met, then there will be no point of rewriting the data
	{                   //!< because it would be the same
		this->copy(other);
	}
	return *this;
}

Dinosaur::~Dinosaur() //!< destructor
{
	this->destroy();
}

Dinosaur::Dinosaur(const char * newName, char newGender, era newDinosaurEra,
	discharge newDinosaurDischarge, const char * newType) //!< constructor with all the data
	:name(nullptr), type(nullptr)
{
	setName(newName);
	setGender(newGender);
	setDinosaurEra(newDinosaurEra);
	setDinosaurDischarge(newDinosaurDischarge);
	setType(newType);
	setDinosaurFood(getDinosaurDischarge());
}
                                                          //!< setters and getters
void Dinosaur::setName(const char * newName)
{
	if (newName != NULL) //!< if the condition is not met, then there is no point of deleting not existing memory
	{
		delete[] this->name;
		this->name = new char[strlen(newName) + 1]; //!< sets aside memory for the new name and determining zero
		strcpy_s(this->name, strlen(newName) + 1, newName);
	}
}

const char * Dinosaur::getName() const
{
	return this->name;
}

void Dinosaur::setGender(char newGender)
{
	this->gender = newGender;
}

char Dinosaur::getGender() const
{
	return this->gender;
}

void Dinosaur::setDinosaurEra(era newDinosaurEra)
{
	switch (newDinosaurEra) //!< switch must be used to set value for enumerators
	{
	case 1:
	{
		this->dinosaurEra = trias;
		break;
	}
	case 2:
	{
		this->dinosaurEra = chalk;
		break;
	}
	case 3:
	{
		this->dinosaurEra = jura;
		break;
	}
	case 4:
	{
		this->dinosaurEra = none;
		break;
	}
	default:
	{
		this->dinosaurEra = trias;
		break;
	}
	}
}

era Dinosaur::getDinosaurEra() const
{
	return this->dinosaurEra;
}

void Dinosaur::setDinosaurDischarge(discharge newDinosaurDischarge)
{
	switch (newDinosaurDischarge)
	{
	case 1:
	{
		this->dinosaurDischarge = herbivorous;
		break;
	}
	case 2:
	{
		this->dinosaurDischarge = carnivorous;
		break;
	}
	case 3:
	{
		this->dinosaurDischarge = flying;
		break;
	}
	case 4:
	{
		this->dinosaurDischarge = aqueous;
		break;
	}
	default:
	{
		this->dinosaurDischarge = herbivorous;
		break;
	}
	}
}

discharge Dinosaur::getDinosaurDischarge() const
{
	return this->dinosaurDischarge;
}

void Dinosaur::setType(const char * newType)
{
	if (newType != NULL)
	{
		delete[] this->type;
		this->type = new char[strlen(newType) + 1];
		strcpy_s(this->type, strlen(newType) + 1, newType);
	}
}

const char * Dinosaur::getType() const
{
	return this->type;
}

void Dinosaur::setDinosaurFood(int newFood)
{
	switch (newFood)
	{
	case 1:
	{
		this->dinosaurFood = grass;
		break;
	}
	case 2:
	{
		this->dinosaurFood = meat;
		break;
	}
	case 3:
	{
		this->dinosaurFood = meat;
		break;
	}
	case 4:
	{
		this->dinosaurFood = fish;
		break;
	}
	default:
	{
		this->dinosaurFood = grass;
		break;
	}
	}
}

food Dinosaur::getDinosaurFood() const
{
	return this->dinosaurFood;
}

std::ostream & operator<<(std::ostream & out, const Dinosaur & other) //!< operator <<
{
	out << "Dinosaur name: " << other.name << std::endl
		<< "Dinosaur gender: " << other.gender << std::endl
		<< "Dinosaur Era: ";

	switch (other.dinosaurEra) //!< again switch must be used for the enumerators
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
	default:
	{
		out << "wrong data" << std::endl;
		break;
	}
	}

	out << "Dinosaur discharge: ";

	switch (other.dinosaurDischarge)
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
	default:
	{
		out << "wrong data" << std::endl;
	}
	}

	out << "Dinosaur type: " << other.type << std::endl
		<< "Dinosaur food: ";

	switch (other.dinosaurFood)
	{
	case 1:
	{
		out << "grass" << std::endl;
		break;
	}
	case 2:
	{
		out << "meat" << std::endl;
		break;
	}
	case 3:
	{
		out << "fish" << std::endl;
		break;
	}
	default:
		break;
	}
	   
	return out;
}

std::istream & operator>>(std::istream & in, Dinosaur & other) //!< operator >>
{
	int era, discharge; //!< because switch is used, the user choice must be saved as int
	char name[256], eraInWords[6], dischargeInWords[12], type[128]; //!< static memory is used, to prevent memory leak from happening
	bool genderCheck = false, eraCheck = false, dischargeCheck = false; //!< flags which are used for the loops

	std::cout << "Name: ";

	in.getline(name, 256);
	other.setName(name);

	while (genderCheck == false) //!< the loop goes on until the user inputs the correct data
	{
		std::cout << "Gender:(f/m) ";
		in >> other.gender; //!< the user enters data

		if (other.gender == 'f' || other.gender == 'm') //!< checks if the input matches one of the correct choices
		{
			genderCheck = true; //!< the falg is now true and the loop stops
		}
		else
		{
			std::cout << "Enter f for female or m for male!" << std::endl;
		}
	}

	while (eraCheck == false) //!< similar as the verification for the gender above
	{
		std::cout << "Era:(trias, chalk, jura) ";
		in >> eraInWords;

		if (strcmp(eraInWords, "trias") == 0)
		{
			era = 1;
		}
		if (strcmp(eraInWords, "chalk") == 0)
		{
			era = 2;
		}
		if (strcmp(eraInWords, "jura") == 0)
		{
			era = 3;
		}

		if (era == 1 || era == 2 || era == 3)
		{
			eraCheck = true;

			switch (era) 
			{
			case 1:
			{
				other.setDinosaurEra(trias);
				break;
			}
			case 2:
			{
				other.setDinosaurEra(chalk);
				break;
			}
			case 3:
			{
				other.setDinosaurEra(jura);
				break;
			}
			case 4:
			{
				other.setDinosaurEra(none);
				break;
			}
			default:
			{
				other.setDinosaurEra(trias);
				break;
			}
			}
		}
		else
		{
			std::cout << "Choose one of the listed!" << std::endl;
		}
	}

	while (dischargeCheck == 0) //!< similar as the verification for the era above
	{
		std::cout << "Discharge:(herbivorous, carnivorous, flying, aqueous) ";
		in >> dischargeInWords;

		if (strcmp(dischargeInWords, "herbivorous") == 0)
		{
			discharge = 1;
		}
		if (strcmp(dischargeInWords, "carnivorous") == 0)
		{
			discharge = 2;
		}
		if (strcmp(dischargeInWords, "flying") == 0)
		{
			discharge = 3;
		}
		if (strcmp(dischargeInWords, "aqueous") == 0)
		{
			discharge = 4;
		}

		if (discharge == 1 || discharge == 2 || discharge == 3 || discharge == 4)
		{
			dischargeCheck = true;

			switch (discharge)
			{
			case 1:
			{
				other.setDinosaurDischarge(herbivorous);
				break;
			}
			case 2:
			{
				other.setDinosaurDischarge(carnivorous);
				break;
			}
			case 3:
			{
				other.setDinosaurDischarge(flying);
				break;
			}
			case 4:
			{
				other.setDinosaurDischarge(aqueous);
				break;
			}
			default:
			{
				other.setDinosaurDischarge(herbivorous);
				break;
			}
			}

		}
		else
		{
			std::cout << "Choose one of the listed!" << std::endl;
		}

	}

	std::cout << "Type: ";

	in.get();
	in.getline(type, 128);
	other.setType(type);

	other.setDinosaurFood(other.getDinosaurDischarge());

	return in;
}
