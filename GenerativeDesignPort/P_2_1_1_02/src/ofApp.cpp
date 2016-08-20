#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("Port of 21102");
    ofBackground(255);
    ofSetColor(0, 0, 0);
    
    tileCount     = 20;
    actRandomSeed = 0;
    
    W = ofGetWidth();
    H = ofGetHeight();
    
    colorLeft.r = 197;   colorRight.r = 87;
    colorLeft.g = 0;     colorRight.g = 35;
    colorLeft.b = 123;   colorRight.b = 129;
    
    // No round caps in OF
    
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
            int px     = gridX == 0 ? 0 : (W / tileCount) * gridX;
            int py     = gridY == 0 ? 0 : (H / tileCount) * gridY;
            int toggle = (int)ofRandom(0.0F, 2.0F);
            
            if (toggle == 0) {
                ofSetColor(colorLeft);
                ofSetLineWidth(mx / 20);
                ofDrawLine(px, py, px + W / tileCount, py + H / tileCount);
            }
            
            if (toggle == 1) {
                ofSetColor(colorRight);
                ofSetLineWidth(my / 20);
                ofDrawLine(px, py + W / tileCount, px + H / tileCount, py);
            }
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
    ofSeedRandom(actRandomSeed);
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
