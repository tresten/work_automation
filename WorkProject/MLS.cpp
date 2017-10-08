#include "MLS.h"

MLS::MLS(ifstream& infile): House()
{
	string sblank, data;
	getline(infile, sblank);
	for (int j = 0; getline(infile, data, '"'); j++)
	{
		//need to check if it is sold price
		if (!data.empty() && data != ",")
		{
			initialize(data, j);
			cout << "data: " << data << endl;
		}
		else
			j--;
	}
	initializeVectors();
}

void removeCommasandDollar(string& data) {
	size_t pos = 0;
	while ((pos = data.find(',')) != string::npos || (pos = data.find('$')) != string::npos) {
		data.erase(pos, 1);
	}
}

void MLS::initialize(string& data, int count) {
	//first remove all ,'s
	removeCommasandDollar(data);
	stringstream ss(data);
	switch(count) {
		case 0: {
			address= data;
			break;
		}
		case 1: {
			city= data;
			break;
		}
		case 2: {
			state= data;
			break;
		}
		case 3: {
			if (!data.empty())
				ss >> zip;
			else
				zip = 0;
			break;
		}
		case 4: {
			county= data;
			break;
		}
		case 5: {
			story= data;
			break;
		}
		case 6: {
			buildType= data;
			break;
		}
		case 7: {
			if (!data.empty())
				ss >> mlsNumber;
			else
				mlsNumber = 0;
			break;
		}
		case 8: {
			if (!data.empty())
				ss >> dom;
			else
				dom = 0;
			break;
		}
		case 9: {
			status= data;
			break;
		}
		case 10: {
			if (!data.empty())
				ss >> soldPrice;
			else
				soldPrice = 0;
			break;
		}
		case 11: {
			if (!data.empty())
				ss>>listPrice;
			else 
				listPrice = 0;
			break;
		}
		case 12: {
			closeDate= data;
			break;
		}
		case 13: {
			pendingDate= data;
			break;
		}
		case 14: {
			listDate= data;
			break;
		}
		case 15: {
			if (!data.empty())
				ss>>yearBuilt;
			else 
				yearBuilt = 0;
			break;
		}
		case 16: {
			if (!data.empty())
				ss >> age;
			else
				age = 0;
			break;
		}
		case 17: {
			if (!data.empty())
				ss >> lotSqft;
			else
				lotSqft = 0;
			break;
		}
		case 18: {
			if (!data.empty())
				ss >> sqft;
			else
				sqft = 0;
			break;
		}
		case 19: {
			if (!data.empty())
				ss >> rooms;
			else
				rooms = 0;
			break;
		}
		case 20: {
			if (!data.empty())
				ss>>bdrm;
			else 
				bdrm = 0;
			break;
		}
		case 21: {
			if (!data.empty())
				ss >> fullBath;
			else
				fullBath = 0;
			break;
		}
		case 22: {
			if (!data.empty())
				ss >> halfBath;
			else
				halfBath = 0;
			break;
		}
		case 23: {
			garageYoN=(data=="Yes");
			break;
		}
		case 24: {
			if (!data.empty())
				ss >> garage;
			else 
				garage = 0;
			break;
		}
		case 25: {
			hoaYoN=(data=="Yes");
			break;
		}
		case 26: {
			hoaName= data;
			break;
		}
		case 27: {
			if (!data.empty())
				ss >> hoaFee;
			else
				hoaFee = 0;
			break;
		}
		case 28: {
			hoaFreq= data;
			break;
		}
		case 29: {
			pool= (data=="Yes");
			break;
		}
		case 30: {
			saleTerms= data;
			break;
		}
		case 31: {
			if (!data.empty())
				ss >> concession;
			else
				concession = 0;
			break;
		}

	}
}

int MLS::checkStories(string storyString)
{
	Keyboard kb("");
	int stories = 0;
	kb.stringToLower(storyString);
	if (storyString == "one story")
		stories = 1;
	else if (storyString == "two story" || storyString == "split level")
		stories = 2;
	else if (storyString == "other")
	{
		string s;
		cout << "Enter the number of stories" << endl;
		getline(cin, s);
		stringstream(s) >> stories;
	}
	else
		stories = 3;
	return stories;
}

