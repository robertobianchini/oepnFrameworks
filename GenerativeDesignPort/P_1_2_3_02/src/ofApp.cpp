#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("Port of 12302");
    ofSetBackgroundAuto(false);
    
    colorCount = 20;
    hue.resize(colorCount);
    sat.resize(colorCount);
    bri.resize(colorCount);
    rebuildScreen();
}

//--------------------------------------------------------------
void ofApp::rebuildScreen() {
    ofBackground(0);
    ofLog(OF_LOG_NOTICE, "Rebuilding Scene");
    for (int i = 0; i < colorCount; i++) {
        if (i % 2 == 0) {
            hue[i] = (int)ofRandom(0, 255);
            sat[i] = 255;
            bri[i] = (int)ofRandom(0, 255);
        } else {
            hue[i] = 138;
            sat[i] = (int)ofRandom(0, 255);
            bri[i] = 255;
            
        }
    }
    
    int   counter   = 0;
    int   rowCount  = (int)ofRandom(5, 40);
    float rowHeight = (float)ofGetHeight() / (float)rowCount;
    vector<float> parts;
    parts.resize(20);
    for (int i = 0; i < rowCount; i++) {
        int partCount = i + 1;
        
        // Since I'm optimizing to use memory with parts
        //  instead of creating everytime a new chunck of memory,
        //  the correct size of the elements generated from
        //  one pass can't be obtained with vector::size(),
        //  that's why I'm using this variable.
        int partsSize = 1;
        
        for (int ii = 0; ii < partCount; ii++) {
            if (ofRandom(1.0F) < 0.075F) {
                int fragments = (int)ofRandom(2.0F, 20.0F);
                partCount     = partCount + fragments;
                for (int iii = 0; iii < fragments; iii++) {
                    parts.push_back(ofRandom(2.0F));
                    partsSize++;
                }
            } else {
                parts.push_back(ofRandom(2.0F, 20.0F));
            }
        }
        
        int W = ofGetWidth();
        
        float sumPartsTotal = 0;
        for (int ii = 0; ii < partCount; ii++) sumPartsTotal += parts[ii];
        
        float sumPartsNow = 0;
        for (int ii = 0; ii < partsSize; ii++) {
            int index = counter % colorCount;
            ofSetColor(hue[index], sat[index], bri[index]);
            sumPartsNow += parts[ii];
            ofDrawRectangle(ofMap(sumPartsNow, 0, sumPartsTotal, 0, W),
                            rowHeight * i,
                            ofMap(parts[ii], 0, sumPartsTotal, 0, W) * -1,
                            rowHeight);
            counter++;
        }
    }
}


//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw(){

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

    rebuildScreen();
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
