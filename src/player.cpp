#include "player.hpp"
#include <cmath>
#include <vector>
#include "raymath.h"
#include "globals.hpp"
#include "levels.hpp"

Player::Player(int x, int y): 
    pos(Vector2 { (float)x, (float)y }),
    vel(Vector2 { 0, 0 }),
    rotation(0),
    isEnabled(false),
    isDead(false),
    isRedActive(false),
    isBlueActive(false) {}

void Player::Update() {
    if (!isEnabled) return;

    // update position
    pos.x += vel.x * GetFrameTime() * 50;
    pos.y += vel.y * GetFrameTime() * 50;
    ClampPos();

    Drag();

    isRedActive = false;
    isBlueActive = false;
    AnchorInteract();
    SpikeInteract();
    RockInteract();
    StarInteract();
    ExitInteract();
    ClampVel();
}

void Player::Render() {
    // DrawCircle(pos.x, pos.y, radius, RED);
    // DrawPoly(Vector2 { pos.x, pos.y }, 4, radius / 3, rotation * 180/PI, BLACK);

    // DrawTexturePro(playerBase, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)radius * 2, (float)radius * 2 }, Vector2 { (float)radius, (float)radius }, 0, WHITE);
    // DrawTexturePro(playerBody, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)radius * 2, (float)radius * 2 }, Vector2 { (float)radius, (float)radius }, rotation * 180/PI + 90, WHITE);
    // DrawTexturePro(playerFace, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)radius * 2, (float)radius * 2 }, Vector2 { (float)radius, (float)radius }, 0, WHITE);

    // body
    if (isDead) {
        DrawTexturePro(playerBody4, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)PLAYER_SPRITE_RADIUS * 2, (float)PLAYER_SPRITE_RADIUS * 2 }, Vector2 { (float)PLAYER_SPRITE_RADIUS, (float)PLAYER_SPRITE_RADIUS}, 0, WHITE);
    } else if (!isRedActive && !isBlueActive) {
        switch (spikeAnimationFrame) {
            case 0:
                DrawTexturePro(playerBody1, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)PLAYER_SPRITE_RADIUS * 2, (float)PLAYER_SPRITE_RADIUS * 2 }, Vector2 { (float)PLAYER_SPRITE_RADIUS, (float)PLAYER_SPRITE_RADIUS}, 0, WHITE);
                break;
            case 1:
                DrawTexturePro(playerBody2, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)PLAYER_SPRITE_RADIUS * 2, (float)PLAYER_SPRITE_RADIUS * 2 }, Vector2 { (float)PLAYER_SPRITE_RADIUS, (float)PLAYER_SPRITE_RADIUS}, 0, WHITE);
                break;
            default:
                break;
        }
    } else {
        DrawTexturePro(playerBody3, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)PLAYER_SPRITE_RADIUS * 2, (float)PLAYER_SPRITE_RADIUS * 2 }, Vector2 { (float)PLAYER_SPRITE_RADIUS, (float)PLAYER_SPRITE_RADIUS}, 0, WHITE);
    }

    // red arm
    if (isDead) {
        DrawTexturePro(redArm3, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)PLAYER_SPRITE_RADIUS * 2, (float)PLAYER_SPRITE_RADIUS * 2 }, Vector2 { (float)PLAYER_SPRITE_RADIUS, (float)PLAYER_SPRITE_RADIUS}, rotation * 180/PI + 135, WHITE);
    } else if (!isRedActive) {
        switch (spikeAnimationFrame) {
            case 0:
                DrawTexturePro(redArm1, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)PLAYER_SPRITE_RADIUS * 2, (float)PLAYER_SPRITE_RADIUS * 2 }, Vector2 { (float)PLAYER_SPRITE_RADIUS, (float)PLAYER_SPRITE_RADIUS}, rotation * 180/PI + 135, WHITE);
                break;
            case 1:
                DrawTexturePro(redArm2, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)PLAYER_SPRITE_RADIUS * 2, (float)PLAYER_SPRITE_RADIUS * 2 }, Vector2 { (float)PLAYER_SPRITE_RADIUS, (float)PLAYER_SPRITE_RADIUS}, rotation * 180/PI + 135, WHITE);
                break;
            default:
                break;
        }
    } else {
        DrawTexturePro(redArm3, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)PLAYER_SPRITE_RADIUS * 2, (float)PLAYER_SPRITE_RADIUS * 2 }, Vector2 { (float)PLAYER_SPRITE_RADIUS, (float)PLAYER_SPRITE_RADIUS}, rotation * 180/PI + 135, WHITE);
    }

    // blue arm
    if (isDead) {
        DrawTexturePro(blueArm3, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)PLAYER_SPRITE_RADIUS * 2, (float)PLAYER_SPRITE_RADIUS * 2 }, Vector2 { (float)PLAYER_SPRITE_RADIUS, (float)PLAYER_SPRITE_RADIUS}, rotation * 180/PI + 135, WHITE);
    } else if (!isBlueActive) {
        switch (spikeAnimationFrame) {
            case 0:
                DrawTexturePro(blueArm1, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)PLAYER_SPRITE_RADIUS * 2, (float)PLAYER_SPRITE_RADIUS * 2 }, Vector2 { (float)PLAYER_SPRITE_RADIUS, (float)PLAYER_SPRITE_RADIUS}, rotation * 180/PI + 135, WHITE);
                break;
            case 1:
                DrawTexturePro(blueArm2, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)PLAYER_SPRITE_RADIUS * 2, (float)PLAYER_SPRITE_RADIUS * 2 }, Vector2 { (float)PLAYER_SPRITE_RADIUS, (float)PLAYER_SPRITE_RADIUS}, rotation * 180/PI + 135, WHITE);
                break;
            default:
                break;
        }
    } else {
        DrawTexturePro(blueArm3, Rectangle { 0, 0, 100, 100 }, Rectangle { pos.x, pos.y, (float)PLAYER_SPRITE_RADIUS * 2, (float)PLAYER_SPRITE_RADIUS * 2 }, Vector2 { (float)PLAYER_SPRITE_RADIUS, (float)PLAYER_SPRITE_RADIUS}, rotation * 180/PI + 135, WHITE);
    }
}

