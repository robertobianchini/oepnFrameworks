#include "ofApp.h"

constexpr int MAX_COUNT = 5000;

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetWindowTitle("P_2_2_5_01");
    ofBackground(255, 255, 255);
    ofSetColor(0);
    ofNoFill();
    ofSetCircleResolution(40);
    
    W = ofGetWidth();
    H = ofGetHeight();
    
    minRadius    = 3;
    maxRadius    = 50;
    mouseRect    = 30;
    
    points.resize(MAX_COUNT);
    r.resize(MAX_COUNT);
    closestIndex.resize(MAX_COUNT);
    
    reset();
}

//--------------------------------------------------------------
void ofApp::reset() {
    points.clear();
    r.clear();
    closestIndex.clear();
    
    points[0]       = ofVec2f(200, 100);
    r[0]            = 50;
    closestIndex[0] = 0;
    currentCount    = 1;
    mouseRect       = 30;
}


//--------------------------------------------------------------
void ofApp::update() {
    auto newP = ofVec2f(ofRandom(maxRadius, W - maxRadius), ofRandom(maxRadius, H - maxRadius));
    auto newR = minRadius;
    
    if (mousePre) {
        newP.x = ofRandom(mouseX - mouseRect / 2, mouseX + mouseRect / 2);
        newP.y = ofRandom(mouseY - mouseRect / 2, mouseY + mouseRect / 2);
        newR   = 1;
    }
    
    auto intersection = false;
    for (auto i = 0; i < currentCount; i++) {
        auto d = newP.distance(points[i]);
        if (d < (newR + r[i])) {
            intersection = true;
            break;
        }
    }
    
    if (!intersection) {
        auto newRadius = W;
        for (auto i = 0; i < currentCount; i++) {
            auto d = newP.distance(points[i]);
            if (newRadius > d - r[i]) {
                newRadius = d - r[i];
                closestIndex[currentCount] = i;
            }
        }
        
        if (newRadius > maxRadius) newRadius = maxRadius;
        
        points[currentCount].x = newP.x;
        points[currentCount].y = newP.y;
        r[currentCount]        = newRadius;
        currentCount++;
        if (currentCount > MAX_COUNT) reset();
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    for (auto i = 0; i < currentCount; i++) {
        ofSetColor(0);
        ofSetLineWidth(1.5F);
        ofDrawCircle(points[i].x, points[i].y, r[i]);
        
        ofSetColor(226, 185, 0);
        ofSetLineWidth(0.75F);
        auto n = closestIndex[i];
        ofDrawLine(points[i].x, points[i].y, points[n].x, points[n].y);
    }
    
    if (mousePre) {
        ofSetColor(255, 200, 0);
        ofSetLineWidth(2.0F);
        ofDrawRectangle(mouseX - mouseRect / 2, mouseY - mouseRect / 2, mouseRect, mouseRect);
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == OF_KEY_UP)   mouseRect += 4;
    if (key == OF_KEY_DOWN) mouseRect -= 4;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    mousePre = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    mousePre = false;
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
