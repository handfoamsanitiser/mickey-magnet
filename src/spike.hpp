#pragma once
#include "raylib.h"

class Spike {
public:
    Spike(int x, int y, int radius, int strength, bool isRed);
    static void UpdateAnimation();

    void Update();
    void Render();

    Vector2 pos;
    int radius;
    int strength;
    bool isRed;

private:
    void Drag();
};