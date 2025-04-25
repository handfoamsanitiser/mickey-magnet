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
    int spriteRadius;
    bool isEnabled;

private:
    void Drag();
    void AnchorInteract();
    void SpikeInteract();

    Vector2 Attract(int strength, Vector2 dir, float xDiff, float yDiff, float dist);
    Vector2 Repel(int strength, Vector2 dir, float xDiff, float yDiff, float dist);

    void ClampVel();
    void ClampPos();
};