#pragma once
#include"DxLib.h"
class Shot;
class PlayerTank  {
public:
	PlayerTank();

    // �v���C���[��p�̈ړ����\�b�h
	void Move();
    // �ˌ����\�b�h�̃I�[�o�[���C�h
    void Shoot() ;
	void Update() ;
	void Draw() ;
	void Initialize() ;
	void LoadModel() ;
	void SetModel() ;

	void DrawBullets() ;


public:
	//�萔
	const float ModelScale = 0.002f; //���f���̃X�P�[��	
	const float ROTATE_0_DEG = 0.0f * DX_PI_F / 180.0f;	//0�x��]
	const float ROTATE_90_DEG = 90.0f * DX_PI_F / 180.0f;	//90�x��]
	const float ROTATE_180_DEG = 180.0f * DX_PI_F / 180.0f;	//180�x��]
	const float ROTATE_270_DEG = 270.0f * DX_PI_F / 180.0f;	//270�x��]
	const float ROTATE_360_DEG = 360.0f * DX_PI_F / 180.0f;	//270�x��]
	
	
	Shot* shot;
	//�ϐ�
	VECTOR position;		//���W	
	VECTOR speed;			//���x
	int modelHandle;		//���f���n���h��
	bool canShoot;			// �ˌ��\�t���O
	float angle;				//�p�x
	int padX = 0, padY = 0;
	int padInput;

};