#include "anchor.hpp"

Anchor::Anchor(int x, int y, int strength, bool isRed): 
    pos(Vector2 { (float)x, (float)y }), 
    strength(strength),
    isRed(isRed) {}

void Anchor::Render() {
    if (isRed) {
        DrawCircle(pos.x, pos.y, strength * 50, RED);
    } else {
        DrawCircle(pos.x, pos.y, strength * 50, BLUE);
    }
}