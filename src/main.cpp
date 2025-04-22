#include "raylib.h"
#include "player.hpp"

// #define PLATFORM_WEB
#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif


Player player(0, 0, true);

void UpdateDrawFrame();

int main() {
    InitWindow(1440, 810, "Mick");
    

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
        player.Render();
    EndDrawing();
}