void Player::Drag() {
    // drag
    if (vel.x < 0) {
        vel.x = std::min(vel.x + PLAYER_DRAG * GetFrameTime(), 0.0f);
    } else if (vel.x > 0){
        vel.x = std::max(vel.x - PLAYER_DRAG * GetFrameTime(), 0.0f);
    }

    if (vel.y < 0) {
        vel.y = std::min(vel.y + PLAYER_DRAG * GetFrameTime(), 0.0f);
    } else if (vel.y > 0){
        vel.y = std::max(vel.y - PLAYER_DRAG * GetFrameTime(), 0.0f);
    }
}

void Player::AnchorInteract() {
    if (!isEnabled) return;

    // targeting detection
    rotation = atan2((mousePos.y - pos.y), (mousePos.x - pos.x));

    isMagnetSoundPlaying1 = false;
    for (int i = 0; i < (int)anchors.size(); ++i) {
        float dist = Vector2Distance(pos, anchors[i].pos);
        float xDiff = dist * cos(rotation);
        float yDiff = dist * sin(rotation);
        Vector2 dir = Vector2Normalize(Vector2Subtract(mousePos, pos));

        Vector2 final1 = { pos.x + xDiff, pos.y + yDiff };
        Vector2 final2 = { pos.x - xDiff, pos.y - yDiff };
    
        // reset white colour of anchor before collison check
        anchors[i].isActive = false;
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            // forward check (red)
            if (CheckCollisionPointCircle(final1, anchors[i].pos, ANCHOR_RADIUS)) {
                PlayMagnetStartSound1();
                isRedActive = true;
                anchors[i].isActive = true;
                if (anchors[i].isRed) {
                    vel = Vector2Add(vel, Repel(anchors[i].strength, dir, xDiff, yDiff, dist)); 
                } else {
                    vel = Vector2Add(vel, Attract(anchors[i].strength, dir, xDiff, yDiff, dist)); 
                }
            }

            // backward check (blue)
            if (CheckCollisionPointCircle(final2, anchors[i].pos, ANCHOR_RADIUS)) {
                PlayMagnetStartSound1();
                isBlueActive = true;
                anchors[i].isActive = true;
                if (anchors[i].isRed) {
                    vel = Vector2Add(vel, Attract(anchors[i].strength, dir, -xDiff, -yDiff, dist)); 
                } else {
                    vel = Vector2Add(vel, Repel(anchors[i].strength, dir, -xDiff, -yDiff, dist)); 
                }
            }
        }
    }

    PlayMagnetEndSound1();
    wasMagnetingLastUpdate1 = isMagnetSoundPlaying1;
}

