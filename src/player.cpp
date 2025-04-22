#include "player.hpp"
#include <cmath>

Player::Player(int x, int y, bool isEnabled): 
    pos(Vector2 { (float) x, (float) y }),
    vel(Vector2 { 0, 0 }),
    acc(Vector2 { 0, 0 }),
    rotation(0),
    radius(50),
    speed(10),
    isEnabled(isEnabled) {}

void Player::Update() {
    rotation = atan((GetMouseY() - pos.y) / (GetMouseX() - pos.x)) * 180/PI;
}

void Player::Render() {
    DrawText(TextFormat("Thing: %f", rotation), 0, 0, 20, BLACK);
    DrawCircle(pos.x, pos.y, radius, RED);
    DrawPoly(Vector2 { pos.x, pos.y }, 4, radius / 3, rotation, BLACK);
}