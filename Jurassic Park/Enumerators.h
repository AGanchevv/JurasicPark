#pragma once
                    //!< this is a file only for the enumerators, so the code is easier to read later on
enum era //!< data type era
{
	trias = 1,
	chalk = 2,
	jura = 3,
	none = 4
};

enum discharge //!< data type discharge
{
	herbivorous = 1,
	carnivorous = 2,
	flying = 3,
	aqueous = 4,
	nothing = 5
};

enum food //!< data type food
{
	grass = 1,
	meat = 2,
	fish = 3
};

enum size //!< data type size
{
	small = 1,
	middle = 2,
	big = 3
};

enum climate //!< data type climate
{
	land = 1,
	airborne = 2,
	water = 3
};

enum position //!< data type position
{
	groundControl = 1,
	airControl = 2,
	waterControl = 3,
	foodSupplier = 4,
	unemployed = 5
};