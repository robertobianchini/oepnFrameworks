#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("Port of 21203");
    ofBackground(255);
    ofSetLineWidth(3);
    ofNoFill();
    
    tileCount     = 20;
    actRandomSeed = 0;
    drawRect      = true;
    maxDistance   = 500;
    W             = ofGetWidth();
    H             = ofGetHeight();

    ofColor c;
    c.set(0, 0, 0);
    c.a = 180;
    ofSetColor(c);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
    float mx = abs(mouseX);
    float my = abs(mouseY);
    
    ofSeedRandom(actRandomSeed);
    
    for (int gridY = 0; gridY < H; gridY += 25) {
        for (int gridX = 0; gridX < W; gridX += 25) {
            float diameter = ofDist(mx, my, gridX, gridY);
            diameter       = (diameter / maxDistance) * 40;
            ofPushMatrix();
                ofTranslate(gridX, gridY, diameter * 5);
                if (drawRect)
                    ofDrawRectangle(0, 0, diameter, diameter);
                else
                    ofDrawEllipse(0, 0, diameter, diameter);
            ofPopMatrix();
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
    drawRect      = !drawRect;
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
