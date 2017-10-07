#pragma once

#include "ofMain.h"
#include "constants.h"
#include "ofxAssimpModelLoader.h"

class game
{
public:
	game();
	~game();
	void mouseMoved(int x, int y);
	void blink();
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
	ofxAssimpModelLoader room;
};

