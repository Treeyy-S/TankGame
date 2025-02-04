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
	//�v���C���[�̃��f�����W���X�V����
	MV1SetPosition(skyDomeHandle,position);
	//3d���f���̃X�P�[������
	MV1SetScale(skyDomeHandle, VGet(SKYDOME_SCALE, SKYDOME_SCALE, SKYDOME_SCALE));


}
void SkyDome::Draw()
{
	MV1DrawModel(skyDomeHandle);
}
void SkyDome::Update()
{
	//�X�J�C�h�[������]������
	position.y -= 0.00003f;
	//�v���C���[�̃��f�����W���X�V����
	MV1SetRotationXYZ(skyDomeHandle, VGet(0.0f, position.y, 0.0f));
}