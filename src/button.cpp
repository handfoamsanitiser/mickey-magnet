#include "button.hpp"
#include "globals.hpp"

Button::Button(int x, int y, int w, int h, const char *text, int fontSize, bool isEnabled):
    text(text),
    fontSize(fontSize),
    isEnabled(isEnabled),
    rec(Rectangle { (float)x, (float)y, (float)w, (float)h }) {}

bool Button::isClicked() {
    if (!isEnabled) return false;

    if (CheckCollisionPointRec(mousePos, rec) && IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        return true;
    }
    return false;
}

void Button::Render() {
    DrawTextEx(font, text, Vector2 { rec.x, rec.y }, fontSize, 0, WHITE);
}