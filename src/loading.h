#pragma once

#include "ofMain.h"

class loading
{
public:
	loading();
	~loading();
	bool update();
	void display();
	void start();

	ofTrueTypeFont font;
};