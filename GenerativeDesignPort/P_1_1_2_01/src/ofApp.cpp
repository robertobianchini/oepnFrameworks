#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetWindowTitle("Port of 11201");
    ofBackground(0);
    ofSetPolyMode(OF_POLY_WINDING_ODD);
    
    segmentCount = 360;
    radius       = 300;
    W            = ofGetWidth();
    H            = ofGetHeight();

    mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
    mesh.enableColors();
    
    rebuildMesh();
    
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackground(0);
    mesh.draw();
}


//--------------------------------------------------------------
void ofApp::rebuildMesh() {
    // Clean Mesh First ...
    mesh.clearVertices();
    
    ofColor c = {0, 0, 0};
    float hue = 254.0F;
    float sat = 255.0F;
    float bri = 255.0F;
    c.setHsb(hue, sat, bri);

    
    float angleStep = 360.0F / (float)segmentCount;
    
    mesh.addVertex(ofVec3f(W / 2, H / 2, 0));
    mesh.addColor(c);
    
    for (float angle = 0; angle <= 360; angle += angleStep) {
        float VX = W / 2 + cosf(ofDegToRad(angle)) * radius;
        float VY = H / 2 + sinf(ofDegToRad(angle)) * radius;
        mesh.addVertex(ofVec3f(VX, VY, 0));
        hue = ofMap(angle, 0, 360, 0, 255);
        c.setHsb(hue, sat, bri);
        mesh.addColor(c);
    }
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (key == '1') {
        segmentCount = 360;
        rebuildMesh();
    } else if (key == '2') {
        segmentCount = 45;
        rebuildMesh();
    } else if (key == '3') {
        segmentCount = 24;
        rebuildMesh();
    } else if (key == '4') {
        segmentCount = 12;
        rebuildMesh();
    } else if (key == '5') {
        segmentCount = 6;
        rebuildMesh();
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
    // Update the Saturation and the Brightness
    float hue = 255.0F;
    float sat = 255.0F;
    float bri = 255.0F;
    float mX  = abs(x);
    float mY  = abs(y);
    
    float angleStep = 360.0F / (float)segmentCount;
    
    ofFloatColor* colors = mesh.getColorsPointer();
    int index            = 0;
    
    
    // and Reset the Colors
    for (float angle = 0; angle <= 360; angle += angleStep) {
        hue = ofMap(angle, 0, 360, 0, 255);
        sat = ofMap(mX, 0, W, 0, 255);
        bri = ofMap(mY, 0, H, 0, 255);
        colors[index].setHsb(hue, sat, bri);
        index++;
    }
    
    for (int i = 0; i < index - 1; i++) {
        mesh.setColor(i, colors[i]);
    }
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
