#include "stdafx.h"
#include<iostream>
#include"Dinosaur.h" //!< includes all the headers from now on
#include"Cell.h"
#include"Zoopark.h"
#include"Staff.h"

int main()
{
	Zoopark zoopark; //!< creates object of class Zoopark
	zoopark.enterTheZoo(); //!< creates the user interface and there is every command that can be
	                       //!< entered by the user
	system("pause");
    return 0;
}

