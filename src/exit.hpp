#pragma once
#include "raylib.h"

class Exit {
public:
    Exit(int x, int y);

    void Render();

    Vector2 pos;
};