#pragma once
#include <vector>
#include "player.hpp"
#include "anchor.hpp"
#include "spike.hpp"
#include "rock.hpp"

// game
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

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
extern int spikeAnimationFrame;
extern float spikeAnimationTimer;
extern float curSpikeAnimationTime;
extern const float BASE_SPIKE_ANIMATION_TIME;

// rocks
extern std::vector<Rock> rocks;

// exit

// stars

// textures
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