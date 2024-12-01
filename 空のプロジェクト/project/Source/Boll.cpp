#include "Boll.h"
#include <cmath> 
#include "Player.h"
#include"config.h"
#include "Stage.h"

Boll::Boll()
{
	hImage = LoadGraph("data/image/Stone.png");
	position.x = 10;
	position.y = 10;

}

Boll::~Boll()
{
	DeleteGraph(hImage);
}

void Boll::Update()
{
	position.x += 5.0f;
	// 5秒経過したらオブジェクトを消す
	timeElapsed += Time::DeltaTime();  // 経過時間を加算

	if (timeElapsed >= 5.0f) {
		DestroyMe();  // 5秒経過したらオブジェクトを消す
	}

}

void Boll::Draw()
{
	DrawRectGraph(position.x, position.y, 0, 0, 64, 64, hImage, TRUE);
}

// ボールの中心座標の取得
void Boll::GetBallCenter(int* centerX, int* centerY)
{
}

// 進行方向の反転
void Boll::SetFlip(bool flagX, int flagY)
{
	// X方向の反転
	if (flagX)
	{
		ballVy = -ballVy;
	}
	// Y方向の反転
	if (flagY)
	{
		ballVy = -ballVy;
	}
}