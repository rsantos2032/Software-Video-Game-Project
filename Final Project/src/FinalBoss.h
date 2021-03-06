//
//  FinalBoss.h
//  Final Project
//
//  Created by Rolando Santos on 12/12/18.
//

#ifndef FinalBoss_h
#define FinalBoss_h
#include "ofMain.h"
#include "ElementState.h"
#include "Enemy.h"

class FinalBoss : public Enemy {
    
public:
    
    void setup(ofImage *e_img) {
        
        enemy_image = e_img;
        lives = 150;
        flives = 200;
        shoot_interval = 3;
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
    ElementState boss_state = ICE;
    int flives;
};

#endif /* FinalBoss_h */
