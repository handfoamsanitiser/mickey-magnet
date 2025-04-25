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
    
}

// blue spike
void LoadLevel6() {}

// red spike
void LoadLevel7() {}

// medium level
void LoadLevel8() {}

// star
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