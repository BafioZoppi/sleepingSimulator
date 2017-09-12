#pragma once

#include "ofMain.h"
#include "game.h"
#include "menu.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void mouseMoved(int x, int y );

		game Game;
		menu Menu;
};
