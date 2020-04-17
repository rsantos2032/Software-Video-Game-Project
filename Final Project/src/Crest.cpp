//
//  Crest.cpp
//  Final Project
//
//  Created by Rolando Santos on 12/5/18.
//

#include "Crest.h"

void Crest::setup(ofImage *c_img) {
    
    crest_image = c_img;
    width = crest_image->getWidth();
}

void Crest::draw() {
    
    crest_image -> draw(pos.x,pos.y);
}
