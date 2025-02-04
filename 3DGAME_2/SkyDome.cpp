#include"SkyDome.h"
SkyDome::SkyDome()
{

	Initialize();

}


void SkyDome::Initialize()
{
	skyDomeHandle = MV1LoadModel("data/model/skydome/Sunny/Dome_X501.pmx");
	MV1SetScale(skyDomeHandle, VGet(0.1f, 0.1f, 0.1f));
	position = VGet(0.0f, 0.0f, 0.0f);
	//プレイヤーのモデル座標を更新する
	MV1SetPosition(skyDomeHandle,position);
	//3dモデルのスケール決定
	MV1SetScale(skyDomeHandle, VGet(SKYDOME_SCALE, SKYDOME_SCALE, SKYDOME_SCALE));


}
void SkyDome::Draw()
{
	MV1DrawModel(skyDomeHandle);
}
void SkyDome::Update()
{
	//スカイドームを回転させる
	position.y -= 0.00003f;
	//プレイヤーのモデル座標を更新する
	MV1SetRotationXYZ(skyDomeHandle, VGet(0.0f, position.y, 0.0f));
}