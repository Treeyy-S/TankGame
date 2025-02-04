#pragma once
#include"DxLib.h"

class EnemyTank {
public:
	EnemyTank();


	// 敵専用の移動メソッド (例: ランダム移動)
	void MoveRandom();
	//int direction = rand() % 2; // 0か1をランダムで取得
//      switch (direction) {
//      case 0: Move(1, 0); break; // 右に移動
//      case 1: Move(-1, 0); break; // 左に移動
//      }

  // 射撃メソッドのオーバーライド
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
	//定数
	const float ModelScale = 0.002f; //モデルのスケール	
	const float ROTATE_90_DEG = 90.0f * DX_PI_F / 180.0f;	//90度回転
	const float ROTATE_180_DEG = 180.0f * DX_PI_F / 180.0f;	//180度回転
	const float ROTATE_270_DEG = 270.0f * DX_PI_F / 180.0f;	//270度回転
	//変数
	VECTOR position;		//座標	
	VECTOR speed;			//速度
	int modelHandle;		//モデルハンドル	
	bool canShoot;			// 射撃可能フラグ
};