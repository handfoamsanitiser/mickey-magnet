#pragma once
#include "raylib.h"

class Spike {
public:
    Spike(int x, int y, bool isRed);
    static void UpdateAnimation();

    void Update();
    void Render();

    Vector2 pos;
    Vector2 vel;
    int radius;
    int spriteRadius;
    int strength;
    bool isRed;
    bool isActive;
    bool isEnabled;

private:
    void Drag();
    void ClampVel();
    void ClampPos();
};