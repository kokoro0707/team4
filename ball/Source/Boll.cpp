#include "Boll.h"
#include <cmath> 
#include "Player.h"
#include "config.h"
#include <cassert>
#include "Stage.h"
#include "Target.h"
#include "Player2.h"

Boll::Boll() {
    hImage = LoadGraph("data/image/Effect.png");
    position.x = 10;
    position.y = 0;
    attacking = true;
    velocity.x = BALL_SPEED;
    velocity.y = BALL_SPEED;
    timeHitWall = -1.0f;  // �����l�i�܂��ǂɓ������Ă��Ȃ���ԁj
}

Boll::~Boll() {
    DeleteGraph(hImage);
}

void Boll::Update() {
    Target* target = FindGameObject<Target>();
    if (attacking) {
        VECTOR2 to = VSub(target->position, position);
        to = VNorm(to);
        position = position + VScale(to, 6.0f);
    }

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
    // ���i�̕`��
    DrawRectGraph(position.x, position.y, 0, 0, 32, 32, hImage, TRUE);
}

void Boll::GetBallCenter(int* centerX, int* centerY) {
    *centerX = (int)position.x;
    *centerY = (int)position.y;
}
