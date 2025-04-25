#pragma once
#include "raylib.h"

class Rock {
public:
    Rock(int x, int y);

    void Render();

    Vector2 pos;
    int radius;
    int spriteRadius;
    bool isVisible;

private:
};