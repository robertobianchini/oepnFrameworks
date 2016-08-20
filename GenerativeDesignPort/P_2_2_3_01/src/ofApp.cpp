#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("Port of 22301");
    ofBackground(255);
    ofSetBackgroundAuto(false);
    ofSetColor(0, 0, 0, 50);
    ofNoFill();

    centerX          = ofGetWidth()  / 2;
    centerY          = ofGetHeight() / 2;
    formResolution   = 15;
    stepSize         = 2;
    distortionFactor = 1;
    initRadius       = 150;
    filled           = false;
    auto angle       = ofDegToRad(360.0F / (float)formResolution);
    for (auto i = 0; i < formResolution; i++) {
        x.push_back(cosf(angle * i) * initRadius);
        y.push_back(sinf(angle * i) * initRadius);
    }

    curve.setFilled(true);
}

//--------------------------------------------------------------
void ofApp::update() {
    auto mx = abs(mouseX);
    auto my = abs(mouseY);
    if (mx != 0 || my != 0) {
        centerX += (mx - centerX) * 0.01F;
        centerY += (my - centerY) * 0.01F;
    }

    for (auto i = 0; i < formResolution; i++){
        x[i] += ofRandom(-stepSize, stepSize);
        y[i] += ofRandom(-stepSize, stepSize);
    }

    if (filled) {
        curve.clear();
        curve.curveTo(x[formResolution - 1] + centerX, y[formResolution - 1] + centerY);
        for (auto i = 0; i < formResolution; i++)
            curve.curveTo(x[i] + centerX, y[i] + centerY);
        curve.curveTo(x[0] + centerX, y[0] + centerY);
        curve.curveTo(x[1] + centerX, y[1] + centerY);
        curve.close();
    } else {
        lines.clear();
        lines.curveTo(x[formResolution - 1] + centerX, y[formResolution - 1] + centerY);
        for (auto i = 0; i < formResolution; i++)
            lines.curveTo(x[i] + centerX, y[i] + centerY);
        lines.curveTo(x[0] + centerX, y[0] + centerY);
        lines.curveTo(x[1] + centerX, y[1] + centerY);
    }

}

//--------------------------------------------------------------
void ofApp::draw() {
    if (filled) {
        auto r = (int)ofRandom(0, 255);
        randomColor.set(r, r, r);
        curve.setFillColor(randomColor);
        curve.draw();
    } else {
        ofSetColor(0, 0, 0, 50);
        lines.draw();
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == '1') filled = false;
    if (key == '2') filled = true;
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
    centerX     = ofGetWidth()  / 2;
    centerY     = ofGetHeight() / 2;
    auto angle  = ofDegToRad(360.0F / (float)formResolution);
    auto radius = initRadius * ofRandom(0.5F, 1.0F);

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
