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
	float timeElapsed;     // 経過時間
	bool isSpacePressed;   // スペースキーが押されたかどうかのフラグ

	int InputX, InputY;
	int Key;
	int speed = 3;
	int dashspeed = 4;
	float timer;
	float Angel = 0.0f;

};

