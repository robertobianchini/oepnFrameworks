#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("Port of 21301");
    ofBackground(255);
    ofNoFill();
    ofSetColor(128, 128, 128);
    
    W             = ofGetWidth();
    H             = ofGetHeight();
    tileCountX    = tileCountY = 10;
    tileWidth     = W / tileCountX;
    tileHeight    = H / tileCountY;
    actRandomSeed = 0;

}

//--------------------------------------------------------------
void ofApp::update() {

    
}

//--------------------------------------------------------------
void ofApp::draw() {
    auto mx = abs(mouseX);
    auto my = abs(mouseY);
    
    ofSeedRandom(actRandomSeed);

    ofTranslate((W / tileCountX) / 2, (H / tileCountY) / 2);
    
    circleCount = mx / 30 + 1;
    endSize     = ofMap(mx, 0, W, tileWidth / 2.0F, 0);
    endOffset   = ofMap(my, 0, H, 0, (tileWidth - endSize) / 2);
    
    for (auto gridY = 0; gridY <= tileCountY; gridY++) {
        for (auto gridX = 0; gridX <= tileCountX; gridX++) {
            ofPushMatrix();
                ofTranslate(tileWidth * gridX, tileHeight * gridY);
                ofScale(1, tileHeight / tileWidth, 1);
                int toggle = (int)ofRandom(0.0F, 4.0F);
                if (toggle == 0) ofRotate(-PI / 2);
                if (toggle == 1) ofRotate(0); // Inutil
                if (toggle == 2) ofRotate(PI / 2);
                if (toggle == 3) ofRotate(PI);
            
                for (auto i = 0; i < circleCount; i++) {
                    auto diameter = ofMap(i, 0, circleCount - 1, tileWidth, endSize);
                    auto offset   = ofMap(i, 0, circleCount - 1, 0, endOffset);
                    ofDrawEllipse(offset, 0, diameter, diameter);
                }
            
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
