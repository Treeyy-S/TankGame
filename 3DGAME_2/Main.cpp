
#include"DxLib.h"
#include"Map.h"
#include"Screen.h"
#include"Camera.h"

#include"PlayerTank.h"
#include"EnemyTank.h"

#include"SkyDome.h"


#include"UI.h"

#include"FrameRateLimiter.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}
	//�E�B���h�E���[�h
	ChangeWindowMode(TRUE);
	//// ��ʃ��[�h�̐ݒ�
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 16);		// �𑜓x��1920*1080�Acolor��16bit�ɐݒ�.
	////�E�B���h�E���ύX
	SetMainWindowText("HIDE AND HIT");
	//////�`���𗠉�ʂɐݒ�
	SetDrawScreen(DX_SCREEN_BACK);
	//Z�o�b�t�@��L��
	SetWriteZBuffer3D(TRUE);
	SetUseLighting(TRUE);  // ���C�e�B���O��L���ɂ���
	SetUseSpecular(TRUE);  // ���ʔ��˂�L���ɂ���
	SetUseZBuffer3D(TRUE); // Z�o�b�t�@��L���ɂ���
	
	FrameRateLimiter* frameRateLimiter = new FrameRateLimiter(60); // 60FPS�ɐ���


	//�C���X�^���X��
	Map* map = new Map(); 		// �}�b�v�̐���
	SkyDome* skyDome = new SkyDome();	// �X�J�C�h�[���̐���	
	PlayerTank* playerTank = new PlayerTank();	// �v���C���[�^���N�̐���
	EnemyTank* enemyTank = new EnemyTank();	// �G�^���N�̐���
	UI* ui = new UI();	// UI�̐���	
	//�J�����̐ݒ�
	SetCamera();		// �J�����̐ݒ�
	

	// ���C�����[�v
	while (!CheckHitKey(KEY_INPUT_ESCAPE))	// ESC�L�[�������ꂽ�烋�[�v�𔲂���
	{
		ClearDrawScreen();		//�`��N���A
		float deltaTime = frameRateLimiter->CalculateDeltaTime(); // deltaTime�̌v�Z

		//�`��n
		map->Draw();			//�}�b�v�̕`��
		skyDome->Draw();		// �X�J�C�h�[���̕`��
		playerTank->Draw();		// �v���C���[�^���N�̕`��
		enemyTank->Draw();		// �G�^���N�̕`��
		ui->Draw();			// UI�̕`��	
		//�X�V�n
	
		skyDome->Update();		// �X�J�C�h�[���̍X�V
		UpdateCamera(playerTank->position);	// �J�����̍X�V
		playerTank->Update();		// �v���C���[�^���N�̍X�V
		ScreenFlip();			//���̉�ʂ�`��
	
		frameRateLimiter->Wait(); // �t���[�����[�g�𐧌�

	}

	// �����������
	delete frameRateLimiter; 

	DxLib_End();				// �c�w���C�u�����g�p�̏I������
	return 0;					// �\�t�g�̏I�� 
}