#pragma once
#include "../Library/gameObject.h"
#include "VECTOR2.h"


class Boll : public GameObject {
private:
	
	const int BALL_SPEED = 100;
private:
	int ballVx, ballVy;				//	�{�[�����x(�t���[����)
	int radius;//	���a

public:
	Boll();
	~Boll();
	void Update() override;
	void Draw() override;
	
	int hImage; //�摜
	VECTOR2 position;
	float timeElapsed;     // �o�ߎ���
	bool CheckCollisionWithRectangle(float rectX, float rectY, float rectWidth, float rectHeight);
	void GetBallCenter(int* centerX, int* centerY);			// �{�[���̒��S���W�̎擾
	void SetFlip(bool flagX, int flagY);					// �i�s�����̔��]



	

};

