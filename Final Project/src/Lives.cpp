//
//  Lives.cpp
//  Final Project
//
//  Created by Rolando Santos on 12/8/18.
//

#include "Lives.h"

void Lives::setup(ofImage *img) {
    
    image = img;
    width = image->getWidth();
    speed = 5;
}

void Lives::draw() {
    
    image->draw(pos.x, pos.y);
}
