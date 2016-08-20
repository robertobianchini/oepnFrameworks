#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetWindowTitle("Port of 21204");
    ofBackground(255);
    
    ofColor c;
    c.setHsb(136, 255, 163);
    c.a = 153;
    ofSetColor(c);
    
    tileCount     = 20;
    rectSize      = 30;
    actRandomSeed = 0;
    W             = ofGetWidth();
    H             = ofGetHeight();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
    float mx = abs(mouseX);
    float my = abs(mouseY);
    
    ofSeedRandom(actRandomSeed);
    
    for (int gridY = 0; gridY < tileCount; gridY++) {
        for (int gridX = 0; gridX < tileCount; gridX++) {
            int   px      = (W / tileCount) * gridX;
            int   py      = (H / tileCount) * gridY;
            float shiftX1 = ofRandom(-1, 1) * mx / tileCount;
            float shiftY1 = ofRandom(-1, 1) * my / tileCount;
            float shiftX2 = ofRandom(-1, 1) * mx / tileCount;
            float shiftY2 = ofRandom(-1, 1) * my / tileCount;
            float shiftX3 = ofRandom(-1, 1) * mx / tileCount;
            float shiftY3 = ofRandom(-1, 1) * my / tileCount;
            float shiftX4 = ofRandom(-1, 1) * mx / tileCount;
            float shiftY4 = ofRandom(-1, 1) * my / tileCount;
            ofBeginShape();
                ofVertex(px + shiftX1, py + shiftY1);
                ofVertex(px + rectSize + shiftX2, py + shiftY2);
                ofVertex(px + rectSize + shiftX3, py + rectSize + shiftY3);
                ofVertex(px + shiftX4, py + rectSize + shiftY4);
            ofEndShape();
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
