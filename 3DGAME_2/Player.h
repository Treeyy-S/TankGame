#pragma once

#include"DxLib.h"
#include <iostream>
#include <vector>
#include <chrono>
//定数
const int	MAP_WIDTH = 13;		//マップの横幅
const int	MAP_HEIGHT = 9;		//マップの縦幅

//プロトタイプ宣言
class Map;
struct sMapLayer;

/// プレイヤーの色（列挙）
enum PlayerNum
{
	RED, BLUE
};
/// プレイヤーの構造体
struct Character
{
	VECTOR position;		//座標
	VECTOR speed;			//速度
	int modelHandle;		//モデルハンドル
	bool isLiveFlg = true;
};
// 球の構造体
struct Bullet {
	VECTOR position;    //座標
	VECTOR velocity;    //速度
	unsigned int color; //色
};

//プレイヤークラス
class Player
{
public:
	/// コンストラクタ
	Player();
	/// デストラクタ
	~Player();
	/// 描画
	void Draw();

	/// 初期化
	void Initialize();

	/// モデルロード
	void LoadModel();

	/// モデルセット
	void SetModel();

	//更新
	void Update();
	/// ショット
	void Shot();
	void UpdateBullets();
	void DrawBullets();


private:
	
	static constexpr int PLAYER_NUM = 2;		//プレイヤーの数
	const float MODEL_SCALE = 0.002f;			//スケール（全部同じ）
	const float MODEL_SPEED = 0.05f;			//スピード（全部同じ）	
	const float MOVE_SPEED = 0.05f;				// 移動速度
	Character characters[PLAYER_NUM];			//プレイヤー構造体	

	//最新マップ
	int mapChip[MAP_HEIGHT][MAP_WIDTH] = { 0 };	//マップチップ

	Map* map;								//マップクラス
	std::vector<Bullet> bullets;            // 球のリスト
	const float BULLET_SPEED = 0.1f;   // 球の速度
	const float BULLET_RADIUS = 0.3f;  // 球の半径
	const int BULLET_DIV_NUM = 32;     // 球の分割数
	std::chrono::time_point<std::chrono::steady_clock> lastShotTime; // 最後に弾を発射した時間

	//回転　定数
	const float ROTATE_90_DEG = 90.0f * DX_PI_F / 180.0f;	//90度回転
	const float ROTATE_180_DEG = 180.0f * DX_PI_F / 180.0f;	//180度回転
	const float ROTATE_270_DEG = 270.0f * DX_PI_F / 180.0f;	//270度回転

	const int RED = GetColor(255, 0, 0);	//色
	const int BLUE = GetColor(0, 0, 255);	//色
	const int GREEN = GetColor(0, 255, 0);	//色

};