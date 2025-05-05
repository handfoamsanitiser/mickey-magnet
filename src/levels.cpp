#include "levels.hpp"
#include "globals.hpp"
#include "game.hpp"
#include <cmath>

void EnableEverything() {
    player.isEnabled = true;
    player.rotation = atan2((mousePos.y - player.pos.y), (mousePos.x - player.pos.x));

    for (int i = 0; i < (int)spikes.size(); ++i) {
        spikes[i].isEnabled = true;
    }
}

void ClearEverything() {
    anchors.clear();
    spikes.clear();
    rocks.clear();
    buttons.clear();
}

void LoadLevel(int level) {
    ClearEverything();
    switch (level) {
    case 1:
        LoadLevel1();
        break;
    case 2:
        LoadLevel2();
        break;
    case 3:
        LoadLevel3();
        break;
    case 4:
        LoadLevel4();
        break;
    case 5:
        LoadLevel5();
        break;
    case 6:
        LoadLevel6();
        break;
    case 7:
        LoadLevel7();
        break;
    case 8:
        LoadLevel8();
        break;
    case 9:
        LoadLevel9();
        break;
    case 10:
        LoadLevel10();
        break;
    case 11:
        LoadLevel11();
        break;
    case 12:
        LoadLevel12();
        break;
    case 13:
        LoadWinMenu();
        break;
    default:
        LoadLevelT1();
        break;
    }

    EnableEverything();
}

