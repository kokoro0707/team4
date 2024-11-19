#include "Player.h"
#include "Stage.h"

Player::Player()
{
	hImage = LoadGraph("data/image/TankBlue.png");
	position.x = 0;
	position.y = 0;

}

Player::~Player()
{

}

void Player::Update()
{
	Stage* s = FindGameObject<Stage>();

	if (CheckHitKey(KEY_INPUT_W)) {
		position.y -= 2;
		int push = s->IsWallUp(position + VECTOR2(0,39));
		position.y += push;
		push = s->IsWallLeft(position + VECTOR2(39, 39));
		position.y += push;
	}
	if (CheckHitKey(KEY_INPUT_S)) {
		position.y += 2;
		int push = s->IsWallUp(position + VECTOR2(39, 0));
		position.y -= push;
		push = s->IsWallLeft(position + VECTOR2(39, 39));
		position.y -= push;
	}
	if (CheckHitKey(KEY_INPUT_A)) {
		position.x -= 2;
		int push = s->IsWallLeft(position + VECTOR2(0, 0));
		position.x += push;
		push = s->IsWallLeft(position + VECTOR2(0, 39));
		position.x += push;
	}
	if (CheckHitKey(KEY_INPUT_D)) {
		position.x += 2;
		int push = s->IsWallRight(position + VECTOR2(39, 0));
		position.x -= push;
		push = s->IsWallRight(position + VECTOR2(39, 39));
		position.x -= push;
	}
}

void Player::Draw()
{
	Stage* s = FindGameObject<Stage>();
	DrawRectGraph(position.x,position.y, 0, 0, 50, 50, hImage, TRUE);
}
