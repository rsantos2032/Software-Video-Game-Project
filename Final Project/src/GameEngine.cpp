//
//  GameEngine.cpp
//  Final Project
//
//  Created by Rolando Santos on 12/5/18.
//

#include "GameEngine.h"

//---------------------------------------------------------------------------------
//    X     X    XXXXXXX    X    X          X    XXXXXXX    X    XXXXXXX    XXXXXXX
//    X     X       X       X    X          X       X       X    X          X
//    X     X       X       X    X          X       X       X    XXXXXXX    XXXXXXX
//    X     X       X       X    X          X       X       X    X                X
//    XXXXXXX       X       X    XXXXXXX    X       X       X    XXXXXXX    XXXXXXX
//---------------------------------------------------------------------------------

//--------------------------------------------------------------
void GameEngine::pauseGame() {

    if (is_pause == true) {
        pause_menu.draw(0,0);
    }
    else {
        story_menu.draw(0,0);
    }
}

// Preloads almost all of the images that I want to use.
//--------------------------------------------------------------
void GameEngine::loadImages() {
    
    start_screen_image.load("StartScreen.png");
    background_image.load("GameBGNormal.png");
    pause_menu.load("PauseMenu.png");
    story_menu.load("StoryMenu.png");
    death_menu.load("DeathMenu.png");
    victory_menu.load("VictoryMenu.png");
    intermission_menu.load("IntermissionMenu.png");
    
    fire_crest_image.load("FireCrest.png");
    ice_crest_image.load("IceCrest.png");
    shock_crest_image.load("ShockCrest.png");
    
    skeleton_image.load("Skeleton.png");
    fmage_image.load("FireMob.png");
    ice_mage_image.load("IceMob.png");
    smage_image.load("ShockMob.png");
    
    skeleton_spell_image.load("SkeletonSpell.png");
    fmage_spell_image.load("FireballLeft.png");
    ice_mage_spell_image.load("FrostboltLeft.png");
    smage_spell_image.load("ShockboltLeft.png");
    
    player_fright.load("PlayerFireRight.png");
    player_iright.load("PlayerIceRight.png");
    player_sright.load("PlayerShockRight.png");
    player_rright.load("PlayerRotRight.png");
    player_fleft.load("PlayerFireLeft.png");
    player_ileft.load("PlayerIceLeft.png");
    player_sleft.load("PlayerShockLeft.png");
    player_rleft.load("PlayerRotLeft.png");
    
    player_fright_spell.load("FireballRight.png");
    player_iright_spell.load("FrostboltRight.png");
    player_sright_spell.load("ShockboltRight.png");
    player_rright_spell.load("RotRight.png");
    player_fleft_spell.load("FireballLeft.png");
    player_ileft_spell.load("FrostboltLeft.png");
    player_sleft_spell.load("ShockboltLeft.png");
    player_rleft_spell.load("RotLeft.png");
    
    player_fright_shield.load("PlayerFireRightShield.png");
    player_iright_shield.load("PlayerIceRightShield.png");
    player_sright_shield.load("PlayerShockRightShield.png");
    player_rright_shield.load("PlayerRotRightShield.png");
    player_fleft_shield.load("PlayerFireLeftShield.png");
    player_ileft_shield.load("PlayerIceLeftShield.png");
    player_sleft_shield.load("PlayerShockLeftShield.png");
    player_rleft_shield.load("PlayerRotLeftShield.png");
    
    lower_platform_image.load("FloorNormal.png");
    upper_platform_image.load("UpperNormal.png");
    
    life_image.load("Lives.png");
    ladder_image.load("Ladder.png");
    
    final_boss_image.load("FinalBossIce.png");
    boss_spell_image.load("BossSIce.png");
}

// This draws the health icons on screen
//--------------------------------------------------------------
void GameEngine::drawLives() {
    
    for (int i = 0; i < player.lives; i++) {
        Lives life;
        life.setup(&life_image);
        lives.push_back(life);
    }
    for (int i = 0; i < lives.size(); i++) {
        lives[i].pos.x = i*kPlatform_x;
        lives[i].pos.y = 0;
    }
}

// This will change the player image to face right.
//---------------------------------------------------------------
void GameEngine::setPlayerImageRight() {
    
    if (player_state == FIRE) {
        player_image = player_fright;
        
    } else if (player_state == ICE) {
        player_image = player_iright;
        
    } else if (player_state == SHOCK) {
        player_image = player_sright;
        
    } else {
        player_image = player_rright;
    }
}

// This will change the player image to face left.
//-----------------------------------------------------------------
void GameEngine::setPlayerImageLeft() {
    
    if (player_state == FIRE) {
        player_image = player_fleft;
        
    } else if (player_state == ICE) {
        player_image = player_ileft;
        
    } else if (player_state == SHOCK){
        player_image = player_sleft;
        
    } else {
        player_image = player_rleft;
    }
}

// This will change the player image to face right when using shield.
//------------------------------------------------------------------
void GameEngine::setPlayerShieldRight() {
    
    if (player_state == FIRE) {
        player_image = player_fright_shield;
        
    } else if (player_state == ICE) {
        player_image = player_iright_shield;
        
    } else if (player_state == SHOCK) {
        player_image = player_sright_shield;
        
    } else {
        player_image = player_rright_shield;
    }
}

