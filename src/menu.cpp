#include "menu.h"

int menu::GAME = 0;
int menu::SETTINGS = 1;
int menu::EXIT = 2;

string title[3] = { "GIOCA", "IMPOSTAZIONI", "ESCI" };

int selected = menu::GAME;

menu::menu()
{
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
	for (int i = 0; i < 3; i++) {
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
	selected = 0;
}

int menu::keyPressed(int key)
{
	if (key == OF_KEY_RETURN)
		return selected;
	else if (key == OF_KEY_DOWN)
		selected++;
	else if (key == OF_KEY_UP)
		selected--;

	if (selected > 2)
		selected = 0;
	if (selected < 0)
		selected = 2;

	return -1;
}