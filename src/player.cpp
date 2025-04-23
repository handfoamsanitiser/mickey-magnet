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

    // update position
    pos.x += vel.x;
    pos.y += vel.y;

    // targeting detection
    rotation = atan2((GetMouseY() - pos.y), (GetMouseX() - pos.x));

    for (int i = 0; i < (int)anchors.size(); ++i) {
        float dist = Vector2Distance(pos, anchors[i].pos);
        float xDiff = dist * cos(rotation);
        float yDiff = dist * sin(rotation);

        Vector2 final = { pos.x + xDiff, pos.y + yDiff };

        anchors[i].isRed = true;
        if (CheckCollisionPointCircle(final, anchors[i].pos, anchors[i].strength * 50)) {
            anchors[i].isRed = false;

            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                float accX = anchors[i].strength * (xDiff / (xDiff + yDiff)) / 100;
                float accY = anchors[i].strength * (yDiff / (xDiff + yDiff)) / 100;
                if (xDiff < 0) {
                    accX = -abs(accX);
                } else {
                    accX = abs(accX);
                }

                if (yDiff < 0) {
                    accY = -abs(accY);
                } else {
                    accY = abs(accX);
                }

                vel.x += accX;
                vel.y += accY;
            }
        }
    }
}

void Player::Render() {
    if (!isEnabled) return;
    DrawText(TextFormat("Rotation: %f", rotation), 0, 0, 20, BLACK);
    DrawCircle(pos.x, pos.y, radius, RED);
    DrawPoly(Vector2 { pos.x, pos.y }, 4, radius / 3, rotation * 180/PI, BLACK);
}