#pragma once

#include "ofMain.h"
#include "game.h"
#include "menu.h"
#include "loading.h"
#include "constants.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void mouseMoved(int x, int y );

	private:
		game Game;
		menu Menu;
		loading Loading;
		int status;
};
