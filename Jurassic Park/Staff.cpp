#include "stdafx.h"
#include "Staff.h"

void Staff::copy(const Staff & other) //!< copies all data from one worker to another
{
	setWorkerName(other.workerName);
	setAge(other.age);
	setWorkPosition(other.workPosition);
}

void Staff::destroy() //!< deletes data to prevent memory leak from happening
{
	delete[] this->workerName;
}

Staff::Staff() //!< default constructor
{
	setWorkerName("Default name");
	setAge(0);
	setWorkPosition(unemployed);
}

Staff::Staff(const Staff & other) //!< copy constructor
{
	this->copy(other);
}

Staff & Staff::operator=(const Staff & other) //!< operator =
{
	if (this != &other)
	{
		this->copy(other);
	}
	return *this;
}

Staff::~Staff() //!< destructor
{
	this->destroy();
}

Staff::Staff(const char * newWorkerName, int newAge, position newWorkPosition) //!< general purpose constructor
{
	setWorkerName(newWorkerName);
	setAge(newAge);
	setWorkPosition(newWorkPosition);
}
//!< setters and getters
void Staff::setWorkerName(const char * newWorkerName)
{
	if (newWorkerName != NULL)
	{
		this->workerName = new char[strlen(newWorkerName) + 1];
		strcpy_s(this->workerName, strlen(newWorkerName) + 1, newWorkerName);
	}
}

const char * Staff::getWorkerName() const
{
	return this->workerName;
}

void Staff::setAge(int newAge)
{
	this->age = newAge;
}

int Staff::getAge() const
{
	return this->age;
}

void Staff::setWorkPosition(position newWorkPosition)
{
	switch (newWorkPosition) //!< switch for the enum type data
	{
	case 1:
	{
		this->workPosition = groundControl;
		break;
	}
	case 2:
	{
		this->workPosition = airControl;
		break;
	}
	case 3:
	{
		this->workPosition = waterControl;
		break;
	}
	case 4:
	{
		this->workPosition = foodSupplier;
		break;
	}
	case 5:
	{
		this->workPosition = unemployed;
		break;
	}
	default:
	{
		this->workPosition = groundControl;
		break;
	}
	}
}

position Staff::getWorkPosition() const
{
	return this-> workPosition;
}

std::ostream & operator<<(std::ostream& out, const Staff & other) //!< operator <<
{
	out << "Worker's name: " << other.workerName << std::endl
		<< "Worker's age: " << other.age << std::endl
		<< "Workers position: ";

	switch (other.workPosition)
	{
	case 1:
	{
		out << "groundControl" << std::endl;
		break;
	}
	case 2:
	{
		out << "airControl" << std::endl;
		break;
	}
	case 3:
	{
		out << "waterControl" << std::endl;
		break;
	}
	case 4:
	{
		out << "foodSupplier" << std::endl;
		break;
	}
	case 5:
	{
		out << "unemployed" << std::endl;
		break;
	}
	default:
	{
		out << "wrong data" << std::endl;
		break;
	}
	}

	return out;
}

std::istream & operator>>(std::istream& in, Staff & other)
{
	int position = 0; //!< because switch is used, the user choice must be saved as int
	char nameWorker[256], positionInWords[14]; //!< static memory is used, to prevent memory leak from happening
	bool positionCheck = false; //!< flag

	std::cout << "Enter worker's name: ";

	in.get();
	in.getline(nameWorker, 256);
	other.setWorkerName(nameWorker);

	while (other.age < 20 || other.age > 90) //!< the loop goes on until the user inputs the correct data
	{
		std::cout << "Enter worker's age(20-90): ";
		in >> other.age;
	}

	while (positionCheck == false) //!< the loop goes on until the user inputs the correct data
	{
		std::cout << "Enter position:(groundControl, airControl, waterControl, foodSupplier) ";
		in >> positionInWords;

		if (strcmp(positionInWords, "groundControl") == 0) //!< compares the input to the options
		{
			position = 1;
		}
		if (strcmp(positionInWords, "airControl") == 0)
		{
			position = 2;
		}
		if (strcmp(positionInWords, "waterControl") == 0)
		{
			position = 3;
		}
		if (strcmp(positionInWords, "foodSupplier") == 0)
		{
			position = 4;
		}

		if (position == 1 || position == 2 || position == 3 || position == 4) //!< verification if position matches one of the options
		{
			positionCheck = true; //!< the flag is true to stop the loop

			switch (position)
			{
			case 1:
			{
				other.setWorkPosition(groundControl);
				break;
			}
			case 2:
			{
				other.setWorkPosition(airControl);
				break;
			}
			case 3:
			{
				other.setWorkPosition(waterControl);
				break;
			}
			case 4:
			{
				other.setWorkPosition(foodSupplier);
				break;
			}
			default :
			{
				other.setWorkPosition(groundControl);
				break;
			}
			}
		}
	}
	return in;
}
