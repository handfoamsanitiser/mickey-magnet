#include "rock.hpp"
#include "globals.hpp"

Rock::Rock(int x, int y):
    pos(Vector2 { (float)x, (float)y }),
    radius(50),
    spriteRadius(60),
    isEnabled(true) {}

void Rock::Render() {
    if (!isEnabled) return;

    switch (spikeAnimationFrame) {
        case 0:
            DrawTexturePro(greySpike1, Rectangle { 22, 21, 61, 57 }, Rectangle { pos.x, pos.y, (float)spriteRadius * 2, (float)spriteRadius * 2 }, Vector2 { (float)spriteRadius, (float)spriteRadius}, 0, WHITE);
            break;
        case 1:
            DrawTexturePro(greySpike2, Rectangle { 22, 21, 58, 61 }, Rectangle { pos.x, pos.y, (float)spriteRadius * 2, (float)spriteRadius * 2 }, Vector2 { (float)spriteRadius, (float)spriteRadius}, 0, WHITE);
            break;
        default:
            break;
    }

}