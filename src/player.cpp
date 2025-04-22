#include "player.hpp"

Player::Player(int x, int y, bool isEnabled): 
    pos(Vector2 { (float) x, (float) y }),
    vel(Vector2 { 0, 0 }),
    acc(Vector2 { 0, 0 }),
    rotation(0),
    radius(50),
    speed(10),
    isEnabled(isEnabled) {}

void Player::Update() {
    
}

void Player::Render() {
    DrawCircle(pos.x, pos.y, radius, RED);
}