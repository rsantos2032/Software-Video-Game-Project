//
//  GameEngine.h
//  Final Project
//
//  Created by Rolando Santos on 12/5/18.
//

#ifndef GameEngine_h
#define GameEngine_h
#include "ofMain.h"
#include "Player.h"
#include "Spell.h"
#include "Skeleton.h"
#include "FireMage.h"
#include "IceMage.h"
#include "ShockMage.h"
#include "Crest.h"
#include "ElementState.h"
#include "Lives.h"
#include "Ladder.h"
#include "FinalBoss.h"
#include "ofxATK.hpp"

enum GameState {
    START,
    IN_PROGRESS,
    PAUSED,
    FINALBOSS,
    INTERMISSION,
    FINALBOSS2,
    FINISHED
};

class GameEngine {
    
public:
    
    GameState game_state;
    
    // Player functions
    ElementState player_state;
    Player player;
    vector<Spell> spells;
    bool is_shield_up;
    bool is_player_right;
    void spawnPlayerSpell();
    void updateSpells();
    void checkPlayerStatus();
    
    // All methods to reassign player or world images
    void loadImages();
    void setPlayerImageRight();
    void setPlayerImageLeft();
    void setPlayerShieldRight();
    void setPlayerShieldLeft();
    void setPlayerSpellRight();
    void setPlayerSpellLeft();
    
    // Constants
    const float kPlatform_x = 64.0f;
    const float kPlatform_y = 550.0f;
    const int kSpell_size = 50;
    const int kPlatform_num = 31;
    const float kPlatform_limit_lower = -64.0;
    const float kPlatform_limit_upper = 1920.0;
    const int kUPlatform_num = 7;
    const int kUPlatform_show = 18;
    const float kUPlatform_y = 300;
    const float kPlayer_upper = 200;
    const float kUpper_spawn = 200;
    const float kBoss_y = 150.0;
    const float kFloor = 450.0;
    const float kSpawn = 1100.0;
    const float kAggro_range = 450;
    const float kSpeed = 10.0;
    const int kEnemy_movement = 5;
    
    // All variables and methods are for Skeleton enemies only
    vector<Skeleton> skeletons;
    vector<int> skeleton_spawn = {0,200,400,600,700,800};
    bool is_skeleton_present = false;
    void checkSkeletonCollision();
    void spawnSkeleton();
    void spawnSkeletonSpell();
    bool skeletonNearPlayer();
    ofPoint skeleton_pos;
    ofImage skeleton_spell_image;
    ofImage skeleton_image;
    
    // All variables and methods are for Fire Mages only
    vector<FireMage> fire_mages;
    vector<int> fmage_spawn = {450,500,575};
    bool is_fmage_present;
    void checkFireMageCollision();
    void spawnFireMage();
    void spawnFireMageSpell();
    bool fmageNearPlayer();
    ofPoint fmage_pos;
    ofImage fmage_spell_image;
    ofImage fmage_image;
    
    // All variables and methods are for Ice Mages only
    vector<IceMage> ice_mages;
    vector<int> ice_mage_spawn = {50,150,300,375};
    bool is_ice_mage_present;
    void checkIceMageCollision();
    void spawnIceMage();
    void spawnIceMageSpell();
    bool iceMageNearPlayer();
    ofPoint ice_mage_pos;
    ofImage ice_mage_spell_image;
    ofImage ice_mage_image;
    
    // All variables and methods are for Shock Mages only
    vector<ShockMage> shock_mages;
    vector<int> smage_spawn = {100,175,650,750};
    bool is_smage_present;
    void checkShockMageCollision();
    void spawnShockMage();
    void spawnShockMageSpell();
    bool smageNearPlayer();
    ofPoint smage_pos;
    ofImage smage_spell_image;
    ofImage smage_image;
    
    // Final boss
    bool is_fb_present = false;
    ofImage final_boss_image;
    ofPoint boss_pos;
    vector<FinalBoss> final_boss;
    ElementState boss_state;
    vector<int> boss_spawn = {967};
    void spawnFinalBoss();
    void checkBossCollision();
    void checkBossState();
    void updateBossState();
    void spawnBossSpell();
    ofImage boss_spell_image;
    ofPoint boss_spell_pos;
    void checkFBStatus();
    
    // Crest spawns
    ofImage fire_crest_image;
    ofImage ice_crest_image;
    ofImage shock_crest_image;
    ofPoint crest_pos;
    vector<int> fcrest_spawn = {40};
    vector<int> icrest_spawn = {440};
    vector<int> screst_spawn = {240, 940};
    vector<Crest> crests;
    ElementState crest_state;
    void spawnCrest();
    void interactCrest();
    bool atCrest();
    
    
    // Platforms
    vector<int> upper_platform_spawn{0, 200, 400, 900};
    ofImage platform[31];
    ofImage lower_platform_image;
    ofVec2f platformxy[31];
    void spawnLowerPlatform();
    void spawnUpperPlatform();
    
    ofImage u_platform[7];
    ofImage upper_platform_image;
    ofVec2f u_platformxy[7];
    
    // All player and player-related images
    ofImage player_image;
    
    ofImage player_fright;
    ofImage player_iright;
    ofImage player_sright;
    ofImage player_rright;
    ofImage player_fleft;
    ofImage player_ileft;
    ofImage player_sleft;
    ofImage player_rleft;
    
    ofImage player_fright_spell;
    ofImage player_iright_spell;
    ofImage player_sright_spell;
    ofImage player_fleft_spell;
    ofImage player_ileft_spell;
    ofImage player_sleft_spell;
    ofImage player_rleft_spell;
    ofImage player_rright_spell;
    
    ofImage player_fright_shield;
    ofImage player_iright_shield;
    ofImage player_sright_shield;
    ofImage player_fleft_shield;
    ofImage player_ileft_shield;
    ofImage player_sleft_shield;
    ofImage player_rleft_shield;
    ofImage player_rright_shield;
    
    ofImage spell_image;
    
    // Menu Screeens 
    ofImage start_screen_image;
    ofImage background_image;
    ofImage pause_menu;
    ofImage story_menu;
    ofImage death_menu;
    ofImage victory_menu;
    ofImage intermission_menu;
    
    //Use a the counter for visual cues
    int counter = 0;

    void pauseGame();
    
    // Lives
    vector<Lives> lives;
    ofImage life_image;
    void drawLives();
    void updateLives();
    
    // Ladder
    vector<int> ladder_spawn = {25, 225, 425, 925};
    ofPoint ladder_pos;
    vector<Ladder> ladders;
    ofImage ladder_image;
    void spawnLadder();
    bool atLadder;
    bool onLadder = false;
    bool onFloor = true;
    bool onUpper = false;
    void interactLadderUp();
    void interactLadderDown();
    
    void playerMoveLeft();
    void playerMoveRight();
    
    // Bonus Lives
    vector<Lives> bonus_lives;
    void spawnBonusLives();
    void checkBLCollision();
    ofPoint bl_pos;
    vector<int> bonus_lives_spawn = {10, 210, 410, 910};
    
    void checkContactCollision();
    
    // Sound
    void setupSound();
    SoundFile *spell_file;
    SoundPlayer *spell_player;
    SoundFile *death_file;
    SoundPlayer *death_player;
    SoundFile *upgrade_file;
    SoundPlayer *upgrade_player;
    
    bool is_enemy_dead = false;
    bool did_spell_cast = false;
    bool did_get_upgrade = false;
    
    void spawnAll();
    void drawAll();
    
    bool is_pause;
    
    void spellPressed();
};


#endif /* GameEngine_h */