// This will change the player image to face left when using shield.
//--------------------------------------------------------------
void GameEngine::setPlayerShieldLeft() {
    
    if (player_state == FIRE) {
        player_image = player_fleft_shield;
        
    } else if (player_state == ICE) {
        player_image = player_ileft_shield;
        
    } else if (player_state == SHOCK) {
        player_image = player_sleft_shield;

    } else {
        player_image = player_rleft_shield;
    }
}

// This will change the player spell image to look like it's going in the right direction
//--------------------------------------------------------------
void GameEngine::setPlayerSpellRight() {
    
    if (player_state == FIRE) {
        spell_image = player_fright_spell;
        
    } else if (player_state == ICE) {
        spell_image = player_iright_spell;
        
    } else if (player_state == SHOCK) {
        spell_image = player_sright_spell;
        
    } else {
        spell_image = player_rright_spell;
    }
}

// This will change the player spell image to look like it's going in the left direction
//--------------------------------------------------------------
void GameEngine::setPlayerSpellLeft() {
    
    if (player_state == FIRE) {
        spell_image = player_fleft_spell;
        
    } else if (player_state == ICE) {
        spell_image = player_ileft_spell;
        
    } else if (player_state == SHOCK) {
        spell_image = player_sleft_spell;
        
    } else {
        spell_image = player_rleft_spell;
    }
}

// Move all the objects in the world away from the player
//--------------------------------------------------------------
void GameEngine::playerMoveLeft() {
    
    player.is_left_pressed = true;
    setPlayerImageLeft();
    is_player_right = false;
    counter--;
    
    if(is_skeleton_present) {
        skeletons[0].pos.x += kEnemy_movement;
    }
    if (is_fmage_present) {
        fire_mages[0].pos.x += kEnemy_movement;
    }
    if (is_ice_mage_present) {
        ice_mages[0].pos.x += kEnemy_movement;
    }
    if (is_smage_present) {
        shock_mages[0].pos.x += kEnemy_movement;
    }
    for (int i = 0; i < crests.size(); i++) {
        crests[i].pos.x += kEnemy_movement+5;
    }
    for (int i = 0; i < kPlatform_num; i++) {
        platformxy[i].x += kSpeed;
        if (platformxy[i].x > kPlatform_limit_upper) {
            platformxy[i].x = kPlatform_limit_lower;
        }
    }
    for (int i = 0; i < kUPlatform_num; i++) {
        u_platformxy[i].x += kSpeed;
    }
    for (int i = 0; i < ladders.size(); i++) {
        ladders[i].pos.x += kEnemy_movement+5;
    }
    for (int i = 0; i < bonus_lives.size(); i++) {
        bonus_lives[i].pos.x += kEnemy_movement+5;
    }
    if (is_fb_present) {
        final_boss[0].pos.x += kEnemy_movement;
    }
}

// Move all the objects in the world towards the player
//--------------------------------------------------------------
void GameEngine::playerMoveRight() {
    
    player.is_right_pressed = true;
    setPlayerImageRight();
    is_player_right = true;
    counter += 1;
    
    if (is_skeleton_present){
        skeletons[0].pos.x -= kEnemy_movement;
    }
    if (is_fmage_present) {
        fire_mages[0].pos.x -= kEnemy_movement;
    }
    if (is_ice_mage_present) {
        ice_mages[0].pos.x -= kEnemy_movement;
    }
    if (is_smage_present) {
        shock_mages[0].pos.x -= kEnemy_movement;
    }
    for (int i = 0; i < crests.size(); i++) {
        crests[i].pos.x -= kEnemy_movement+5;
    }
    for (int i = 0; i < kPlatform_num; i++) {
        platformxy[i].x -= kSpeed;
        if (platformxy[i].x < kPlatform_limit_lower) {
            platformxy[i].x = kPlatform_limit_upper;
        }
    }
    for (int i = 0; i < kUPlatform_num; i++) {
        u_platformxy[i].x -= kSpeed;
    }
    for (int i = 0; i < ladders.size(); i++) {
        ladders[i].pos.x -= kEnemy_movement+5;
    }
    for (int i = 0; i < bonus_lives.size(); i++) {
        bonus_lives[i].pos.x -= kEnemy_movement+5;
    }
    if (is_fb_present) {
        final_boss[0].pos.x -= kEnemy_movement;
    }
}

// Differing sound effect files I used.
//--------------------------------------------------------------
void GameEngine::setupSound() {
    
    string fileName = ofToDataPath("spell_cast.aiff");
    spell_file = new SoundFile(fileName);
    spell_player = new SoundPlayer(spell_file);
    
    string fileName2 = ofToDataPath("Enemydeath.aiff");
    death_file = new SoundFile(fileName2);
    death_player = new SoundPlayer(death_file);
    
    upgrade_file = new SoundFile(ofToDataPath("powerup.aiff"));
    upgrade_player = new SoundPlayer(upgrade_file);
    
    ofSoundStreamSetup(2, 0, ATKSettings::sampleRate, ATKSettings::bufferSize, 4);
}

