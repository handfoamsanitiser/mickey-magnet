#include "raylib.h"
#include <vector>

#include "globals.hpp"
#include "player.hpp"
#include "anchor.hpp"


// #define PLATFORM_WEB
#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif


Player player(200, 200, true);

void UpdateDrawFrame();

int main() {
    InitWindow(1440, 810, "Mick");

    anchors.push_back(Anchor(500, 500, 1, true));
    
#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 60, 1);
#else
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        UpdateDrawFrame();
    }
#endif

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

