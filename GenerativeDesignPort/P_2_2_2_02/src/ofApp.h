#pragma once

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
        int  getRandomDirection(int dir);
    
        float posX, posY;
        float posXcross, posYcross;
        float angle;
        float angleCount;
        float stepSize;
        float minLength;
        int   direction;
        int   W, H;
        int   dWeight;
        int   dStroke;
        int   drawMode;
};
