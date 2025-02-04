#pragma once
#include"DxLib.h"
class Tank {
public:
    int x, y;  // 位置
    int speed; // 移動速度
    int health; // ヘルス
    bool canShoot; // 射撃可能かどうか

    int modelHandle; // モデルハンドル


    Tank(int startX, int startY, int startSpeed, int startHealth)
        : x(startX), y(startY), speed(startSpeed), health(startHealth), canShoot(true) {
    }

    virtual ~Tank() {}

    // 移動メソッド
    virtual void Move(int dx, int dy) {
        x += dx * speed;
        y += dy * speed;
    }

    // 射撃メソッド (仮想関数にしておく)
    virtual void Shoot() {
        if (canShoot) {
            // 弾を発射する処理
            canShoot = false; // 射撃後は一時的に射撃不可能にする（クールタイムなど）
        }
    }

    // ダメージを受けるメソッド
    virtual void TakeDamage(int damage) {
        health -= damage;
        if (health <= 0) {
            // タンクが破壊されたときの処理
        }
    }
};