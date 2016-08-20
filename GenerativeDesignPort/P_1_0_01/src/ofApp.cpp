#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetWindowTitle("Port of 1001");
    ofHideCursor();
    ofSetBackgroundAuto(false);
    ofSetRectMode(OF_RECTMODE_CENTER);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
    ofColor bgColor;
    bgColor.setHsb(ofMap(mouseY * 0.5F, 0, ofGetHeight(), 0, 255), 100, 100);
    ofBackground(bgColor);
    
    float hsb = ofMap(ofGetHeight() - mouseY * 0.5F, 0, ofGetHeight(), 0, 255);
    
    ofColor rectColor;
    rectColor.setHsb(hsb, 100, 100);
    ofSetColor(rectColor);
    ofDrawRectangle(360, 360, mouseX + 1, mouseY + 1);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
