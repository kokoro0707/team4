#include "Boll.h"
#include <cmath> 
#include "Player2.h"
#include "config.h"
#include <cassert>
#include "Stage.h"
#include "Target.h"

<<<<<<< HEAD
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
=======
Boll::Boll() {
    hImage = LoadGraph("data/image/Efect.png");
    position.x = 10;
    position.y = 0;
    velocity.x = BALL_SPEED;
    velocity.y = BALL_SPEED;
    timeHitWall = -1.0f;  // �����l�i�܂��ǂɓ������Ă��Ȃ���ԁj
>>>>>>> Collision
}

Boll::~Boll() {
    DeleteGraph(hImage);
}

<<<<<<< HEAD
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
=======
void Boll::Update() {

    //VECTOR2 to = VSub(targetposition, position);
    //to = VNorm(to);
    position = position + VScale(shotDirection, 6.0f);


    // ��ʒ[����(X����)
    if ((position.x < 0) || (position.x > SCREEN_WIDTH)) {
        DestroyMe();
    }

    // ��ʒ[����(Y����)
    if ((position.y < 0) || (position.y > SCREEN_HEIGHT)) {
        DestroyMe();
    }

    Stage* s = FindGameObject<Stage>();
    if (s->IsWallRight(position) > 0) {
        if (isWallRight) {
            // �ǂɓ������Ă���ꍇ
// �ǂɓ������Ă���ꍇ�A�ʂ̉摜��`��
            DrawRectGraph(position.x, position.y, 40, 40, 80, 80, hImage, TRUE);

            // �~�`�̓����蔻���`��
            DrawCircle(position.x, position.y, 80, GetColor(255, 0, 0));  // �Ԃ��~
            std::list< Player2*> players = FindGameObjects<Player2>();
            for (Player2* p : players) {
                VECTOR2 EX;
                EX.x = position.x ;
                EX.y = position.y ;

                VECTOR2 pCenter;
                pCenter.x = p->position.x ;
                pCenter.y = p->position.y ;
                if (CircleHit(pCenter, EX, 20 + 80)) {
                    p->hp -= 1;
                }
            }
        }
       else {
              // �ǂɓ������Ă��Ȃ��ꍇ�A���̉摜��`��
             DrawRectGraph(position.x, position.y, 0, 0, 32, 32, hImage, TRUE);
       }

           // �ǂɓ���������I�u�W�F�N�g������
         DestroyMe();
    }
    else {
         // �ǂɓ������Ă��Ȃ��ꍇ�A�ʏ�̕`  
          DrawRectGraph(position.x, position.y, 0, 0, 32, 32, hImage, TRUE);
    }
>>>>>>> Collision
}

void Boll::Draw()
{
    // ���i�̕`��
    DrawRectGraph(position.x, position.y, 0, 0, 32, 32, hImage, TRUE);
}

void Boll::GetBallCenter(int* centerX, int* centerY) {
    *centerX = (int)position.x;
    *centerY = (int)position.y;
}

void Boll::Shot(VECTOR2 target, VECTOR2 startPosition)
{
<<<<<<< HEAD
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
=======
    position = startPosition;
    VECTOR2 to = VSub(target, position);
    shotDirection = VNorm(to);
>>>>>>> Collision
}

