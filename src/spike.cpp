#include "spike.hpp"
#include "globals.hpp"

Spike::Spike(int x, int y, bool isRed): 
    pos(Vector2 { (float)x, (float)y }),
    vel(Vector2 { 0.0f, 0.0f }),
    radius(59),
    spriteRadius(60),
    strength(15),
    isRed(isRed),
    isActive(false),
    isEnabled(false),
    isVisible(true) {}

void Spike::UpdateAnimation() {
    spikeAnimationTimer += GetFrameTime();
    if (spikeAnimationTimer > SPIKE_ANIMATION_TIME) {
        spikeAnimationTimer -= SPIKE_ANIMATION_TIME;
        spikeAnimationFrame = (spikeAnimationFrame + 1) % 2;

        if (star.isCollected && star.isVisible) {
            star.cyclesSinceCollected++;
            if (star.cyclesSinceCollected > 1) {
                star.isVisible = false;
            }
        }
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
        switch (spikeAnimationFrame) {
            case 0:
                DrawTexturePro(redSpike1, Rectangle { 22, 21, 61, 57 }, Rectangle { pos.x, pos.y, (float)spriteRadius * 2, (float)spriteRadius * 2 }, Vector2 { (float)spriteRadius, (float)spriteRadius}, 0, WHITE);
                break;
            case 1:
                DrawTexturePro(redSpike2, Rectangle { 22, 21, 58, 61 }, Rectangle { pos.x, pos.y, (float)spriteRadius * 2, (float)spriteRadius * 2 }, Vector2 { (float)spriteRadius, (float)spriteRadius}, 0, WHITE);
                break;
            default:
                break;
        }
    } else {
        switch (spikeAnimationFrame) {
            case 0:
                DrawTexturePro(blueSpike1, Rectangle { 22, 21, 61, 57 }, Rectangle { pos.x, pos.y, (float)spriteRadius * 2, (float)spriteRadius * 2 }, Vector2 { (float)spriteRadius, (float)spriteRadius}, 0, WHITE);
                break;
            case 1:
                DrawTexturePro(blueSpike2, Rectangle { 22, 21, 58, 61 }, Rectangle { pos.x, pos.y, (float)spriteRadius * 2, (float)spriteRadius * 2 }, Vector2 { (float)spriteRadius, (float)spriteRadius}, 0, WHITE);
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
    if (pos.x - radius < 0) {
        pos.x = radius;
        vel.x = 0;
    } else if (pos.x + radius > SCREEN_WIDTH) {
        pos.x = SCREEN_WIDTH - radius;
        vel.x = 0;
    }

    if (pos.y - radius < 0) {
        pos.y = radius;
        vel.y = 0;
    } else if (pos.y + radius > SCREEN_HEIGHT) {
        pos.y = SCREEN_HEIGHT - radius;
        vel.y = 0;
    }
}