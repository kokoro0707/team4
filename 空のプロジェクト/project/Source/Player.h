#pragma once
#include "../Library/gameObject.h"
#include "Vector2.h"

class Player:public GameObject
{
public:
	Player();
	~Player();
	void Update()override;
	void Draw() override;

	int hImage;
	VECTOR2 position;
	float velocity;
	bool prevJumpKey; // 前のジャンプキー
	bool onGround; // 地面にいる
	bool prevKey; //前のキーを保存する
	float timeElapsed;     // 経過時間
	bool isSpacePressed;   // スペースキーが押されたかどうかのフラグ

	int InputX, InputY;
	int Key;
	int speed = 2;

};

