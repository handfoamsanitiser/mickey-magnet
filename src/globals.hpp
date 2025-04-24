#pragma once
#include <vector>
#include "anchor.hpp"

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

extern std::vector<Anchor> anchors;
extern int anchorAnimationFrame;
extern float anchorAnimationTimer;
extern const float ANCHOR_ANIMATION_TIME;

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