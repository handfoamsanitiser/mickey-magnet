#include "globals.hpp"

const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

Player player(50, SCREEN_HEIGHT / 2, true);
const float PLAYER_MAX_SPEED = 7;
const float PLAYER_MIN_SPEED = 0.1f;
const float PLAYER_DRAG = 3;
const float MAX_DISTANCE = 1200;
const float MIN_PLAYER_ACC_MULT = 0.6f;

std::vector<Anchor> anchors;
extern const float ANCHOR_ANIMATION_TIME = 0.25f;
float anchorAnimationTimer = 0.0f;
int anchorAnimationFrame = 0;

std::vector<Spike> spikes;
int spikeAnimationFrame = 0;
float spikeAnimationTimer = 0.0f;
extern const float BASE_SPIKE_ANIMATION_TIME = 1.0f;
extern const float FAST_SPIKE_ANIMATION_TIME = 0.5f;
float curSpikeAnimationTime = BASE_SPIKE_ANIMATION_TIME;


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

Texture2D blueSpike1;
Texture2D blueSpike2;