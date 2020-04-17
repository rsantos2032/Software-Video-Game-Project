//
//  Lives.h
//  Final Project
//
//  Created by Rolando Santos on 12/8/18.
//

#ifndef Lives_h
#define Lives_h
#include "ofMain.h"

class Lives {
    
public:
    
    ofPoint pos;
    float speed, width;
    
    ofImage *image;
    void setup(ofImage *img);
    void draw();
    void update();
};


#endif /* Lives_h */
