#include "raylib.h"
#include "raymath.h"
#include <vector>
#include "time.h"

#include "globals.hpp"
#include "levels.hpp"
#include "player.hpp"
#include "anchor.hpp"
#include "spike.hpp"
#include "rock.hpp"
#include "exit.hpp"
#include "star.hpp"
#include "button.hpp"
#include "game.hpp"

//#define PLATFORM_WEB
#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

void UpdateDrawFrame();

void LoadTextures();
void UnloadTextures();

void LoadSounds();
void UnloadSounds();

void MuteMusic();
void UnmuteMusic();

void MuteSounds();
void UnmuteSounds();

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Mick");
    HideCursor();

    srand(time(NULL));

    InitAudioDevice();
    LoadTextures();
    LoadSounds();
    
    UnmuteMusic();
    PlayMusicStream(music);

    LoadMainMenu();
    
#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 60, 1);
#else
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        UpdateDrawFrame();
    }
#endif

    UnloadSounds();
    UnloadTextures();
    CloseAudioDevice();
    CloseWindow();
    return 0;
}

void UpdateDrawFrame() {
    if (IsCursorOnScreen()) {
        mousePos = GetMousePosition();
    }

    UpdateMusicStream(music);

    switch (gameState) {
        case 0:
            UpdateMainMenu();
            break;
        case 1:
            UpdateGame();
            break;
        case 2:
            UpdateWinMenu();
            break;
    }

    Anchor::UpdateAnimation();
    Spike::UpdateAnimation();

    BeginDrawing();
        DrawTexture(background, 0, 0, WHITE);

        switch (gameState) {
            case 0:
                DrawMainMenu();
                break;
            case 1:
                DrawGame();
                break;
            case 2:
                DrawWinMenu();
                break;
        }

        if (IsCursorOnScreen()) {
            switch (spikeAnimationFrame) {
                case 0:
                    DrawTexturePro(cursor1, Rectangle { 0, 0, 32, 32 }, Rectangle { (float)mousePos.x, (float)mousePos.y, 32, 32 }, Vector2 { 0, 0}, 0, WHITE);
                    break;
                case 1:
                    DrawTexturePro(cursor2, Rectangle { 0, 0, 32, 32 }, Rectangle { (float)mousePos.x, (float)mousePos.y, 32, 32 }, Vector2 {0, 0 }, 0, WHITE);
                    break;
                default:
                    break;
            }
        }
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
    redSpike3 = LoadTextureFromImage(LoadImage("resources/red-spike/red-spike-3.png"));

    blueSpike1 = LoadTextureFromImage(LoadImage("resources/blue-spike/blue-spike-1.png"));
    blueSpike2 = LoadTextureFromImage(LoadImage("resources/blue-spike/blue-spike-2.png"));
    blueSpike3 = LoadTextureFromImage(LoadImage("resources/blue-spike/blue-spike-3.png"));

    greySpike1 = LoadTextureFromImage(LoadImage("resources/grey-spike/grey-spike-1.png"));
    greySpike2 = LoadTextureFromImage(LoadImage("resources/grey-spike/grey-spike-2.png"));

    exit1 = LoadTextureFromImage(LoadImage("resources/exit/exit-1.png"));
    exit2 = LoadTextureFromImage(LoadImage("resources/exit/exit-2.png"));
    exit3 = LoadTextureFromImage(LoadImage("resources/exit/exit-3.png"));
    exit4 = LoadTextureFromImage(LoadImage("resources/exit/exit-4.png"));

    exitOff1 = LoadTextureFromImage(LoadImage("resources/exit/exit-off-1.png"));
    exitOff2 = LoadTextureFromImage(LoadImage("resources/exit/exit-off-2.png"));
    exitOff3 = LoadTextureFromImage(LoadImage("resources/exit/exit-off-3.png"));
    exitOff4 = LoadTextureFromImage(LoadImage("resources/exit/exit-off-4.png"));

    star1 = LoadTextureFromImage(LoadImage("resources/star/star-1.png"));
    star2 = LoadTextureFromImage(LoadImage("resources/star/star-2.png"));
    star3 = LoadTextureFromImage(LoadImage("resources/star/star-3.png"));

    cursor1 = LoadTextureFromImage(LoadImage("resources/cursor/cursor-1.png"));
    cursor2 = LoadTextureFromImage(LoadImage("resources/cursor/cursor-2.png"));

    background = LoadTextureFromImage(LoadImage("resources/background/background.png"));
    font = LoadFont("resources/font/goofy/goofy.fnt");
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
    UnloadTexture(redSpike3);

    UnloadTexture(blueSpike1);
    UnloadTexture(blueSpike2);
    UnloadTexture(blueSpike3);

    UnloadTexture(greySpike1);
    UnloadTexture(greySpike2);

    UnloadTexture(exit1);
    UnloadTexture(exit2);
    UnloadTexture(exit3);
    UnloadTexture(exit4);

    UnloadTexture(exitOff1);
    UnloadTexture(exitOff2);
    UnloadTexture(exitOff3);
    UnloadTexture(exitOff4);

    UnloadTexture(star1);
    UnloadTexture(star2);
    UnloadTexture(star3);

    UnloadTexture(cursor1);
    UnloadTexture(cursor2);

    UnloadTexture(background);
    UnloadFont(font);
}

void LoadSounds() {
    music = LoadMusicStream("resources/music/music.wav");
    buttonSound = LoadSound("resources/sounds/button.wav");
    deathSound = LoadSound("resources/sounds/death.wav");
    finishSound = LoadSound("resources/sounds/finish.wav");
    magnetStartSound = LoadSound("resources/sounds/magnet-start.wav");
    magnetEndSound = LoadSound("resources/sounds/magnet-end.wav");
    starSound = LoadSound("resources/sounds/star.wav");
}

void UnloadSounds() {
    UnloadMusicStream(music);
    UnloadSound(buttonSound);
    UnloadSound(deathSound);
    UnloadSound(finishSound);
    UnloadSound(magnetStartSound);
    UnloadSound(magnetEndSound);
    UnloadSound(starSound);
}

void MuteMusic() {
    SetMusicVolume(music, 0);
}

void UnmuteMusic() {
    SetMusicVolume(music, 0.5);
}

void MuteSounds() {
    SetSoundVolume(buttonSound, 0);
    SetSoundVolume(deathSound, 0);
    SetSoundVolume(finishSound, 0);
    SetSoundVolume(magnetStartSound, 0);
    SetSoundVolume(magnetEndSound, 0);
    SetSoundVolume(starSound, 0);
}

void UnmuteSounds() {
    SetSoundVolume(buttonSound, 1);
    SetSoundVolume(deathSound, 1);
    SetSoundVolume(finishSound, 1);
    SetSoundVolume(magnetStartSound, 1);
    SetSoundVolume(magnetEndSound, 1);
    SetSoundVolume(starSound, 1);
}