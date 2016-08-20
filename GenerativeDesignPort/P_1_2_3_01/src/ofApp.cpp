#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetWindowTitle("Port of 12301");
    ofBackground(0);
    
    tileCountX = 50;
    tileCountY = 10;
    hue.resize(tileCountX);
    sat.resize(tileCountX);
    bri.resize(tileCountX);
    
    W = ofGetWidth();
    H = ofGetHeight();
    
    for (int i = 0; i < tileCountX; i++) {
        hue[i] = ofRandom(0, 255);
        sat[i] = ofRandom(0, 255);
        bri[i] = ofRandom(0, 255);
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw() {
    int counter = 0;
    
    int mx = mouseX;
    if (mx > W)
        mx = W;
    else if (mx < 0)
        mx = 0;

    int my = mouseY;
    if (my > H)
        my = H;
    else if (my < 0)
        my = 0;

    int currentTileX = (int)ofMap(mx, 0, W, 1, tileCountX);
    int currentTIleY = (int)ofMap(my, 0, H, 1, tileCountY);
    float tileW      = W / (float)currentTileX;
    float tileH      = H / (float)currentTIleY;
    
    for (int gridY = 0; gridY < tileCountY; gridY++) {
        for (int gridX = 0; gridX < tileCountX; gridX++) {
            float posX = tileW * gridX;
            float posY = tileH * gridY;
            int index  = counter % currentTileX;

            ofSetColor(hue[index], sat[index], bri[index]);
            ofDrawRectangle(posX, posY, tileW, tileH);
            counter++;
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == '1') {
        for (int i = 0; i < tileCountX; i++) {
            hue[i] = ofRandom(0, 255);
            sat[i] = ofRandom(0, 255);
            bri[i] = ofRandom(0, 255);
        }
    }
    
    if (key == '2') {
        for (int i = 0; i < tileCountX; i++) {
            hue[i] = ofRandom(0, 255);
            sat[i] = ofRandom(0, 255);
            bri[i] = 255;
        }
    }
    
    if (key == '3') {
        for (int i = 0; i < tileCountX; i++) {
            hue[i] = ofRandom(0, 255);
            sat[i] = 255;
            bri[i] = ofRandom(0, 255);
        }
    }
    
    if (key == '4') {
        for (int i = 0; i < tileCountX; i++) {
            hue[i] = 0;
            sat[i] = 0;
            bri[i] = ofRandom(0, 255);
        }
    }
    
    if (key == '5') {
        for (int i = 0; i < tileCountX; i++) {
            hue[i] = 138;
            sat[i] = 255;
            bri[i] = ofRandom(0, 255);
        }
    }
    
    if (key == '6') {
        for (int i = 0; i < tileCountX; i++) {
            hue[i] = 138;
            sat[i] = ofRandom(0, 255);
            bri[i] = 255;
        }
    }
    
    if (key == '7') {
        for (int i = 0; i < tileCountX; i++) {
            hue[i] = ofRandom(0, 127);
            sat[i] = ofRandom(204, 255);
            bri[i] = ofRandom(127, 229);
        }
    }
    
    if (key == '8') {
        for (int i = 0; i < tileCountX; i++) {
            hue[i] = ofRandom(127, 255);
            sat[i] = ofRandom(204, 255);
            bri[i] = ofRandom(127, 229);
        }
    }
    
    if (key == '9') {
        for (int i = 0; i < tileCountX; i++) {
            if (i % 2 == 0) {
                hue[i] = ofRandom(0, 255);
                sat[i] = 255;
                bri[i] = ofRandom(0, 255);
                
            } else {
                hue[i] = 138;
                sat[i] = ofRandom(0, 255);
                bri[i] = 255;
            }
        }
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