// Spawns all enemies when their counter nummber is in place
//-------------------------------------------------------------
void GameEngine::spawnAll() {
    
    for (int i = 0; i < skeleton_spawn.size(); i++) {
        if (counter == skeleton_spawn[i]) {
            spawnSkeleton();
        }
    }
    for (int i = 0; i < fmage_spawn.size(); i++) {
        if (counter == fmage_spawn[i]) {
            spawnFireMage();
        }
    }
    for (int i = 0; i < ice_mage_spawn.size(); i++) {
        if (counter == ice_mage_spawn[i]) {
            spawnIceMage();
        }
    }
    for (int i = 0; i < smage_spawn.size(); i++) {
        if (counter == smage_spawn[i]) {
            spawnShockMage();
        }
    }
    for (int i = 0; i < fcrest_spawn.size(); i++) {
        if (counter == fcrest_spawn[i]) {
            crest_state = FIRE;
            spawnCrest();
        }
    }
    for (int i = 0; i < icrest_spawn.size(); i++) {
        if (counter == icrest_spawn[i]) {
            crest_state = ICE;
            spawnCrest();
        }
    }
    for (int i = 0; i < screst_spawn.size(); i++) {
        if (counter == screst_spawn[i]) {
            crest_state = SHOCK;
            spawnCrest();
        }
    }
    for (int i = 0; i < upper_platform_spawn.size(); i++) {
        if(counter == upper_platform_spawn[i]) {
            spawnUpperPlatform();
        }
    }
    for (int i = 0; i < ladder_spawn.size(); i++) {
        if (counter == ladder_spawn[i]) {
            spawnLadder();
        }
    }
    
    for (int i = 0; i < bonus_lives_spawn.size(); i++) {
        if (counter == bonus_lives_spawn[i]) {
            spawnBonusLives();
        }
    }
    for (int i = 0; i < boss_spawn.size(); i++) {
        if (counter == boss_spawn[i]) {
            spawnFinalBoss();
        }
    }
}

// Draws all the images
//--------------------------------------------------------------
void GameEngine::drawAll() {
    
    for(int i = 0; i < skeletons.size(); i++) {
        skeletons[i].draw();
    }
    for(int i = 0; i < fire_mages.size(); i++) {
        fire_mages[i].draw();
    }
    for(int i = 0; i < ice_mages.size(); i++) {
        ice_mages[i].draw();
    }
    for(int i = 0; i < shock_mages.size(); i++) {
        shock_mages[i].draw();
    }
    for (int i = 0; i < kPlatform_num; i++) {
        platform[i].draw(platformxy[i].x,platformxy[i].y);
    }
    for (int i = 0; i < spells.size(); i++) {
        spells[i].draw();
    }
    for (int i = 0; i < crests.size(); i++) {
        crests[i].draw();
    }
    for (int i = 0; i < kUPlatform_num; i++) {
        u_platform[i].draw(u_platformxy[i].x, u_platformxy[i].y);
    }
    for (int i = 0; i < lives.size(); i++) {
        lives[i].draw();
    }
    for (int i = 0; i < ladders.size(); i++) {
        ladders[i].draw();
    }
    for (int i = 0; i < bonus_lives.size(); i++) {
        bonus_lives[i].draw();
    }
    for (int i = 0; i < final_boss.size(); i++) {
        final_boss[i].draw();
    }
}

//----------------------------------------------------------------------------------------------
//    XX    XX    XXXXXXX    XXXXXXX    X     X    XXXXXXX    XX    X    X    XXXXXXX    XXXXXXX
//    X X  X X    X          X          X     X    X     X    X X   X    X    X          X
//    X  XX  X    XXXXXXX    X          XXXXXXX    XXXXXXX    X  X  X    X    X          XXXXXXX
//    X      X    X          X          X     X    X     X    X   X X    X    X                X
//    X      X    XXXXXXX    XXXXXXX    X     X    X     X    X    XX    X    XXXXXXX    XXXXXXX
//----------------------------------------------------------------------------------------------

// Will update the spells of the players and enemies. Seperated them with different game states to relieve pressure on the machine
//--------------------------------------------------------------
void GameEngine::updateSpells() {
    
    for (int i = 0; i < spells.size(); i++) {
        spells[i].update();
        if (spells[i].pos.x - spells[i].width/2 < 0 || spells[i].pos.x + spells[i].width/2 > ofGetWidth()) {
            spells.erase(spells.begin()+i);
        }
    }
    if (game_state == IN_PROGRESS) {
        checkSkeletonCollision();
        checkFireMageCollision();
        checkIceMageCollision();
        checkShockMageCollision();
    }
    if (game_state == FINALBOSS || game_state == FINALBOSS2) {
        checkBossCollision();
    }
}

// Player spell is casted
//-------------------------------------------------------------
void GameEngine::spawnPlayerSpell() {
    
    Spell spell;
    spell.setup(is_player_right, true, player.pos, player.speed, &spell_image);
    spells.push_back(spell);
}

// Checks the status of the player. Game gets bad end if player dies
//--------------------------------------------------------------
void GameEngine::checkPlayerStatus() {
    
    if (!is_shield_up) {
        player.lives--;
        lives.pop_back();
    }
    if (player.lives <= 0) {
        game_state = FINISHED;
    }
}

