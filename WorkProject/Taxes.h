#ifndef TAXES_H
#define TAXES_H
#include<string>
#include"House.h"
#include<fstream>

using std::string;
using std::fstream;
class Taxes: public House
{
	friend class MLS;
private:
	int docNumber, recentPrice, apn;
	string recentDate, owner, county, legalDescription, taxAmount;
public:
	//can initialize with a file
	Taxes(ifstream&);
	int getDoc() { return docNumber;}
};

#endif