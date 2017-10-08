#include "Keyboard.h"
#include<iostream>
using std::cout;
using std::endl;

Keyboard::Keyboard(string d) {
	directoryPath = d;
}

void Keyboard::typeChar(char c)
{

	INPUT ip = { 0 };
	ip.type = INPUT_KEYBOARD;
	ip.ki.wVk = c;
	//key down
	ip.ki.dwFlags = 0;
	SendInput(1, &ip, sizeof(INPUT));
	//key up
	ip.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &ip, sizeof(INPUT));
}


void Keyboard::toggleCaps()
{
	//try using 
	//typeChar(20);
	INPUT ip;
	ip.type = INPUT_KEYBOARD;
	ip.ki.wVk = 20;
	ip.ki.dwFlags = 0;
	SendInput(1, &ip, sizeof(INPUT));

	ip.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &ip, sizeof(INPUT));
}


void Keyboard::sendTwoKeys(char key1, char key2)
{
	vector <INPUT> ip(2);
	for (int i = 0; i<ip.size(); i++)
	{
		ip.at(i).type = INPUT_KEYBOARD;
		ip.at(i).ki.dwFlags = 0;
	}
	ip.at(0).ki.wVk = key1;
	ip.at(1).ki.wVk = key2;
	for (int i = 0; i<ip.size(); i++)
		SendInput(1, &ip.at(i), sizeof(INPUT));
	for (int i = 0; i<ip.size(); i++)
		ip.at(i).ki.dwFlags = KEYEVENTF_KEYUP;
	for (int i = 0; i<ip.size(); i++)
		SendInput(1, &ip.at(i), sizeof(INPUT));
}


void Keyboard::typeString(string s)
{
	for (int i = 0; i<s.size(); i++)
	{
		s.at(i) = toupper(s.at(i));
		if (s.at(i) == '\\')
			typeChar(VK_OEM_102);
		else if (s.at(i) == '.')
			typeChar(VK_OEM_PERIOD);
		else if (s.at(i) == ':')
			sendTwoKeys(VK_SHIFT, VK_OEM_1);
		else if (s.at(i) == '/')
			typeChar(VK_OEM_2);
		else
			typeChar(s.at(i));
	}
}

void Keyboard::cop()
{
	sendTwoKeys(17, 'C');
}

void Keyboard::paste()
{
	sendTwoKeys(17, 'V');
}

void Keyboard::select()
{
	sendTwoKeys(17, 'A');
}

void Keyboard::enter()
{
	typeChar(13);
}
void Keyboard::tab()
{
	typeChar(9);
}

void Keyboard::multiRight(int iteration)
{
	for (int j = 0; j < iteration; j++)
		typeChar(39);
}

void Keyboard::multiDelete(int iteration)
{
	for (int j = 0; j < iteration; j++)
		typeChar(46);
}

void Keyboard::multiTab(int iteration)
{
	for (int j = 0; j < iteration; j++)
		tab();
}
void Keyboard::multiEnter(int iteration)
{
	for (int j = 0; j < iteration; j++)
	{
		enter();
		Sleep(50);
	}

}

void Keyboard::shiftTab()
{
	sendTwoKeys(VK_SHIFT, 9);
}


void Keyboard::stringToLower(string &s)
{
	for (char &c : s)
		c = tolower(c);
}

void Keyboard::logIn() {
	typeString("206503021");
	tab();
	Sleep(100);
	typeString("comps8me2");
	enter();
}

void Keyboard::enterSearch(string address, string addressnum) {
	int speed = 1000;

	multiTab(13);

	typeString(addressnum);
	multiTab(3);

	typeString(address);
	enter();
	enter();
	Sleep(1000);
}

void Keyboard::saveFile() {
	typeString(directoryPath);
	Sleep(2500);
}

void Keyboard::renameFile(string address, string addressnum, int i) {
	Sleep(1000);
	typeString(addressnum + address + to_string(i));
	Sleep(1000);
	enter();
	Sleep(3000);
}