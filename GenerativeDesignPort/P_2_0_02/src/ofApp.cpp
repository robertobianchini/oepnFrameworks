#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetWindowTitle("Port of 2002");
    ofBackground(255);
    ofSetBackgroundAuto(false);
    ofSetColor(10, 10, 10, 25);
    ofSetLineWidth(2);

    W = ofGetWidth();
    H = ofGetHeight();

    lines.resize(200);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
    ofEnableAlphaBlending();
    ofTranslate(W * 0.5F, H * 0.5F);
    for (auto line : lines) line.draw();
    ofDisableAlphaBlending();
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
    float mx               = mouseX < 0 ? 0 : mouseX > W ? W : mouseX;
    float my               = mouseY < 0 ? 0 : mouseY > H ? H : mouseY;
    int   circleResolution = (int)ofMap(my + 100, 0, H, 2, 10);
    float radius           = mx - W * 0.5F + 0.5F;
    float angle            = TWO_PI / circleResolution;

    ofPolyline L;
    for (int i = 0; i <= circleResolution; i++) {
        float x = cosf(angle * i) * radius;
        float y = sinf(angle * i) * radius;
        L.addVertex(x, y);
    }
    lines.push_back(L);

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    float mx               = mouseX < 0 ? 0 : mouseX > W ? W : mouseX;
    float my               = mouseY < 0 ? 0 : mouseY > H ? H : mouseY;
    int   circleResolution = (int)ofMap(my + 100, 0, H, 2, 10);
    float radius           = mx - W * 0.5F + 0.5F;
    float angle            = TWO_PI / circleResolution;

    ofPolyline L;
    for (int i = 0; i <= circleResolution; i++) {
        float x = cosf(angle * i) * radius;
        float y = sinf(angle * i) * radius;
        L.addVertex(x, y);
    }
    lines.push_back(L);
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
