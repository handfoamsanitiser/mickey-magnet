#include "anchor.hpp"
#include "globals.hpp"

Anchor::Anchor(int x, int y, int radius, int strength, bool isRed): 
    pos(Vector2 { (float)x, (float)y }),
    radius(radius),
    strength(strength),
    isRed(isRed) {}

void Anchor::UpdateAnimation() {
    anchorAnimationTimer += GetFrameTime();
    if (anchorAnimationTimer > ANCHOR_ANIMATION_TIME) {
        anchorAnimationTimer -= ANCHOR_ANIMATION_TIME;
        anchorAnimationFrame = (anchorAnimationFrame + 1) % 4;
    }
}

void Anchor::Render() {
    if (isRed) {
        //DrawCircle(pos.x, pos.y, radius, RED);
        switch (anchorAnimationFrame) {
            case 0:
                DrawTexturePro(redAnchor1, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)radius * 4, (float)radius * 4 }, Vector2 { (float)radius * 2, (float)radius * 2}, 0, WHITE);
                break;
            case 1:
                DrawTexturePro(redAnchor2, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)radius * 4, (float)radius * 4 }, Vector2 { (float)radius * 2, (float)radius * 2}, 0, WHITE);
                break;
            case 2:
                DrawTexturePro(redAnchor3, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)radius * 4, (float)radius * 4 }, Vector2 { (float)radius * 2, (float)radius * 2}, 0, WHITE);
                break;
            case 3: 
                DrawTexturePro(redAnchor4, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)radius * 4, (float)radius * 4 }, Vector2 { (float)radius * 2, (float)radius * 2}, 0, WHITE);
                break;
            default:
                break;
        }
    } else {
        //DrawCircle(pos.x, pos.y, radius, BLUE);
        switch (anchorAnimationFrame) {
            case 0:
                DrawTexturePro(blueAnchor1, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)radius * 4, (float)radius * 4 }, Vector2 { (float)radius * 2, (float)radius * 2}, 0, WHITE);
                break;
            case 1:
                DrawTexturePro(blueAnchor2, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)radius * 4, (float)radius * 4 }, Vector2 { (float)radius * 2, (float)radius * 2}, 0, WHITE);
                break;
            case 2:
                DrawTexturePro(blueAnchor3, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)radius * 4, (float)radius * 4 }, Vector2 { (float)radius * 2, (float)radius * 2}, 0, WHITE);
                break;
            case 3: 
                DrawTexturePro(blueAnchor4, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)radius * 4, (float)radius * 4 }, Vector2 { (float)radius * 2, (float)radius * 2}, 0, WHITE);
                break;
            default:
                break;
        }
    }
}