# Project Proposal

## What is it?

For my final project I will go with a 2d side-scroller game. The concept will be similar to the original Mario games with a bit of a twist. In essence the player controls a character that is able to cast spells. There is a single room, and the player must eliminate all enemies in a room to complete the level. However, different enemies can only be beaten by a certain spell type. Similar to how mushrooms work in Mario. The player will need use crests to obtain a power up to be able to cast certain spells. An example would be an enemy being only susceptible to frost spells, and immune to all others. The game will include sound as well.

## Libraries

### *A Sound Library*

ofxATK is what I'll be using for the audio of my game. There are different sound effects that I would like to implement and this library would help me with doing so. The sound library would be useful for: 

* Sound effects for each NPC enemy
* Sound effects for when a spell hits the environment and/or enemy
* Background music for each map.

## Libraries that I am Considering

### *An Image Library*

The reason I am considering an image library is primarily for the background image of the game. The Graphics of this game will be one of my larger obstacles to overcome and using a background image library can this a lot simpler. I am considering using cairo.

## Difficulties 

The primary difficulty I see approaching this project is the graphics. My character and enemy design are pixelated characters similar to the one of the earlier Mario games. 

*https://www.noupe.com/wp-content/uploads/2012/06/super-mario-bros-2.png*

This is an examply of the look I am going for. Once the graphics are complete, the second difficulty would be getting the mechanics of the game to work as intended. The sound will then be implemented during the middle-final stages of the project.

## Features

Features I intend to implement in my game are:

* A basic user interface around the edges of the screen that shows the player lives
* The player is able to change states after using an upgrade item.
* The player is able to collect upgrades. If the player currently has the ice upgrade and touches a fire upgrade, the fire upgrade will overwrite the ice upgrade. The player can also collect extra lives scattered around the map.
* Instead of jumping, the player will use ladders.

## Stretch Goals

* Adding more Random Number Generation (RNG) in the game so that upgrades will be scattered randomly through each playthrough. 
* Better enemy AI. NPCs will become more aggressive if they are the only ones left in the room. Likewise enemies with an immunity to the player's current upgrade will also behave aggressively. Enemies who are vulnerable to the player's current upgrade will try to dodge/ avoid fighting the player.
* Adding bosses to the end of every level.
* Adding additional levels with different unique themes

## Final Thoughts

Originally I was considering a more dynamic action game, however I believe that it would be too difficult in the time I have to implement it. I even see this game could probably be a lot of work as well. I liked the idea of creating a 2d platformer and it was the first thing that came to mind after I played the Snake Game in this week's assignment. If I'm able to overcome the primary challenges of the mechanics and graphics, then everything else should come into place nicely.


