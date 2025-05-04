#pragma once
#include "raylib.h"

class Button {
public:
    Button(int x, int y, int w, int h, const char *text, int fontSize, bool isEnabled);

    bool isClicked();
    void Render();

    const char *text;
    int fontSize;
    bool isEnabled;

    Rectangle rec;
};