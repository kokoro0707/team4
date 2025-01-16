#pragma once
#include "../Library/gameObject.h"
#include "VECTOR2.h"



class Boll2 : public GameObject {
private:

	const int BALL_SPEED = 5;

	//	int ballVx, ballVy;				//	ボール速度(フレーム毎)
	int radius;//	半径
	VECTOR2 baseNormalize;
	VECTOR2 targetNormalize;
	VECTOR2 center;// 壁に当たっているかどうか
	float timeHitWall;  // 壁に当たった時刻（秒）

public:
	Boll2();
	~Boll2();
	void Update() override;
	void Draw() override;
	bool isWallRight;

	int hImage; //画像
	VECTOR2 position;
<<<<<<< HEAD
=======
	VECTOR2 shotDirection;
>>>>>>> Collision
	VECTOR2 velocity;
	float timeElapsed;     // 経過時間
	bool attacking;
	bool CheckCollisionWithRectangle(float rectX, float rectY, float rectWidth, float rectHeight);
<<<<<<< HEAD
	void GetBallCenter(int* centerX, int* centerY);			// ボールの中心座標の取得
=======
	void GetBallCenter(int* centerX, int* centerY);	
	
	void Shot(VECTOR2 target, VECTOR2 startPosition);
>>>>>>> Collision






};

