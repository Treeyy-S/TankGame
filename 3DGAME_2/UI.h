#pragma once
#include"DxLib.h"
class UI
{
public:
	UI();
	~UI();
	void Initialize();
	void Update();
	void Load();
	void Draw();
	
private:
	int reticleImg;
};
