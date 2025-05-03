#include "globals.hpp"

// game
const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

Vector2 mousePos = Vector2 { 0, 0 };

int curLevel = 1;
const int NUM_LEVELS = 10;

// player
Player player(-1000, -1000);
const int PLAYER_RADIUS = 33;
const int PLAYER_SPRITE_RADIUS = 100;
const float PLAYER_MAX_SPEED = 8;
const float PLAYER_MIN_SPEED = 0.05f;
const float PLAYER_DRAG = 3;
const float MAX_DISTANCE = 800;
const float MIN_PLAYER_ACC_MULT = 0.5f;

// anchors
std::vector<Anchor> anchors;
const int ANCHOR_RADIUS = 50;
const float ANCHOR_ANIMATION_TIME = 0.25f;
float anchorAnimationTimer = 0.0f;
int anchorAnimationFrame = 0;

// spikes
std::vector<Spike> spikes;
const int SPIKE_RADIUS = 59;
const int SPIKE_SPRITE_RADIUS = 60;
int spikeAnimationFrame = 0;
float spikeAnimationTimer = 0.0f;
const float SPIKE_ANIMATION_TIME = 1.0f;

// rocks
std::vector<Rock> rocks;

// exit
Exit levelExit(-1000, -1000);
const int EXIT_RADIUS = 80;
const int EXIT_SPRITE_RADIUS = 140;
bool isExitOn = true;

// star
Star star(-1000, -1000);
const int STAR_RADIUS = 50;
const int STAR_SPRITE_RADIUS = 50;
int starsCollected = 0;

// sounds
Sound buttonSound;
Sound deathSound;
Sound finishSound;
Sound magnetSound;
Sound magnetStartSound;
Sound magnetEndSound;
bool isMagnetSoundPlaying = false;
bool isMagneting = false;
bool wasMagnetingLastUpdate = false;
Sound starSound;
Sound unmagnetSound;

// textures
Texture2D playerBody1;
Texture2D playerBody2;
Texture2D playerBody3;
Texture2D playerBody4;

Texture2D redArm1;
Texture2D redArm2;
Texture2D redArm3;

Texture2D blueArm1;
Texture2D blueArm2;
Texture2D blueArm3;

Texture2D playerBase;
Texture2D playerBody;
Texture2D playerFace;

Texture2D redAnchor1;
Texture2D redAnchor2;
Texture2D redAnchor3;
Texture2D redAnchor4;

Texture2D blueAnchor1;
Texture2D blueAnchor2;
Texture2D blueAnchor3;
Texture2D blueAnchor4;

Texture2D whiteAnchor1;
Texture2D whiteAnchor2;
Texture2D whiteAnchor3;
Texture2D whiteAnchor4;

Texture2D redSpike1;
Texture2D redSpike2;
Texture2D redSpike3;

Texture2D blueSpike1;
Texture2D blueSpike2;
Texture2D blueSpike3;

Texture2D greySpike1;
Texture2D greySpike2;

Texture2D exit1;
Texture2D exit2;
Texture2D exit3;
Texture2D exit4;

Texture2D exitOff1;
Texture2D exitOff2;
Texture2D exitOff3;
Texture2D exitOff4;

Texture2D star1;
Texture2D star2;
Texture2D star3;

Texture2D cursor1;
Texture2D cursor2;