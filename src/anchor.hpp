#pragma once
#include "raylib.h"

class Anchor {
public:
    Anchor(int x, int y, int radius, int strength, bool isRed);
    static void UpdateAnimation();
    void Render();

    Vector2 pos;
    int radius;
    int strength;
    bool isRed;
};