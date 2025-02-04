#include"UI.h"
#include"Screen.h"
UI::UI()
{
	Initialize();
}

UI::~UI()
{
}

void UI::Initialize()
{
	Load();
}

void UI::Load()
{
	reticleImg = LoadGraph("data/texture/ui/reticle.png");
}

void UI::Draw()
{
	
	DrawExtendGraph(SCREEN_WIDTH / 2-50, SCREEN_HEIGHT / 2-200, SCREEN_WIDTH / 2 + 50, SCREEN_HEIGHT / 2 - 100, reticleImg, TRUE);
}
void UI::Update()
{
}