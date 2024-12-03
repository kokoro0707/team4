#pragma once
#include "../Library/gameObject.h"
#include "VECTOR2.h"


class Boll : public GameObject {
private:
	const int BALL_SPEED = 5;
public:
	Boll();
	~Boll();
	void Update() override;
	void Draw() override;
<<<<<<< HEAD

=======
	
>>>>>>> 5c95bcf4d6dde1faf22398a59ddeb03df4ffed40
	int hImage; //画像
	VECTOR2 position;
	float timeElapsed;     // 経過時間
	bool CheckCollisionWithRectangle(float rectX, float rectY, float rectWidth, float rectHeight);
	void GetBallCenter(int* centerX, int* centerY);			// ボールの中心座標の取得
	void SetFlip(bool flagX, int flagY);					// 進行方向の反転


private:
	int ballVx, ballVy;				//	ボール速度(フレーム毎)
	int radius;
<<<<<<< HEAD

=======
	
>>>>>>> 5c95bcf4d6dde1faf22398a59ddeb03df4ffed40

};

