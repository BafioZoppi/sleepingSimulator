#include "menu.h"

menu::menu()
{
	selected = constants::GAME;
	selections = 4;
	title[0] = "CONTINUE";
	title[1] = "NEW GAME";
	title[2] = "SETTINGS";
	title[3] = "EXIT";
	bigFont.load("Helvetica-Regular.ttf", 20);
	smallFont.load("Helvetica-Regular.ttf", 16);
}

menu::~menu()
{
}

void menu::update()
{
}

void menu::display()
{
	ofBackground(0);
	ofSetColor(255);

	bigFont.drawString("SLEEPING SIMULATOR", 100, 100);

	if (constants::isRunning) {
		if (selected == constants::CONTINUE) {
			ofSetColor(0, 255, 0);
			smallFont.drawString(title[0], 100, 200);
			ofSetColor(255);
		}
		else
			smallFont.drawString(title[0], 100, 200);
	}
	else {
		ofSetColor(128);
		smallFont.drawString(title[0], 100, 200);
		ofSetColor(255);
	}

	for (int i = 1; i < selections; i++) {
		if (selected == i) {
			ofSetColor(0, 255, 0);
			smallFont.drawString(title[i], 100, 200 + i * 100);
			ofSetColor(255);
		}
		else
			smallFont.drawString(title[i], 100, 200 + i * 100);
	}
}

void menu::start()
{
	if (constants::isRunning)
		selected = constants::CONTINUE;
	else
		selected = constants::GAME;
}

int menu::keyPressed(int key)
{
	if (key == OF_KEY_RETURN)
		return selected;
	else if (key == OF_KEY_DOWN)
		selected++;
	else if (key == OF_KEY_UP)
		selected--;

	if (constants::isRunning) {
		if (selected > selections - 1)
			selected = 0;
		if (selected < 0)
			selected = selections - 1;
	}
	else {
		if (selected > selections - 1)
			selected = 1;
		if (selected < 1)
			selected = selections - 1;
	}

	return -1;
}