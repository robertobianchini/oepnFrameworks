#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetWindowTitle("Port of 21302");
    ofBackground(255, 255, 255);
    ofNoFill();
    ofSetColor(0, 0, 0);

    W           = ofGetWidth();
    H           = ofGetHeight();
    tileCountX  = 6;
    tileCountY  = 6;
    drawMode    = 1;
    count       = 0;
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
    auto mx = abs(mouseX);
    auto my = abs(mouseY);

    count     = mx / 20 + 5;
    auto para = (float)my / H - 0.5F;
    
    for (auto gridY = 0; gridY <= tileCountY; gridY++) {
        for (auto gridX = 0; gridX <= tileCountX; gridX++) {
            auto tileWidth  = W / tileCountX;
            auto tileHeight = H / tileCountY;
            auto posX       = tileWidth * gridX  + tileWidth  / 2;
            auto posY       = tileHeight * gridY + tileHeight / 2;
       
            ofPushMatrix();
                ofTranslate(posX, posY);
                switch (drawMode) {
                    case 1:
                        ofTranslate(-tileWidth / 2, -tileHeight / 2);
                        for (auto i = 0; i < count; i++) {
                            ofDrawLine(0, (para + 0.5F) * tileHeight, tileWidth, i * tileHeight / count);
                            ofDrawLine(0, i * tileHeight / count, tileWidth, tileHeight - (para + 0.5F) * tileHeight);
                        }
                    break;
                    
                    case 2:
                        for (auto i = 0; i <= count; i++) {
                            ofDrawLine(para * tileWidth, para * tileHeight, tileWidth / 2,  ((float)i / count - 0.5F) * tileHeight);
                            ofDrawLine(para * tileWidth, para * tileHeight, -tileWidth / 2, ((float)i / count - 0.5F) * tileHeight);
                            ofDrawLine(para * tileWidth, para * tileHeight, ((float)i / count - 0.5F) * tileWidth, tileHeight / 2);
                            ofDrawLine(para * tileWidth, para * tileHeight, ((float)i / count - 0.5F) * tileWidth, -tileHeight / 2);
                        }
                    break;
                    
                    case 3:
                        for (auto i = 0; i <= count; i++) {
                            ofDrawLine(0, para * tileHeight, tileWidth / 2,  ((float)i / count - 0.5F) * tileHeight);
                            ofDrawLine(0, para * tileHeight, -tileWidth / 2, ((float)i / count - 0.5F) * tileHeight);
                            ofDrawLine(0, para * tileHeight, ((float)i / count - 0.5F) * tileWidth, tileHeight / 2);
                            ofDrawLine(0, para * tileHeight, ((float)i / count - 0.5F) * tileWidth, -tileHeight / 2);
                        }
                    break;
                        
                }
            ofPopMatrix();
        }
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == '1') drawMode = 1;
    if (key == '2') drawMode = 2;
    if (key == '3') drawMode = 3;
    
    if (key == OF_KEY_DOWN)  tileCountY  = MAX(tileCountY - 1, 1);
    if (key == OF_KEY_UP)    tileCountY += 1;
    if (key == OF_KEY_LEFT)  tileCountX  = MAX(tileCountX - 1, 1);
    if (key == OF_KEY_RIGHT) tileCountX += 1;

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
