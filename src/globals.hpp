#pragma once
#include <vector>
#include "player.hpp"
#include "anchor.hpp"
#include "spike.hpp"
#include "rock.hpp"
#include "exit.hpp"
#include "star.hpp"

// game
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

extern int curLevel;
extern const int NUM_LEVELS;

// player
extern Player player;
extern const float PLAYER_MAX_SPEED;
extern const float PLAYER_MIN_SPEED;
extern const float PLAYER_DRAG;
extern const float MAX_DISTANCE;
extern const float MIN_PLAYER_ACC_MULT;

// anchors
extern std::vector<Anchor> anchors;
extern const float ANCHOR_ANIMATION_TIME;
extern float anchorAnimationTimer;
extern int anchorAnimationFrame;

// spikes
extern std::vector<Spike> spikes;
extern const int SPIKE_RADIUS;
extern int spikeAnimationFrame;
extern float spikeAnimationTimer;
extern const float SPIKE_ANIMATION_TIME;

// rocks
extern std::vector<Rock> rocks;

// exit
extern Exit levelExit;

// star
extern Star star;
extern int starsCollected;

// textures
extern Texture2D playerBody1;
extern Texture2D playerBody2;
extern Texture2D playerBody3;
extern Texture2D playerBody4;

extern Texture2D redArm1;
extern Texture2D redArm2;
extern Texture2D redArm3;

extern Texture2D blueArm1;
extern Texture2D blueArm2;
extern Texture2D blueArm3;

extern Texture2D playerBase;
extern Texture2D playerBody;
extern Texture2D playerFace;

extern Texture2D redAnchor1;
extern Texture2D redAnchor2;
extern Texture2D redAnchor3;
extern Texture2D redAnchor4;

extern Texture2D blueAnchor1;
extern Texture2D blueAnchor2;
extern Texture2D blueAnchor3;
extern Texture2D blueAnchor4;

extern Texture2D whiteAnchor1;
extern Texture2D whiteAnchor2;
extern Texture2D whiteAnchor3;
extern Texture2D whiteAnchor4;

extern Texture2D redSpike1;
extern Texture2D redSpike2;

extern Texture2D blueSpike1;
extern Texture2D blueSpike2;

extern Texture2D greySpike1;
extern Texture2D greySpike2;

extern Texture2D exit1;
extern Texture2D exit2;
extern Texture2D exit3;
extern Texture2D exit4;

extern Texture2D star1;
extern Texture2D star2;
extern Texture2D star3;

extern Texture2D cursor1;
extern Texture2D cursor2;