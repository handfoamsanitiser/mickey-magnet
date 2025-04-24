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

    playerBase = LoadTextureFromImage(LoadImage("resources/magnet-base.png"));
    playerBody = LoadTextureFromImage(LoadImage("resources/magnet-body.png"));
    playerFace = LoadTextureFromImage(LoadImage("resources/magnet-face.png"));

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

