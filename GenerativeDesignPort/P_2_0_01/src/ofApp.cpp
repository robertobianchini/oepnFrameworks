#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetWindowTitle("Port of 2001");
    ofBackground(255);
    ofSetColor(0, 0, 0);

    W = ofGetWidth();
    H = ofGetHeight();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
    float mx               = mouseX < 0 ? 0 : mouseX > W ? W : mouseX;
    float my               = mouseY < 0 ? 0 : mouseY > H ? H : mouseY;
    int   circleResolution = (int)ofMap(my, 0, H, 2, 80);
    float radius           = mx - W * 0.5F + 0.5F;
    float angle            = TWO_PI / circleResolution;

    ofTranslate(W * 0.5F, H * 0.5F);
    ofSetLineWidth(my / 20);

    for (int i = 0; i <= circleResolution; i++) {
        float x = cosf(angle * i) * radius;
        float y = sinf(angle * i) * radius;
        ofDrawLine(0, 0, x, y);
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
