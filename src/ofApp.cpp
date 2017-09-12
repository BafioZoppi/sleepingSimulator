#include "ofApp.h"

int GAME = 0;
int MENU = 1;
int status = MENU;
int statusOld = status;

//--------------------------------------------------------------
void ofApp::setup(){
	FreeConsole();
	ofHideCursor();
	ofSetEscapeQuitsApp(false);
	Menu.start();
}

//--------------------------------------------------------------
void ofApp::update(){
	if (status == GAME)
		Game.update();
	else if (status == MENU)
		Menu.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (status == MENU) {
		Menu.display();
	}
	else if (status == GAME) {
		Game.display();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if (status == MENU) {
		int selection = -1;
		selection = Menu.keyPressed(key);

		if (selection == menu::GAME) {
			Game.start();
			status = GAME;
		}
		else if (selection == menu::EXIT) {
			OF_EXIT_APP(0);
		}
	}
	else if (status == GAME) {
		if (!Game.keyPressed(key)) {
			Menu.start();
			status = MENU;
		}
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	if (status == GAME)
		Game.mouseMoved(x, y);
}