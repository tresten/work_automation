#ifndef HOUSE_H
#define HOUSE_H
#include<string>
#include<vector>
#include<fstream>
#include <iostream>
#include<sstream>


using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::stringstream;
using std::getline;
using std::ifstream;
using namespace std;

class House
{
protected:
	const vector<string> intVariablesNames = {"Sold Price", "Sqft", "Lot Sqft", "Year Built","Rooms", "Bedrooms", "Full Bath", "Half Bath", "Age", "Zip" };
	vector<int> intVariables;
	const vector<string> stringVariablesNames = { "Address", "Closing Date", "City", "Story", "Unit" };
	vector<string> stringVariables;

	int soldPrice, sqft, lotSqft, yearBuilt;
	int rooms, bdrm, fullBath, halfBath, age, zip;
	string address, closeDate, city, story, unit, state;

	void fixDifference(string var, string &mls, string &taxes);
	void fixDifference(string var, int &mls, int &taxes);

public:
	
	House();
	void initializeVectors();
	bool operator==(House right);
	void findDifferences(House& h);
};

#endif


/*
TODO:
finish findDifferences();

*/