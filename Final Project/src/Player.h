//
//  Player.h
//  Final Project
//
//  Created by Rolando Santos on 11/12/18.
//

#ifndef Player_h
#define Player_h
#include "ofMain.h"

class Player {
    
    public:
        ofPoint pos;
        float width, speed;
        int lives;
        bool is_right_pressed, is_left_pressed;
        void setup(ofImage *img);
        void update();
        void draw();
        void shoot();
        void calculate_movement();
        bool check_can_shoot();
    
        ofImage *image;
};

#endif /* Player_h */
