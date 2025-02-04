#include"PlayerTank.h"
#include"ShotBullet.h"
PlayerTank::PlayerTank()
{
	Initialize();
}


void PlayerTank::Initialize()
{
	// �v���C���[��p�̏���������

	LoadModel();
	SetModel();
	angle = 270;	
}
void PlayerTank::LoadModel()
{
	// �v���C���[��p�̃��f�����[�h����
	modelHandle = MV1LoadModel("data/model/vehicle/tank_red.mv1");
}
void PlayerTank::SetModel()
{	
	// �v���C���[��p�̃��f���Z�b�g����
	position = VGet(6.0f, 0.0f, -11.0f);
	MV1SetPosition(modelHandle, position);
	MV1SetScale(modelHandle, VGet(ModelScale, ModelScale, ModelScale));
	MV1SetRotationXYZ(modelHandle, VGet(0.0f, ROTATE_270_DEG, 0.0f));
}

void PlayerTank::Shoot()
{
	if (canShoot)
	{
		// �v���C���[��p�̎ˌ�����
		
		// �ˌ��������Ăяo��
		canShoot = false;		// �ˌ��\�t���O��false�ɂ�
	}
}
void PlayerTank::Update()
{
	// �v���C���[��p�̍X�V����
	Move();
	

}
void PlayerTank::Move()
{
	//�p�b�h�̓��͂��擾
	GetJoypadAnalogInput(&padX, &padY, DX_INPUT_KEY_PAD1);
	padInput = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	//���ړ�
	if (padX<0||CheckHitKey(KEY_INPUT_A))
	{
		
		if (angle <= 180)//������������ړ����n�߂�
		{
			// ���Ɉړ�
			position.x -= 0.02f;
			angle = 180;
		}
		else
		{
			angle += padX / 250; // �X�e�B�b�N�̊��x�𒲐����邽�߂ɓK���ɒl������
			if (CheckHitKey(KEY_INPUT_A))
			{
				angle -= 4;
			}
		}
	}
	else if(padX == 0 && angle <= 270)
	{
		angle += 4;
	}
	//�E�ړ�
	if (padX > 0||CheckHitKey(KEY_INPUT_D))
	{
		if (angle >= 360)//�E����������ړ����n�߂�
		{
			// ���Ɉړ�
			position.x += 0.02f;
			angle = 360;
		}
		else
		{
			angle += padX / 250;
			if (CheckHitKey(KEY_INPUT_D))
			{
				angle += 4;
			}
		}
	}
	else if (padX == 0 && angle >= 270)
	{
		angle -= 4;
	}

	//�ړ��͈͐���
	if (position.x >= 14.5f)
	{
		position.x = 14.5f;
	}	
	if (position.x <= -2.5f)
	{
		position.x = -2.5f;
	}
	//�p�b�h�̓��͂��Ȃ��Ƃ��f�t�H���g�p�x�ɂ��ǂ� ���ꂪ�Ȃ��ƍ��Ɍ����Ė߂������̊p�x��270����Ȃ��Ȃ�
	if (angle <= 274&&266<=angle&& padX == 0)
	{
		angle = 270;
	}
	//�e���ˏ���
	if (angle == 270)
	{
		//�����ˏo����
		if (padInput& PAD_INPUT_2|| CheckHitKey(KEY_INPUT_SPACE))
		{
			printfDx("shot\n");
		
		}
	}

	//�ړ�����
	MV1SetRotationXYZ(modelHandle, VGet(0.0f, angle * DX_PI_F / 180.0f, 0.0f));
	MV1SetPosition(modelHandle, position);

	
}
void PlayerTank::Draw()
{
	// �v���C���[��p�̕`�揈��
	MV1DrawModel(modelHandle);
	DrawBullets();
}

void PlayerTank::DrawBullets()
{
	// �v���C���[��p�̒e�̕`�揈��

}


