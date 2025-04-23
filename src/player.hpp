#pragma once
#include "raylib.h"

class Player {
public:
    Player(int x, int y, bool isEnabled);

    void Update();
    void Render();

    Vector2 pos;
    Vector2 vel;
    float rotation;
    int radius;
    int speed;
    bool isEnabled;

    bool c;
};