#pragma once
#include"DxLib.h"
#include <vector>
#include <algorithm>
struct Bullet {
    VECTOR position;    // 座標
    VECTOR velocity;    // 速度
    unsigned int color; // 色

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
    const int FIRE_COOLDOWN = 2000; // クールタイムは2秒（2000ミリ秒）

};