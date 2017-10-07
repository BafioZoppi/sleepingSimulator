#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofEnableDepthTest();
	status = constants::MENU;
	//FreeConsole();
	ofHideCursor();
	ofSetEscapeQuitsApp(false);
	Menu.start();
}

//--------------------------------------------------------------
void ofApp::update(){
	if (status == constants::GAME)
		Game.update();
	else if (status == constants::MENU)
		Menu.update();
	else if (status == constants::LOADING) {
		if (!Loading.update()) {
			status = constants::GAME;
			Game.start();
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (status == constants::MENU)
		Menu.display();
	else if (status == constants::GAME)
		Game.display();
	else if (status == constants::LOADING)
		Loading.display();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if (status == constants::MENU) {
		int selection = -1;
		selection = Menu.keyPressed(key);

		if (selection == constants::GAME) {
			Loading.start();
			status = constants::LOADING;
		}
		else if (selection == constants::EXIT) {
			OF_EXIT_APP(0);
		}
		else if (selection == constants::CONTINUE) {
			Game.unPause();
			status = constants::GAME;
		}
	}
	else if (status == constants::GAME) {
		if (!Game.keyPressed(key)) {
			Menu.start();
			status = constants::MENU;
			Game.pause();
		}
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	if (status == constants::GAME)
		Game.mouseMoved(x, y);
}