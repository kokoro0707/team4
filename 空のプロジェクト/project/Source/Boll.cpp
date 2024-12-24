#include "Boll.h"
#include <cmath> e
#include "Player.h"
#include"config.h"
#include <cassert>
#include "Stage.h"

Boll::Boll()
{
	hImage = LoadGraph("data/image/Effect.png");
	position.x = 10;
	position.y = 10;

	//	�ړ����x
//	ballVx = BALL_SPEED;
//	ballVy = BALL_SPEED;
	velocity.x = BALL_SPEED;
	velocity.y = BALL_SPEED;
}

Boll::~Boll()
{
	DeleteGraph(hImage);
}

void Boll::Update()
{
	position += velocity;

	//	��ʒ[����(X����)
	if ((position.x < 0) || (position.y > SCREEN_WIDTH))
	{
		DestroyMe();
	}
	// ��ʒ[����(Y����...��̂�) 
	// ��ʉ��ɍs������~�X 
	// 
	//isMiss = ballY > bottom - (radius * 2);

	Stage* s = FindGameObject<Stage>();
	if (s->IsWallRight(position) > 0) {
		//�ʂȉ摜�ɂ���
		DestroyMe(); // �Ƃ肠����
	}
	//	�v���C���[�Ƃ̓����蔻��
//	if (CheckPlayerHit())
//	{
		// Hit�T�E���h�̍Đ� 
		//PlaySoundMem(hitSoundHandle, DX_PLAYTYPE_BACK);

		//	�v���C���[�Ɠ�������
//		ballVy = -ballVy;
//	}
}

void Boll::Draw()
{
	DrawRectGraph(position.x, position.y, 0, 0, 32, 32, hImage, TRUE);
}

// �{�[���̒��S���W�̎擾
void Boll::GetBallCenter(int* centerX, int* centerY)
{
}

// �i�s�����̔��]
void Boll::SetFlip(bool flagX, int flagY)
{
	// X�����̔��]
//	if (flagX)
//	{
//		ballVy = -ballVy;
//	}
	// Y�����̔��]
//	if (flagY)
//	{
//		ballVy = -ballVy;
//	}
}

