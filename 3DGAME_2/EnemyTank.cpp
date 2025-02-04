#include"EnemyTank.h"




EnemyTank::EnemyTank()
{
	Initialize();
}


void EnemyTank::Initialize()
{
	// 敵専用の初期化処理
	LoadModel();
	SetModel();

}

void EnemyTank::LoadModel()
{
	// 敵専用のモデルロード処理
	modelHandle=MV1LoadModel("data/model/vehicle/tank_blue.mv1");


}
void EnemyTank::SetModel()
{
	// プレイヤー専用のモデルセット処理
	position = VGet(6.0f, 0.0f,5.0f);
	MV1SetPosition(modelHandle, position);
	MV1SetScale(modelHandle, VGet(ModelScale, ModelScale, ModelScale));
	MV1SetRotationXYZ(modelHandle, VGet(0.0f,ROTATE_90_DEG,0.0f ));
}
void EnemyTank::Draw()
{
	// 敵専用の描画処理
	MV1DrawModel(modelHandle);
}	