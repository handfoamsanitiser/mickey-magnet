#include "player.hpp"
#include <cmath>
#include <vector>
#include "raymath.h"
#include "globals.hpp"

Player::Player(int x, int y, bool isEnabled): 
    pos(Vector2 { (float)x, (float)y }),
    vel(Vector2 { 0, 0 }),
    rotation(0),
    radius(100),
    isEnabled(isEnabled) {}

void Player::Update() {
    if (!isEnabled) return;

    // update position
    pos.x += vel.x * GetFrameTime() * 50;
    pos.y += vel.y * GetFrameTime() * 50;

    Drag();
    AnchorInteract();
    SpikeInteract();
    ClampVel();
}

void Player::Render() {
    if (!isEnabled) return;
    // DrawCircle(pos.x, pos.y, radius, RED);
    // DrawPoly(Vector2 { pos.x, pos.y }, 4, radius / 3, rotation * 180/PI, BLACK);

    DrawTexturePro(playerBase, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)radius * 2, (float)radius * 2 }, Vector2 { (float)radius, (float)radius }, 0, WHITE);
    DrawTexturePro(playerBody, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)radius * 2, (float)radius * 2 }, Vector2 { (float)radius, (float)radius }, rotation * 180/PI + 90, WHITE);
    DrawTexturePro(playerFace, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)radius * 2, (float)radius * 2 }, Vector2 { (float)radius, (float)radius }, 0, WHITE);
}

void Player::Drag() {
    // drag
    if (vel.x < 0) {
        vel.x = std::min(vel.x + PLAYER_DRAG * GetFrameTime(), 0.0f);
    } else if (vel.x > 0){
        vel.x = std::max(vel.x - PLAYER_DRAG * GetFrameTime(), 0.0f);
    }

    if (vel.y < 0) {
        vel.y = std::min(vel.y + PLAYER_DRAG * GetFrameTime(), 0.0f);
    } else if (vel.y > 0){
        vel.y = std::max(vel.y - PLAYER_DRAG * GetFrameTime(), 0.0f);
    }
}

void Player::AnchorInteract() {
    // targeting detection
    rotation = atan2((GetMouseY() - pos.y), (GetMouseX() - pos.x));

    for (int i = 0; i < (int)anchors.size(); ++i) {
        float dist = Vector2Distance(pos, anchors[i].pos);
        float xDiff = dist * cos(rotation);
        float yDiff = dist * sin(rotation);
        Vector2 dir = Vector2Normalize(Vector2Subtract(GetMousePosition(), pos));

        Vector2 final1 = { pos.x + xDiff, pos.y + yDiff };
        Vector2 final2 = { pos.x - xDiff, pos.y - yDiff };
    
        // reset white colour of anchor before collison check
        anchors[i].isActive = false;
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            // forward check (red)
            if (CheckCollisionPointCircle(final1, anchors[i].pos, anchors[i].radius)) {
                anchors[i].isActive = true;
                if (anchors[i].isRed) {
                    vel = Vector2Add(vel, Repel(anchors[i].strength, dir, xDiff, yDiff, dist)); 
                } else {
                    vel = Vector2Add(vel, Attract(anchors[i].strength, dir, xDiff, yDiff, dist)); 
                }
            }

            // backward check (blue)
            if (CheckCollisionPointCircle(final2, anchors[i].pos, anchors[i].radius)) {
                anchors[i].isActive = true;
                if (anchors[i].isRed) {
                    vel = Vector2Add(vel, Attract(anchors[i].strength, dir, -xDiff, -yDiff, dist)); 
                } else {
                    vel = Vector2Add(vel, Repel(anchors[i].strength, dir, -xDiff, -yDiff, dist)); 
                }
            }
        }
    }
}

void Player::SpikeInteract() {
    // targeting detection
    rotation = atan2((GetMouseY() - pos.y), (GetMouseX() - pos.x));

    for (int i = 0; i < (int)spikes.size(); ++i) {
        float dist = Vector2Distance(pos, spikes[i].pos);
        float xDiff = dist * cos(rotation);
        float yDiff = dist * sin(rotation);
        Vector2 dir = Vector2Normalize(Vector2Subtract(GetMousePosition(), pos));

        Vector2 final1 = { pos.x + xDiff, pos.y + yDiff };
        Vector2 final2 = { pos.x - xDiff, pos.y - yDiff };
    
        // reset animation of spike before collison check
        spikes[i].isActive = false;
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            // forward check (red)
            if (CheckCollisionPointCircle(final1, spikes[i].pos, spikes[i].radius)) {
                spikes[i].isActive = true;
                if (spikes[i].isRed) {
                    vel = Vector2Add(vel, Repel(spikes[i].strength, dir, xDiff, yDiff, dist));
                    spikes[i].vel = Vector2Add(spikes[i].vel, Attract(spikes[i].strength, dir, xDiff, yDiff, dist));
                } else {
                    vel = Vector2Add(vel, Attract(spikes[i].strength, dir, xDiff, yDiff, dist)); 
                    spikes[i].vel = Vector2Add(spikes[i].vel, Repel(spikes[i].strength, dir, xDiff, yDiff, dist));
                }
            }

            // backward check (blue)
            if (CheckCollisionPointCircle(final2, spikes[i].pos, spikes[i].radius)) {
                spikes[i].isActive = true;
                if (spikes[i].isRed) {
                    vel = Vector2Add(vel, Attract(spikes[i].strength, dir, -xDiff, -yDiff, dist)); 
                    spikes[i].vel = Vector2Add(spikes[i].vel, Attract(spikes[i].strength, dir, xDiff, yDiff, dist));
                } else {
                    vel = Vector2Add(vel, Repel(spikes[i].strength, dir, -xDiff, -yDiff, dist));
                    spikes[i].vel = Vector2Add(spikes[i].vel, Repel(spikes[i].strength, dir, xDiff, yDiff, dist));
                }
            }
        }
    }
}

Vector2 Player::Attract(int strength, Vector2 dir, float xDiff, float yDiff, float dist) {
    float accX = strength * dir.x * GetFrameTime() * Clamp(Remap(dist, 0, MAX_DISTANCE, 1, 0), MIN_PLAYER_ACC_MULT, 1);
    float accY = strength * dir.y * GetFrameTime() * Clamp(Remap(dist, 0, MAX_DISTANCE, 1, 0), MIN_PLAYER_ACC_MULT, 1);
    if (xDiff < 0) {
        accX = -abs(accX);
    } else {
        accX = abs(accX);
    }

    if (yDiff < 0) {
        accY = -abs(accY);
    } else {
        accY = abs(accY);
    }

    return Vector2 { accX, accY };
}

Vector2 Player::Repel(int strength, Vector2 dir, float xDiff, float yDiff, float dist) {
    float accX = strength * -dir.x * GetFrameTime() * Clamp(Remap(dist, 0, MAX_DISTANCE, 1, 0), MIN_PLAYER_ACC_MULT, 1);
    float accY = strength * -dir.y * GetFrameTime() * Clamp(Remap(dist, 0, MAX_DISTANCE, 1, 0), MIN_PLAYER_ACC_MULT, 1);
    if (xDiff < 0) {
        accX = abs(accX);
    } else {
        accX = -abs(accX);
    }

    if (yDiff < 0) {
        accY = abs(accY);
    } else {
        accY = -abs(accY);
    }

    return Vector2 { accX, accY };
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

void Player::ClampPos() {
    
}