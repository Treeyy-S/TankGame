#pragma once
#pragma once
#include"DxLib.h"

class Map
{
public:
	Map();
	~Map();
	void Initialize();
	void Draw();

private:
	int groundHandle;	//�n�ʂ̃n���h��
	int townHandle;		//town�̃n���h��

	const float GROUND_MODEL_SCALE = 0.03f; //�n�ʂ̃X�P�[��
	const float TOWN_MODEL_SCALE = 0.01f; //town�̃X�P�[��

	const float TOWN_POS_X = 6.0f;			//town�̈ʒuX
	const float TOWN_POS_Y = 0.0f;			//town�̈ʒuY
	const float TOWN_POS_Z = -3.5f;			//town�̈ʒuZ

	const VECTOR GROUND_MODEL_POSITION_VECTOR = VGet(0.0f, -0.1f, 0.0f);
	const VECTOR GROUND_MODEL_SCALE_VECTOR = VGet(GROUND_MODEL_SCALE, GROUND_MODEL_SCALE, GROUND_MODEL_SCALE);
	const VECTOR TOWN_MODEL_POSITION_VECTOR = VGet(TOWN_POS_X, TOWN_POS_Y, TOWN_POS_Z);
	const VECTOR TOWN_MODEL_SCALE_VECTOR = VGet(TOWN_MODEL_SCALE, TOWN_MODEL_SCALE, TOWN_MODEL_SCALE);

};