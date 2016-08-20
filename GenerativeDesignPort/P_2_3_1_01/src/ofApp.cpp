#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("P_2_3_1_01");
    ofBackground(255, 255, 255);
    ofSetBackgroundAuto(false);
    ofNoFill();
    
    col.set(181, 157, 0, 100);

    lineLength = 0;
    angle      = 0;
    angleSpeed = 1.0F;
    mouseP     = false;
}

//--------------------------------------------------------------
void ofApp::update() {
    angle += angleSpeed;
}

//--------------------------------------------------------------
void ofApp::draw() {
    if (mouseP) {
        ofPushMatrix();
            ofSetLineWidth(1.0F);
            ofSetColor(col);
            ofTranslate(mouseX, mouseY);
            ofDrawLine(0, 0, lineLength, 0);
        ofPopMatrix();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (key == OF_KEY_UP)    lineLength += 5;
    if (key == OF_KEY_DOWN)  lineLength -= 5;
    if (key == OF_KEY_LEFT)  angleSpeed -= 0.5F;
    if (key == OF_KEY_RIGHT) angleSpeed += 0.5F;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == OF_KEY_DEL || key == OF_KEY_BACKSPACE) ofBackground(255);
    
    if (key=='d' || key=='D') {
        angle = angle + 180;
        angleSpeed = angleSpeed * -1;
    }
    
    if (key == ' ') col.set(ofRandom(255), ofRandom(255), ofRandom(255), ofRandom(80, 150));
    if (key == '1') col.set(181, 157, 0, 100);
    if (key == '2') col.set(0, 130, 164, 100);
    if (key == '3') col.set(87, 35, 129, 100);
    if (key == '4') col.set(197, 0, 123, 100);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    mouseP     = true;
    lineLength = ofRandom(70, 200);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    mouseP = false;
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