//--------------------------------------------------------------
void GameEngine::spawnLowerPlatform() {
    
    for (int i = 0; i < kPlatform_num; i++) {
        platform[i] = lower_platform_image;
        platformxy[i].x = i * kPlatform_x;
        platformxy[i].y = kPlatform_y;
    }
    
}

//--------------------------------------------------------------
void GameEngine::spawnUpperPlatform() {
    
    for (int i = 0; i < kUPlatform_num; i++) {
        u_platform[i] = upper_platform_image;
        u_platformxy[i].x = (i+kUPlatform_show) * kPlatform_x;
        u_platformxy[i].y = kUPlatform_y;
    }
}

// If the player goes near any and touches them they will instantly die. This is to enforce spell combat
//--------------------------------------------------------------
void GameEngine::checkContactCollision() {
    
    for (int i = 0; i < skeletons.size(); i++) {
        if (ofDist(player.pos.x, player.pos.y, skeletons[i].pos.x, skeletons[i].pos.y) < (player.width/2 + skeletons[i].width/2)/2) {
            player.lives = 0;
            checkPlayerStatus();
        }
    }
    for (int i = 0; i < fire_mages.size(); i++) {
        if (ofDist(player.pos.x, player.pos.y, fire_mages[i].pos.x, fire_mages[i].pos.y) < (player.width/2 + fire_mages[i].width/2)/2) {
            player.lives = 0;
            checkPlayerStatus();
        }
    }
    for (int i = 0; i < ice_mages.size(); i++) {
        if (ofDist(player.pos.x, player.pos.y, ice_mages[i].pos.x, ice_mages[i].pos.y) < (player.width/2 + ice_mages[i].width/2)/2) {
            player.lives = 0;
            checkPlayerStatus();
        }
    }
    for (int i = 0; i < shock_mages.size(); i++) {
        if (ofDist(player.pos.x, player.pos.y, shock_mages[i].pos.x, shock_mages[i].pos.y) < (player.width/2 + shock_mages[i].width/2)/2) {
            player.lives = 0;
            checkPlayerStatus();
        }
    }
    
    for (int i = 0; i < final_boss.size(); i++) {
        if (ofDist(player.pos.x, player.pos.y, final_boss[i].pos.x, final_boss[i].pos.y) < (player.width/2 + final_boss[i].width/2)/2) {
            player.lives = 0;
            checkPlayerStatus();
        }
    }
}

//--------------------------------------------------------------
void GameEngine::spawnLadder() {
    
    ladder_pos.x = kSpawn;
    ladder_pos.y = 300;
    Ladder ladder;
    ladder.pos = ladder_pos;
    ladder.setup(&ladder_image);
    ladders.push_back(ladder);
}

//--------------------------------------------------------------
void GameEngine::interactLadderUp() {
    
    for (int i = 0; i < ladders.size(); i++) {
        
        if (ofDist(player.pos.x, player.pos.y, ladders[i].pos.x, ladders[i].pos.y) <= 205) {
            
            if (player.pos.y > kPlayer_upper) {
                player.pos.y -= 5;
                onLadder = true;
                onFloor = false;
            }
            else {
                onLadder = false;
                onUpper = true;
            }
        }
    }
}

//--------------------------------------------------------------
void GameEngine::interactLadderDown() {
    
    for (int i = 0; i < ladders.size(); i++) {
        
        if (ofDist(player.pos.x, player.pos.y, ladders[i].pos.x, ladders[i].pos.y) <= 205) {
            
            if (player.pos.y < kFloor) {
                player.pos.y += 5;
                onLadder = true;
                onUpper = false;
            }
            else {
                onLadder = false;
                onFloor = true;
            }
        }
    }
}

//--------------------------------------------------------------
void GameEngine::spawnBonusLives() {
    
    
    if (game_state == IN_PROGRESS) {
        bl_pos.x = kSpawn;
        bl_pos.y = kUpper_spawn;
        Lives life;
        life.pos = bl_pos;
        life.setup(&life_image);
        bonus_lives.push_back(life);
    } else if (game_state == FINALBOSS) {
        bl_pos.x = 150;
        bl_pos.y = kUpper_spawn;
        Lives life;
        life.pos = bl_pos;
        life.setup(&life_image);
        bonus_lives.push_back(life);
    }
    
}

// Unlike the crests the player will automatically consume a bonus life without pressing W
//--------------------------------------------------------------
void GameEngine::checkBLCollision() {
    
    for (int i = 0; i < bonus_lives.size(); i++) {
        
        if (ofDist(player.pos.x, player.pos.y, bonus_lives[i].pos.x, bonus_lives[i].pos.y) < (player.width + bonus_lives[i].width)/2) {
            
            did_spell_cast = false;
            is_enemy_dead = false;
            did_get_upgrade = true;
            upgrade_player->play();
            upgrade_player->setLocation(0);
            
            if (player.lives < 3) {
                player.lives++;
                updateLives();
            }
            bonus_lives.clear();
        }
    }
}

//--------------------------------------------------------------
void GameEngine::updateLives() {
    
    Lives life;
    life.setup(&life_image);
    
    if (lives.size() == 2) {
        life.pos.x = 2*kPlatform_x;
        life.pos.y = 0;
        lives.push_back(life);
    }
    else if (lives.size() == 1) {
        life.pos.x = kPlatform_x;
        life.pos.y = 0;
        lives.push_back(life);
    }
}

