#include "House.h"



House::House()
{
}

void House::initializeVectors() {
	stringVariables = { address,closeDate,city,story,unit };
	intVariables = { soldPrice,sqft,lotSqft,yearBuilt,rooms,bdrm,fullBath,halfBath,age,zip };
}

bool House::operator==(House right) {
	bool b = true;
	for (int i = 0; i < intVariables.size() && b; i++)
	{
		if (intVariables.at(i) != right.intVariables.at(i))
			b = false;
	}
	for (int i = 0; i < stringVariables.size() && b; i++)
	{
		if (stringVariables.at(i) != right.stringVariables.at(i))
			b = false;
	}
	return b;
}

void House::findDifferences(House& h) {

	for (int i = 0; i < intVariables.size(); i++)
	{
		if (intVariables.at(i) != h.intVariables.at(i))
			fixDifference(intVariablesNames.at(i), intVariables.at(i), h.intVariables.at(i));

	}
	for (int i = 0; i < stringVariables.size(); i++)
	{
		if (stringVariables.at(i) != h.stringVariables.at(i))
			fixDifference(stringVariablesNames.at(i), stringVariables.at(i), h.stringVariables.at(i));
	}
}

void House::fixDifference(string var, string &mls, string &taxes) {
	int choice = 0;
	while (choice != 1 || choice != 2) {

		cout << "There is a difference in the " << var << "the mls has value: " << mls << " and the taxes have value: " << taxes << endl;
		cout << "Enter 1 to go with the mls and 2 for taxes";
		getline(cin, var);
		stringstream(var) >> choice;
	}
	if (choice == 1)
		taxes = mls;
	else
		mls = taxes;
}

void House::fixDifference(string var, int &mls, int &taxes) {
	int choice = 0;
	while (choice != 1 || choice != 2) {

		cout << "There is a difference in the " << var << "the mls has value: " << mls << " and the taxes have value: " << taxes << endl;
		cout << "Enter 1 to go with the mls and 2 for taxes";
		getline(cin, var);
		stringstream(var) >> choice;
	}
	if (choice == 1)
		taxes = mls;
	else
		mls = taxes;
}