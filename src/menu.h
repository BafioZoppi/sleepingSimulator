#pragma once

#include "ofMain.h"
#include "constants.h"

class menu
{
public:
	menu();
	~menu();
	void update();
	void display();
	void start();
	int keyPressed(int key);

private:
	ofTrueTypeFont bigFont, smallFont;
	string title[4];
	int selected, selections;
};