#include "Boll.h"
#include <cmath> e
#include "Player.h"
#include"config.h"
#include <cassert>
#include "Stage.h"
#include "Target.h"

Boll::Boll()
{
	hImage = LoadGraph("data/image/Efect.png");
	position.x = 10;
	position.y = 0;

	//	�ړ����x
//	ballVx = BALL_SPEED;
//	ballVy = BALL_SPEED;
	velocity.x = BALL_SPEED;
	velocity.y = BALL_SPEED;
	timeHitWall = -1.0f;
}

Boll::~Boll()
{
	DeleteGraph(hImage);
}

void Boll::Update()
{
	Target* target = FindGameObject<Target>();

	VECTOR2 to = VSub(target->position, position);
	to = VNorm(to);
	position = position + VScale(to, 6.0f);

	//	��ʒ[����(X����)
	if ((position.x < 0) || (position.y > SCREEN_WIDTH))
	{
		DestroyMe();
	}
	if ((position.y < 0) || (position.y > SCREEN_HEIGHT)) {
		DestroyMe();
	}
	// ��ʒ[����(Y����...��̂�) 
	// ��ʉ��ɍs������~�X 
	// 
	//isMiss = ballY > bottom - (radius * 2);

	Stage* s = FindGameObject<Stage>();
	if (s->IsWallRight(position) > 0) {
		if (isWallRight) {
			// �ǂɓ������Ă���ꍇ�A�ʂ̉摜��`��
			DrawRectGraph(position.x, position.y, 40, 40, 80, 80, hImage, TRUE);

			// �~�`�̓����蔻���`��
			DrawCircle(position.x + 32, position.y + 32, 40, GetColor(255, 0, 0));  // �Ԃ��~
		}
		else {
			// �ǂɓ������Ă��Ȃ��ꍇ�A���̉摜��`��
			DrawRectGraph(position.x, position.y, 0, 0, 32, 32, hImage, TRUE);
		}

		// �ǂɓ���������I�u�W�F�N�g������
		DestroyMe();
	}
	else {
		// �ǂɓ������Ă��Ȃ��ꍇ�A�ʏ�̕`��
		DrawRectGraph(position.x, position.y, 0, 0, 32, 32, hImage, TRUE);
	}
}

void Boll::Draw()
{
	DrawRectGraph(position.x, position.y, 0, 0, 32, 32, hImage, TRUE);
}

// �{�[���̒��S���W�̎擾
void Boll::GetBallCenter(int* centerX, int* centerY)
{
	*centerX = (int)position.x;
	*centerY = (int)position.y;
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

