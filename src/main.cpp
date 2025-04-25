#include "raylib.h"
#include <vector>

#include "globals.hpp"
#include "player.hpp"
#include "anchor.hpp"
#include "spike.hpp"
#include "rock.hpp"

// #define PLATFORM_WEB
#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

void UpdateDrawFrame();
void LoadTextures();
void UnloadTextures();

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Mick");
    InitAudioDevice();
    LoadTextures();

    anchors.push_back(Anchor(500, 500, 50, 15, false));
    anchors.push_back(Anchor(800, 600, 50, 15, true));

    spikes.push_back(Spike(1000, 800, 50, 10, true));
    spikes.push_back(Spike(70, 80, 50, 10, false));

    rocks.push_back(Rock(1300, 300));
    
#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 60, 1);
#else
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        UpdateDrawFrame();
    }
#endif

    UnloadTextures();
    CloseAudioDevice();
    CloseWindow();
    return 0;
}

void UpdateDrawFrame() {
    player.Update();
    for (int i = 0; i < (int)spikes.size(); ++i) {
        spikes[i].Update();
    }

    Anchor::UpdateAnimation();
    Spike::UpdateAnimation();

    BeginDrawing();
        ClearBackground(BLACK);

        for (Anchor anchor : anchors) {
            anchor.Render();
        }

        for (Spike spike : spikes) {
            spike.Render();
        }

        for (Rock rock : rocks) {
            rock.Render();
        }

        player.Render();
    EndDrawing();
}

void LoadTextures() {
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

    whiteAnchor1 = LoadTextureFromImage(LoadImage("resources/white-anchor/white-anchor-1.png"));
    whiteAnchor2 = LoadTextureFromImage(LoadImage("resources/white-anchor/white-anchor-2.png"));
    whiteAnchor3 = LoadTextureFromImage(LoadImage("resources/white-anchor/white-anchor-3.png"));
    whiteAnchor4 = LoadTextureFromImage(LoadImage("resources/white-anchor/white-anchor-4.png"));

    redSpike1 = LoadTextureFromImage(LoadImage("resources/red-spike/red-spike-1.png"));
    redSpike2 = LoadTextureFromImage(LoadImage("resources/red-spike/red-spike-2.png"));

    blueSpike1 = LoadTextureFromImage(LoadImage("resources/blue-spike/blue-spike-1.png"));
    blueSpike2 = LoadTextureFromImage(LoadImage("resources/blue-spike/blue-spike-2.png"));

    greySpike1 = LoadTextureFromImage(LoadImage("resources/grey-spike/grey-spike-1.png"));
    greySpike2 = LoadTextureFromImage(LoadImage("resources/grey-spike/grey-spike-2.png"));
}

void UnloadTextures() {
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

    UnloadTexture(whiteAnchor1);
    UnloadTexture(whiteAnchor2);
    UnloadTexture(whiteAnchor3);
    UnloadTexture(whiteAnchor4);

    UnloadTexture(redSpike1);
    UnloadTexture(redSpike2);

    UnloadTexture(blueSpike1);
    UnloadTexture(blueSpike2);

    UnloadTexture(greySpike1);
    UnloadTexture(greySpike2);
}