//--------------------------------------------------------------
void GameEngine::spellPressed() {
    
    if (is_player_right) {
        did_spell_cast = true;
        is_enemy_dead = false;
        did_get_upgrade = false;
        spell_player->play();
        setPlayerSpellRight();
        spawnPlayerSpell();
        
    } else {
        did_spell_cast = true;
        is_enemy_dead = false;
        did_get_upgrade = false;
        spell_player->play();
        setPlayerSpellLeft();
        spawnPlayerSpell();
    }
}

//-----------------------------------------------------------------------------------------
//    XXXXXXXX    X    X    XXXXXXX    X          XXXXXXX    XXXXXXX    XXXXXXX    XX    X
//    X           X   X     X          X          X             X       X     X    X X   X
//    XXXXXXXX    XXXX      XXXXXXX    X          XXXXXXX       X       X     X    X  X  X
//           X    X   X     X          X          X             X       X     X    X   X X
//    XXXXXXXX    X    X    XXXXXXX    XXXXXXX    XXXXXXX       X       XXXXXXX    X    XX
//----------------------------------------------------------------------------------------

// Sadly, did not have time to come up with a solution to repeating the collisions. They are not exact copy and pastes, but the similarities are evident.
//--------------------------------------------------------------
void GameEngine::checkSkeletonCollision() {
    
    for (int i = 0; i < spells.size(); i++) {
        
        if (spells[i].from_player) {
            
            if (is_skeleton_present) {
                
                for (int j = skeletons.size()-1; j >= 0 ; j--) {
                    
                    if (ofDist(spells[i].pos.x, spells[i].pos.y, skeletons[j].pos.x, skeletons[j].pos.y) <
                        (skeletons[j].width/2 + spells[i].width/2)/2) {
                        
                        spells.erase(spells.begin()+i);
                        skeletons[j].lives--;
                        
                        if (skeletons[j].lives <= 0) {
                            is_enemy_dead = true;
                            death_player->play();
                            skeletons.clear();
                            is_skeleton_present = false;
                        }
                    }
                }
            }
        } else {
            
            if (ofDist(spells[i].pos.x, spells[i].pos.y, player.pos.x, player.pos.y) <
                (player.width/2 + spells[i].width/2)/2) {
                
                spells.erase(spells.begin()+i);
                checkPlayerStatus();
            }
        }
    }
}

//-------------------------------------------------------------
void GameEngine::spawnSkeleton() {
    
    skeleton_pos.x = kSpawn;
    skeleton_pos.y = kFloor;
    Skeleton skeleton;
    skeleton.pos = skeleton_pos;
    skeleton.setup(&skeleton_image);
    skeletons.push_back(skeleton);
    is_skeleton_present = true;
}

//--------------------------------------------------------------
void GameEngine::spawnSkeletonSpell() {
    
    for (int i = 0; i < skeletons.size(); i++) {
        if (skeletonNearPlayer()) {
            if (skeletons[i].time_to_shoot()) {
                
                Spell skeleton_spell;
                skeleton_spell.setup(false, false, skeletons[i].pos, skeletons[i].speed, &skeleton_spell_image);
                skeleton_spell.from_boss = false;
                spells.push_back(skeleton_spell);
                did_spell_cast = true;
                is_enemy_dead = false;
                did_get_upgrade = false;
                spell_player->play();
                spell_player->setLocation(0);
            }
        }
    }
}

//--------------------------------------------------------------
bool GameEngine::skeletonNearPlayer() {
    
    for (int i = 0; i < skeletons.size(); i++) {
        
        if (ofDist(player.pos.x, player.pos.y, skeletons[i].pos.x, skeletons[i].pos.y) < kAggro_range) {
            return true;
        }
    }
    return false;
}

//---------------------------------------------------------------------------------------
//   XXXXXXX    X    XXXXXX     XXXXXXX         XX    XX    XXXXXXX    XXXXXXX    XXXXXXX
//   X          X    X     X    X               X X  X X    X     X    X          X
//   XXXXXXX    X    XXXXXX     XXXXXXX         X  XX  X    XXXXXXX    X   XXX    XXXXXXX
//   X          X    X    X     X               X      X    X     X    X     X    X
//   X          X    X     X    XXXXXXX         X      X    X     X    XXXXXXX    XXXXXXX
//---------------------------------------------------------------------------------------

//--------------------------------------------------------------
void GameEngine::checkFireMageCollision() {
    
    for (int i = 0; i < spells.size(); i++) {
        
        if (spells[i].from_player) {
            
            if (is_fmage_present) {
                
                for (int j = fire_mages.size()-1; j >= 0 ; j--) {
                    
                    if (ofDist(spells[i].pos.x, spells[i].pos.y, fire_mages[j].pos.x, fire_mages[j].pos.y) <
                        (fire_mages[j].width/2 + spells[i].width/2)/2) {
                        
                        spells.erase(spells.begin()+i);
                        
                        if (player_state == ICE) {
                            fire_mages[j].lives -= 2;
                        }
                        if (player_state == SHOCK) {
                            fire_mages[j].lives -= 1;
                        }
                        if (fire_mages[j].lives <= 0) {
                            is_enemy_dead = true;
                            death_player->play();
                            fire_mages.clear();
                            is_fmage_present = false;
                        }
                    }
                }
            }
        } else {
            
            if (ofDist(spells[i].pos.x, spells[i].pos.y, player.pos.x, player.pos.y) < (player.width/2 + spells[i].width/2)/2) {
                
                spells.erase(spells.begin()+i);
                checkPlayerStatus();
            }
        }
    }
}

