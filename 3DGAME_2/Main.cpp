
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
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	//ウィンドウモード
	ChangeWindowMode(TRUE);
	//// 画面モードの設定
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 16);		// 解像度を1920*1080、colorを16bitに設定.
	////ウィンドウ名変更
	SetMainWindowText("HIDE AND HIT");
	//////描画先を裏画面に設定
	SetDrawScreen(DX_SCREEN_BACK);
	//Zバッファを有効
	SetWriteZBuffer3D(TRUE);
	SetUseLighting(TRUE);  // ライティングを有効にする
	SetUseSpecular(TRUE);  // 鏡面反射を有効にする
	SetUseZBuffer3D(TRUE); // Zバッファを有効にする
	
	FrameRateLimiter* frameRateLimiter = new FrameRateLimiter(60); // 60FPSに制限


	//インスタンス化
	Map* map = new Map(); 		// マップの生成
	SkyDome* skyDome = new SkyDome();	// スカイドームの生成	
	PlayerTank* playerTank = new PlayerTank();	// プレイヤータンクの生成
	EnemyTank* enemyTank = new EnemyTank();	// 敵タンクの生成
	UI* ui = new UI();	// UIの生成	
	//カメラの設定
	SetCamera();		// カメラの設定
	

	// メインループ
	while (!CheckHitKey(KEY_INPUT_ESCAPE))	// ESCキーが押されたらループを抜ける
	{
		ClearDrawScreen();		//描画クリア
		float deltaTime = frameRateLimiter->CalculateDeltaTime(); // deltaTimeの計算

		//描画系
		map->Draw();			//マップの描画
		skyDome->Draw();		// スカイドームの描画
		playerTank->Draw();		// プレイヤータンクの描画
		enemyTank->Draw();		// 敵タンクの描画
		ui->Draw();			// UIの描画	
		//更新系
	
		skyDome->Update();		// スカイドームの更新
		UpdateCamera(playerTank->position);	// カメラの更新
		playerTank->Update();		// プレイヤータンクの更新
		ScreenFlip();			//裏の画面を描画
	
		frameRateLimiter->Wait(); // フレームレートを制限

	}

	// メモリを解放
	delete frameRateLimiter; 

	DxLib_End();				// ＤＸライブラリ使用の終了処理
	return 0;					// ソフトの終了 
}