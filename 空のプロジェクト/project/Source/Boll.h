#pragma once
#include "../Library/gameObject.h"
#include "VECTOR2.h"


class Boll : public GameObject {
private:
	
	const int BALL_SPEED = 100;
private:
	int ballVx, ballVy;				//	ボール速度(フレーム毎)
	int radius;//	半径

public:
	Boll();
	~Boll();
	void Update() override;
	void Draw() override;
	
	int hImage; //画像
	VECTOR2 position;
	float timeElapsed;     // 経過時間
	bool CheckCollisionWithRectangle(float rectX, float rectY, float rectWidth, float rectHeight);
	void GetBallCenter(int* centerX, int* centerY);			// ボールの中心座標の取得
	void SetFlip(bool flagX, int flagY);					// 進行方向の反転



	

};

