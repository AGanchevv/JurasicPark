#pragma once
#include"Dinosaur.h"//!<Enumerators.h does not has to be included, because Dinosaur.h contains it
#include<iostream>
/**
* @brief Class that represents a cell and it's residents
*/
class Cell
{
private: //!< declares data members
	size cellSize;
	int capacity;
	int numberOfDinosaurs;
	era dinosaursEra;
	discharge dinosaursDischarge;
	climate dinosaursClimate;
	Dinosaur* dinosaurs; //!< dynamic memory
	
	void increaseCellSize(); //!< increases cell capacity
	void resinCellSize(); //!< decreases cell capacity

	void copy(const Cell& other); //!< declares "big six"
	void destroy();

public:
	Cell();
	Cell(const Cell& other);
	Cell& operator=(const Cell& other);
	~Cell();

	Cell(size newCellSize, era newDinosaursEra); //!< constructor with only size and era
	Cell(size newCellSize, climate newDinosaursClimate); //!<constructor with size and climate
	                                       //!<setters and getters
	void setCellSize(size newCellSize);
	size getCellSize()const;

	void setCapacity(int newCapacity);
	int getCapacity()const;

	void setNumberOfDinosaurs(int newNumberOfDinosaurs);
	int getNumberOfDinosaurs()const;

	void setDinosaursDischarge(discharge newDinosaursDischarge);
	discharge getDinosaursDischarge()const;

	void setDinosaursClimate(climate newDinosaursClimate);
	climate getDinosaursClimate()const;

	void setDinosaursEra(era newDinosaursEra);
	era getDinosaursEra()const;

	bool addDinosaur(const Dinosaur& other); //!< addes a new dinosaur to the cell
	void removeDinosaur(const char* other); //!< removes a dinosaur from the cell

	bool enoughSpace(); //!< verification if there is enough space to add a new dinosaur
	
	Dinosaur* allDinosaurs() const; //!< returns all dinosaurs in cage

	bool isDinosaurHere(const char* other); //!< checks if a certain dinosaur is in the cage
	                                        //!< by given dinosaur name
	bool compareDinosaurEra(const Dinosaur& other); //!< compares dinosaur era with cell's era
	bool checkIndex(int volume, const Dinosaur& other); //!< verification if a dinosaur can be added to the cell

	bool firstDinosaurInCell(const Dinosaur& other); //!< enteres first dinosaur
	bool anotherDinosaurInCell(const Dinosaur& other); //!< enteres dinosaur 

	friend std::ostream& operator<<(std::ostream& out, const Cell& other); //!< output operator
	friend std::istream& operator>>(std::istream& in, Cell& other); //!< input operator
};

