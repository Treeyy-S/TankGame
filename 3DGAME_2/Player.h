#pragma once

#include"DxLib.h"
#include <iostream>
#include <vector>
#include <chrono>
//�萔
const int	MAP_WIDTH = 13;		//�}�b�v�̉���
const int	MAP_HEIGHT = 9;		//�}�b�v�̏c��

//�v���g�^�C�v�錾
class Map;
struct sMapLayer;

/// �v���C���[�̐F�i�񋓁j
enum PlayerNum
{
	RED, BLUE
};
/// �v���C���[�̍\����
struct Character
{
	VECTOR position;		//���W
	VECTOR speed;			//���x
	int modelHandle;		//���f���n���h��
	bool isLiveFlg = true;
};
// ���̍\����
struct Bullet {
	VECTOR position;    //���W
	VECTOR velocity;    //���x
	unsigned int color; //�F
};

//�v���C���[�N���X
class Player
{
public:
	/// �R���X�g���N�^
	Player();
	/// �f�X�g���N�^
	~Player();
	/// �`��
	void Draw();

	/// ������
	void Initialize();

	/// ���f�����[�h
	void LoadModel();

	/// ���f���Z�b�g
	void SetModel();

	//�X�V
	void Update();
	/// �V���b�g
	void Shot();
	void UpdateBullets();
	void DrawBullets();


private:
	
	static constexpr int PLAYER_NUM = 2;		//�v���C���[�̐�
	const float MODEL_SCALE = 0.002f;			//�X�P�[���i�S�������j
	const float MODEL_SPEED = 0.05f;			//�X�s�[�h�i�S�������j	
	const float MOVE_SPEED = 0.05f;				// �ړ����x
	Character characters[PLAYER_NUM];			//�v���C���[�\����	

	//�ŐV�}�b�v
	int mapChip[MAP_HEIGHT][MAP_WIDTH] = { 0 };	//�}�b�v�`�b�v

	Map* map;								//�}�b�v�N���X
	std::vector<Bullet> bullets;            // ���̃��X�g
	const float BULLET_SPEED = 0.1f;   // ���̑��x
	const float BULLET_RADIUS = 0.3f;  // ���̔��a
	const int BULLET_DIV_NUM = 32;     // ���̕�����
	std::chrono::time_point<std::chrono::steady_clock> lastShotTime; // �Ō�ɒe�𔭎˂�������

	//��]�@�萔
	const float ROTATE_90_DEG = 90.0f * DX_PI_F / 180.0f;	//90�x��]
	const float ROTATE_180_DEG = 180.0f * DX_PI_F / 180.0f;	//180�x��]
	const float ROTATE_270_DEG = 270.0f * DX_PI_F / 180.0f;	//270�x��]

	const int RED = GetColor(255, 0, 0);	//�F
	const int BLUE = GetColor(0, 0, 255);	//�F
	const int GREEN = GetColor(0, 255, 0);	//�F

};