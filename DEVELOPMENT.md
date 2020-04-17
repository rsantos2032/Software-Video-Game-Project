# DEVELOPMENT

## WEEK 1
* Nov 12: Created the Player Class of my game. Used a placeholder image.
* Nov 13: Added the ability for the character to face another direction when the right or left key is pressed
* Nov 13: Added the ability for a character to shoot a fireball 
* Nov 13: The fireball moves in the direction that the player is facing
* Nov 14: Added an enemy image.
* Nov 14: Added a pause menu
* Overall Amount of Time Spent: 6 ~ 8 hours

## Thanksgiving and Week 2
* Thanksgiving Break: Mainly tried playing around with OpenFrameworks libraries like Box2d, but decided not to use it
* Nov 28: Instead of the character moving around the screen, made it so that the world moves and the character is in the center (like classic Mario.
* Nov 28: Created the counter system. When a player moves a certain distance this causes events to occurs
* Dec 1: Enemies spawn depending on the where the player is facing (this feature was removed). Enemies now properly "die".
* Overall Amount of Time Spent: 4 ~ 5 hours

## Week 3
* Dec 3: Added the shield mechanic
* Dec 3: Got enemies to shoot projectiles
* Dec 4: Enemies start attacking once the player is a certain distance away from them
* Dec 4: The player can now lose lives. Enemy life mechanics are added.
* Dec 5: Added a Parent class for all enemies and proper constants
* Dec 5: Fire Mages and Skeletons are fully implemented
* Dec 5: All Enemy types are implemented
* Dec 5: Game Engine is created. ofApp was used as a pseudo game engine for earlier parts of the project
* Dec 5: Implemented the player states: FIRE, ICE, SHOCK
* Dec 5: Crest system is added and the player can now press a key and is given an upgrade
* Dec 5: BackTracking was fixed (this feature wasn't utilized, I found out it worked by accident and touched it up a bit. Crests were originally not meant to disappear after use but this changed in the final version)
* Dec 5: Code Cleanup, etc.
* Dec 6: Played around with different graphic and sound libraries. Unable to use a lot of the graphics ones because of an apparent issue with GLSL Shaders and OSX
* Dec 7: Art was done for the project as well as finding Background Music
* Dec 8: Added the player health onto the UI to track your status
* Overall Amount of Time Spent: 16 ~ 20 hours

## Week 4
* Dec 11: Implemented the Ladder System
* Dec 11: Bonus lives implemeented. Unlike crests the player automatically consumes it when there's contact
* Dec 11: Player/Enemy physical contact implemented. This makes the player instantly die if they come into contact with an enemy. This is to enforce ranged combat.
* Dec 11: Implementing sound library ofxATK
* Dec 11: Spell and death sounds added
* Dec 12: Menu art and code cleaning
* Dec 12: Started to implement Final Boss Stage
* Dec 12: Got spell collision with Final Boss done (this gave me a lot of trouble), added another state ROT (boss only).
* Dec 12: Boss shoots a hail of spells onto players, got the collision to work
* Dec 12: Started to work on level design to show all features
* Dec 12: Game Mechanics are completed. Final Artwork done
* Dec 12: Code Cleanup is done for the semi-final time.
* Dec 12: Was able to quickly squeeze in another stage for the boss fight with an intermission phase. This is the final project version.
* Overall Amount of Time Spent: 12 ~ 14 hours
