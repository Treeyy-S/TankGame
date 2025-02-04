#include"EnemyTank.h"




EnemyTank::EnemyTank()
{
	Initialize();
}


void EnemyTank::Initialize()
{
	// �G��p�̏���������
	LoadModel();
	SetModel();

}

void EnemyTank::LoadModel()
{
	// �G��p�̃��f�����[�h����
	modelHandle=MV1LoadModel("data/model/vehicle/tank_blue.mv1");


}
void EnemyTank::SetModel()
{
	// �v���C���[��p�̃��f���Z�b�g����
	position = VGet(6.0f, 0.0f,5.0f);
	MV1SetPosition(modelHandle, position);
	MV1SetScale(modelHandle, VGet(ModelScale, ModelScale, ModelScale));
	MV1SetRotationXYZ(modelHandle, VGet(0.0f,ROTATE_90_DEG,0.0f ));
}
void EnemyTank::Draw()
{
	// �G��p�̕`�揈��
	MV1DrawModel(modelHandle);
}	