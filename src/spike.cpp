#include "spike.hpp"
#include "globals.hpp"

Spike::Spike(int x, int y, int radius, int strength, bool isRed): 
    pos(Vector2 { (float)x, (float)y }),
    radius(radius),
    strength(strength),
    isRed(isRed) {}

void Spike::UpdateAnimation() {
    spikeAnimationTimer += GetFrameTime();
    if (spikeAnimationTimer > SPIKE_ANIMATION_TIME) {
        spikeAnimationTimer -= SPIKE_ANIMATION_TIME;
        spikeAnimationFrame = (spikeAnimationFrame + 1) % 2;
    }
}

void Spike::Update() {
    
}

void Spike::Render() {

}