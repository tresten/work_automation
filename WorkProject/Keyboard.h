#ifndef KEYBOARD_H
#define KEYBOARD_H

#define WINVER 0x0500
#include <windows.h>
#include<string>
#include<vector>

using namespace std;

class Keyboard
{
private:
	string directoryPath;
	void sendTwoKeys(char key1, char key2);
	void cop();
	void paste();
	void enter();
	void tab();
	void shiftTab();


public:
	//need new definition for logIn and enterData
	Keyboard(string);
	void multiTab(int iteration);
	void multiDelete(int iteration);
	void multiEnter(int iteration);
	void multiRight(int iteration);
	void toggleCaps();
	void select();
	void typeChar(char c);
	void stringToLower(string &s);
	void logIn();
	void typeString(string );
	void enterSearch(string, string );
	void saveFile();
	void renameFile(string,string,int);

};

#endif KEYBOARD_H