#include "menu.h"

menu::menu()
{
	selected = constants::GAME;
	selections = 4;
	titleFileName = "Title";
	ext = ".png";
	menuFileName[0] = "Continue";
	menuFileName[1] = "New Game";
	menuFileName[2] = "Options";
	menuFileName[3] = "Exit";
	imageFolder = "Menu/";

	scale = float(ofGetHeight()) / constants::height;
	newWidth = scale * constants::width;

	titleImage.load(imageFolder + titleFileName + ext);
	titleImage.resize(newWidth, scale * titleImage.getHeight());

	offset = (ofGetWidth() - titleImage.getWidth()) / 2;

	for (int i = 0; i < selections; i++) {
		selection[i] = new ofImage(imageFolder + menuFileName[i] + "-s" + ext);
		selection[i]->resize(newWidth, scale * selection[i]->getHeight());

		normal[i] = new ofImage(imageFolder + menuFileName[i] + ext);
		normal[i]->resize(newWidth, scale * normal[i]->getHeight());
	}

	notSelectable = new ofImage(imageFolder + menuFileName[0] + "-n" + ext);
	notSelectable->resize(newWidth, scale * notSelectable->getHeight());

	cout << ofGetHeight();
}

menu::~menu()
{
}

void menu::update()
{
	if (!constants::isRunning)
		menuImage[0] = notSelectable;
	else if (selected == constants::CONTINUE)
		menuImage[0] = selection[0];
	else
		menuImage[0] = normal[0];

	for (int i = 1; i < selections; i++) {
		if (selected == i)
			menuImage[i] = selection[i];
		else
			menuImage[i] = normal[i];
	}
}

void menu::display()
{
	ofBackground(0);
	titleImage.draw(offset, 0);
	float yOffset = titleImage.getHeight();
	for (int i = 0; i < selections; i++) {
		menuImage[i]->draw(offset, yOffset);
		yOffset += menuImage[i]->getHeight();
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