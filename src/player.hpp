#pragma once
#include "raylib.h"


class Player {
public:
    Player(int x, int y);

    void Update();
    void Render();

    Vector2 pos;
    Vector2 vel;
    float rotation;
    bool isEnabled;
    bool isDead;
    bool isRedActive;
    bool isBlueActive;

private:
    void Drag();
    void AnchorInteract();
    void SpikeInteract();
    void RockInteract();
    void ExitInteract();
    void StarInteract();

    void PlayRandomMagnetSound();

    Vector2 Attract(int strength, Vector2 dir, float xDiff, float yDiff, float dist);
    Vector2 Repel(int strength, Vector2 dir, float xDiff, float yDiff, float dist);

    void ClampVel();
    void ClampPos();
};