#pragma once
#include "raylib.h"

class Spike {
public:
    Spike(int x, int y, int radius, int strength, bool isRed);
    static void UpdateAnimation();

    void Update();
    void Render();

    Vector2 pos;
    Vector2 vel;
    int radius;
    int strength;
    bool isRed;
    bool isActive;
    bool isEnabled;

private:
    void Drag();
    void ClampVel();
    void ClampPos();
};