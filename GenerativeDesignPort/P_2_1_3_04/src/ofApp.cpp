#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("Port of 21304");
    ofBackground(255, 255, 255);
    ofNoFill();
    ofSetColor(0, 0, 0);
    ofSetRectMode(OF_RECTMODE_CENTER);

    W           = ofGetWidth();
    H           = ofGetHeight();
    tileCountX  = 6;
    tileCountY  = 6;
    drawMode    = 1;
    count       = 0;

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    auto mx = abs(mouseX);
    auto my = abs(mouseY);
    
    count     = mx / 10 + 10;
    auto para = (float)my / H;
    
    for (auto gridY = 0; gridY <= tileCountY; gridY++) {
        for (auto gridX = 0; gridX <= tileCountX; gridX++) {
            auto tileWidth  = W / tileCountX;
            auto tileHeight = H / tileCountY;
            auto posX       = tileWidth  * gridX + tileWidth  / 2;
            auto posY       = tileHeight * gridY + tileHeight / 2;
            
            ofColor from;
            ofColor to;
            
            ofPushMatrix();
                ofTranslate(posX, posY);
                switch (drawMode) {
                    case 1:
                        for (auto i = 0; i < count; i++) {
                            ofDrawRectangle(0, 0, tileWidth, tileHeight);
                            ofScale(1 - 3.0F / count, 1 - 3.0F / count);
                            auto angle = ofRadToDeg(para * 0.1F);
                            ofRotate(angle);
                        }
                    break;
                        
                    case 2:
                        from.setHsb(0, 0, 0);
                        to.setHsb(36.8F, 255, 50.2F);
                        for (auto j = 0; j < count; j++) {
                            auto gradiente = from.lerp(to, j / count);
                            //gradiente.a    = (int)(j / count * 200);
                            ofSetColor(gradiente);
                            ofRotate(PI / 4);
                            ofDrawRectangle(0, 0, tileWidth, tileHeight);
                            ofScale(1 - 3.0F / count, 1 - 3.0F / count);
                            auto angle = ofRadToDeg(para * 1.5F);
                            ofRotate(angle);
                        }
                    break;
                        
                    case 3:
                        from.set(0, 130, 164, 255);
                        to.set(255, 255, 255, 255);
                        for (float k = 0; k < count; k++) {
                            auto gradiente = from.lerp(to, k / count);
                            gradiente.a    = 170;
                            ofSetColor(gradiente);
                            ofPushMatrix();
                                ofTranslate(4 * k, 0);
                                ofDrawEllipse(0, 0, tileWidth / 4, tileHeight / 4);
                            ofPopMatrix();
                            
                            ofPushMatrix();
                                ofTranslate(-4 * k, 0);
                                ofDrawEllipse(0, 0, tileWidth / 4, tileHeight / 4);
                            ofPopMatrix();
                            
                            ofScale(1 - 1.5F / count, 1 - 1.5F / count);
                            auto angle = ofRadToDeg(para * 1.5F);
                            ofRotate(angle);
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
