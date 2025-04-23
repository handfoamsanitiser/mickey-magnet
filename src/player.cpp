#include "player.hpp"
#include <cmath>
#include <vector>
#include "raymath.h"

#include "globals.hpp"
#include "anchor.hpp"

const float PLAYER_MAX_SPEED = 10;
const float PLAYER_DRAG = 0.05;
const float MAX_DISTANCE = 800;

Player::Player(int x, int y, bool isEnabled): 
    pos(Vector2 { (float)x, (float)y }),
    vel(Vector2 { 0, 0 }),
    rotation(0),
    radius(50),
    isEnabled(isEnabled) {}

void Player::Update() {
    if (!isEnabled) return;

    // update position
    pos.x += vel.x * GetFrameTime() * 50;
    pos.y += vel.y * GetFrameTime() * 50;

    Drag();
    Accelerate();
    ClampVel();
}

void Player::Render() {
    if (!isEnabled) return;
    DrawText(TextFormat("Rotation: %f", rotation), 0, 0, 20, BLACK);
    DrawText(TextFormat("Rotation: %f", vel.x), 0, 20, 20, BLACK);
    DrawText(TextFormat("Rotation: %f", vel.y), 0, 40, 20, BLACK);
    DrawCircle(pos.x, pos.y, radius, RED);
    DrawPoly(Vector2 { pos.x, pos.y }, 4, radius / 3, rotation * 180/PI, BLACK);
}

void Player::Drag() {
    // drag
    if (vel.x < 0) {
        vel.x = std::min(vel.x + PLAYER_DRAG, 0.0f);
    } else if (vel.x > 0){
        vel.x = std::max(vel.x - PLAYER_DRAG, 0.0f);
    }

    if (vel.y < 0) {
        vel.y = std::min(vel.y + PLAYER_DRAG, 0.0f);
    } else if (vel.y > 0){
        vel.y = std::max(vel.y - PLAYER_DRAG, 0.0f);
    }
}

void Player::Accelerate() {
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
                float accX = anchors[i].strength * (xDiff / (xDiff + yDiff)) * GetFrameTime() * 10/** Clamp(Remap(dist, 0, MAX_DISTANCE, 1, 0), 0.5, 1)*/;
                float accY = anchors[i].strength * (yDiff / (xDiff + yDiff)) * GetFrameTime() * 10/** Clamp(Remap(dist, 0, MAX_DISTANCE, 1, 0), 0.5, 1)*/;
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

void Player::ClampVel() {
    // clamp velocity
    if (vel.x < 0 && vel.x < -PLAYER_MAX_SPEED) {
        vel.x = -PLAYER_MAX_SPEED;
    } else if (vel.x > 0 && vel.x > PLAYER_MAX_SPEED){
        vel.x = PLAYER_MAX_SPEED;
    }

    if (vel.y < 0 && vel.y < -PLAYER_MAX_SPEED) {
        vel.y = -PLAYER_MAX_SPEED;
    } else if (vel.y > 0 && vel.y > PLAYER_MAX_SPEED){
        vel.y = PLAYER_MAX_SPEED;
    }
}