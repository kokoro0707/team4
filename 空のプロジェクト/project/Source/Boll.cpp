#include "Boll.h"
#include <cmath> 
#include "Player.h"
#include"config.h"
<<<<<<< HEAD
#include "Stage.h"
=======
>>>>>>> 5c95bcf4d6dde1faf22398a59ddeb03df4ffed40

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
	// 5�b�o�߂�����I�u�W�F�N�g������
	timeElapsed += Time::DeltaTime();  // �o�ߎ��Ԃ����Z

	if (timeElapsed >= 5.0f) {
		DestroyMe();  // 5�b�o�߂�����I�u�W�F�N�g������
	}

}

void Boll::Draw()
{
	DrawRectGraph(position.x, position.y, 0, 0, 64, 64, hImage, TRUE);
}

// �{�[���̒��S���W�̎擾
void Boll::GetBallCenter(int* centerX, int* centerY)
{
}

// �i�s�����̔��]
void Boll::SetFlip(bool flagX, int flagY)
{
	// X�����̔��]
	if (flagX)
	{
		ballVy = -ballVy;
	}
	// Y�����̔��]
	if (flagY)
	{
		ballVy = -ballVy;
	}
<<<<<<< HEAD
}
=======
}

>>>>>>> 5c95bcf4d6dde1faf22398a59ddeb03df4ffed40
