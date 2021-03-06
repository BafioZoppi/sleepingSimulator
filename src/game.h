#pragma once

#include "ofMain.h"
#include "constants.h"

class game
{
public:
	game();
	~game();
	void mouseMoved(int x, int y);
	void update();
	void display();
	void start();
	void pause();
	void unPause();
	bool keyPressed(int key);

private:
	float t, t0, dt;
	int X, Y;
	float alpha, beta;
	float blinkDuration, blinkPerc;
	ofCamera camera;
	ofVec3f up, look;
	ofFbo fbo;
	void drawRoom();
	void blink();
	ofMesh room;
};