//-------------------------------------------------------------
void GameEngine::spawnFireMage() {
    
    fmage_pos.x = kSpawn;
    fmage_pos.y = kFloor;
    FireMage fire_mage;
    fire_mage.pos = fmage_pos;
    fire_mage.setup(&fmage_image);
    fire_mages.push_back(fire_mage);
    is_fmage_present = true;
}

//--------------------------------------------------------------
void GameEngine::spawnFireMageSpell() {
    
    for (int i = 0; i < fire_mages.size(); i++) {
    
        if (fmageNearPlayer()) {
        
            if (fire_mages[i].time_to_shoot()) {
                
                Spell fmage_spell;
                fmage_spell.setup(false, false, fire_mages[i].pos, fire_mages[i].speed, &fmage_spell_image);
                fmage_spell.from_boss = false;
                spells.push_back(fmage_spell);
                did_spell_cast = true;
                is_enemy_dead = false;
                did_get_upgrade = false;
                spell_player->play();
                spell_player->setLocation(0);
            }
        }
    }
}

//--------------------------------------------------------------
bool GameEngine::fmageNearPlayer() {
    
    for (int i = 0; i < fire_mages.size(); i++) {
        
        if (ofDist(player.pos.x, player.pos.y, fire_mages[i].pos.x, fire_mages[i].pos.y) < kAggro_range) {
            return true;
        }
    }
    return false;
}

//---------------------------------------------------------------------------------------
//   X    XXXXXXX    XXXXXXX          XX    XX    XXXXXXX    XXXXXXX    XXXXXXX
//   X    X          X                X X  X X    X     X    X          X
//   X    X          XXXXXXX          X  XX  X    XXXXXXX    X   XXX    XXXXXXX
//   X    X          X                X      X    X     X    X     X    X
//   X    XXXXXXX    XXXXXXX          X      X    X     X    XXXXXXX    XXXXXXX
//---------------------------------------------------------------------------------------

void GameEngine::checkIceMageCollision() {
    
    for (int i = 0; i < spells.size(); i++) {
        
        if (spells[i].from_player) {
            
            if (is_ice_mage_present) {
                
                for (int j = ice_mages.size()-1; j >= 0 ; j--) {
                    
                    if (ofDist(spells[i].pos.x, spells[i].pos.y, ice_mages[j].pos.x, ice_mages[j].pos.y) <
                        (ice_mages[j].width/2 + spells[i].width/2)/2) {
                        
                        spells.erase(spells.begin()+i);
                        
                        if (player_state == SHOCK) {
                            ice_mages[j].lives -= 2;
                        }
                        
                        if (player_state == FIRE) {
                            ice_mages[j].lives -= 1;
                        }
                        
                        if (ice_mages[j].lives <= 0) {
                            is_enemy_dead = true;
                            death_player->play();
                            ice_mages.clear();
                            is_ice_mage_present = false;
                        }
                    }
                }
            }
        } else {
            
            if (ofDist(spells[i].pos.x, spells[i].pos.y, player.pos.x, player.pos.y) <
                (player.width/2 + spells[i].width/2)/2) {
                
                spells.erase(spells.begin()+i);
                checkPlayerStatus();
            }
        }
    }
}

//-------------------------------------------------------------
void GameEngine::spawnIceMage() {
    
    ice_mage_pos.x = kSpawn;
    ice_mage_pos.y = kFloor;
    IceMage ice_mage;
    ice_mage.pos = ice_mage_pos;
    ice_mage.setup(&ice_mage_image);
    ice_mages.push_back(ice_mage);
    is_ice_mage_present = true;
}

//--------------------------------------------------------------
void GameEngine::spawnIceMageSpell() {
    
    for (int i = 0; i < ice_mages.size(); i++) {
    
        if (iceMageNearPlayer()) {
        
            if (ice_mages[i].time_to_shoot()) {
            
                Spell ice_mage_spell;
                ice_mage_spell.setup(false, false, ice_mages[i].pos, ice_mages[i].speed, &ice_mage_spell_image);
                ice_mage_spell.from_boss = false;
                spells.push_back(ice_mage_spell);
                did_spell_cast = true;
                is_enemy_dead = false;
                did_get_upgrade = false;
                spell_player->play();
                spell_player->setLocation(0);
            }
        }
    }
}

//--------------------------------------------------------------
bool GameEngine::iceMageNearPlayer() {
    
    for (int i = 0; i < ice_mages.size(); i++) {
        
        if (ofDist(player.pos.x, player.pos.y, ice_mages[i].pos.x, ice_mages[i].pos.y) < kAggro_range) {
            return true;
        }
    }
    return false;
}

