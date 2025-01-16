#pragma once
#include "../Library/gameObject.h"
#include "VECTOR2.h"


class Boll : public GameObject {
private:
	
	const int BALL_SPEED = 5;
//	int ballVx, ballVy;				//	�{�[�����x(�t���[����)
	int radius;//	���a
	VECTOR2 baseNormalize;
	VECTOR2 targetNormalize;
	VECTOR2 center;// �ǂɓ������Ă��邩�ǂ���
	float timeHitWall;  // �ǂɓ������������i�b�j

public:
	Boll();
	~Boll();
	void Update() override;
	void Draw() override;
	bool isWallRight;
<<<<<<< HEAD
=======
	bool IsWalLeft;
>>>>>>> Collision
	
	int hImage; //�摜
	VECTOR2 position;
	VECTOR2 shotDirection;
	VECTOR2 velocity;
	float timeElapsed;     // �o�ߎ���
	bool attacking;
	bool CheckCollisionWithRectangle(float rectX, float rectY, float rectWidth, float rectHeight);
	void GetBallCenter(int* centerX, int* centerY);			// �{�[���̒��S���W�̎擾
	void SetFlip(bool flagX, int flagY);					// �i�s�����̔��]

		void Shot(VECTOR2 target, VECTOR2 startPosition);

	

};

