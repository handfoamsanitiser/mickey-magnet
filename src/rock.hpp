#pragma once
#include "raylib.h"

class Rock {
public:
    Rock(int x, int y);
    Rock(int x, int y, Vector2 point1, Vector2 point2, float speed);

    void Update();
    void Render();

    Vector2 pos;
    bool isVisible;

    bool isMovable;
    Vector2 point1;
    Vector2 point2;
    float speed;

    bool dir;

private:
};