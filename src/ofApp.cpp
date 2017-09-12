#include "ofApp.h"

int GAME = 0;
int MENU = 1;
int status = MENU;
int selected = 0;
string menu[3] = { "GIOCA", "IMPOSTAZIONI", "ESCI" };
int statusOld = status;

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	FreeConsole();
	ofHideCursor();
	bigFont.load("Helvetica-Regular.ttf", 20);
	smallFont.load("Helvetica-Regular.ttf", 16);
	ofSetEscapeQuitsApp(false);
}

//--------------------------------------------------------------
void ofApp::update(){
	if (status == GAME) {
		if (statusOld != GAME) {
			Game.start();
		}
		Game.update();
	}

	statusOld = status;
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	ofSetColor(255);

	if (status == MENU) {
		bigFont.drawString("SLEEPING SIMULATOR", 100, 100);
		for (int i = 0; i < 3; i++) {
			if (selected == i) {
				ofSetColor(0, 255, 0);
				smallFont.drawString(menu[i], 100, 200 + i * 100);
				ofSetColor(255);
			}
			else
				smallFont.drawString(menu[i], 100, 200 + i * 100);
		}
	}
	else if (status == GAME) {
		Game.display();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == OF_KEY_RETURN) {
		if (status == MENU) {
			if (selected == 0)
				status = GAME;
			else if (selected == 2)
				OF_EXIT_APP(0);
		}
	}
	else if (key == OF_KEY_ESC)
		status = MENU;
	else if (key == OF_KEY_DOWN)
		selected++;
	else if (key == OF_KEY_UP)
		selected--;

	if (selected > 2)
		selected = 0;
	if (selected < 0)
		selected = 2;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	//glfwSetCursorPos(ofGetWidth() / 2, ofGetHeight() / 2);
	//Game.mouseMoved(x - ofGetWidth(), y - ofGetHeight());
	Game.mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
