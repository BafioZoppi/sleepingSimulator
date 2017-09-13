#include "game.h"

int t = 0;
int X, Y;
float alpha = 0, beta = 0;
ofCamera camera;
ofVec3f up, look;

game::game()
{
	up = ofVec3f(0, 1, 0);
	look = ofVec3f(0, 0, -1);
}


game::~game()
{
}

void game::mouseMoved(int x, int y)
{
	X = x;
	Y = y;
}

void game::update()
{
	alpha = ofMap(X, 0, ofGetWidth(), -HALF_PI, HALF_PI, true);
	beta = ofMap(Y, 0, ofGetHeight(), -HALF_PI, HALF_PI, true);
	look = ofVec3f(sin(alpha), sin(-beta), -1);
	look.normalize();
}

void game::display()
{
	camera.begin();
	camera.lookAt(look, up);
	ofBox(0, 10, -100, 50);
	camera.end();
}

void game::start()
{
	t = ofGetElapsedTimef();
}

bool game::keyPressed(int key)
{
	if (key == OF_KEY_ESC)
		return false;
	else
		return true;
}