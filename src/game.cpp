#include "game.h"

game::game()
{
	alpha = 0;
	beta = 0;
	blinkDuration = 10;
	fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA, 4);
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
	t = ofGetElapsedTimef() - t0;
	blinkPerc = t / blinkDuration;
}

void game::display()
{
	if (t > blinkDuration)
		ofBackground(0);
	else {
		fbo.begin();
		ofClear(255, 255, 255);
		camera.begin();
		ofBackground(255);
		camera.lookAt(look, up);
		ofSetColor(0, 255, 0);
		ofBox(0, 10, -100, 50);
		camera.end();
		blink();
		fbo.end();
		fbo.draw(0, 0);
	}
}

void game::blink()
{
	ofSetColor(0);
	ofRectangle b(0, 0, ofGetWidth(), (ofGetHeight() / 2) * blinkPerc);
	ofRect(b);
	ofPushMatrix();
	ofTranslate(0, ofGetHeight() - b.height);
	ofRect(b);
	ofPopMatrix();
	ofSetColor(255);
}

void game::start()
{
	t0 = ofGetElapsedTimef();
	constants::isRunning = true;
}

void game::pause()
{
	dt = ofGetElapsedTimef() - t0;
}

void game::unPause()
{
	t0 = ofGetElapsedTimef() - dt;
}

bool game::keyPressed(int key)
{
	if (key == OF_KEY_ESC)
		return false;
	else
		return true;
}