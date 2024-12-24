#include "Boll.h"
#include <cmath> e
#include "Player.h"
#include"config.h"
#include <cassert>
#include "Stage.h"

Boll::Boll()
{
	hImage = LoadGraph("data/image/Effect.png");
	position.x = 10;
	position.y = 10;

	//	移動速度
//	ballVx = BALL_SPEED;
//	ballVy = BALL_SPEED;
	velocity.x = BALL_SPEED;
	velocity.y = BALL_SPEED;
}

Boll::~Boll()
{
	DeleteGraph(hImage);
}

void Boll::Update()
{
	position += velocity;

	//	画面端判定(X方向)
	if ((position.x < 0) || (position.y > SCREEN_WIDTH))
	{
		DestroyMe();
	}
	// 画面端判定(Y方向...上のみ) 
	// 画面下に行ったらミス 
	// 
	//isMiss = ballY > bottom - (radius * 2);

	Stage* s = FindGameObject<Stage>();
	if (s->IsWallRight(position) > 0) {
		//別な画像にする
		DestroyMe(); // とりあえず
	}
	//	プレイヤーとの当たり判定
//	if (CheckPlayerHit())
//	{
		// Hitサウンドの再生 
		//PlaySoundMem(hitSoundHandle, DX_PLAYTYPE_BACK);

		//	プレイヤーと当たった
//		ballVy = -ballVy;
//	}
}

void Boll::Draw()
{
	DrawRectGraph(position.x, position.y, 0, 0, 32, 32, hImage, TRUE);
}

// ボールの中心座標の取得
void Boll::GetBallCenter(int* centerX, int* centerY)
{
}

// 進行方向の反転
void Boll::SetFlip(bool flagX, int flagY)
{
	// X方向の反転
//	if (flagX)
//	{
//		ballVy = -ballVy;
//	}
	// Y方向の反転
//	if (flagY)
//	{
//		ballVy = -ballVy;
//	}
}

