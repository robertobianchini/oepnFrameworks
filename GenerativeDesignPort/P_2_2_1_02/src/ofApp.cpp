#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("Port of 22102");
    ofBackground(255, 255, 255);
    ofSetBackgroundAuto(false);
    
    W        = ofGetWidth();
    H        = ofGetHeight();
    counter  = 0;
    drawMode = 1;
    stepSize = 1;
    diameter = 1;
    posX     = W / 2;
    posY     = H / 2;

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw() {
    auto mx = abs(mouseX);
    for (auto i = 0; i <= mx; i++) {
        counter++;
        
        if (drawMode == 2) {
            direction = (int)ofRandom(0, 3);    // only NORTH, NORTHEAST, EAST possible
        } else {
            direction = (int)ofRandom(0, 7);
        }
        
        switch (direction) {
            // NORTH
            case 0:
                posY -= stepSize;
                break;
                
            // NORTHEAST
            case 1:
                posX += stepSize;
                posY -= stepSize;
            break;
                
            // EAST
            case 2:
                posX += stepSize;
            break;
                
            // SOUTHEAST
            case 3:
                posX += stepSize;
                posY += stepSize;
            break;
                
            // SOUTH
            case 4:
                posY += stepSize;
            break;
                
            // SOUTHWEST
            case 5:
                posX -= stepSize;
                posY += stepSize;
            break;
                
            // WEST
            case 6:
                posX -= stepSize;
            break;
                
            // NORTHEAST
            case 7:
                posX -= stepSize;
                posY -= stepSize;
            break;
        }
        
        if (posX > W) posX = 0;
        if (posX < 0) posX = W;
        if (posY < 0) posY = H;
        if (posY > H) posY = 0;

        if (drawMode == 3) {
            if (counter >= 100) {
                counter = 0;
                ofColor c1;
                c1.set(0, 131, 163);
                c1.a = 200;
                ofSetColor(c1);
                ofDrawEllipse(posX + stepSize / 2, posY + stepSize / 2, diameter + 7, diameter + 7);
            } 
        }

        ofColor c;
        c.set(0, 0, 0);
        c.a = 80;
        ofSetColor(c);
        ofDrawEllipse(posX + stepSize / 2, posY + stepSize / 2, diameter, diameter);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == '1') {
        drawMode = 1;
        stepSize = 1;
        diameter = 1;
        ofBackground(255, 255, 255);
    }
    if (key == '2') {
        drawMode = 2;
        stepSize = 1;
        diameter = 1;
        ofBackground(255, 255, 255);
    }
    if (key == '3') {
        drawMode = 3;
        stepSize = 10;
        diameter = 5;
        ofBackground(255, 255, 255);
    }

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
