//
//  Spell.h
//  Final Project
//
//  Created by Rolando Santos on 11/12/18.
//

#ifndef Spell_h
#define Spell_h
#include "ofMain.h"

class Spell {
  
    public:
        ofPoint pos;
        float speed, width, height;
        ofImage *spell_image;
        bool is_p_right;
        bool from_player;
        bool from_boss;
        void setup(bool is_p_r, bool is_f_p, ofPoint p, float s, ofImage *spell_img);
        void draw();
        void update();
};

#endif /* Spell_h */
