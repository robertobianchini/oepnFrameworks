#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("Port of 12201");
    ofBackground(0);
    
    W = ofGetWidth();
    
    int newSize = (W / 5) * (W / 5);
    
    img.load("pic1.jpg");
    colors.resize(newSize);
}

//--------------------------------------------------------------
void ofApp::update() {
    int mx = mouseX;
    if (mx > W)
        mx = W;
    else if (mx < 0)
        mx = 0;
    
    tileCount = W / (int)max(mx , 5);
    rectSize  = W / (float)tileCount;
    
    int i = 0;
    for (int gridY = 0; gridY < tileCount; gridY++) {
        for (int gridX = 0; gridX < tileCount; gridX++) {
            int px    = (int)gridX * rectSize;
            int py    = (int)gridY * rectSize;
            ofColor c = img.getColor(px, py);
            colors[i].set(c);
            i++;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    int i = 0;
    for (int gridY = 0; gridY < tileCount; gridY++) {
        for (int gridX = 0; gridX < tileCount; gridX++) {
            ofSetColor(colors[i]);
            ofDrawRectangle(gridX * rectSize, gridY * rectSize, rectSize, rectSize);
            i++;
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (key == '1') {
        img.load("pic1.jpg");
    } else if (key == '2') {
        img.load("pic2.jpg");
    } else if (key == '3') {
        img.load("pic3.jpg");
    } else if (key == '4') {
        img.load("pic4.jpg");
    } else if (key == '5') {
        img.load("pic5.jpg");
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
