#include "exit.hpp"
#include "globals.hpp"

Exit::Exit(int x, int y):
    pos(Vector2 { (float)x, (float)y }),
    radius(70),
    spriteRadius(140) {}

void Exit::Render() {
    // switch (anchorAnimationFrame) {
    //     case 0:
    //         DrawTexturePro(exit1, Rectangle { 13, 9, 79, 85 }, Rectangle { pos.x, pos.y, (float)spriteRadius * 2, (float)spriteRadius * 2 }, Vector2 { (float)spriteRadius, (float)spriteRadius}, 0, WHITE);
    //         break;
    //     case 1:
    //         DrawTexturePro(exit2, Rectangle { 5, 12, 89, 81 }, Rectangle { pos.x, pos.y, (float)spriteRadius * 2, (float)spriteRadius * 2 }, Vector2 { (float)spriteRadius, (float)spriteRadius}, 0, WHITE);
    //         break;
    //     case 2:
    //         DrawTexturePro(exit3, Rectangle { 12, 14, 78, 74 }, Rectangle { pos.x, pos.y, (float)spriteRadius * 2, (float)spriteRadius * 2 }, Vector2 { (float)spriteRadius, (float)spriteRadius}, 0, WHITE);
    //         break;
    //     case 3: 
    //         DrawTexturePro(exit4, Rectangle { 12, 16, 77, 76 }, Rectangle { pos.x, pos.y, (float)spriteRadius * 2, (float)spriteRadius * 2 }, Vector2 { (float)spriteRadius, (float)spriteRadius}, 0, WHITE);
    //         break;
    //     default:
    //         break;
    // }
    switch (anchorAnimationFrame) {
        case 0:
            DrawTexturePro(exit1, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)spriteRadius * 2, (float)spriteRadius * 2 }, Vector2 { (float)spriteRadius, (float)spriteRadius}, 0, WHITE);
            break;
        case 1:
            DrawTexturePro(exit2, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)spriteRadius * 2, (float)spriteRadius * 2 }, Vector2 { (float)spriteRadius, (float)spriteRadius}, 0, WHITE);
            break;
        case 2:
            DrawTexturePro(exit3, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)spriteRadius * 2, (float)spriteRadius * 2 }, Vector2 { (float)spriteRadius, (float)spriteRadius}, 0, WHITE);
            break;
        case 3: 
            DrawTexturePro(exit4, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)spriteRadius * 2, (float)spriteRadius * 2 }, Vector2 { (float)spriteRadius, (float)spriteRadius}, 0, WHITE);
            break;
        default:
            break;
    }
}