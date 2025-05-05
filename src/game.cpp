#include "game.hpp"
#include "globals.hpp"
#include "levels.hpp"

void UpdateGame() {
    GodMode();
    NotGodMode();

    for (int i = 0; i < (int)spikes.size(); ++i) {
        spikes[i].Drag();
    }
    player.Update();
    for (int i = 0; i < (int)spikes.size(); ++i) {
        spikes[i].Update();
    }

    for (int i = 0; i < (int)rocks.size(); ++i) {
        rocks[i].Update();
    }
}

void DrawGame() {
    levelExit.Render();

    star.Render();

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
}

void LoadMainMenu() {
    ClearEverything();

    buttons.push_back(Button(200, 200, 0, 0, "mickey   magnet", 80, false));
    buttons.push_back(Button(200, SCREEN_HEIGHT - 400, 180, 33, "play!", 40, true));

    player = Player(500, 500);
}

void UpdateMainMenu() {
    if (buttons[1].isClicked()) {
        buttons.clear();
        curLevel = 12;
        LoadLevel(curLevel);
        gameState = 1;
    }
}

void DrawMainMenu() {
    for (Button button : buttons) {
        button.Render();
    }

    player.Render();
}

void LoadWinMenu() {
    gameState = 2;
    ClearEverything();

    buttons.push_back(Button(600, 600, 0, 0, "win!", 250, false));
    buttons.push_back(Button(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 630, 50, "back   to   menu", 60, true));

    player = Player(500, 500);
}

void UpdateWinMenu() {
    if (buttons[1].isClicked()) {
        buttons.clear();
        gameState = 0;
        LoadMainMenu();
    }
}

void DrawWinMenu() {
    for (Button button : buttons) {
        button.Render();
    }

    player.Render();
}

void GodMode() {
    if (IsKeyPressed(KEY_SPACE)) {
        curLevel++;
        LoadLevel(curLevel);
    }

    if (IsKeyPressed(KEY_BACKSPACE)) {
        curLevel--;
        LoadLevel(curLevel);
    }
}

void NotGodMode() {
    if (IsKeyPressed(KEY_R)) {
        LoadLevel(curLevel);
    }
}