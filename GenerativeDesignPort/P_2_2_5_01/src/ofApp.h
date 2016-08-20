#pragma once

#include <vector>
#include "ofMain.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void reset();
    
    
    int                  W, H;
    int                  currentCount;
    float                minRadius;
    float                maxRadius;
    float                mouseRect;
    bool                 mousePre;
    std::vector<ofVec2f> points;
    std::vector<int>     r;
    std::vector<int>     closestIndex;
};
