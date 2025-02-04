#pragma once
#include"DxLib.h"
class Shot;
class PlayerTank  {
public:
	PlayerTank();

    // プレイヤー専用の移動メソッド
	void Move();
    // 射撃メソッドのオーバーライド
    void Shoot() ;
	void Update() ;
	void Draw() ;
	void Initialize() ;
	void LoadModel() ;
	void SetModel() ;

	void DrawBullets() ;


public:
	//定数
	const float ModelScale = 0.002f; //モデルのスケール	
	const float ROTATE_0_DEG = 0.0f * DX_PI_F / 180.0f;	//0度回転
	const float ROTATE_90_DEG = 90.0f * DX_PI_F / 180.0f;	//90度回転
	const float ROTATE_180_DEG = 180.0f * DX_PI_F / 180.0f;	//180度回転
	const float ROTATE_270_DEG = 270.0f * DX_PI_F / 180.0f;	//270度回転
	const float ROTATE_360_DEG = 360.0f * DX_PI_F / 180.0f;	//270度回転
	
	
	Shot* shot;
	//変数
	VECTOR position;		//座標	
	VECTOR speed;			//速度
	int modelHandle;		//モデルハンドル
	bool canShoot;			// 射撃可能フラグ
	float angle;				//角度
	int padX = 0, padY = 0;
	int padInput;

};