//
//  Ladder.cpp
//  Final Project
//
//  Created by Rolando Santos on 12/10/18.
//

#include "Ladder.h"

void Ladder::setup(ofImage *img) {
    
    image = img;
    width = image->getWidth();

}
void Ladder::draw() {
    image->draw(pos.x,pos.y);
}
