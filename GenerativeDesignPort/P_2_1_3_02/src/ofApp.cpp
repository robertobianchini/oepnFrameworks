#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("Port of 21302");
    ofNoFill();
    ofSetColor(0, 0, 0);

    backColor.setHsb(0, 0, 255);
    ofBackground(backColor);
    
    W           = ofGetWidth();
    H           = ofGetHeight();
    tileCountX  = 5;
    tileCountY  = 5;
    count       = 10;
    lineWeight  = 0;
    strokeColor = 0;
    drawMode    = 1;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw() {
    auto mx = abs(mouseX);
    auto my = abs(mouseY);

    ofSetLineWidth(0.5F);

    tileCountX = mx / 30 + 1;
    tileCountY = my / 30 + 1;

    for (auto gridY = 0; gridY <= tileCountY; gridY++) {
        for (auto gridX = 0; gridX <= tileCountX; gridX++) {
            float tileWidth  = W / tileCountX;
            float tileHeight = H / tileCountY;
            float posX       = tileWidth * gridX;
            float posY       = tileHeight * gridY;
            float x1         = tileWidth  / 2;
            float y1         = tileHeight / 2;
            float x2         = 0;
            float y2         = 0;
            
            ofPushMatrix();
                ofTranslate(posX, posY);
                for (auto side = 0; side < 4; side++) {
                    for (auto i = 0; i < count; i++) {
                        if (side == 0) {
                            x2 += tileWidth / count;
                            y2  = 0;
                        }
                        
                        if (side == 1) {
                            x2  = tileWidth;
                            y2 += tileHeight / count;
                        }
                        
                        if (side == 2) {
                            x2 -= tileWidth / count;
                            y2  = tileHeight;
                        }
                        
                        if (side == 3) {
                            x2  = 0;
                            y2 -= tileHeight / count;
                        }
                        
                        switch (drawMode) {
                            case 1: break;
                            case 2:
                                if (i < count / 2) {
                                    lineWeight  += 1;
                                } else {
                                    lineWeight  -= 1;
                                }
                                ofSetLineWidth(lineWeight);
                            break;

                            case 3:
                                if (i < count / 2) {
                                    strokeColor += 42.5F;
                                } else {
                                    strokeColor -= 42.5F;
                                }
                                ofColor c;
                                c.setHsb(strokeColor, 255, 255);
                                ofSetColor(c);
                                ofSetLineWidth(mx / 100);
                            break;
                        }

                        ofDrawLine(x1, y1, x2, y2);
                    }
                }
            ofPopMatrix();
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == '1') {
        drawMode = 1;
        backColor.setHsb(0, 0, 255);
        ofBackground(backColor);
        ofSetColor(0, 0, 0);
    }
    
    if (key == '2') {
        drawMode = 2;
        backColor.setHsb(0, 0, 255);
        ofBackground(backColor);
        ofSetColor(0, 0, 0);

    }
    
    if (key == '3') {
        drawMode = 3;
        backColor.setHsb(0, 0, 0);
        ofBackground(backColor);
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