//---------------------------------------------------------------------------------------------------------
//    XXXXXXX    X     X    XXXXXXX    XXXXXXX    X    X          XX    XX    XXXXXXX    XXXXXXX    XXXXXXX
//    X          X     X    X     X    X          X   X           X X  X X    X     X    X          X
//    XXXXXXX    XXXXXXX    X     X    X          XXXX            X  XX  X    XXXXXXX    X   XXX    XXXXXXX
//          X    X     X    X     X    X          X   X           X      X    X     X    X     X    X
//    XXXXXXX    X     X    XXXXXXX    XXXXXXX    X    X          X      X    X     X    XXXXXXX    XXXXXXX
//---------------------------------------------------------------------------------------------------------

//--------------------------------------------------------------
void GameEngine::checkShockMageCollision() {
    
    for (int i = 0; i < spells.size(); i++) {
        
        if (spells[i].from_player) {
            
            if (is_smage_present) {
                
                for (int j = shock_mages.size()-1; j >= 0 ; j--) {
                    
                    if (ofDist(spells[i].pos.x, spells[i].pos.y, shock_mages[j].pos.x, shock_mages[j].pos.y) <
                        (shock_mages[j].width/2 + spells[i].width/2)/2) {
                        
                        spells.erase(spells.begin()+i);
                        
                        if (player_state == FIRE) {
                            shock_mages[j].lives -= 2;
                        }
                        
                        if (player_state == ICE) {
                            shock_mages[j].lives -= 1;
                        }
                        
                        if (shock_mages[j].lives <= 0) {
                            is_enemy_dead = true;
                            death_player->play();
                            shock_mages.clear();
                            is_smage_present = false;
                        }
                    }
                }
            }
        } else {
            
            if (ofDist(spells[i].pos.x, spells[i].pos.y, player.pos.x, player.pos.y) <
                (player.width/2 + spells[i].width/2)/2) {
                
                spells.erase(spells.begin()+i);
                checkPlayerStatus();
            }
        }
    }
}

//-------------------------------------------------------------
void GameEngine::spawnShockMage() {
    
    smage_pos.x = kSpawn;
    smage_pos.y = kFloor;
    ShockMage shock_mage;
    shock_mage.pos = smage_pos;
    shock_mage.setup(&smage_image);
    shock_mages.push_back(shock_mage);
    is_smage_present = true;
}



//--------------------------------------------------------------
void GameEngine::spawnShockMageSpell() {
    
    for (int i = 0; i < shock_mages.size(); i++) {
    
        if (smageNearPlayer()) {
        
            if (shock_mages[i].time_to_shoot()) {
            
                Spell smage_spell;
                smage_spell.setup(false, false, shock_mages[i].pos, shock_mages[i].speed, &smage_spell_image);
                smage_spell.from_boss = false;
                spells.push_back(smage_spell);
                did_spell_cast = true;
                is_enemy_dead = false;
                did_get_upgrade = false;
                spell_player->play();
                spell_player->setLocation(0);
            }
        }
    }
}

//--------------------------------------------------------------
bool GameEngine::smageNearPlayer() {
    
    for (int i = 0; i < shock_mages.size(); i++) {
        
        if (ofDist(player.pos.x, player.pos.y, shock_mages[i].pos.x, shock_mages[i].pos.y) < kAggro_range) {
            return true;
        }
    }
    return false;
}

//------------------------------------------------------------------
//    XXXXXXX    XXXXXX     XXXXXXX    XXXXXXX    XXXXXXX    XXXXXXX
//    X          X     X    X          X             X       X
//    X          XXXXXX     XXXXXXX    XXXXXXX       X       XXXXXXX
//    X          X    X     X                X       X             X
//    XXXXXXX    X     X    XXXXXXX    XXXXXXX       X       XXXXXXX
//------------------------------------------------------------------

//--------------------------------------------------------------
void GameEngine::spawnCrest() {
    
    if (game_state == IN_PROGRESS) {
        crest_pos.x = kSpawn;
        crest_pos.y = kUpper_spawn;
    }
    if (game_state == FINALBOSS) {
        crest_pos.x = 450;
        crest_pos.y = kUpper_spawn;
    }
    Crest crest;
    crest.crest_state = crest_state;
    
    if (crest.crest_state == FIRE) {
        crest.setup(&fire_crest_image);
        
    } else if (crest.crest_state == ICE) {
        crest.setup(&ice_crest_image);
        
    } else {
        crest.setup(&shock_crest_image);
    }
    crest.pos = crest_pos;
    crests.push_back(crest);
}

//-----------------------------------------------------------------
void GameEngine::interactCrest() {
    
    for (int i = 0; i < crests.size(); i++) {
        
        if (ofDist(player.pos.x, player.pos.y, crests[i].pos.x, crests[i].pos.y) <= (player.width/2 + crests[i].width/2)/2) {
            
            did_spell_cast =false;
            is_enemy_dead = false;
            did_get_upgrade = true;
            upgrade_player->play();
            
            if (crests[i].crest_state == FIRE && player_state != FIRE) {
                player_state = FIRE;
                
            } else if (crests[i].crest_state == ICE && player_state != ICE) {
                player_state = ICE;
                
            } else if (crests[i].crest_state == SHOCK && player_state != SHOCK) {
                player_state = SHOCK;
            }
            crests.clear();
        }
    }
}

