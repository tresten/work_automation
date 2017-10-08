#include<string>
#include<iostream>
#include<sstream>
#include<vector>
#include<Windows.h>

#include"Mouse.h"
#include"Keyboard.h"
#include"MLS.h"
#include"Taxes.h"

using namespace std;
//asked user for address and returns vector filled with addresses
void getAddresses(vector<string> &address)
{
	string add;
	bool b = true;
	do
	{
		cout << "Enter address" << endl;
		getline(cin, add);
		if (add.empty())
			b = false;
		else
			address.push_back(add);

	} while (b);
}

//parse addresses into address # and address street
void parseAddresses(vector<string> &address, vector <string>& addressnum) {
	for (string &stradd : address)
	{
		int intholder;
		string stringholder;
		stringstream ss;
		ss << stradd;
		ss >> intholder;
		addressnum.push_back(to_string(intholder));
		stradd.clear();
		while (ss >> stringholder)
			stradd += stringholder + " ";
		if (!stradd.empty())
			stradd.erase(stradd.end());
	}
}

string returnNoSpaces(string s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (isspace(s.at(i)))
			s.erase(s.begin() + i);
	}
	return s;
}

string makeNewFolder(vector<string> &address, vector<string> &addressnum) {
	
	const string directoryPath = "c:\\Users\\trest\\Desktop\\" + addressnum.at(0) + returnNoSpaces(address.at(0));
	
	LPCWSTR folderDirectory;
	if (!address.empty())
	{
		string s = directoryPath + addressnum.at(0) + address.at(0);
		wstring stemp = wstring(directoryPath.begin(), directoryPath.end());
		folderDirectory = stemp.c_str();
		CreateDirectory(folderDirectory, NULL);
	}
	return directoryPath;
}

vector<MLS> makeMlsObjects(vector<string>& address, vector<string>& addressnum, const string& directoryPath) {
	ifstream infile;
	vector<MLS> mInfo;
	for (int i = 0; i < address.size(); i++) {
		string fileName = directoryPath + "\\" + addressnum.at(i) + address.at(i) + to_string(i) + ".csv";
		infile.open(fileName);
		if (infile)
		{
			MLS obj(infile);
			mInfo.push_back(obj);
			infile.close();
		}
		else
			cout << "infile for "<< addressnum.at(i) + address.at(i) + to_string(i) + ".csv" <<" didnt open" << endl;
	}
	return mInfo;
}

vector<Taxes> makeTaxObjects(vector<string>& address, vector<string>& addressnum, const string& directoryPath) {
	ifstream infile;
	vector<Taxes> tInfo;
	for (int i = 0; i < address.size(); i++) {
		string fileName = directoryPath + "\\" + addressnum.at(i) + address.at(i) + to_string(i) + ".pdf";
		infile.open(fileName);
		if (infile)
		{
			Taxes obj(infile);
			tInfo.push_back(obj);
		}
		else
			cout << "infile didnt open" << endl;
	}
	return tInfo;
}

int main(){
	//setup
	vector<string> address, addressnum;
	getAddresses(address);
	Sleep(2000);
	parseAddresses(address, addressnum);
	const string directoryPath = makeNewFolder(address, addressnum);
	Mouse m;
	Keyboard kb(directoryPath);
	//start Program
	m.openParagon();
	kb.logIn();
	Sleep(12000);
	m.openSearch();
	Sleep(4000);
	//get and save mls files to proper place
	for (int i = 0; i < address.size(); i++) {
		kb.enterSearch(address.at(i), addressnum.at(i));
		m.exportFile();
		kb.saveFile();
		m.clickSave();
		kb.renameFile(address.at(i), addressnum.at(i), i);
		m.closeSearch();
	}
	Sleep(4000);
	
	//get and save taxes files to proper place
	m.goToTaxes();
	Sleep(500);
	for (int i = 0; i < address.size(); i++) {
		kb.typeString(addressnum.at(i) + " " + address.at(i));
		Sleep(2000);
		m.exportTaxes();
		Sleep(2000);
		kb.saveFile();
		Sleep(2000);
		m.clickSave();
		Sleep(2000);
		kb.renameFile(address.at(i), addressnum.at(i), i);
		m.resetTaxes();
	}

	//make mls objects
	vector<MLS> mInfo = makeMlsObjects(address, addressnum, directoryPath);

	/*
	//make tax objects
	vector<Taxes>tInfo = makeTaxObjects(address, addressnum, directoryPath);
	//compare info
	for (int i = 0; i < mInfo.size(); i++) {
		mInfo.at(i).findDifferences(tInfo.at(i));
	}

	//pause to navigate to output
	system("pause");
	Sleep(5000);
	mInfo.at(0).enterSubject(tInfo.at(0));
	*/

	//pause to navigate to output
	system("pause");
	Sleep(5000);
	//output (needs to add doc number to enterSidebySide)
	kb.multiTab(1);
	for (int i = 1; i < mInfo.size(); i++) {
		//mInfo.at(i).enterSidebySide(tInfo.at(i).getDoc()+"");
		mInfo.at(i).enterSidebySide("");
	}
	return 0;
}