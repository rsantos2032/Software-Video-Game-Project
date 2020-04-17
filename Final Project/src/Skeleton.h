//
//  Skeleton.h
//  Final Project
//
//  Created by Rolando Santos on 11/14/18.
//

#ifndef Skeleton_h
#define Skeleton_h
#include "ofMain.h"
#include "Enemy.h"

class Skeleton : public Enemy {
    
public:
    
    void setup(ofImage *e_img) {
        
        enemy_image = e_img;
        lives = 3;
        shoot_interval = 2.5;
        width = enemy_image->getWidth();
        height = enemy_image->getHeight();
        start_shoot = ofGetElapsedTimef();
        speed = 5;
    }
    void draw() {
        
        enemy_image->draw(pos.x, pos.y);
    }
    bool time_to_shoot() {
        
        if (ofGetElapsedTimef() - start_shoot > shoot_interval) {
            start_shoot = ofGetElapsedTimef();
            return true;
        }
        return false;
    }

};

#endif /* Skeleton_h */
