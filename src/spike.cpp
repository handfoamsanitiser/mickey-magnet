#include "spike.hpp"
#include "raymath.h"
#include <cmath>
#include "globals.hpp"

Spike::Spike(int x, int y, bool isRed): 
    pos(Vector2 { (float)x, (float)y }),
    vel(Vector2 { 0.0f, 0.0f }),
    strength(15),
    isRed(isRed),
    isActive(false),
    isEnabled(false),
    isVisible(true) {}

void Spike::UpdateAnimation() {
    spikeAnimationTimer += GetFrameTime();
    if (spikeAnimationTimer > SPIKE_ANIMATION_TIME) {
        spikeAnimationTimer = remainder(spikeAnimationTimer, SPIKE_ANIMATION_TIME);
        spikeAnimationFrame = (spikeAnimationFrame + 1) % 2;
    }
}

void Spike::Update() {
    if (!isEnabled) return;

    pos.x += vel.x * GetFrameTime() * 50;
    pos.y += vel.y * GetFrameTime() * 50;

    ClampPos();
    //Drag();
    ClampVel();
}

void Spike::Render() {
    if (!isVisible) return;

    if (isRed) {
        if (isActive) {
            DrawTexturePro(redSpike3, Rectangle { 22, 21, 58, 61 }, Rectangle { pos.x, pos.y, (float)SPIKE_SPRITE_RADIUS * 2, (float)SPIKE_SPRITE_RADIUS * 2 }, Vector2 { (float)SPIKE_SPRITE_RADIUS, (float)SPIKE_SPRITE_RADIUS}, 0, WHITE);
            return;
        }
        switch (spikeAnimationFrame) {
            case 0:
                DrawTexturePro(redSpike1, Rectangle { 22, 21, 61, 57 }, Rectangle { pos.x, pos.y, (float)SPIKE_SPRITE_RADIUS * 2, (float)SPIKE_SPRITE_RADIUS * 2 }, Vector2 { (float)SPIKE_SPRITE_RADIUS, (float)SPIKE_SPRITE_RADIUS}, 0, WHITE);
                break;
            case 1:
                DrawTexturePro(redSpike2, Rectangle { 22, 21, 58, 61 }, Rectangle { pos.x, pos.y, (float)SPIKE_SPRITE_RADIUS * 2, (float)SPIKE_SPRITE_RADIUS * 2 }, Vector2 { (float)SPIKE_SPRITE_RADIUS, (float)SPIKE_SPRITE_RADIUS}, 0, WHITE);
                break;
            default:
                break;
        }
    } else {
        if (isActive) {
            DrawTexturePro(blueSpike3, Rectangle { 22, 21, 58, 61 }, Rectangle { pos.x, pos.y, (float)SPIKE_SPRITE_RADIUS * 2, (float)SPIKE_SPRITE_RADIUS * 2 }, Vector2 { (float)SPIKE_SPRITE_RADIUS, (float)SPIKE_SPRITE_RADIUS}, 0, WHITE);
            return;            
        }
        switch (spikeAnimationFrame) {
            case 0:
                DrawTexturePro(blueSpike1, Rectangle { 22, 21, 61, 57 }, Rectangle { pos.x, pos.y, (float)SPIKE_SPRITE_RADIUS * 2, (float)SPIKE_SPRITE_RADIUS * 2 }, Vector2 { (float)SPIKE_SPRITE_RADIUS, (float)SPIKE_SPRITE_RADIUS}, 0, WHITE);
                break;
            case 1:
                DrawTexturePro(blueSpike2, Rectangle { 22, 21, 58, 61 }, Rectangle { pos.x, pos.y, (float)SPIKE_SPRITE_RADIUS * 2, (float)SPIKE_SPRITE_RADIUS * 2 }, Vector2 { (float)SPIKE_SPRITE_RADIUS, (float)SPIKE_SPRITE_RADIUS}, 0, WHITE);
                break;
            default:
                break;
        }
    }
}

void Spike::Drag() {
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

void Spike::ClampVel() {
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

    // min velocity
    if (vel.x < 0 && vel.x > -PLAYER_MIN_SPEED) {
        vel.x = 0;
    } else if (vel.x > 0 && vel.x < PLAYER_MIN_SPEED) {
        vel.x = 0;
    }

    if (vel.y < 0 && vel.y > -PLAYER_MIN_SPEED) {
        vel.y = 0;
    } else if (vel.y > 0 && vel.y < PLAYER_MIN_SPEED) {
        vel.y = 0;
    }
}

void Spike::ClampPos() {
    if (pos.x - SPIKE_RADIUS< 0) {
        pos.x = SPIKE_RADIUS;
        vel.x = 0;
    } else if (pos.x + SPIKE_RADIUS > SCREEN_WIDTH) {
        pos.x = SCREEN_WIDTH - SPIKE_RADIUS;
        vel.x = 0;
    }

    if (pos.y - SPIKE_RADIUS < 0) {
        pos.y = SPIKE_RADIUS;
        vel.y = 0;
    } else if (pos.y + SPIKE_RADIUS > SCREEN_HEIGHT) {
        pos.y = SCREEN_HEIGHT - SPIKE_RADIUS;
        vel.y = 0;
    }
}