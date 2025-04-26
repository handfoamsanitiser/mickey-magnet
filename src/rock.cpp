#include "rock.hpp"
#include "globals.hpp"

Rock::Rock(int x, int y):
    pos(Vector2 { (float)x, (float)y }) {}

void Rock::Render() {
    switch (spikeAnimationFrame) {
        case 0:
            DrawTexturePro(greySpike1, Rectangle { 22, 21, 61, 57 }, Rectangle { pos.x, pos.y, (float)SPIKE_SPRITE_RADIUS * 2, (float)SPIKE_SPRITE_RADIUS * 2 }, Vector2 { (float)SPIKE_SPRITE_RADIUS, (float)SPIKE_SPRITE_RADIUS}, 0, WHITE);
            break;
        case 1:
            DrawTexturePro(greySpike2, Rectangle { 22, 21, 58, 61 }, Rectangle { pos.x, pos.y, (float)SPIKE_SPRITE_RADIUS * 2, (float)SPIKE_SPRITE_RADIUS * 2 }, Vector2 { (float)SPIKE_SPRITE_RADIUS, (float)SPIKE_SPRITE_RADIUS}, 0, WHITE);
            break;
        default:
            break;
    }
}