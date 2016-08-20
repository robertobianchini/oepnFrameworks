#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("Port of 12101");
    ofBackground(0);
    
    W          = ofGetWidth();
    H          = ofGetHeight();
    tileCountX = 2;
    tileCountY = 10;
    leftColor.resize(tileCountY);
    rightColor.resize(tileCountY);
    shakeColors();
}

//--------------------------------------------------------------
void ofApp::shakeColors() {
    for (int i = 0; i < tileCountY; i++) {
        leftColor[i].setHsb((int)ofRandom(0, 60), (int)ofRandom(0, 255), 255);
        rightColor[i].setHsb((int)ofRandom(160, 190), 255, ofRandom(0, 255));
    }
}



//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
    int mx      = abs(mouseX);
    int my      = abs(mouseY);
    tileCountX  = (int)ofMap(mx, 0, W, 2, 20);
    tileCountY  = (int)ofMap(my, 0, H, 2, 10);
    float tileW = W / (float)tileCountX;
    float tileH = H / (float)tileCountY;
    
    for (int gridY = 0; gridY < tileCountY; gridY++) {
        ofColor c1 = leftColor[gridY];
        ofColor c2 = rightColor[gridY];
        
        for (int gridX = 0; gridX < tileCountX; gridX++) {
            float ammount = ofMap(gridX, 0, tileCountX - 1, 0.0F, 1.0F);
            ofColor c = c2.getLerped(c1, ammount);
            ofSetColor(c);
            float px = tileW * gridX;
            float py = tileH * gridY;
            ofDrawRectangle(px, py, tileW, tileH);
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
    shakeColors();
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