void MLS::enterData(string& data, int enters)
{
	Keyboard kb("");
	kb.typeString(data);
	kb.multiEnter(enters);
}

void MLS::enterData(int& data, int enters)
{
	Keyboard kb("");
	kb.typeString(to_string(data));
	kb.multiEnter(enters);
}

void MLS::enterSubject(Taxes& t) {
	Keyboard kb("");
	kb.multiEnter(5);
	enterData(t.owner, 2);
	enterData(t.legalDescription, 1);
	enterData(t.apn, 2);
	enterData(t.taxAmount, 0);
	kb.multiDelete(1);
	kb.multiEnter(9);
	enterData(hoaFee, 64);
	enterData(lotSqft, 48);
	enterData(story, 8);
	enterData(yearBuilt, 49);
	if (pool) {
		kb.typeChar('x');
		kb.multiEnter(1);
		//press alt 1
		kb.multiEnter(1);
	}
	else
		kb.multiEnter(2);
	kb.multiEnter(33);

}

void MLS::enterSidebySide(string docNumber) {
	int month, day, year;
	char slash;
	Keyboard kb("");

	bool pending = status.find("Pending") != string::npos;
	bool sold = status.find("Sold") != string::npos || status.find("Rented-Leased") != string::npos;
	bool active = !(sold + pending);
	//address
	enterData(address, 1);
	//city
	enterData(city, 1);
	//state
	enterData(state, 1);
	//zip
	enterData(zip, 2);
	//Sale Price or List Price
	if (sold)
		enterData(soldPrice, 1);
	else
		enterData(listPrice, 1);
	//mlsNum
	kb.multiRight(6);
	kb.multiDelete(4);
	enterData(mlsNumber, 1);
	//DOM
	enterData(dom, 4);
	//Financing type
	kb.select();
	enterData(saleTerms, 2);
	//concession
	kb.select();
	enterData(concession, 5);
	//pending date (Partial)
	if (pending || sold)
	{
		stringstream ss;
		ss << pendingDate;
		ss >> month >> slash >> day >> slash >> year;
		ss.str("");
		kb.select();
		kb.typeString(to_string(month) + "/" + to_string(year).substr(2, 2));
		kb.multiEnter(1);
		if (sold)
		{
			//closing date (Partial) 
			stringstream se;
			cout << "Closing date:" << closeDate << endl;
			se << closeDate;
			se >> month >> slash >> day >> slash >> year;
			se.str("");
			kb.select();
			kb.typeString(to_string(month) + "/" + to_string(year).substr(2, 2));
		}
	}
	else
	{
		kb.select();
		kb.multiDelete(1);
		kb.multiEnter(1);
		kb.select();
		kb.multiDelete(1);
	}

	kb.multiEnter(12);
	//lot sqft
	enterData(lotSqft, 11);
	//stories
	int stories = checkStories(story);
	kb.select();
	kb.typeChar(stories + '0');
	kb.multiEnter(5);
	//enterData(mlsvec, i, 5, 5);
	//age
	enterData(age, 6);
	//bdrms
	enterData(bdrm, 1);
	//baths
	enterData(fullBath, 0);
	kb.typeString(".");
	enterData(halfBath, 2);
	//sqft
	enterData(sqft, 30);
	//skiped garage

	//SD, PD, or LD
	if (active)
	{
		stringstream ss;
		ss << listDate;
		ss >> month >> slash >> day >> slash >> year;
		ss.str("");
	}
	kb.select();
	kb.typeString(to_string(month) + '/' + to_string(day) + '/' + to_string(year));
	kb.toggleCaps();
	if (sold)
		kb.typeString(" sd");
	else if (pending)
		kb.typeString(" pd");
	else
		kb.typeString(" ld");
	kb.toggleCaps();
	kb.multiEnter(6);
}