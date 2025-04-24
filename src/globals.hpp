#pragma once
#include <vector>
#include "anchor.hpp"
#include "spike.hpp"

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

extern std::vector<Anchor> anchors;
extern const float ANCHOR_ANIMATION_TIME;
extern float anchorAnimationTimer;
extern int anchorAnimationFrame;

extern std::vector<Spike> spikes;
extern int spikeAnimationFrame;
extern float spikeAnimationTimer;
extern float curSpikeAnimationTime;
extern const float BASE_SPIKE_ANIMATION_TIME;

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