// attracting
void LoadLevel1() {
    player = Player(200, SCREEN_HEIGHT / 2);
    isExitOn = true;
    levelExit = Exit(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    star = Star(-1000, -1000);

    anchors.push_back(Anchor(SCREEN_WIDTH - 200, SCREEN_HEIGHT / 2, false));

    buttons.push_back(Button(300, 200, 0, 0, "opposite   colours   attract!", 40, false));
    buttons.push_back(Button(300, SCREEN_HEIGHT - 200, 0, 0, "the   green   portal   is   the   exit", 40, false));
}

// repelling
void LoadLevel2() {
    player = Player(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    isExitOn = true;
    levelExit = Exit(SCREEN_WIDTH - 200, SCREEN_HEIGHT / 2);
    star = Star(-1000, -1000);

    anchors.push_back(Anchor(200, SCREEN_HEIGHT / 2, true));

    buttons.push_back(Button(300, 200, 0, 0, "identical   colours   repel!", 40, false));
}

// medium level with spikes
void LoadLevel3() {
    player = Player(500, SCREEN_HEIGHT - 200);
    isExitOn = true;
    levelExit = Exit(500, 250);
    star = Star(-1000, -1000);

    anchors.push_back(Anchor(200, SCREEN_HEIGHT - 200, true));
    anchors.push_back(Anchor(SCREEN_WIDTH - 500, 200, false));
    anchors.push_back(Anchor(200, 250, false));

    rocks.push_back(Rock(SPIKE_RADIUS * 2, SCREEN_HEIGHT / 2 + 100));
    rocks.push_back(Rock(SPIKE_RADIUS * 4 + 30, SCREEN_HEIGHT / 2 + 100));
    rocks.push_back(Rock(SPIKE_RADIUS * 6 + 60, SCREEN_HEIGHT / 2 + 100));
    rocks.push_back(Rock(SPIKE_RADIUS * 8 + 90, SCREEN_HEIGHT / 2 + 100));
    rocks.push_back(Rock(SPIKE_RADIUS * 10 + 120, SCREEN_HEIGHT / 2 + 100));
    rocks.push_back(Rock(SPIKE_RADIUS * 12 + 150, SCREEN_HEIGHT / 2 + 100));
    rocks.push_back(Rock(SPIKE_RADIUS * 14 + 180, SCREEN_HEIGHT / 2 + 100));

    buttons.push_back(Button(1300, 700, 0, 0, "spikes   hurt!", 40, false));
    buttons.push_back(Button(1300, 800, 0, 0, "flames   don't", 40, false));
}

// backwards attraction and repelling
void LoadLevel4() {
    player = Player(SCREEN_WIDTH - 400, 200);
    isExitOn = true;
    levelExit = Exit(250, SCREEN_HEIGHT / 2);
    star = Star(-1000, -1000);

    anchors.push_back(Anchor(SCREEN_WIDTH - 200, 200, false));
    anchors.push_back(Anchor(250, SCREEN_HEIGHT - 200, true));

    rocks.push_back(Rock(SCREEN_WIDTH - SPIKE_RADIUS * 2, SCREEN_HEIGHT / 2 - 100));
    rocks.push_back(Rock(SCREEN_WIDTH - SPIKE_RADIUS * 4 - 30, SCREEN_HEIGHT / 2 - 100));
    rocks.push_back(Rock(SCREEN_WIDTH - SPIKE_RADIUS * 6 - 60, SCREEN_HEIGHT / 2 - 100));
    rocks.push_back(Rock(SCREEN_WIDTH - SPIKE_RADIUS * 8 - 90, SCREEN_HEIGHT / 2 - 100));
    rocks.push_back(Rock(SCREEN_WIDTH - SPIKE_RADIUS * 10 - 120, SCREEN_HEIGHT / 2 - 100));
    rocks.push_back(Rock(SCREEN_WIDTH - SPIKE_RADIUS * 12 - 150, SCREEN_HEIGHT / 2 - 100));
    rocks.push_back(Rock(SCREEN_WIDTH - SPIKE_RADIUS * 14 - 180, SCREEN_HEIGHT / 2 - 100));
    rocks.push_back(Rock(SCREEN_WIDTH - SPIKE_RADIUS * 16 - 210, SCREEN_HEIGHT / 2 - 100));
    rocks.push_back(Rock(SCREEN_WIDTH - SPIKE_RADIUS * 18 - 240, SCREEN_HEIGHT / 2 - 100));

    rocks.push_back(Rock(SCREEN_WIDTH - SPIKE_RADIUS * 18 - 240, SCREEN_HEIGHT / 2 - 100));
    rocks.push_back(Rock(SCREEN_WIDTH - SPIKE_RADIUS * 18 - 240, SCREEN_HEIGHT / 2 + SPIKE_RADIUS * 2 - 70));
    rocks.push_back(Rock(SCREEN_WIDTH - SPIKE_RADIUS * 18 - 240, SCREEN_HEIGHT / 2 + SPIKE_RADIUS * 4 - 40));
    rocks.push_back(Rock(SCREEN_WIDTH - SPIKE_RADIUS * 18 - 240, SCREEN_HEIGHT / 2 + SPIKE_RADIUS * 6 - 10));
    rocks.push_back(Rock(SCREEN_WIDTH - SPIKE_RADIUS * 18 - 240, SCREEN_HEIGHT / 2 + SPIKE_RADIUS * 8 + 20));

    buttons.push_back(Button(800, 800, 0, 0, "the   back   magnet   also   works!", 40, false));
}

// medium level
void LoadLevel5() {
    player = Player(150, SPIKE_RADIUS + 40);
    isExitOn = true;
    levelExit = Exit(SCREEN_WIDTH - 250, SCREEN_HEIGHT / 2);
    star = Star(-1000, -1000);

    anchors.push_back(Anchor(SCREEN_WIDTH - SPIKE_RADIUS, SPIKE_RADIUS + 40, true));
    anchors.push_back(Anchor(SCREEN_WIDTH / 4, SCREEN_HEIGHT - 70, false));
    anchors.push_back(Anchor(SPIKE_RADIUS, SCREEN_HEIGHT / 2, true));

    rocks.push_back(Rock(SCREEN_WIDTH - SPIKE_RADIUS * 3 - 30, SPIKE_RADIUS + 40));
    rocks.push_back(Rock(SCREEN_WIDTH - SPIKE_RADIUS * 3 - 30, SPIKE_RADIUS * 3 + 70));
    rocks.push_back(Rock(SCREEN_WIDTH - SPIKE_RADIUS, SPIKE_RADIUS * 3 + 70));

    rocks.push_back(Rock(SCREEN_WIDTH / 4 - SPIKE_RADIUS * 2 - 30, SCREEN_HEIGHT - 70));
    rocks.push_back(Rock(SCREEN_WIDTH / 4 - SPIKE_RADIUS * 2 - 30, SCREEN_HEIGHT - 100 - SPIKE_RADIUS * 2));
    rocks.push_back(Rock(SCREEN_WIDTH / 4, SCREEN_HEIGHT - 100 - SPIKE_RADIUS * 2));
    rocks.push_back(Rock(SCREEN_WIDTH / 4 + SPIKE_RADIUS * 2 + 30, SCREEN_HEIGHT - 100 - SPIKE_RADIUS * 2));
    rocks.push_back(Rock(SCREEN_WIDTH / 4 + SPIKE_RADIUS * 2 + 30, SCREEN_HEIGHT - 70));

    rocks.push_back(Rock(SPIKE_RADIUS, SCREEN_HEIGHT / 2 - 150));
    rocks.push_back(Rock(SPIKE_RADIUS * 3 + 30, SCREEN_HEIGHT / 2 - 150));
    rocks.push_back(Rock(SPIKE_RADIUS * 3 + 30, SCREEN_HEIGHT / 2));
    rocks.push_back(Rock(SPIKE_RADIUS * 3 + 30, SCREEN_HEIGHT / 2 + 150));
    rocks.push_back(Rock(SPIKE_RADIUS, SCREEN_HEIGHT / 2 + 150));
}

// magnetic spikes
void LoadLevel6() {
    player = Player(150, 150);
    isExitOn = true;
    levelExit = Exit(SCREEN_WIDTH - 350, SCREEN_HEIGHT / 2 - 100);
    star = Star(-1000, -1000);

    anchors.push_back(Anchor(SCREEN_WIDTH - 100, SCREEN_HEIGHT / 2 - 100, false));

    spikes.push_back(Spike(150, SCREEN_HEIGHT - 100, false));

    rocks.push_back(Rock(SCREEN_WIDTH - 300 + SPIKE_RADIUS * 4, SCREEN_HEIGHT / 2 - 300));
    rocks.push_back(Rock(SCREEN_WIDTH - 330 + SPIKE_RADIUS * 2, SCREEN_HEIGHT / 2 - 300));
    rocks.push_back(Rock(SCREEN_WIDTH - 360, SCREEN_HEIGHT / 2 - 300));
    rocks.push_back(Rock(SCREEN_WIDTH - 330 - SPIKE_RADIUS * 3, SCREEN_HEIGHT / 2 - 300));
    rocks.push_back(Rock(SCREEN_WIDTH - 300 - SPIKE_RADIUS * 6, SCREEN_HEIGHT / 2 - 300));
    rocks.push_back(Rock(SCREEN_WIDTH - 270 - SPIKE_RADIUS * 9, SCREEN_HEIGHT / 2 - 300));
    rocks.push_back(Rock(SCREEN_WIDTH - 240 - SPIKE_RADIUS * 12, SCREEN_HEIGHT / 2 - 300));
    rocks.push_back(Rock(SCREEN_WIDTH - 210 - SPIKE_RADIUS * 15, SCREEN_HEIGHT / 2 - 300));

    rocks.push_back(Rock(SCREEN_WIDTH - 300 + SPIKE_RADIUS * 4, SCREEN_HEIGHT / 2 + 100));
    rocks.push_back(Rock(SCREEN_WIDTH - 330 + SPIKE_RADIUS * 2, SCREEN_HEIGHT / 2 + 100));
    rocks.push_back(Rock(SCREEN_WIDTH - 360, SCREEN_HEIGHT / 2 + 100));
    rocks.push_back(Rock(SCREEN_WIDTH - 330 - SPIKE_RADIUS * 3, SCREEN_HEIGHT / 2 + 100));
    rocks.push_back(Rock(SCREEN_WIDTH - 300 - SPIKE_RADIUS * 6, SCREEN_HEIGHT / 2 + 100));
    rocks.push_back(Rock(SCREEN_WIDTH - 270 - SPIKE_RADIUS * 9, SCREEN_HEIGHT / 2 + 100));
    rocks.push_back(Rock(SCREEN_WIDTH - 240 - SPIKE_RADIUS * 12, SCREEN_HEIGHT / 2 + 100));
    rocks.push_back(Rock(SCREEN_WIDTH - 210 - SPIKE_RADIUS * 15, SCREEN_HEIGHT / 2 + 100));

    buttons.push_back(Button(800, 800, 0, 0, "some   spikes   are   magnetic", 40, false));
}

// medium level
void LoadLevel7() {
    player = Player(150, SCREEN_HEIGHT - 150);
    isExitOn = true;
    levelExit = Exit(SCREEN_WIDTH - 200, 200);
    star = Star(-1000, -1000);

    spikes.push_back(Spike(SCREEN_WIDTH / 2, 150, false));
    spikes.push_back(Spike(150, SCREEN_HEIGHT / 2 + 200, true));
    spikes.push_back(Spike(SCREEN_WIDTH - 150, SCREEN_HEIGHT - 150, true));
}

// star maze
void LoadLevel8() {
    player = Player(200, SCREEN_HEIGHT / 2);

    isExitOn = false;
    levelExit = Exit(SCREEN_WIDTH - 200, 200);

    star = Star(SCREEN_WIDTH - 200, SCREEN_HEIGHT - 200);

    anchors.push_back(Anchor(200, 200, false));
    anchors.push_back(Anchor(200, SCREEN_HEIGHT - 200, false));

    rocks.push_back(Rock(SCREEN_WIDTH - SPIKE_RADIUS * 2, SCREEN_HEIGHT / 2));
    rocks.push_back(Rock(SCREEN_WIDTH - SPIKE_RADIUS * 4 - 30, SCREEN_HEIGHT / 2));
    rocks.push_back(Rock(SCREEN_WIDTH - SPIKE_RADIUS * 6 - 60, SCREEN_HEIGHT / 2));
    rocks.push_back(Rock(SCREEN_WIDTH - SPIKE_RADIUS * 8 - 90, SCREEN_HEIGHT / 2));
    rocks.push_back(Rock(SCREEN_WIDTH - SPIKE_RADIUS * 10 - 120, SCREEN_HEIGHT / 2));
    rocks.push_back(Rock(SCREEN_WIDTH - SPIKE_RADIUS * 12 - 150, SCREEN_HEIGHT / 2));
    rocks.push_back(Rock(SCREEN_WIDTH - SPIKE_RADIUS * 14 - 180, SCREEN_HEIGHT / 2));
    rocks.push_back(Rock(SCREEN_WIDTH - SPIKE_RADIUS * 16 - 210, SCREEN_HEIGHT / 2));
    rocks.push_back(Rock(SCREEN_WIDTH - SPIKE_RADIUS * 18 - 240, SCREEN_HEIGHT / 2));
    rocks.push_back(Rock(SCREEN_WIDTH - SPIKE_RADIUS * 20 - 270, SCREEN_HEIGHT / 2));

    rocks.push_back(Rock(0, 0, Vector2 { 800, (float)SCREEN_HEIGHT / 2 + 150 }, Vector2 { 800, (float)SCREEN_HEIGHT / 2 + 450 }, 100.0f));

    buttons.push_back(Button(800, 200, 0, 0, "to   open   the   exit...", 40, false));
    buttons.push_back(Button(1000, SCREEN_HEIGHT - 200, 0, 0, "collect   the   star", 40, false));
}

// maze-ish level
void LoadLevel9() {
    player = Player(200, 500);

    isExitOn = false;
    levelExit = Exit(200, 200);

    star = Star(SCREEN_WIDTH - 200, SCREEN_HEIGHT - 200);

    anchors.push_back(Anchor(200, SCREEN_HEIGHT - 300, true));
    anchors.push_back(Anchor(900, 200, false));
    anchors.push_back(Anchor(SCREEN_WIDTH - 200, 200, false));

    rocks.push_back(Rock(500, 100));
    rocks.push_back(Rock(500, 230));
    rocks.push_back(Rock(500, 360));
    rocks.push_back(Rock(500, 490));
    rocks.push_back(Rock(500, 620));

    rocks.push_back(Rock(500, SCREEN_HEIGHT / 2, Vector2 { 650, (float)SCREEN_HEIGHT / 2 }, Vector2 { 1150, (float)SCREEN_HEIGHT / 2 }, 150.0f));

    rocks.push_back(Rock(1450, SCREEN_HEIGHT / 2, Vector2 { 1450, (float)SCREEN_HEIGHT / 2 }, Vector2 { 1800, (float)SCREEN_HEIGHT / 2 }, 100.0f));
    rocks.push_back(Rock(1650, (float)SCREEN_HEIGHT / 2 + 300, Vector2 { 1450, (float)SCREEN_HEIGHT / 2 + 150 }, Vector2 { 1800, (float)SCREEN_HEIGHT / 2 + 150 }, 100.0f));

    rocks.push_back(Rock(SCREEN_WIDTH - 650, 360));
    rocks.push_back(Rock(SCREEN_WIDTH - 650, 490));
    rocks.push_back(Rock(SCREEN_WIDTH - 650, 620));
    rocks.push_back(Rock(SCREEN_WIDTH - 650, 750));
    rocks.push_back(Rock(SCREEN_WIDTH - 650, 880));
    spikes.push_back(Spike(SCREEN_WIDTH - 650, 1010, true));
}

// gauntlet
void LoadLevel10() {
    player = Player(200, 200);

    isExitOn = true;
    levelExit = Exit(200, SCREEN_HEIGHT - 200);

    star = Star(-1000, -1000);

    anchors.push_back(Anchor(SCREEN_WIDTH - 100, 200, false));
    anchors.push_back(Anchor(SCREEN_WIDTH - 300, 200, false));

    anchors.push_back(Anchor(500, SCREEN_HEIGHT - 200, true));

    rocks.push_back(Rock(100, SCREEN_HEIGHT / 2));
    rocks.push_back(Rock(250, SCREEN_HEIGHT / 2));
    rocks.push_back(Rock(400, SCREEN_HEIGHT / 2));
    rocks.push_back(Rock(550, SCREEN_HEIGHT / 2));
    rocks.push_back(Rock(700, SCREEN_HEIGHT / 2));
    rocks.push_back(Rock(850, SCREEN_HEIGHT / 2));
    rocks.push_back(Rock(1000, SCREEN_HEIGHT / 2));
    rocks.push_back(Rock(1150, SCREEN_HEIGHT / 2));
    rocks.push_back(Rock(1300, SCREEN_HEIGHT / 2));
    rocks.push_back(Rock(1450, SCREEN_HEIGHT / 2));
    rocks.push_back(Rock(SCREEN_WIDTH - 100, SCREEN_HEIGHT / 2));

    rocks.push_back(Rock(500, 320, Vector2 { 500, 100 }, Vector2 { 500, 400 }, 120.0f));
    rocks.push_back(Rock(700, 340, Vector2 { 700, 100 }, Vector2 { 700, 400 }, 120.0f));
    rocks.push_back(Rock(900, 360, Vector2 { 900, 100 }, Vector2 { 900, 400 }, 120.0f));
    rocks.push_back(Rock(1100, 380, Vector2 { 1100, 100 }, Vector2 { 1100, 400 }, 120.0f));
    rocks.push_back(Rock(1300, 400, Vector2 { 1300, 100 }, Vector2 { 1300, 400 }, 120.0f));

    rocks.push_back(Rock(1300, 680, Vector2 { 1300, 680 }, Vector2 { 1300, 980 }, 120.0f));
    rocks.push_back(Rock(1100, 700, Vector2 { 1100, 680 }, Vector2 { 1100, 980 }, 120.0f));
    rocks.push_back(Rock(900, 720, Vector2 { 900, 680 }, Vector2 { 900, 980 }, 120.0f));
}

// open-ish
void LoadLevel11() {
    player = Player(700, SCREEN_HEIGHT / 2 + 50);

    isExitOn = false;
    levelExit = Exit(700, SCREEN_HEIGHT / 2 + 50);

    star = Star(SCREEN_WIDTH - 100, 100);

    rocks.push_back(Rock(550, 400));
    rocks.push_back(Rock(700, 400));
    rocks.push_back(Rock(850, 400));
    rocks.push_back(Rock(550, 550));
    rocks.push_back(Rock(850, 550));
    rocks.push_back(Rock(550, 700));
    rocks.push_back(Rock(850, 700));

    rocks.push_back(Rock(SCREEN_WIDTH - 250, 100));
    spikes.push_back(Spike(SCREEN_WIDTH - 250, 250, true));
    rocks.push_back(Rock(SCREEN_WIDTH - 250, 400));
    rocks.push_back(Rock(SCREEN_WIDTH - 250, 550));
    rocks.push_back(Rock(SCREEN_WIDTH - 250, 700));
    rocks.push_back(Rock(SCREEN_WIDTH - 250, 850));
    rocks.push_back(Rock(SCREEN_WIDTH - 250, 1000));

    anchors.push_back(Anchor(700, SCREEN_HEIGHT - 100, true));
    anchors.push_back(Anchor(100, 250, false));
    anchors.push_back(Anchor(SCREEN_WIDTH - 400, 250, false));
    anchors.push_back(Anchor(SCREEN_WIDTH - 100, SCREEN_HEIGHT - 100, true));
}

// final
void LoadLevel12() {
    player = Player(250, 250);

    isExitOn = false;
    levelExit = Exit(1525, 625);

    star = Star(1600, 250);

    rocks.push_back(Rock(100, 100));
    rocks.push_back(Rock(250, 100));
    rocks.push_back(Rock(400, 100));
    rocks.push_back(Rock(550, 100));
    rocks.push_back(Rock(700, 100));
    rocks.push_back(Rock(850, 100));
    //rocks.push_back(Rock(1000, 100));
    //rocks.push_back(Rock(1150, 100));
    rocks.push_back(Rock(1300, 100));
    rocks.push_back(Rock(1450, 100));
    rocks.push_back(Rock(1600, 100));
    rocks.push_back(Rock(1750, 100));

    spikes.push_back(Spike(100, 250, true));
    rocks.push_back(Rock(100, 400));

    rocks.push_back(Rock(250, 400));
    rocks.push_back(Rock(400, 400));
    rocks.push_back(Rock(550, 400));
    rocks.push_back(Rock(700, 400));
    rocks.push_back(Rock(850, 400));
    //rocks.push_back(Rock(1000, 400));
    spikes.push_back(Spike(1000, 400, false));
    //rocks.push_back(Rock(1150, 400));
    spikes.push_back(Spike(1150, 400, false));
    rocks.push_back(Rock(1300, 400));
    rocks.push_back(Rock(1450, 400));
    rocks.push_back(Rock(1600, 400));
    rocks.push_back(Rock(1750, 400));

    rocks.push_back(Rock(1750, 250));

    rocks.push_back(Rock(1300, 550));
    rocks.push_back(Rock(1300, 700));
    rocks.push_back(Rock(1300, 850));
    rocks.push_back(Rock(850, 850));
    rocks.push_back(Rock(700, 850));
    rocks.push_back(Rock(550, 850));

    anchors.push_back(Anchor(100, 550, false));
    anchors.push_back(Anchor(1525, SCREEN_HEIGHT - 100, true));
}

void LoadLevelT1() {
    player = Player(200, 200);

    levelExit = Exit(1200, 200);

    anchors.push_back(Anchor(500, 500, false));
    anchors.push_back(Anchor(800, 600, true));

    spikes.push_back(Spike(1000, 800, true));
    spikes.push_back(Spike(70, 80, false));

    rocks.push_back(Rock(1300, 300));
}

void LoadLevelT2() {
    player = Player(200, SCREEN_HEIGHT / 2);

    levelExit = Exit(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

    anchors.push_back(Anchor(SCREEN_WIDTH - 200, SCREEN_HEIGHT / 2, false));

    rocks.push_back(Rock(400, SCREEN_HEIGHT / 2, Vector2 { 400, (float)SCREEN_HEIGHT / 2 - 100 }, Vector2 { 400, (float)SCREEN_HEIGHT / 2 + 100 }, 100.0f));
}