#include "ofApp.h"

constexpr int MAX_COUNT = 5000;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("Port of 22402");
    ofBackground(255);
    ofSetColor(50, 50, 50);
    ofSetCircleResolution(40);
    
    W = ofGetWidth();
    H = ofGetHeight();
    
    points.resize(MAX_COUNT);
    newPoints.resize(MAX_COUNT);
    r.resize(MAX_COUNT);
    reset();

}

//--------------------------------------------------------------
void ofApp::reset() {
    currentCount = 1;
    points.clear();
    newPoints.clear();
    r.clear();
    points[0] = ofVec2f(W / 2, H / 2);
    r[0]      = 360;
}


//--------------------------------------------------------------
void ofApp::update(){
    auto newR = ofRandom(1, 7);
    auto newX = ofRandom(newR, W - newR);
    auto newY = ofRandom(newR, H - newR);
    auto p    = ofVec2f(newX, newY);
    
    auto closestDistance = 1000000;
    auto closestIndex    = 0;
    for (auto i = 0; i < currentCount; i++) {
        auto newDist = p.distance(points[i]);
        if (newDist < closestDistance) {
            closestDistance = newDist;
            closestIndex    = i;
        }
    }

    auto angle = atan2(newY - points[closestIndex].y, newX - points[closestIndex].x);
    auto newP  = ofVec2f(points[closestIndex].x + cosf(angle) * (r[closestIndex] + newR),
                         points[closestIndex].y + sinf(angle) * (r[closestIndex] + newR));

    newPoints[currentCount] = p;
    points[currentCount]    = newP;
    r[currentCount]         = newR;

    currentCount++;
    
    if (currentCount >= MAX_COUNT) reset();
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (drawGhosts) {
        ofFill();
        ofSetColor(230, 230, 230);
        for (auto i = 1; i < currentCount; i++) {
            ofDrawEllipse(newPoints[i].x, newPoints[i].y, r[i] * 2, r[i] * 2);
            ofDrawLine(newPoints[i].x, newPoints[i].y, points[i].x, points[i].y);
        }
    }
    
    for (auto i = 0; i < currentCount; i++) {
        if (i == 0)
            ofNoFill();
        else {
            ofFill();
            ofSetColor(50, 50, 50);
        }
        
        ofDrawEllipse(points[i].x, points[i].y, r[i] * 2, r[i] * 2);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == '1') drawGhosts = !drawGhosts;
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
