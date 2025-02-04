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
	int groundHandle;	//地面のハンドル
	int townHandle;		//townのハンドル

	const float GROUND_MODEL_SCALE = 0.03f; //地面のスケール
	const float TOWN_MODEL_SCALE = 0.01f; //townのスケール

	const float TOWN_POS_X = 6.0f;			//townの位置X
	const float TOWN_POS_Y = 0.0f;			//townの位置Y
	const float TOWN_POS_Z = -3.5f;			//townの位置Z

	const VECTOR GROUND_MODEL_POSITION_VECTOR = VGet(0.0f, -0.1f, 0.0f);
	const VECTOR GROUND_MODEL_SCALE_VECTOR = VGet(GROUND_MODEL_SCALE, GROUND_MODEL_SCALE, GROUND_MODEL_SCALE);
	const VECTOR TOWN_MODEL_POSITION_VECTOR = VGet(TOWN_POS_X, TOWN_POS_Y, TOWN_POS_Z);
	const VECTOR TOWN_MODEL_SCALE_VECTOR = VGet(TOWN_MODEL_SCALE, TOWN_MODEL_SCALE, TOWN_MODEL_SCALE);

};