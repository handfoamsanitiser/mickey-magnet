#include "spike.hpp"
#include "globals.hpp"

Spike::Spike(int x, int y, int radius, int strength, bool isRed): 
    pos(Vector2 { (float)x, (float)y }),
    vel(Vector2 { 0.0f, 0.0f }),
    radius(radius),
    strength(strength),
    isRed(isRed) {}

void Spike::UpdateAnimation() {
    spikeAnimationTimer += GetFrameTime();
    if (spikeAnimationTimer > BASE_SPIKE_ANIMATION_TIME) {
        spikeAnimationTimer -= BASE_SPIKE_ANIMATION_TIME;
        spikeAnimationFrame = (spikeAnimationFrame + 1) % 2;
    }
}

void Spike::Update() {
    pos.x += vel.x * GetFrameTime() * 50;
    pos.y += vel.y * GetFrameTime() * 50;

    Drag();
}

void Spike::Render() {
    if (isRed) {
        switch (spikeAnimationFrame) {
            case 0:
                DrawTexturePro(redSpike1, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)radius * 4, (float)radius * 4 }, Vector2 { (float)radius * 2, (float)radius * 2}, 0, WHITE);
                break;
            case 1:
                DrawTexturePro(redSpike2, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)radius * 4, (float)radius * 4 }, Vector2 { (float)radius * 2, (float)radius * 2}, 0, WHITE);
               break;
            default:
                break;
        }
    } else {
        switch (spikeAnimationFrame) {
            case 0:
                DrawTexturePro(blueSpike1, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)radius * 4, (float)radius * 4 }, Vector2 { (float)radius * 2, (float)radius * 2}, 0, WHITE);
                break;
            case 1:
                DrawTexturePro(blueSpike2, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)radius * 4, (float)radius * 4 }, Vector2 { (float)radius * 2, (float)radius * 2}, 0, WHITE);
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
}