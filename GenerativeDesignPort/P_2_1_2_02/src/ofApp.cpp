#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetWindowTitle("Port of 21202");
    ofBackground(255);
    
    tileCount        = 20;
    actRandomSeed    = 0;
    W                = ofGetWidth();
    H                = ofGetHeight();
    cx               = W / tileCount / 2;
    cy               = H / tileCount / 2;
    backgroundRadius = 30;
    foregroundRadius = 15;
    
    backgroundColor.set(0, 0, 0);
    foregroundColor.set(255, 255, 255);
    backgroundColor.a = 255;
    foregroundColor.a = 255;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw() {
    float mx = abs(mouseX);
    float my = abs(mouseY);
    
    ofSeedRandom(actRandomSeed);
    
    ofSetLineWidth(my / 60);
    
    ofTranslate(cx, cy);
    for (int gridY = 0; gridY < tileCount; gridY++) {
        for (int gridX = 0; gridX < tileCount; gridX++) {
            int   px     = gridX == 0 ? 0 : (W / tileCount) * gridX;
            int   py     = gridY == 0 ? 0 : (H / tileCount) * gridY;
            float shiftX = ofRandom(-1, 1) * mx / 20;
            float shiftY = ofRandom(-1, 1) * my / 20;
            ofSetColor(backgroundColor);
            ofDrawEllipse(px + shiftX, py + shiftY, backgroundRadius, backgroundRadius);
            ofSetColor(foregroundColor);
            ofDrawEllipse(px, py, foregroundRadius, foregroundRadius);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (key == '0') {
        backgroundColor.set(0, 0, 0);
        foregroundColor.set(255, 255, 255);
        backgroundColor.a = 255;
        foregroundColor.a = 255;
        backgroundRadius  = 20;
        foregroundRadius  = 10;
    }

    if (key == '1') {
        if (backgroundColor.r == 0)
            backgroundColor.setHsb(193, 186, 130);
        else
            backgroundColor.setHsb(0, 0, 0);
    }
    
    if (key == '2') {
        if (foregroundColor.r == 255)
            foregroundColor.setHsb(228, 255, 196);
        else
            foregroundColor.setHsb(255, 255, 255);
    }

    if (key == '3') {
        if (backgroundColor.a == 255)
            backgroundColor.a = foregroundColor.a = 128;
        else
            backgroundColor.a = foregroundColor.a = 255;
    }
    
    if (key == OF_KEY_UP)    backgroundRadius += 2;
    if (key == OF_KEY_DOWN)  backgroundRadius  = MAX(backgroundRadius - 2, 10);
    if (key == OF_KEY_LEFT)  foregroundRadius  = MAX(foregroundRadius - 2, 5);
    if (key == OF_KEY_RIGHT) foregroundRadius += 2;
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
    actRandomSeed = (int)ofRandom(100000);
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
