//
//  Crest.h
//  Final Project
//
//  Created by Rolando Santos on 12/5/18.
//

#ifndef Crest_h
#define Crest_h
#include "ofMain.h"
#include "ElementState.h"

class Crest {
    
public:
    
    ofPoint pos;
    ofImage *crest_image;
    ElementState crest_state;
    float width;
    void setup(ofImage *c_img);
    void draw();
};

#endif /* Crest_h */
