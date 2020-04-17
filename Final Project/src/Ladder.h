//
//  Ladder.h
//  Final Project
//
//  Created by Rolando Santos on 12/10/18.
//

#ifndef Ladder_h
#define Ladder_h
#include "ofMain.h"

class Ladder {
  
public:
    
    ofImage *image;
    ofPoint pos;
    float width;
    void setup(ofImage *img);
    void draw(); 
};

#endif /* Ladder_h */
