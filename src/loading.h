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

private:
	float frac, t0;
	float duration;
	float l, h, b;
	string text;
	ofTrueTypeFont font;
};