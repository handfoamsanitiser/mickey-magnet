#include "levels.hpp"
#include "globals.hpp"

void EnableEverything() {
    player.isEnabled = true;

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
    default:
        break;
    }

    EnableEverything();
}

void LoadLevel1() {
    player = Player(200, SCREEN_HEIGHT / 2);

    levelExit = Exit(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

    anchors.push_back(Anchor(SCREEN_WIDTH - 200, SCREEN_HEIGHT / 2, false));
}

void LoadLevel2() {
    player = Player(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

    levelExit = Exit(SCREEN_WIDTH - 200, SCREEN_HEIGHT / 2);

    anchors.push_back(Anchor(200, SCREEN_HEIGHT / 2, true));
}

void LoadLevel3() {}
void LoadLevel4() {}

void LoadLevel5() {
    player = Player(200, 200);

    levelExit = Exit(1200, 200);

    anchors.push_back(Anchor(500, 500, false));
    anchors.push_back(Anchor(800, 600, true));

    spikes.push_back(Spike(1000, 800, true));
    spikes.push_back(Spike(70, 80, false));

    rocks.push_back(Rock(1300, 300));
}