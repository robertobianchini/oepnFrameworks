#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetWindowTitle("Port of 21201");
    ofBackground(255);
    
    tileCount     = 20;
    actRandomSeed = 0;
    c.set(0, 0, 0);
    c.a = 180;
    W   = ofGetWidth();
    H   = ofGetHeight();
    cx  = W / tileCount / 2;
    cy  = H / tileCount / 2;
    
    ofSetColor(c);
    ofNoFill();
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
            int px       = gridX == 0 ? 0 : (W / tileCount) * gridX;
            int py       = gridY == 0 ? 0 : (H / tileCount) * gridY;
            float shiftX = ofRandom(-mx, mx) / 20;
            float shiftY = ofRandom(-mx, mx) / 20;
            ofDrawEllipse(px + shiftX, py + shiftY, my / 15, my / 15);
        }
    }
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