void Player::SpikeInteract() {
    if (!isEnabled) return;

    // targeting detection
    rotation = atan2((mousePos.y - pos.y), (mousePos.x - pos.x));

    isMagnetSoundPlaying2 = false;
    for (int i = 0; i < (int)spikes.size(); ++i) {
        if (CheckCollisionCircles(pos, PLAYER_RADIUS, spikes[i].pos, SPIKE_RADIUS)) {
            isDead = true;
            isEnabled = false;

            if (isSoundsEnabled) {
                PlaySound(deathSound);
            }

            LoadLevel(curLevel);
            return;
        }

        float dist = Vector2Distance(pos, spikes[i].pos);
        float xDiff = dist * cos(rotation);
        float yDiff = dist * sin(rotation);
        Vector2 dir = Vector2Normalize(Vector2Subtract(mousePos, pos));

        Vector2 final1 = { pos.x + xDiff, pos.y + yDiff };
        Vector2 final2 = { pos.x - xDiff, pos.y - yDiff };
    
        // reset animation of spike before collison check
        spikes[i].isActive = false;
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            // forward check (red)
            if (CheckCollisionPointCircle(final1, spikes[i].pos, SPIKE_RADIUS)) {
                PlayMagnetStartSound2();
                isRedActive = true;
                spikes[i].isActive = true;
                if (spikes[i].isRed) {
                    vel = Vector2Add(vel, Repel(spikes[i].strength, dir, xDiff, yDiff, dist));
                    spikes[i].vel = Vector2Add(spikes[i].vel, Attract(spikes[i].strength, dir, xDiff, yDiff, dist));
                } else {
                    vel = Vector2Add(vel, Attract(spikes[i].strength, dir, xDiff, yDiff, dist)); 
                    spikes[i].vel = Vector2Add(spikes[i].vel, Repel(spikes[i].strength, dir, xDiff, yDiff, dist));
                }
            }

            // backward check (blue)
            if (CheckCollisionPointCircle(final2, spikes[i].pos, SPIKE_RADIUS)) {
                PlayMagnetStartSound2();
                isBlueActive = true;
                spikes[i].isActive = true;
                if (spikes[i].isRed) {
                    vel = Vector2Add(vel, Attract(spikes[i].strength, dir, -xDiff, -yDiff, dist)); 
                    spikes[i].vel = Vector2Add(spikes[i].vel, Attract(spikes[i].strength, dir, xDiff, yDiff, dist));
                } else {
                    vel = Vector2Add(vel, Repel(spikes[i].strength, dir, -xDiff, -yDiff, dist));
                    spikes[i].vel = Vector2Add(spikes[i].vel, Repel(spikes[i].strength, dir, xDiff, yDiff, dist));
                }
            }
        }
    }

    PlayMagnetEndSound2();
    wasMagnetingLastUpdate2 = isMagnetSoundPlaying2;
}

void Player::RockInteract() {
    if (!isEnabled) return;

    for (int i = 0; (float)i < rocks.size(); ++i) {
        if (CheckCollisionCircles(pos, PLAYER_RADIUS, rocks[i].pos, SPIKE_RADIUS)) {
            isDead = true;
            isEnabled = false;

            if (isSoundsEnabled) {
                PlaySound(deathSound);
            }

            LoadLevel(curLevel);
            return;
        }
    }
}

void Player::ExitInteract() {
    if (!isEnabled) return;

    if (CheckCollisionCircles(pos, PLAYER_RADIUS, levelExit.pos, EXIT_RADIUS) && isExitOn) {
        curLevel++;
        if (isSoundsEnabled) {
            PlaySound(finishSound);
        }
        LoadLevel(curLevel);
    }
}

void Player::StarInteract() {
    if (!isEnabled || star.isCollected) return;

    if (CheckCollisionCircles(pos, PLAYER_RADIUS, star.pos, STAR_RADIUS)) {
        starsCollected++;
        if (isSoundsEnabled) {
            PlaySound(starSound);
        }
        star.isCollected = true;
        star.isVisible = false;
        isExitOn = true;
    }
}

Vector2 Player::Attract(int strength, Vector2 dir, float xDiff, float yDiff, float dist) {
    float accX = strength * dir.x * GetFrameTime() * Clamp(Remap(dist, 0, MAX_DISTANCE, 1, 0), MIN_PLAYER_ACC_MULT, 1);
    float accY = strength * dir.y * GetFrameTime() * Clamp(Remap(dist, 0, MAX_DISTANCE, 1, 0), MIN_PLAYER_ACC_MULT, 1);
    if (xDiff < 0) {
        accX = -abs(accX);
    } else {
        accX = abs(accX);
    }

    if (yDiff < 0) {
        accY = -abs(accY);
    } else {
        accY = abs(accY);
    }

    return Vector2 { accX, accY };
}

