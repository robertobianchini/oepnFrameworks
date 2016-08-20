#include "ofApp.h"

constexpr int MAX_COUNT = 5000;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("Port of 22401");
    ofBackground(255);
    ofSetColor(50, 50, 50);

    W = ofGetWidth();
    H = ofGetHeight();
    
    points.resize(MAX_COUNT);
    r.resize(MAX_COUNT);
    reset();
}

//--------------------------------------------------------------
void ofApp::reset() {
    currentCount = 1;
    points.clear();
    r.clear();
    points.push_back(ofVec2f(W / 2, H / 2));
    r.push_back(10);
}


//--------------------------------------------------------------
void ofApp::update(){
    auto newR = ofRandom(1, 7);
    auto newX = ofRandom(newR, W - newR);
    auto newY = ofRandom(newR, H - newR);
    
    auto closestDistance = 1000000;
    auto closestIndex    = 0;
    for (auto i = 0; i < currentCount; i++) {
        auto p       = ofVec2f(newX, newY);
        auto newDist = p.distance(points[i]);
        if (newDist < closestDistance) {
            closestDistance = newDist;
            closestIndex    = i;
        }
    }
    
    auto angle = atan2(newY - points[closestIndex].y, newX - points[closestIndex].x);
    auto newP  = ofVec2f(points[closestIndex].x + cosf(angle) * (r[closestIndex] + newR),
                         points[closestIndex].y + sinf(angle) * (r[closestIndex] + newR));
                         
    points.push_back(newP);
    r.push_back(newR);
    currentCount++;
    
    if (currentCount >= MAX_COUNT) reset();
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (auto i = 0; i < currentCount; i++) ofDrawEllipse(points[i].x, points[i].y, r[i] * 2, r[i] * 2);
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
