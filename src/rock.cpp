#include "rock.hpp"
#include "globals.hpp"
#include "raymath.h"

Rock::Rock(int x, int y):
    pos(Vector2 { (float)x, (float)y }),
    isMovable(false) {}

Rock::Rock(int x, int y, Vector2 point1, Vector2 point2, float speed):
    pos(Vector2 { (float)x, (float)y }),
    isMovable(true),
    point1(point1),
    point2(point2),
    speed(speed),
    dir(false) {}

void Rock::Update() {
    if (!isMovable) return;

    if (dir) {
        Vector2 nextPos = Vector2Add(Vector2Scale(Vector2Negate(Vector2Normalize(Vector2Subtract(pos, point2))), speed * GetFrameTime()), pos);
        pos.x = Clamp(nextPos.x, point1.x, point2.x);
        pos.y = Clamp(nextPos.y, point1.y, point2.y);

        if (Vector2Equals(pos, point2)) {
            dir = false;
        }
    } else {
        Vector2 nextPos = Vector2Add(Vector2Scale(Vector2Negate(Vector2Normalize(Vector2Subtract(pos, point1))), speed * GetFrameTime()), pos);
        pos.x = Clamp(nextPos.x, point1.x, point2.x);
        pos.y = Clamp(nextPos.y, point1.y, point2.y);

        if (Vector2Equals(pos, point1)) {
            dir = true;
        }
    } 
}

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