#include "ofApp.h"
using namespace finalproject;

//--------------------------------------------------------------
void ofApp::setup(){
   
    ge.loadImages();
    ge.game_state = START;
    ge.player_state = ICE;
    ge.setPlayerImageRight();
    ge.is_player_right = true;
    ge.player.setup(&ge.player_image);
    ge.spawnLowerPlatform();
    BGM.load("GameBGM2.mp3");
    BGM2.load("GameBGM4.mp3");
    BGM3.load("GameBGM3.mp3");
    ge.drawLives();
    ge.setupSound();
}


//--------------------------------------------------------------
void ofApp::update(){
    
    if (ge.game_state == START) {
        
    } else if (ge.game_state == IN_PROGRESS) {
        ge.updateSpells();
        ge.checkBLCollision();
        ge.checkContactCollision();
        ge.spawnAll();
        ge.spawnSkeletonSpell();
        ge.spawnFireMageSpell();
        ge.spawnIceMageSpell();
        ge.spawnShockMageSpell();
        
        if (ge.counter == 850) {
            BGM.stop();
        }
        
        if (ge.counter == 1000) {
            ge.game_state = FINALBOSS;
            BGM2.play();
        }
        
    } else if (ge.game_state == FINALBOSS) {
        ge.spawnAll();
        ge.updateSpells();
        ge.checkBLCollision();
        ge.checkContactCollision();
        ge.player.update();
        ge.updateBossState();
        ge.spawnBossSpell();
        
    } else if (ge.game_state == FINALBOSS2) {
        ge.spawnAll();
        ge.updateSpells();
        ge.checkBLCollision();
        ge.checkContactCollision();
        ge.player.update();
        ge.updateBossState();
        ge.spawnBossSpell();
    
    } else if (ge.game_state == FINISHED) {
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if (ge.game_state == START) {
        ge.start_screen_image.draw(0,0);
      
    } else if (ge.game_state == IN_PROGRESS) {
        ge.background_image.draw(0,0,0);
        ge.player.draw();
        ge.drawAll();
        
    } else if (ge.game_state == FINALBOSS) {
        ge.background_image.draw(0, 0, 0);
        ge.player.draw();
        ge.drawAll();
        
    } else if (ge.game_state == PAUSED) {
        ge.pauseGame();
        
    } else if (ge.game_state == INTERMISSION) {
        BGM2.stop();
        ge.intermission_menu.draw(0,0,0);
    
    } else if (ge.game_state == FINALBOSS2) {
        ge.background_image.draw(0, 0, 0);
        ge.player.draw();
        ge.drawAll();
    
    } else if (ge.game_state == FINISHED) {
        BGM.stop();
        BGM2.stop();
        BGM3.stop();
        
        if (ge.player.lives <= 0) {
            ge.death_menu.draw(0, 0);
        }
        else if (ge.final_boss[0].flives <= 0){
            ge.victory_menu.draw(10, 10, 10);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    int upper_key = toupper(key);
    
    if (upper_key == 'P' && ge.game_state != FINISHED) {
        ge.game_state = (ge.game_state == IN_PROGRESS) ? PAUSED : IN_PROGRESS;
        ge.is_pause = true;
    }
    
    if (upper_key == 'O' && ge.game_state != FINISHED) {
        ge.game_state = (ge.game_state == IN_PROGRESS) ? PAUSED : IN_PROGRESS;
        ge.is_pause = false;
    }
    
    else if (ge.game_state == IN_PROGRESS) {
        
        if (upper_key == 'A') {
            
            if (ge.onFloor) {
                ge.playerMoveLeft();
            }
            if (ge.onUpper && ge.player.pos.x > ge.u_platformxy[1].x) {
                ge.playerMoveLeft();
            }
        }
        
        if (upper_key == 'D') {
            
            if (ge.onFloor) {
                ge.playerMoveRight();
            }
            
            if (ge.onUpper && ge.player.pos.x < ge.u_platformxy[6].x) {
                ge.playerMoveRight();
            }
        }

        if (upper_key == 'J') {
            ge.is_shield_up = true;
            
            if (ge.is_player_right) {
                ge.setPlayerShieldRight();
                
            } else {
                ge.setPlayerShieldLeft();
                
            }
        }
        
        if (upper_key == 'H') {
            ge.spellPressed();
        }
        if (upper_key == 'W') {
            ge.interactCrest();
            ge.interactLadderUp();
        }
        
        if (upper_key == 'S') {
            ge.interactLadderDown();
        }
    }
    
    
    else if (ge.game_state == FINALBOSS) {
    
        if (upper_key == 'A') {
            
            if (ge.onFloor) {
                ge.player.is_left_pressed = true;
                ge.setPlayerImageLeft();
                ge.is_player_right = false;
            }
            if (ge.onUpper && ge.player.pos.x > ge.u_platformxy[1].x) {
                ge.player.is_left_pressed = true;
                ge.setPlayerImageLeft();
                ge.is_player_right = false;
            }
        }
        
        if (upper_key == 'D') {
            
            if (ge.onFloor) {
                ge.player.is_right_pressed = true;
                ge.setPlayerImageRight();
                ge.is_player_right = true;
            }
            if (ge.onUpper && ge.player.pos.x < ge.u_platformxy[6].x) {
                ge.player.is_right_pressed = true;
                ge.setPlayerImageRight();
                ge.is_player_right = true;
            }
        }
        
        if (upper_key == 'H') {
            ge.spellPressed();
        }
        if (upper_key == 'J') {
            ge.is_shield_up = true;
            
            if (ge.is_player_right) {
                ge.setPlayerShieldRight();
                
            } else {
                ge.setPlayerShieldLeft();
            }
        }
        if (upper_key == 'W') {
            ge.interactCrest();
            ge.interactLadderUp();
        }
        if (upper_key == 'S') {
            ge.interactLadderDown();
        }
        
    } else if (ge.game_state == FINALBOSS2) {
        
        if (upper_key == 'A') {
            
            if (ge.onFloor) {
                ge.player.is_left_pressed = true;
                ge.setPlayerImageLeft();
                ge.is_player_right = false;
            }
            if (ge.onUpper && ge.player.pos.x > ge.u_platformxy[1].x) {
                ge.player.is_left_pressed = true;
                ge.setPlayerImageLeft();
                ge.is_player_right = false;
            }
        }
        
        if (upper_key == 'D') {
            
            if (ge.onFloor) {
                ge.player.is_right_pressed = true;
                ge.setPlayerImageRight();
                ge.is_player_right = true;
            }
            if (ge.onUpper && ge.player.pos.x < ge.u_platformxy[6].x) {
                ge.player.is_right_pressed = true;
                ge.setPlayerImageRight();
                ge.is_player_right = true;
            }
        }
        
        if (upper_key == 'H') {
            ge.spellPressed();
        }
        if (upper_key == 'J') {
            ge.is_shield_up = true;
            
            if (ge.is_player_right) {
                ge.setPlayerShieldRight();
                
            } else {
                ge.setPlayerShieldLeft();
            }
        }
        if (upper_key == 'W') {
            ge.interactCrest();
            ge.interactLadderUp();
        }
        if (upper_key == 'S') {
            ge.interactLadderDown();
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

    int upper_key = toupper(key);
    
    if (ge.game_state == START) {
        ge.game_state = IN_PROGRESS;
        BGM.play();
    
    } else if (ge.game_state == IN_PROGRESS) {

        if (upper_key == 'A') {
            ge.player.is_left_pressed = false;
        }
        if (upper_key == 'D') {
            ge.player.is_right_pressed = false;
        }
        if (upper_key == 'J') {
            
            ge.is_shield_up = false;
            
            if (ge.is_player_right) {
                ge.setPlayerImageRight();
            } else {
                ge.setPlayerImageLeft();
            }
        }
        if (upper_key == 'H') {
            ge.spell_player->setLocation(0);
        }
        
    } else if (ge.game_state == FINALBOSS) {
        
        if (upper_key == 'A') {
            ge.player.is_left_pressed = false;
        }
        if (upper_key == 'D') {
            ge.player.is_right_pressed = false;
        }
        if (upper_key == 'J') {
            
            ge.is_shield_up = false;
            
            if (ge.is_player_right) {
                ge.setPlayerImageRight();
                
            } else {
                ge.setPlayerImageLeft();
            }
        }
        if (upper_key == 'H') {
            ge.spell_player->setLocation(0);
        }
        
    } else if (ge.game_state == INTERMISSION) {
        ge.game_state = FINALBOSS2;
        BGM3.play();
        
    } else if (ge.game_state == FINALBOSS2) {
        
        if (upper_key == 'A') {
            ge.player.is_left_pressed = false;
        }
        if (upper_key == 'D') {
            ge.player.is_right_pressed = false;
        }
        if (upper_key == 'J') {
            
            ge.is_shield_up = false;
            
            if (ge.is_player_right) {
                ge.setPlayerImageRight();
                
            } else {
                ge.setPlayerImageLeft();
            }
        }
        if (upper_key == 'H') {
            ge.spell_player->setLocation(0);
        }
    }
}

void ofApp::audioOut(float* buffer, int bufferSize, int nChannels){
    
    if (ge.is_enemy_dead == true) {
        ge.did_spell_cast = false;
        for (int i  = 0; i < bufferSize; i++) {
            
            ge.death_player->process();
            buffer[i*nChannels+0] = ge.death_player->getSample();
            buffer[i*nChannels+1] = ge.death_player->getSample();
        }
    }
    else if (ge.did_spell_cast == true) {
        for(int i = 0; i < bufferSize; i++) {
            
            ge.spell_player->process();
            buffer[i*nChannels+0] = ge.spell_player->getSample();
            buffer[i*nChannels+1] = ge.spell_player->getSample();
        }
    }
    else if (ge.did_get_upgrade == true) {
        for(int i = 0; i < bufferSize; i++) {
            
            ge.upgrade_player->process();
            buffer[i*nChannels+0] = ge.upgrade_player->getSample();
            buffer[i*nChannels+1] = ge.upgrade_player->getSample();
        }
    }
}


//------------------------------------------------------------------------------------
//    XX    X    XXXXXXX    XXXXXXX         X      X    XXXXXXXX    XXXXXXX    XXXXXX
//    X X   X    X     X       X            X      X    X           X          X      X
//    X  X  X    X     X       X            X      X    XXXXXXXX    XXXXXXX    X      X
//    X   X X    X     X       X            X      X           X    X          X      X
//    X    XX    XXXXXXX       X            XXXXXXXX    XXXXXXXX    XXXXXXX    XXXXXX
//------------------------------------------------------------------------------------

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}

void ofApp::exit() {
    ofSoundStreamClose();
}


