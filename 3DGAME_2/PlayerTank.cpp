#include"PlayerTank.h"
#include"ShotBullet.h"
PlayerTank::PlayerTank()
{
	Initialize();
}


void PlayerTank::Initialize()
{
	// プレイヤー専用の初期化処理

	LoadModel();
	SetModel();
	angle = 270;	
}
void PlayerTank::LoadModel()
{
	// プレイヤー専用のモデルロード処理
	modelHandle = MV1LoadModel("data/model/vehicle/tank_red.mv1");
}
void PlayerTank::SetModel()
{	
	// プレイヤー専用のモデルセット処理
	position = VGet(6.0f, 0.0f, -11.0f);
	MV1SetPosition(modelHandle, position);
	MV1SetScale(modelHandle, VGet(ModelScale, ModelScale, ModelScale));
	MV1SetRotationXYZ(modelHandle, VGet(0.0f, ROTATE_270_DEG, 0.0f));
}

void PlayerTank::Shoot()
{
	if (canShoot)
	{
		// プレイヤー専用の射撃処理
		
		// 射撃処理を呼び出す
		canShoot = false;		// 射撃可能フラグをfalseにす
	}
}
void PlayerTank::Update()
{
	// プレイヤー専用の更新処理
	Move();
	

}
void PlayerTank::Move()
{
	//パッドの入力を取得
	GetJoypadAnalogInput(&padX, &padY, DX_INPUT_KEY_PAD1);
	padInput = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	//左移動
	if (padX<0||CheckHitKey(KEY_INPUT_A))
	{
		
		if (angle <= 180)//左を向いたら移動し始める
		{
			// 左に移動
			position.x -= 0.02f;
			angle = 180;
		}
		else
		{
			angle += padX / 250; // スティックの感度を調整するために適当に値を割る
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
	//右移動
	if (padX > 0||CheckHitKey(KEY_INPUT_D))
	{
		if (angle >= 360)//右を向いたら移動し始める
		{
			// 左に移動
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

	//移動範囲制限
	if (position.x >= 14.5f)
	{
		position.x = 14.5f;
	}	
	if (position.x <= -2.5f)
	{
		position.x = -2.5f;
	}
	//パッドの入力がないときデフォルト角度にもどす これがないと左に向いて戻った時の角度が270じゃなくなる
	if (angle <= 274&&266<=angle&& padX == 0)
	{
		angle = 270;
	}
	//弾発射処理
	if (angle == 270)
	{
		//球を射出する
		if (padInput& PAD_INPUT_2|| CheckHitKey(KEY_INPUT_SPACE))
		{
			printfDx("shot\n");
		
		}
	}

	//移動処理
	MV1SetRotationXYZ(modelHandle, VGet(0.0f, angle * DX_PI_F / 180.0f, 0.0f));
	MV1SetPosition(modelHandle, position);

	
}
void PlayerTank::Draw()
{
	// プレイヤー専用の描画処理
	MV1DrawModel(modelHandle);
	DrawBullets();
}

void PlayerTank::DrawBullets()
{
	// プレイヤー専用の弾の描画処理

}


