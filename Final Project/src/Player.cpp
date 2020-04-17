//
//  Player.cpp
//  Final Project
//
//  Created by Rolando Santos on 11/12/18.
//

#include "Player.h"

void Player::setup(ofImage *img) {
    
    lives = 3;
    speed = 5;
    image = img;
    width = image->getWidth();
    pos.x = 500;
    pos.y = 450;
}

void Player::update() {
    
    calculate_movement();
}

void Player::draw() {
    
    image->draw(pos.x - width/2, pos.y);
}

void Player::calculate_movement() {
    
    if (is_left_pressed && pos.x > 0 + width/2) {
        pos.x -= speed;
    }
    if (is_right_pressed && pos.x < ofGetWidth() - width/2) {
        pos.x += speed;
    }
}


