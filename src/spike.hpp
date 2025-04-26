#pragma once
#include "raylib.h"

class Spike {
public:
    Spike(int x, int y, bool isRed);
    static void UpdateAnimation();

    void Drag();
    void Update();
    void Render();

    Vector2 pos;
    Vector2 vel;
    int strength;
    bool isRed;
    bool isActive;
    bool isEnabled;
    bool isVisible;

private:
    void ClampVel();
    void ClampPos();
};