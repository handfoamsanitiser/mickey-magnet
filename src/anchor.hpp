#pragma once
#include "raylib.h"

class Anchor {
public:
    Anchor(int x, int y, bool isRed);
    static void UpdateAnimation();
    void Render();

    Vector2 pos;
    int strength;
    bool isRed;
    bool isActive;
};