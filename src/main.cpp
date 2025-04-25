#include "raylib.h"
#include <vector>

#include "globals.hpp"
#include "levels.hpp"
#include "player.hpp"
#include "anchor.hpp"
#include "spike.hpp"
#include "rock.hpp"
#include "exit.hpp"

//#define PLATFORM_WEB
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

    LoadLevel(curLevel);
    
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

        levelExit.Render();

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
    playerBody1 = LoadTextureFromImage(LoadImage("resources/magnet/magnet-body-1.png"));
    playerBody2 = LoadTextureFromImage(LoadImage("resources/magnet/magnet-body-2.png"));
    playerBody3 = LoadTextureFromImage(LoadImage("resources/magnet/magnet-body-3.png"));
    playerBody4 = LoadTextureFromImage(LoadImage("resources/magnet/magnet-body-4.png"));

    redArm1 = LoadTextureFromImage(LoadImage("resources/magnet/red-arm-1.png"));
    redArm2 = LoadTextureFromImage(LoadImage("resources/magnet/red-arm-2.png"));
    redArm3 = LoadTextureFromImage(LoadImage("resources/magnet/red-arm-3.png"));

    blueArm1 = LoadTextureFromImage(LoadImage("resources/magnet/blue-arm-1.png"));
    blueArm2 = LoadTextureFromImage(LoadImage("resources/magnet/blue-arm-2.png"));
    blueArm3 = LoadTextureFromImage(LoadImage("resources/magnet/blue-arm-3.png"));

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

    exit1 = LoadTextureFromImage(LoadImage("resources/exit/exit-1.png"));
    exit2 = LoadTextureFromImage(LoadImage("resources/exit/exit-2.png"));
    exit3 = LoadTextureFromImage(LoadImage("resources/exit/exit-3.png"));
    exit4 = LoadTextureFromImage(LoadImage("resources/exit/exit-4.png"));
}

void UnloadTextures() {
    UnloadTexture(playerBody1);
    UnloadTexture(playerBody2);
    UnloadTexture(playerBody3);
    UnloadTexture(playerBody4);

    UnloadTexture(redArm1);
    UnloadTexture(redArm2);
    UnloadTexture(redArm3);

    UnloadTexture(blueArm1);
    UnloadTexture(blueArm2);
    UnloadTexture(blueArm3);

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

    UnloadTexture(exit1);
    UnloadTexture(exit2);
    UnloadTexture(exit3);
    UnloadTexture(exit4);
}