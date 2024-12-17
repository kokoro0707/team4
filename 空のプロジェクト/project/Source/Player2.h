#pragma once
#include "../Library/gameObject.h"
#include "Vector2.h"

class Player2 :public GameObject
{
public:
	Player2();
	~Player2();
	void Update()override;
	void Draw() override;

	int BaImage;
	int hImage;
	VECTOR2 position;
	float velocity;
	bool prevJumpKey; // 前のジャンプキー
	bool onGround; // 地面にいる
	bool prevKey; //前のキーを保存する
	bool prevKey2;
	bool prevKeyUP;
	bool prevKeyDown;
	bool prevKeyRight;
	bool prevKeyLeft;
	float timeElapsed;     // 経過時間
	bool isSpacePressed;   // スペースキーが押されたかどうかのフラグ

	int InputX, InputY;
	int Key;
	float speed = 0.0f;
	float a = 0.08;
	int dashspeed = 4;
	float timer;

private:
	VECTOR2 baseNormalize;
	VECTOR2 targetNormalize;
	float angle;
	VECTOR2 center;
};

