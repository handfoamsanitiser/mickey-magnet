#include "raylib.h"
#include <vector>

#include "globals.hpp"
#include "player.hpp"
#include "anchor.hpp"


// #define PLATFORM_WEB
#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif


Player player(500, 400, true);

void UpdateDrawFrame();

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Mick");

    playerBase = LoadTextureFromImage(LoadImage("resources/magnet/magnet-base.png"));
    playerBody = LoadTextureFromImage(LoadImage("resources/magnet/magnet-body.png"));
    playerFace = LoadTextureFromImage(LoadImage("resources/magnet/magnet-face.png"));

    redAnchor1 = LoadTextureFromImage(LoadImage("resources/red-anchor/red-anchor-1.png"));
    redAnchor2 = LoadTextureFromImage(LoadImage("resources/red-anchor/red-anchor-2.png"));
    redAnchor3 = LoadTextureFromImage(LoadImage("resources/red-anchor/red-anchor-3.png"));
    redAnchor4 = LoadTextureFromImage(LoadImage("resources/red-anchor/red-anchor-4.png"));

    blueAnchor1 = LoadTextureFromImage(LoadImage("resources/blue-anchor/blue-anchor-1.png"));
    blueAnchor2 = LoadTextureFromImage(LoadImage("resources/blue-anchor/blue-anchor-2.png"));
    blueAnchor3 = LoadTextureFromImage(LoadImage("resources/blue-anchor/blue-anchor-3.png"));
    blueAnchor4 = LoadTextureFromImage(LoadImage("resources/blue-anchor/blue-anchor-4.png"));

    anchors.push_back(Anchor(500, 500, 1, false));
    anchors.push_back(Anchor(800, 600, 1, true));
    
#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 60, 1);
#else
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        UpdateDrawFrame();
    }
#endif

    UnloadTexture(playerBase);
    UnloadTexture(playerBody);
    UnloadTexture(playerFace);

    UnloadTexture(redAnchor1);
    UnloadTexture(redAnchor2);
    UnloadTexture(redAnchor3);
    UnloadTexture(redAnchor4);

    UnloadTexture(blueAnchor1);
    UnloadTexture(blueAnchor2);
    UnloadTexture(blueAnchor3);
    UnloadTexture(blueAnchor4);

    CloseWindow();
    return 0;
}

void UpdateDrawFrame() {
    player.Update();

    BeginDrawing();
        ClearBackground(RAYWHITE);
        for (Anchor anchor : anchors) {
            anchor.Render();
        }
        player.Render();
    EndDrawing();
}

