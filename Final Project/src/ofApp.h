#pragma once

#include "ofMain.h"
#include "GameEngine.h"
#include "ofxATK.hpp"
#include <fstream>

namespace finalproject {

class ofApp : public ofBaseApp{

	public:
    
        GameEngine ge;
    
        void setup();
		void update();
		void draw();

        ofSoundPlayer BGM;
        ofSoundPlayer BGM2;
        ofSoundPlayer BGM3;
    
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
        void exit();
        void audioOut(float* buffer, int bufferSize, int nChannels);
    
    
};
}


