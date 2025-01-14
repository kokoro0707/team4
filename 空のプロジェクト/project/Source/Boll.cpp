#include "Boll.h"
#include <cmath> e
#include "Player.h"
#include"config.h"
#include <cassert>
#include "Stage.h"
#include "Target.h"

Boll::Boll()
{
	hImage = LoadGraph("data/image/Efect.png");
	position.x = 10;
	position.y = 0;

	//	移動速度
//	ballVx = BALL_SPEED;
//	ballVy = BALL_SPEED;
	velocity.x = BALL_SPEED;
	velocity.y = BALL_SPEED;
	timeHitWall = -1.0f;
}

Boll::~Boll()
{
	DeleteGraph(hImage);
}

void Boll::Update()
{
	Target* target = FindGameObject<Target>();

	VECTOR2 to = VSub(target->position, position);
	to = VNorm(to);
	position = position + VScale(to, 6.0f);

	//	画面端判定(X方向)
	if ((position.x < 0) || (position.y > SCREEN_WIDTH))
	{
		DestroyMe();
	}
	if ((position.y < 0) || (position.y > SCREEN_HEIGHT)) {
		DestroyMe();
	}
	// 画面端判定(Y方向...上のみ) 
	// 画面下に行ったらミス 
	// 
	//isMiss = ballY > bottom - (radius * 2);

	Stage* s = FindGameObject<Stage>();
	if (s->IsWallRight(position) > 0) {
		if (isWallRight) {
			// 壁に当たっている場合、別の画像を描画
			DrawRectGraph(position.x, position.y, 40, 40, 80, 80, hImage, TRUE);

			// 円形の当たり判定を描画
			DrawCircle(position.x + 32, position.y + 32, 40, GetColor(255, 0, 0));  // 赤い円
		}
		else {
			// 壁に当たっていない場合、元の画像を描画
			DrawRectGraph(position.x, position.y, 0, 0, 32, 32, hImage, TRUE);
		}

		// 壁に当たったらオブジェクトを消す
		DestroyMe();
	}
	else {
		// 壁に当たっていない場合、通常の描画
		DrawRectGraph(position.x, position.y, 0, 0, 32, 32, hImage, TRUE);
	}
}

void Boll::Draw()
{
	DrawRectGraph(position.x, position.y, 0, 0, 32, 32, hImage, TRUE);
}

// ボールの中心座標の取得
void Boll::GetBallCenter(int* centerX, int* centerY)
{
	*centerX = (int)position.x;
	*centerY = (int)position.y;
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

