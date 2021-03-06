// SkyNet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Tells the preproccessor what to include
#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
// Gives me access to the std namespace
using namespace std;


int main()
{
	srand(static_cast<unsigned int>(time(0)));	//Seed the random number generator
	
	//Declare variables
	int randomNumber;
	int enemyLocation;
	int skyNetPrediction;
	int searchGridHighNumber;
	int searchGridLowNumber;
	int numberOfSearches;

	//Set random enemy location
	randomNumber = rand();
	enemyLocation = (randomNumber % 64) + 1;

	//Set other initial variable values
	skyNetPrediction = 0;
	searchGridHighNumber = 64;
	searchGridLowNumber = 1;
	numberOfSearches = 0;

	cout << "Generating random enemy location" << endl;
	cout << "Enemy located at sector " << enemyLocation << endl;
	cout << "Initializing Skynet HK-Aerial search and destroy protocal" << endl;
	cout << "==========================================================================" << endl;
	
	while (skyNetPrediction != enemyLocation)	//Loops while the sky nets prediction does not equal the enemies location
	{
		numberOfSearches++;		//Tracks how many times the loop has run
		cout << "Sending out radar ping #" << numberOfSearches << endl;
		skyNetPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;	//Binary search algorithm

		//Checks the computers prediction against actual enemy location 
		if (skyNetPrediction > enemyLocation)	//Prediction is too high
		{
			searchGridHighNumber = skyNetPrediction - 1;	//Change perameters for next search
			cout << "Prediction of " << skyNetPrediction << " higher than enemy location" << endl;
			cout << "Setting new high end search perameters to " << searchGridHighNumber << endl;
			cout << "==========================================================================" << endl;
		}
		else if (skyNetPrediction < enemyLocation)	//Prediction is too low
		{
			searchGridLowNumber = skyNetPrediction + 1;		//Change perameteers for next search
			cout << "Prediction of " << skyNetPrediction << " lower than enemy location" << endl;
			cout << "Setting new low end search perameters to " << searchGridLowNumber << endl;
			cout << "==========================================================================" << endl;
		}

	}

	cout << "Enemy located in sector " << skyNetPrediction << endl;
	cout << "Enemy eliminated after " << numberOfSearches << " searches of an 8x8 grid";



}
 
// Run program: Ctrl + F5 or Debug > Start Without Debugging  
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
