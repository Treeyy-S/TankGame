#pragma once
#include"DxLib.h"

class EnemyTank {
public:
	EnemyTank();


	// �G��p�̈ړ����\�b�h (��: �����_���ړ�)
	void MoveRandom();
	//int direction = rand() % 2; // 0��1�������_���Ŏ擾
//      switch (direction) {
//      case 0: Move(1, 0); break; // �E�Ɉړ�
//      case 1: Move(-1, 0); break; // ���Ɉړ�
//      }

  // �ˌ����\�b�h�̃I�[�o�[���C�h
	void Shoot();
	void Update();
	void Draw();
	void Initialize();
	void LoadModel();
	void SetModel();
	void Shot();
	void UpdateBullets();
	void DrawBullets();
private:
	//�萔
	const float ModelScale = 0.002f; //���f���̃X�P�[��	
	const float ROTATE_90_DEG = 90.0f * DX_PI_F / 180.0f;	//90�x��]
	const float ROTATE_180_DEG = 180.0f * DX_PI_F / 180.0f;	//180�x��]
	const float ROTATE_270_DEG = 270.0f * DX_PI_F / 180.0f;	//270�x��]
	//�ϐ�
	VECTOR position;		//���W	
	VECTOR speed;			//���x
	int modelHandle;		//���f���n���h��	
	bool canShoot;			// �ˌ��\�t���O
};