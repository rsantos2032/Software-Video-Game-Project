//
//  Spell.cpp
//  Final Project
//
//  Created by Rolando Santos on 11/12/18.
//

#include "Spell.h"

void Spell::setup(bool is_p_r, bool f_p, ofPoint p, float s, ofImage *spell_img) {
    
    is_p_right = is_p_r;
    from_player = f_p;
    pos =  p;
    speed = s * 3;
    spell_image = spell_img;
    width = spell_image->getWidth();
    height = spell_image->getHeight();
    //pos.y = 450;
}

void Spell::update() {
    
    if (from_player) {
        if(is_p_right) {
            pos.x += speed;
        } else {
            pos.x -= speed;
        }
    } else {
        
        if (from_boss) {
            
            pos.y += speed;
        } else {
            pos.x -= speed;
        
        }
    }
}

void Spell::draw() {
    
    if (from_player) {
        if(is_p_right) {
            spell_image->draw(pos.x, pos.y+42);
        } else {
            spell_image->draw(pos.x - width, pos.y+42);
        }
    } else {
        spell_image->draw(pos.x - width/2, pos.y+42);
    }
}
