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
    colorIndex.resize(200);

    ofColor c1; c1.setHsb(0, 255, 255);
    colors.push_back(c1);

    ofColor c2; c2.setHsb(136, 255, 255);
    colors.push_back(c2);

    ofColor c3; c3.setHsb(37, 255, 255);
    colors.push_back(c3);

    index = 0;
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
    ofEnableAlphaBlending();
    ofTranslate(W * 0.5F, H * 0.5F);
    for (int i = 0; i < lines.size(); i++) {
        ofSetColor(colors[colorIndex[i]]);
        lines[i].draw();
    }
    ofDisableAlphaBlending();
}

//--------------------------------------------------------------
void ofApp::addLine() {
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
    colorIndex.push_back(index);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == '1') index = 0;
    if (key == '2') index = 1;
    if (key == '3') index = 2;
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    addLine();
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    addLine();
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
