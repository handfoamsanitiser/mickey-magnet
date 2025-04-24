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
    bool isEnabled;

    

private:
    void Drag();
    void Accelerate();
    void ClampVel();

    Vector2 Attract(int strength, Vector2 dir, float xDiff, float yDiff);
    Vector2 Repel(int strength, Vector2 dir, float xDiff, float yDiff);
};

extern const float PLAYER_MAX_SPEED;
extern const float PLAYER_DRAG;
extern const float MAX_DISTANCE;