Vector2 Player::Repel(int strength, Vector2 dir, float xDiff, float yDiff, float dist) {
    float accX = strength * -dir.x * GetFrameTime() * Clamp(Remap(dist, 0, MAX_DISTANCE, 1, 0), MIN_PLAYER_ACC_MULT, 1);
    float accY = strength * -dir.y * GetFrameTime() * Clamp(Remap(dist, 0, MAX_DISTANCE, 1, 0), MIN_PLAYER_ACC_MULT, 1);
    if (xDiff < 0) {
        accX = abs(accX);
    } else {
        accX = -abs(accX);
    }

    if (yDiff < 0) {
        accY = abs(accY);
    } else {
        accY = -abs(accY);
    }

    return Vector2 { accX, accY };
}

void Player::ClampVel() {
    // max velocity
    if (vel.x < 0 && vel.x < -PLAYER_MAX_SPEED) {
        vel.x = -PLAYER_MAX_SPEED;
    } else if (vel.x > 0 && vel.x > PLAYER_MAX_SPEED){
        vel.x = PLAYER_MAX_SPEED;
    }

    if (vel.y < 0 && vel.y < -PLAYER_MAX_SPEED) {
        vel.y = -PLAYER_MAX_SPEED;
    } else if (vel.y > 0 && vel.y > PLAYER_MAX_SPEED){
        vel.y = PLAYER_MAX_SPEED;
    }

    // min velocity
    if (vel.x < 0 && vel.x > -PLAYER_MIN_SPEED) {
        vel.x = 0;
    } else if (vel.x > 0 && vel.x < PLAYER_MIN_SPEED) {
        vel.x = 0;
    }

    // min velocity
    if (vel.y < 0 && vel.y > -PLAYER_MIN_SPEED) {
        vel.y = 0;
    } else if (vel.y > 0 && vel.y < PLAYER_MIN_SPEED) {
        vel.y = 0;
    }
}

void Player::ClampPos() {
    if (pos.x - PLAYER_SPRITE_RADIUS < 0) {
        pos.x = PLAYER_SPRITE_RADIUS;
        vel.x = 0;
    } else if (pos.x + PLAYER_SPRITE_RADIUS > SCREEN_WIDTH) {
        pos.x = SCREEN_WIDTH - PLAYER_SPRITE_RADIUS;
        vel.x = 0;
    }

    if (pos.y - PLAYER_SPRITE_RADIUS < 0) {
        pos.y = PLAYER_SPRITE_RADIUS;
        vel.y = 0;
    } else if (pos.y + PLAYER_SPRITE_RADIUS > SCREEN_HEIGHT) {
        pos.y = SCREEN_HEIGHT - PLAYER_SPRITE_RADIUS;
        vel.y = 0;
    }
}

void Player::PlayMagnetStartSound1() {
    if (!isSoundsEnabled) return;
    isMagnetSoundPlaying1 = true;
    if (IsSoundPlaying(magnetStartSound) || isMagneting1) return;
    isMagneting1 = true;
    if (IsSoundPlaying(magnetEndSound)) {
        StopSound(magnetEndSound);
    }
    PlaySound(magnetStartSound);
}

void Player::PlayMagnetEndSound1() {
    if (!isSoundsEnabled) return;
    if (IsSoundPlaying(magnetEndSound) || isMagnetSoundPlaying1 || !wasMagnetingLastUpdate1) return;
    isMagneting1 = false;
    if (IsSoundPlaying(magnetStartSound)) {
        StopSound(magnetStartSound);
    }
    PlaySound(magnetEndSound);
}

void Player::PlayMagnetStartSound2() {
    if (!isSoundsEnabled) return;
    isMagnetSoundPlaying2 = true;
    if (IsSoundPlaying(magnetStartSound) || isMagneting2) return;
    isMagneting2 = true;
    if (IsSoundPlaying(magnetEndSound)) {
        StopSound(magnetEndSound);
    }
    PlaySound(magnetStartSound);
}

void Player::PlayMagnetEndSound2() {
    if (!isSoundsEnabled) return;
    if (IsSoundPlaying(magnetEndSound) || isMagnetSoundPlaying2 || !wasMagnetingLastUpdate2) return;
    isMagneting2 = false;
    if (IsSoundPlaying(magnetStartSound)) {
        StopSound(magnetStartSound);
    }
    PlaySound(magnetEndSound);
}