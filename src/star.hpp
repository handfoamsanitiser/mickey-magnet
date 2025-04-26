#pragma once
#include "raylib.h"

class Star {
public:
    Star(int x, int y);

    void Render();

    Vector2 pos;
    int cyclesSinceCollected;
    bool isCollected;
    bool isVisible;
};