//---------------------------------------------------------------------------------------------------
//    XXXXXXX    X    XX    X    XXXXXXX    X                XXXXXX     XXXXXXX    XXXXXXX    XXXXXXX
//    X          X    X X   X    X     X    X                X     X    X     X    X          X
//    XXXXXXX    X    X  X  X    XXXXXXX    X                XXXXXX     X     X    XXXXXXX    XXXXXXX
//    X          X    X   X X    X     X    X                X     X    X     X          X          X
//    X          X    X    XX    X     X    XXXXXXX          XXXXXX     XXXXXXX    XXXXXXX    XXXXXXX
//---------------------------------------------------------------------------------------------------

//--------------------------------------------------------------
void GameEngine::spawnFinalBoss() {
    
    boss_pos.x = kSpawn;
    boss_pos.y = kBoss_y;
    FinalBoss fb;
    fb.pos = boss_pos;
    fb.setup(&final_boss_image);
    final_boss.push_back(fb);
    is_fb_present = true;
}

// The reason why this one is a lot nastier is because the math done by the machine doesn't use the same values when the player in on a different platform. ofDist() uses pythagoras' theorem to calculate distance. I accomadated this by adding 300 onto the onFloor boolean to mimic onUpper boolean
//--------------------------------------------------------------
void GameEngine::checkBossCollision() {
    
    for (int i = 0; i < spells.size(); i++) {

        if (spells[i].from_player) {

            if (is_fb_present) {

                for (int j = final_boss.size()-1; j >= 0 ; j--) {
                    
                    if (onUpper) {

                        if (ofDist(spells[i].pos.x, spells[i].pos.y, final_boss[j].pos.x, final_boss[j].pos.y) <
                            (final_boss[j].width + spells[i].width/2)/2) {

                            spells.erase(spells.begin()+i);
                            checkBossState();
                            checkFBStatus();
                        }
                    } else {
                        if (ofDist(spells[i].pos.x, spells[i].pos.y, final_boss[j].pos.x, final_boss[j].pos.y+300) < (final_boss[j].width + spells[i].width/2)/2) {
                            
                            spells.erase(spells.begin()+i);
                            checkBossState();
                            checkFBStatus();
                        }
                    }
                }
            }
        } else {
            
            if (ofDist(spells[i].pos.x, spells[i].pos.y, player.pos.x, player.pos.y) < (player.width + spells[i].width)/2) {
                spells.erase(spells.begin()+i);
                
                checkPlayerStatus();
            }
        }
    }
}

//--------------------------------------------------------------
void GameEngine::spawnBossSpell() {
    
    for (int i = 0; i < final_boss.size(); i++) {
        
        for (int i = 0; i < 5; i++) {
            
            boss_spell_pos.x = ofRandom(0, 900);
            boss_spell_pos.y = 0;
            
            if (final_boss[i].time_to_shoot()) {
                
                Spell bs;
                bs.setup(false, false, boss_spell_pos, 2, &boss_spell_image);
                bs.from_boss = true;
                spells.push_back(bs);
            }
        }
    }
}

//--------------------------------------------------------------
void GameEngine::updateBossState() {
    
    if (final_boss[0].lives == 100) {
        final_boss[0].boss_state = SHOCK;
        final_boss_image.load("FinalBossShock.png");
        boss_spell_image.load("BossSShock.png");
        final_boss[0].shoot_interval = 2.5;
        if (player_state != FIRE) {
            spawnBonusLives();
            crest_state = FIRE;
            spawnCrest();
        }
    }
    if (final_boss[0].lives == 50) {
        final_boss[0].boss_state = FIRE;
        final_boss_image.load("FinalBossFire.png");
        boss_spell_image.load("BossSFire.png");
        final_boss[0].shoot_interval = 2;
        if (player_state != ICE) {
            spawnBonusLives();
            crest_state = ICE;
            spawnCrest();
        }

    }
    if (final_boss[0].lives == 0) {
        final_boss[0].boss_state = ROT;
        final_boss_image.load("FinalBossFinal.png");
        boss_spell_image.load("BossSRot.png");
    }
}

//--------------------------------------------------------------
void GameEngine::checkBossState() {
    
    if (player_state == ICE && final_boss[0].boss_state == FIRE) {
        final_boss[0].lives--;
    }
    if (player_state == FIRE && final_boss[0].boss_state == SHOCK) {
        final_boss[0].lives--;
    }
    if (player_state == SHOCK && final_boss[0].boss_state == ICE) {
        final_boss[0].lives--;
    }
    if (final_boss[0].boss_state == ROT) {
        final_boss[0].flives--;
        final_boss[0].shoot_interval -= 0.015;
    }
}

//--------------------------------------------------------------
void GameEngine::checkFBStatus() {
    
    if (game_state == FINALBOSS) {
        if (final_boss[0].lives <= 0) {
            game_state = INTERMISSION;
            player_state = ROT;
            final_boss[0].shoot_interval = 3;
        }
    } else if (game_state == FINALBOSS2) {
        if (final_boss[0].flives <= 0) {
            is_enemy_dead = true;
            death_player->play();
            final_boss.clear();
            is_fb_present = false;
            game_state = FINISHED;
        }
    }
}
