//
//  Enemy.h
//  Final Project
//
//  Created by Rolando Santos on 12/4/18.
//

#ifndef Enemy_h
#define Enemy_h
#include "ofMain.h"
class Enemy {

public:

    ofPoint pos;
    int lives;
    float speed, width, height;
    void setup(ofImage *e_img);
    void update();
    void draw();
    float start_shoot;
    float shoot_interval;
    ofImage *enemy_image;
};


#endif /* Enemy_h */
