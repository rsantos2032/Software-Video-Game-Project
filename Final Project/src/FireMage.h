//
//  FireMage.h
//  Final Project
//
//  Created by Rolando Santos on 12/5/18.
//

#ifndef FireMage_h
#define FireMage_h
#include "ofMain.h"
#include "Enemy.h"

class FireMage : public Enemy {
    
public:
    
    void setup(ofImage *e_img) {
        
        enemy_image = e_img;
        lives = 10;
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


#endif /* FireMage_h */
