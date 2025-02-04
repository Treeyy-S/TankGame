#pragma once
#include"DxLib.h"
class SkyDome
{

public:
	SkyDome();
	~SkyDome();
	void Initialize();
	void Draw();
	void Update();	



private:
	int skyDomeHandle;
	VECTOR position;
	const float SKYDOME_SCALE = 0.1f;	
};