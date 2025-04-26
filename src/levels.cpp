#include "levels.hpp"
#include "globals.hpp"
#include <cmath>

void EnableEverything() {
    player.isEnabled = true;
    player.rotation = atan2((GetMouseY() - player.pos.y), (GetMouseX() - player.pos.x));

    for (int i = 0; i < (int)spikes.size(); ++i) {
        spikes[i].isEnabled = true;
    }
}

void ClearEverything() {
    anchors.clear();
    spikes.clear();
    rocks.clear();
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
    default:
        break;
    }

    EnableEverything();
}

// attracting
void LoadLevel1() {
    player = Player(200, SCREEN_HEIGHT / 2);

    levelExit = Exit(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

    anchors.push_back(Anchor(SCREEN_WIDTH - 200, SCREEN_HEIGHT / 2, false));
}

// repelling
void LoadLevel2() {
    player = Player(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

    levelExit = Exit(SCREEN_WIDTH - 200, SCREEN_HEIGHT / 2);

    anchors.push_back(Anchor(200, SCREEN_HEIGHT / 2, true));
}

// medium level with spikes
void LoadLevel3() {
    player = Player(500, SCREEN_HEIGHT - 200);

    levelExit = Exit(500, 250);

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
}

// backwards attraction and repelling
void LoadLevel4() {
    player = Player(SCREEN_WIDTH - 400, 200);

    levelExit = Exit(250, SCREEN_HEIGHT / 2);

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
}

// medium level
void LoadLevel5() {
    player = Player(150, 150);

    levelExit = Exit(SCREEN_WIDTH - 250, SCREEN_HEIGHT / 2);

    anchors.push_back(Anchor(SCREEN_WIDTH - SPIKE_RADIUS, SPIKE_RADIUS + 40, true));
    anchors.push_back(Anchor(SCREEN_WIDTH / 4, SCREEN_HEIGHT - 150, false));
    anchors.push_back(Anchor(SPIKE_RADIUS, SCREEN_HEIGHT / 2, true));

    rocks.push_back(Rock(SCREEN_WIDTH - SPIKE_RADIUS * 3 - 30, SPIKE_RADIUS + 40));
    rocks.push_back(Rock(SCREEN_WIDTH - SPIKE_RADIUS * 3 - 30, SPIKE_RADIUS * 3 + 70));
    rocks.push_back(Rock(SCREEN_WIDTH - SPIKE_RADIUS, SPIKE_RADIUS * 3 + 70));

    rocks.push_back(Rock(SCREEN_WIDTH / 4 - SPIKE_RADIUS * 2 - 30, SCREEN_HEIGHT - 150));
    rocks.push_back(Rock(SCREEN_WIDTH / 4 - SPIKE_RADIUS * 2 - 30, SCREEN_HEIGHT - 180 - SPIKE_RADIUS * 2));
    rocks.push_back(Rock(SCREEN_WIDTH / 4, SCREEN_HEIGHT - 180 - SPIKE_RADIUS * 2));
    rocks.push_back(Rock(SCREEN_WIDTH / 4 + SPIKE_RADIUS * 2 + 30, SCREEN_HEIGHT - 180 - SPIKE_RADIUS * 2));
    rocks.push_back(Rock(SCREEN_WIDTH / 4 + SPIKE_RADIUS * 2 + 30, SCREEN_HEIGHT - 150));

    rocks.push_back(Rock(SPIKE_RADIUS, SCREEN_HEIGHT / 2 - 150));
    rocks.push_back(Rock(SPIKE_RADIUS * 3 + 30, SCREEN_HEIGHT / 2 - 150));
    rocks.push_back(Rock(SPIKE_RADIUS * 3 + 30, SCREEN_HEIGHT / 2));
    rocks.push_back(Rock(SPIKE_RADIUS * 3 + 30, SCREEN_HEIGHT / 2 + 150));
    rocks.push_back(Rock(SPIKE_RADIUS, SCREEN_HEIGHT / 2 + 150));
}

// magnetic spikes
void LoadLevel6() {
    player = Player(150, 150);

    levelExit = Exit(SCREEN_WIDTH - 350, SCREEN_HEIGHT / 2 - 100);

    anchors.push_back(Anchor(SCREEN_WIDTH - 100, SCREEN_HEIGHT / 2 - 100, false));

    spikes.push_back(Spike(150, SCREEN_HEIGHT - 150, false));

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
}

// medium level
void LoadLevel7() {
    
}

// star
void LoadLevel8() {}

// medium level
void LoadLevel9() {
    player = Player(200, SCREEN_HEIGHT / 2);

    levelExit = Exit(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

    anchors.push_back(Anchor(SCREEN_WIDTH - 200, SCREEN_HEIGHT / 2, false));

    rocks.push_back(Rock(400, SCREEN_HEIGHT / 2));
}

// medium level
void LoadLevel10() {
    player = Player(200, 200);

    levelExit = Exit(1200, 200);

    anchors.push_back(Anchor(500, 500, false));
    anchors.push_back(Anchor(800, 600, true));

    spikes.push_back(Spike(1000, 800, true));
    spikes.push_back(Spike(70, 80, false));

    rocks.push_back(Rock(1300, 300));
}

// 5 - 10 more medium to hard levels