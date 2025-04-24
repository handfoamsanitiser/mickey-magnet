#include "globals.hpp"

const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

std::vector<Anchor> anchors;
int anchorAnimationFrame = 0;
float anchorAnimationTimer = 0.0f;
const float ANCHOR_ANIMATION_TIME = 0.25f;

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