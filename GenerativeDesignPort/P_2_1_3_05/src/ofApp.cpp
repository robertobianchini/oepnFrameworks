#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("Port of 21305");
    ofBackground(255, 255, 255);
    ofSetColor(0, 0, 0);
    
    W             = ofGetWidth();
    H             = ofGetHeight();
    tileCountX    = 10;
    tileCountY    = 10;
    count         = 0;
    colorStep     = 5;
    endSize       = 0;
    stepSize      = 30;
    actRandomSeed = 0;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw() {
    auto mx = abs(mouseX);
    auto my = abs(mouseY);
    
    ofSeedRandom(actRandomSeed);
    
    stepSize = mx / 10;
    endSize  = my / 10;

    for (int gridY = 0; gridY <= tileCountY; gridY++) {
        for (int gridX = 0; gridX <= tileCountX; gridX++) {
            auto tileWidth  = W / tileCountX;
            auto tileHeight = H / tileCountY;
            auto posX       = tileWidth * gridX;
            auto posY       = tileHeight * gridY;
            auto random     = (int)ofRandom(0.0F, 4.0F);
            
            switch (random) {
                case 0:
                    for(auto i = 0; i < stepSize; i++) {
                        auto diameter = ofMap(i, 0, stepSize, tileWidth, endSize);
                        auto color = 255 - (i * colorStep);
                        ofSetColor(color);
                        ofDrawEllipse(posX + i, posY, diameter, diameter);
                    }
                break;
                    
                case 1:
                    for(auto i = 0; i < stepSize; i++) {
                        auto diameter = ofMap(i, 0, stepSize, tileWidth, endSize);
                        auto color = 255 - (i * colorStep);
                        ofSetColor(color);
                        ofDrawEllipse(posX, posY + i, diameter, diameter);
                    }
                break;

                case 2:
                    for(auto i = 0; i < stepSize; i++) {
                        auto diameter = ofMap(i, 0, stepSize, tileWidth, endSize);
                        auto color = 255 - (i * colorStep);
                        ofSetColor(color);
                        ofDrawEllipse(posX - i, posY, diameter, diameter);
                    }
                break;
                    
                case 3:
                    for(auto i = 0; i < stepSize; i++) {
                        auto diameter = ofMap(i, 0, stepSize, tileWidth, endSize);
                        auto color = 255 - (i * colorStep);
                        ofSetColor(color);
                        ofDrawEllipse(posX, posY - i, diameter, diameter);
                    }
                break;
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
