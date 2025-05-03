#include "exit.hpp"
#include "globals.hpp"

Exit::Exit(int x, int y):
    pos(Vector2 { (float)x, (float)y }) {}

void Exit::Render() {
    // switch (anchorAnimationFrame) {
    //     case 0:
    //         DrawTexturePro(exit1, Rectangle { 13, 9, 79, 85 }, Rectangle { pos.x, pos.y, (float)EXIT_SPRITE_RADIUS * 2, (float)EXIT_SPRITE_RADIUS * 2 }, Vector2 { (float)EXIT_SPRITE_RADIUS, (float)EXIT_SPRITE_RADIUS}, 0, WHITE);
    //         break;
    //     case 1:
    //         DrawTexturePro(exit2, Rectangle { 5, 12, 89, 81 }, Rectangle { pos.x, pos.y, (float)EXIT_SPRITE_RADIUS * 2, (float)EXIT_SPRITE_RADIUS * 2 }, Vector2 { (float)EXIT_SPRITE_RADIUS, (float)EXIT_SPRITE_RADIUS}, 0, WHITE);
    //         break;
    //     case 2:
    //         DrawTexturePro(exit3, Rectangle { 12, 14, 78, 74 }, Rectangle { pos.x, pos.y, (float)EXIT_SPRITE_RADIUS * 2, (float)EXIT_SPRITE_RADIUS * 2 }, Vector2 { (float)EXIT_SPRITE_RADIUS, (float)EXIT_SPRITE_RADIUS}, 0, WHITE);
    //         break;
    //     case 3: 
    //         DrawTexturePro(exit4, Rectangle { 12, 16, 77, 76 }, Rectangle { pos.x, pos.y, (float)EXIT_SPRITE_RADIUS * 2, (float)EXIT_SPRITE_RADIUS * 2 }, Vector2 { (float)EXIT_SPRITE_RADIUS, (float)EXIT_SPRITE_RADIUS}, 0, WHITE);
    //         break;
    //     default:
    //         break;
    // }
    if (isExitOn) {
        switch (anchorAnimationFrame) {
            case 0:
                DrawTexturePro(exit1, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)EXIT_SPRITE_RADIUS * 2, (float)EXIT_SPRITE_RADIUS * 2 }, Vector2 { (float)EXIT_SPRITE_RADIUS, (float)EXIT_SPRITE_RADIUS}, 0, WHITE);
                break;
            case 1:
                DrawTexturePro(exit2, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)EXIT_SPRITE_RADIUS * 2, (float)EXIT_SPRITE_RADIUS * 2 }, Vector2 { (float)EXIT_SPRITE_RADIUS, (float)EXIT_SPRITE_RADIUS}, 0, WHITE);
                break;
            case 2:
                DrawTexturePro(exit3, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)EXIT_SPRITE_RADIUS * 2, (float)EXIT_SPRITE_RADIUS * 2 }, Vector2 { (float)EXIT_SPRITE_RADIUS, (float)EXIT_SPRITE_RADIUS}, 0, WHITE);
                break;
            case 3: 
                DrawTexturePro(exit4, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)EXIT_SPRITE_RADIUS * 2, (float)EXIT_SPRITE_RADIUS * 2 }, Vector2 { (float)EXIT_SPRITE_RADIUS, (float)EXIT_SPRITE_RADIUS}, 0, WHITE);
                break;
            default:
                break;
        }
    } else {
        switch (anchorAnimationFrame) {
            case 0:
                DrawTexturePro(exitOff1, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)EXIT_SPRITE_RADIUS * 2, (float)EXIT_SPRITE_RADIUS * 2 }, Vector2 { (float)EXIT_SPRITE_RADIUS, (float)EXIT_SPRITE_RADIUS}, 0, WHITE);
                break;
            case 1:
                DrawTexturePro(exitOff2, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)EXIT_SPRITE_RADIUS * 2, (float)EXIT_SPRITE_RADIUS * 2 }, Vector2 { (float)EXIT_SPRITE_RADIUS, (float)EXIT_SPRITE_RADIUS}, 0, WHITE);
                break;
            case 2:
                DrawTexturePro(exitOff3, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)EXIT_SPRITE_RADIUS * 2, (float)EXIT_SPRITE_RADIUS * 2 }, Vector2 { (float)EXIT_SPRITE_RADIUS, (float)EXIT_SPRITE_RADIUS}, 0, WHITE);
                break;
            case 3: 
                DrawTexturePro(exitOff4, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)EXIT_SPRITE_RADIUS * 2, (float)EXIT_SPRITE_RADIUS * 2 }, Vector2 { (float)EXIT_SPRITE_RADIUS, (float)EXIT_SPRITE_RADIUS}, 0, WHITE);
                break;
            default:
                break;
        }
    }
    
}