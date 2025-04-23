#pragma once
#include "raylib.h"

class Anchor {
public:
    Anchor(int x, int y, int strength, bool isRed);
    void Render();

    Vector2 pos;
    int strength;
    bool isRed;
};