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
	int hImage; //�摜
	VECTOR2 position;
	float timeElapsed;     // �o�ߎ���
	bool CheckCollisionWithRectangle(float rectX, float rectY, float rectWidth, float rectHeight);
	void GetBallCenter(int* centerX, int* centerY);			// �{�[���̒��S���W�̎擾
	void SetFlip(bool flagX, int flagY);					// �i�s�����̔��]


private:
	int ballVx, ballVy;				//	�{�[�����x(�t���[����)
	int radius;
<<<<<<< HEAD

=======
	
>>>>>>> 5c95bcf4d6dde1faf22398a59ddeb03df4ffed40

};

