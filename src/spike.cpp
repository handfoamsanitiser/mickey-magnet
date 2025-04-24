#include "spike.hpp"
#include "globals.hpp"

Spike::Spike(int x, int y, int radius, int strength, bool isRed): 
    pos(Vector2 { (float)x, (float)y }),
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