#include "Boll2.h"
#include <cmath> 
#include "config.h"
#include <cassert>
#include "Stage.h"
#include "Player2.h"
<<<<<<< HEAD
#include "Target2.h"

Boll2::Boll2() {
    hImage = LoadGraph("data/image/Effect.png");
=======
#include "Player.h"
#include "Target2.h"

Boll2::Boll2() {
    hImage = LoadGraph("data/image/Efect.png");
>>>>>>> Collision
    position.x = 10;
    position.y = 0;
    velocity.x = BALL_SPEED;
    velocity.y = BALL_SPEED;
    timeHitWall = -1.0f;  // �����l�i�܂��ǂɓ������Ă��Ȃ���ԁj
}

Boll2::~Boll2() {
    DeleteGraph(hImage);
}

void Boll2::Update() {
<<<<<<< HEAD
    Target2* target2 = FindGameObject<Target2>();

    VECTOR2 to = VSub(target2->position2, position);
    to = VNorm(to);
    position = position + VScale(to, 6.0f);

=======
    //Target2* target2 = FindGameObject<Target2>();

    //VECTOR2 to = VSub(target2->position2, position);
    //to = VNorm(to);
    //position = position + VScale(to, 6.0f);
    position = position + VScale(shotDirection, 6.0f);
>>>>>>> Collision

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
        // �ǂɓ������Ă���ꍇ
        if (isWallRight) {
            // �ǂɓ������Ă���ꍇ�A�ʂ̉摜��`��
            DrawRectGraph(position.x, position.y, 40, 40, 80, 80, hImage, TRUE);

            // �~�`�̓����蔻���`��
<<<<<<< HEAD
            DrawCircle(position.x + 32, position.y + 32, 40, GetColor(255, 0, 0));  // �Ԃ��~
=======
            DrawCircle(position.x  , position.y , 80, GetColor(255, 0, 0));  // �Ԃ��~
            std::list< Player*> players = FindGameObjects<Player>();
            for (Player* p : players) {
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
>>>>>>> Collision
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

void Boll2::Draw()
{
    // ���i�̕`��
    DrawRectGraph(position.x, position.y, 0, 0, 32, 32, hImage, TRUE);
}

void Boll2::GetBallCenter(int* centerX, int* centerY) {
    *centerX = (int)position.x;
    *centerY = (int)position.y;
}
<<<<<<< HEAD
=======

void Boll2::Shot(VECTOR2 target, VECTOR2 startPosition)
{
    position = startPosition;
    VECTOR2 to = VSub(target, position);
    shotDirection = VNorm(to);
}
>>>>>>> Collision
