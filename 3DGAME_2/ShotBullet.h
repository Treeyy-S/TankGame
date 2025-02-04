#pragma once
#include"DxLib.h"
#include <vector>
#include <algorithm>
struct Bullet {
    VECTOR position;    // ���W
    VECTOR velocity;    // ���x
    unsigned int color; // �F

    Bullet(VECTOR pos, VECTOR vel, unsigned int col)
        : position(pos), velocity(vel), color(col) {
    }
};

class ShotBullet
{
    void draw();
    void shot();
    void update();
private:
    std::vector<Bullet> bullets;
    int lastFireTime;
    const int FIRE_COOLDOWN = 2000; // �N�[���^�C����2�b�i2000�~���b�j

};