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
    timeHitWall = -1.0f;  // 初期値（まだ壁に当たっていない状態）
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

    // 画面端判定(X方向)
    if ((position.x < 0) || (position.x > SCREEN_WIDTH)) {
        DestroyMe();
    }

    // 画面端判定(Y方向)
    if ((position.y < 0) || (position.y > SCREEN_HEIGHT)) {
        DestroyMe();
    }

    Stage* s = FindGameObject<Stage>();
    if (s->IsWallRight(position) > 0) {
        // 壁に当たっている場合
        if (isWallRight) {
            // 壁に当たっている場合、別の画像を描画
            DrawRectGraph(position.x, position.y, 40, 40, 80, 80, hImage, TRUE);

            // 円形の当たり判定を描画
            DrawCircle(position.x + 32, position.y + 32, 40, GetColor(255, 0, 0));  // 赤い円
        }
        else {
            // 壁に当たっていない場合、元の画像を描画
            DrawRectGraph(position.x, position.y, 0, 0, 32, 32, hImage, TRUE);
        }

        // 壁に当たったらオブジェクトを消す
       DestroyMe();
    }
    else {
        // 壁に当たっていない場合、通常の描画
        DrawRectGraph(position.x, position.y, 0, 0, 32, 32, hImage, TRUE);
    }
}

void Boll::Draw()
{
    // 普段の描画
    DrawRectGraph(position.x, position.y, 0, 0, 32, 32, hImage, TRUE);
}

void Boll::GetBallCenter(int* centerX, int* centerY) {
    *centerX = (int)position.x;
    *centerY = (int)position.y;
}
