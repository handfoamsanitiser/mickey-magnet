#include "player.hpp"
#include <cmath>
#include <vector>
#include "raymath.h"

#include "globals.hpp"
#include "anchor.hpp"

Player::Player(int x, int y, bool isEnabled): 
    pos(Vector2 { (float)x, (float)y }),
    vel(Vector2 { 0, 0 }),
    rotation(0),
    radius(50),
    speed(10),
    isEnabled(isEnabled) {}

void Player::Update() {
    if (!isEnabled) return;
    rotation = atan2((GetMouseY() - pos.y), (GetMouseX() - pos.x));

    for (int i = 0; i < (int)anchors.size(); ++i) {
        float dist = Vector2Distance(pos, anchors[i].pos);
        float xDiff = dist * cos(rotation);
        float yDiff = dist * sin(rotation);

        Vector2 final = { pos.x + xDiff, pos.y + yDiff };

        anchors[i].isRed = true;
        if (CheckCollisionPointCircle(final, anchors[i].pos, anchors[i].strength * 50)) {
            anchors[i].isRed = false;
        }
    }
}

void Player::Render() {
    if (!isEnabled) return;
    DrawText(TextFormat("Rotation: %f", rotation), 0, 0, 20, BLACK);
    DrawCircle(pos.x, pos.y, radius, RED);
    DrawPoly(Vector2 { pos.x, pos.y }, 4, radius / 3, rotation * 180/PI, BLACK);
}