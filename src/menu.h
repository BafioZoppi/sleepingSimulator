#pragma once

#include "ofMain.h"
#include "constants.h"
#include <iostream>

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
	float newWidth, offset, scale;
	string titleFileName, ext, imageFolder;
	string menuFileName[4];
	int selected, selections;
	ofImage titleImage, *menuImage[4];
	ofImage *selection[4], *normal[4], *notSelectable;
};