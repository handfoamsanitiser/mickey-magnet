#include "star.hpp"
#include "globals.hpp"

Star::Star(int x, int y):
    pos(Vector2 { (float)x, (float)y}),
    cyclesSinceCollected(0),
    isCollected(false),
    isVisible(true) {}

void Star::Render() {
    if (!isVisible) return;

    if (isCollected) {
        DrawTexturePro(star3, Rectangle { 0, 0, 50, 50 }, Rectangle { pos.x, pos.y, (float)STAR_SPRITE_RADIUS * 2, (float)STAR_SPRITE_RADIUS * 2 }, Vector2 { (float)STAR_SPRITE_RADIUS, (float)STAR_SPRITE_RADIUS}, 0, WHITE);
    } else {
        switch (spikeAnimationFrame) {
            case 0:
                DrawTexturePro(star1, Rectangle { 0, 0, 50, 50 }, Rectangle { pos.x, pos.y, (float)STAR_SPRITE_RADIUS * 2, (float)STAR_SPRITE_RADIUS * 2 }, Vector2 { (float)STAR_SPRITE_RADIUS, (float)STAR_SPRITE_RADIUS}, 0, WHITE);
                break;
            case 1:
                DrawTexturePro(star2, Rectangle { 0, 0, 50, 50 }, Rectangle { pos.x, pos.y, (float)STAR_SPRITE_RADIUS * 2, (float)STAR_SPRITE_RADIUS * 2 }, Vector2 { (float)STAR_SPRITE_RADIUS, (float)STAR_SPRITE_RADIUS}, 0, WHITE);
                break;
            default:
                break;
        }
    }
}