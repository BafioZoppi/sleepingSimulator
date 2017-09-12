#pragma once

#include "ofMain.h"

class menu
{
public:
	menu();
	~menu();
	void update();
	void display();
	void start();
	int keyPressed(int key);

	static int GAME, SETTINGS, EXIT;

	ofTrueTypeFont bigFont, smallFont;
};