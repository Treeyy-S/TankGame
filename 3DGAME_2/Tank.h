#pragma once
#include"DxLib.h"
class Tank {
public:
    int x, y;  // �ʒu
    int speed; // �ړ����x
    int health; // �w���X
    bool canShoot; // �ˌ��\���ǂ���

    int modelHandle; // ���f���n���h��


    Tank(int startX, int startY, int startSpeed, int startHealth)
        : x(startX), y(startY), speed(startSpeed), health(startHealth), canShoot(true) {
    }

    virtual ~Tank() {}

    // �ړ����\�b�h
    virtual void Move(int dx, int dy) {
        x += dx * speed;
        y += dy * speed;
    }

    // �ˌ����\�b�h (���z�֐��ɂ��Ă���)
    virtual void Shoot() {
        if (canShoot) {
            // �e�𔭎˂��鏈��
            canShoot = false; // �ˌ���͈ꎞ�I�Ɏˌ��s�\�ɂ���i�N�[���^�C���Ȃǁj
        }
    }

    // �_���[�W���󂯂郁�\�b�h
    virtual void TakeDamage(int damage) {
        health -= damage;
        if (health <= 0) {
            // �^���N���j�󂳂ꂽ�Ƃ��̏���
        }
    }
};