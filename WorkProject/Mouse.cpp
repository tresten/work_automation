#include "Mouse.h"

void Mouse::leftClick() {
	//INPUT is a structure while Input is a variable name
	INPUT    Input = { 0 };
	// left down
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	SendInput(1, &Input, sizeof(INPUT));

	// left up
	ZeroMemory(&Input, sizeof(INPUT));
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	SendInput(1, &Input, sizeof(INPUT));
}


void Mouse::openParagon() {
	SetCursorPos(614, 709);
	leftClick();
	Sleep(speed);
	Sleep(2000);
	SetCursorPos(894, 90);
	leftClick();
	Sleep(speed);
	//Log in to paragon now
	Sleep(10000);
}
void Mouse::openSearch() {
	SetCursorPos(311, 139);
	leftClick();
	Sleep(speed);
	SetCursorPos(311, 205);
	leftClick();
	Sleep(speed);
	Sleep(3000);
}

void Mouse::exportFile() {
	SetCursorPos(921, 229);
	leftClick();
	Sleep(speed);
	//left click above was to click search

	SetCursorPos(921, 229);
	leftClick();
	Sleep(speed);
	//left click above was to click search
	Sleep(5000);
	speed = 2000;
	//click top mls
	SetCursorPos(459, 345);
	leftClick();
	Sleep(speed);
	//start export below  
	SetCursorPos(352, 238);

	leftClick();
	Sleep(speed);
	SetCursorPos(352, 261);

	leftClick();
	Sleep(speed);
	SetCursorPos(750, 437);

	leftClick();
	Sleep(speed);
	Sleep(1000);
	SetCursorPos(713, 593);

	leftClick();
	Sleep(speed);
	SetCursorPos(733, 252);
	leftClick();
	Sleep(speed);
	Sleep(4000);
}

void Mouse::clickSave() {
	SetCursorPos(468, 447);
	leftClick();
	Sleep(speed);
	SetCursorPos(137, 370);
	leftClick();
}

void Mouse::closeSearch() {
	/*
	SetCursorPos(304, 211);
	leftClick();
	Sleep(50);
	SetCursorPos(298, 211);
	leftClick();
	Sleep(50);
	SetCursorPos(287, 211);
	leftClick();
	Sleep(speed);
	*/
	SetCursorPos(404, 210);
	leftClick();
	Sleep(50);
	SetCursorPos(387, 210);
	leftClick();
	Sleep(speed);
	//reclick top line
	SetCursorPos(147, 287);
	leftClick();
	Sleep(speed);
	Sleep(5000);
}

void Mouse::goToTaxes()
{
	//close search
	SetCursorPos(166, 181);
	leftClick();
	Sleep(1000);
	//navigate to taxes
	SetCursorPos(647, 128);
	leftClick();
	Sleep(1500);
	SetCursorPos(656, 205);
	leftClick();
	Sleep(5000);
	SetCursorPos(616, 321);
	leftClick();
	Sleep(1000);
	//click search bar
	SetCursorPos(617, 512);
	leftClick();
	Sleep(5000);
}

void Mouse::exportTaxes()
{
	//click search
	SetCursorPos(934, 510);
	leftClick();
	Sleep(7000);
	//export pdf
	SetCursorPos(346, 344);
	leftClick();
	Sleep(50);
	SetCursorPos(346, 344);
	leftClick();
	Sleep(5000);
}

void Mouse::resetTaxes()
{
	//click back
	SetCursorPos(249, 302);
	leftClick();
	Sleep(4000);
	//highlight address
	SetCursorPos(760, 513);
	leftClick();
	Sleep(50);
	SetCursorPos(760, 513);
	leftClick();
	Sleep(50);
	SetCursorPos(760, 513);
	leftClick();
	Sleep(1000);
}

