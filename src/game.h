#pragma once

#include "ofMain.h"

class game
{
public:
	game();
	~game();
	void mouseMoved(int x, int y);
	void update();
	void display();
	void start();
	bool keyPressed(int key);
};

