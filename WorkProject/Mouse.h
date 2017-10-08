#ifndef MOUSE_H
#define MOUSE_H
#include <windows.h>

class Mouse
{
private:
	int speed = 500;
	void leftClick();
public:
	Mouse() {};
	void openParagon();
	void openSearch();
	void exportFile();
	void clickSave();
	void closeSearch();
	void goToTaxes();
	void exportTaxes();
	void resetTaxes();
};

#endif