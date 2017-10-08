#ifndef MLS_H
#define MLS_H
#include<string>
#include"House.h"
#include"Taxes.h"
#include"Keyboard.h"
#include<vector>
#include<fstream>
using std::vector;
using std::string;
using std::ifstream;
using std::to_string;
class MLS: public House
{
private:
	vector<int> mlsIntVariables;
	vector<string> mlsStringsVariables;
	bool garageYoN,hoaYoN, pool;
	int listPrice, mlsNumber, hoaFee, dom, garage, concession;
	string listDate, pendingDate, saleTerms, hoaFreq, hoaName, heating, cooling, status,county,buildType;

	const string active = "Back on Market, Contingent, New, Price Change, Active-REO, Active-Short Sale, Back on Market-REO, Back on Market-Short Sale, New-REO, New-Short Sale, Price Change-REO, Price Change-Short Sale";
	const string pending = "Pending, Pending CourtConfirmation, Pending Show for Backups, Pending Subj LenderApprov, Pending Show Backups-REO, Pending Show Backup-Short, Pending-REO";
	const string sold = "Sold, Sold-REO, Sold-Short Sale, Rented-Leased";
	int checkStories(string);
	void enterData(string& data, int enters);
	void enterData(int& data, int enters);
	void initialize(string&, int);
public:
	//can initialize with a file
	//have to pass to house.h with 2 vectors
	MLS(ifstream &);
	void enterSubject(Taxes& t);
	void enterSidebySide(string);
};

#endif
