#include "ofApp.h"

constexpr int NORTH = 0;
constexpr int EAST  = 1;
constexpr int SOUTH = 2;
constexpr int WEST  = 3;

ofColor white{ 255, 255, 255 };

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("Port of 22202");
    ofBackground(255);
    ofSetBackgroundAuto(false);
    ofSetColor(128);
    ofSetLineWidth(1);

    W          = ofGetWidth();
    H          = ofGetHeight();
    direction  = SOUTH;
    angleCount = 7;
    angle      = getRandomDirection(direction);
    stepSize   = 3;
    minLength  = 10;
    posX       = ofRandom(0, W);
    posY       = 5;
    posXcross  = posX;
    posYcross  = posY;
    dWeight    = 50;
    dStroke    = 4;
    drawMode   = 1;

    
}

int ofApp::getRandomDirection(int dir) {
    auto a = floor(ofRandom(-angleCount, angleCount) + 0.5F) * 90.0F / angleCount;
    
    if (dir == NORTH) return a - 90;
    if (dir == EAST)  return a;
    if (dir == SOUTH) return a + 90;
    if (dir == WEST)  return a + 180;
    
    return 0;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofImage screen;
    screen.grabScreen(0, 0, 600, 600);
    
    auto mx = abs(mouseX);
    for (auto i = 0; i < mx; i++) {
        ofDrawEllipse(posX, posY, 2, 2);
        
        posX += cosf(ofDegToRad(angle)) * stepSize;
        posY += sinf(ofDegToRad(angle)) * stepSize;
        
        auto reachedBorder = false;
        
        if (posY <= 5) {
            direction     = SOUTH;
            reachedBorder = true;
        } else if (posX >= W - 5) {
            direction     = WEST;
            reachedBorder = true;
        } else if (posY >= H - 5) {
            direction     = NORTH;
            reachedBorder = true;
        } else if (posX <= 5) {
            direction     = EAST;
            reachedBorder = true;
        }
        
        auto pixels  = screen.getPixels();
        auto colorAt = pixels.getColor((int)posX, (int)posY);
        if (colorAt != white || reachedBorder) {
            angle         = getRandomDirection(direction);
            auto distance = ofDist(posX, posY, posXcross, posYcross);
            if (distance >= minLength) {
                ofSetLineWidth(distance / dWeight);
                ofColor c;
                if (drawMode == 1) c.set(0, 0, 0);
                if (drawMode == 2) c.setHsb(36, 255, distance/dStroke);
                if (drawMode == 3) {
                    c.setHsb(136, 100, 163);
                    c.a = distance / dStroke;
                }

                ofSetColor(c);
                ofDrawLine(posX, posY, posXcross, posYcross);
                
                ofSetLineWidth(1);
                ofSetColor(0, 255, 255);
            }
            posXcross = posX;
            posYcross = posY;
        }
        
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
     ofBackground(255);
    
    if (key == '1') drawMode = 1;
    if (key == '2') drawMode = 2;
    if (key == '3') drawMode = 3;

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
