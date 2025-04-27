#include "anchor.hpp"
#include "raymath.h"
#include <cmath>
#include "globals.hpp"

Anchor::Anchor(int x, int y, bool isRed): 
    pos(Vector2 { (float)x, (float)y }),
    strength(15),
    isRed(isRed),
    isActive(false) {}

void Anchor::UpdateAnimation() {
    anchorAnimationTimer += GetFrameTime();
    if (anchorAnimationTimer > ANCHOR_ANIMATION_TIME) {
        anchorAnimationTimer = remainder(anchorAnimationTimer, ANCHOR_ANIMATION_TIME);
        anchorAnimationFrame = (anchorAnimationFrame + 1) % 4;
    }
}

void Anchor::Render() {
    if (isActive) {
        switch (anchorAnimationFrame) {
            case 0:
                DrawTexturePro(whiteAnchor1, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)ANCHOR_RADIUS * 4, (float)ANCHOR_RADIUS * 4 }, Vector2 { (float)ANCHOR_RADIUS * 2, (float)ANCHOR_RADIUS * 2}, 0, WHITE);
                break;
            case 1:
                DrawTexturePro(whiteAnchor2, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)ANCHOR_RADIUS * 4, (float)ANCHOR_RADIUS * 4 }, Vector2 { (float)ANCHOR_RADIUS * 2, (float)ANCHOR_RADIUS * 2}, 0, WHITE);
                break;
            case 2:
                DrawTexturePro(whiteAnchor3, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)ANCHOR_RADIUS * 4, (float)ANCHOR_RADIUS * 4 }, Vector2 { (float)ANCHOR_RADIUS * 2, (float)ANCHOR_RADIUS * 2}, 0, WHITE);
                break;
            case 3: 
                DrawTexturePro(whiteAnchor4, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)ANCHOR_RADIUS * 4, (float)ANCHOR_RADIUS * 4 }, Vector2 { (float)ANCHOR_RADIUS * 2, (float)ANCHOR_RADIUS * 2}, 0, WHITE);
                break;
            default:
                break;
        }
        return;
    }

    if (isRed) {
        //DrawCircle(pos.x, pos.y, ANCHOR_RADIUS, RED);
        switch (anchorAnimationFrame) {
            case 0:
                DrawTexturePro(redAnchor1, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)ANCHOR_RADIUS * 4, (float)ANCHOR_RADIUS * 4 }, Vector2 { (float)ANCHOR_RADIUS * 2, (float)ANCHOR_RADIUS * 2}, 0, WHITE);
                break;
            case 1:
                DrawTexturePro(redAnchor2, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)ANCHOR_RADIUS * 4, (float)ANCHOR_RADIUS * 4 }, Vector2 { (float)ANCHOR_RADIUS * 2, (float)ANCHOR_RADIUS * 2}, 0, WHITE);
                break;
            case 2:
                DrawTexturePro(redAnchor3, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)ANCHOR_RADIUS * 4, (float)ANCHOR_RADIUS * 4 }, Vector2 { (float)ANCHOR_RADIUS * 2, (float)ANCHOR_RADIUS * 2}, 0, WHITE);
                break;
            case 3: 
                DrawTexturePro(redAnchor4, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)ANCHOR_RADIUS * 4, (float)ANCHOR_RADIUS * 4 }, Vector2 { (float)ANCHOR_RADIUS * 2, (float)ANCHOR_RADIUS * 2}, 0, WHITE);
                break;
            default:
                break;
        }
    } else {
        //DrawCircle(pos.x, pos.y, ANCHOR_RADIUS, BLUE);
        switch (anchorAnimationFrame) {
            case 0:
                DrawTexturePro(blueAnchor1, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)ANCHOR_RADIUS * 4, (float)ANCHOR_RADIUS * 4 }, Vector2 { (float)ANCHOR_RADIUS * 2, (float)ANCHOR_RADIUS * 2}, 0, WHITE);
                break;
            case 1:
                DrawTexturePro(blueAnchor2, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)ANCHOR_RADIUS * 4, (float)ANCHOR_RADIUS * 4 }, Vector2 { (float)ANCHOR_RADIUS * 2, (float)ANCHOR_RADIUS * 2}, 0, WHITE);
                break;
            case 2:
                DrawTexturePro(blueAnchor3, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)ANCHOR_RADIUS * 4, (float)ANCHOR_RADIUS * 4 }, Vector2 { (float)ANCHOR_RADIUS * 2, (float)ANCHOR_RADIUS * 2}, 0, WHITE);
                break;
            case 3: 
                DrawTexturePro(blueAnchor4, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)ANCHOR_RADIUS * 4, (float)ANCHOR_RADIUS * 4 }, Vector2 { (float)ANCHOR_RADIUS * 2, (float)ANCHOR_RADIUS * 2}, 0, WHITE);
                break;
            default:
                break;
        }
    }
}