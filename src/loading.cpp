#include "loading.h"

loading::loading()
{
	duration = 5;
	l = 1000;
	h = 50;
	b = 5;
	font.load("Helvetica-Regular.ttf", 20);
	text = "LOADING";
}

loading::~loading()
{
}

void loading::start()
{
	t0 = ofGetElapsedTimef();
}

bool loading::update()
{
	float t = ofGetElapsedTimef() - t0;
	frac = t / duration;

	if (frac < 1)
		return true;
	else
		return false;
}

void loading::display()
{
	ofBackground(0);
	ofSetColor(255);

	font.drawString(text, 200, 300);

	ofNoFill();
	ofDrawRectangle(200, 400, l, h);

	ofFill();
	ofDrawRectangle(200 + b, 400 + b, (l - 2*b) * frac, h - 2*b);
}