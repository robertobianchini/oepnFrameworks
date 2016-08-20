#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("Port of 1001");
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofBackground(0, 0, 0);
    W = ofGetWidth();
    H = ofGetHeight();
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw() {
    stepX = abs(mouseX) + 2;
    stepY = abs(mouseY) + 2;

    for (int gridY = 0; gridY < H; gridY += stepY) {
        for (int gridX = 0; gridX < W; gridX += stepX) {
            float hue = ofMap(gridX, 0, W, 0, 255);
            float sat = ofMap(H - gridY, 0, H, 0, 255);
            ofColor c;
            c.setHsb(hue, sat, 255);
            ofSetColor(c);
            ofDrawRectangle(gridX, gridY, stepX, stepY);
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
