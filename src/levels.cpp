#include "levels.hpp"

void LoadLevel(int level) {
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
}

void LoadLevel1() {}
void LoadLevel2() {}
void LoadLevel3() {}
void LoadLevel4() {}
void LoadLevel5() {}