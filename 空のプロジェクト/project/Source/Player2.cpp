#include "Player2.h"
#include "Stage.h"
#include"Boll.h"
#include "Target2.h"


Player2::Player2()
{
	BaImage = LoadGraph("data/image/Player.png");
	hImage = LoadGraph("data/image/Player.png");
	position.x = 0;
	position.y = 0;

}

Player2::~Player2()
{

}

void Player2::Update()
{
	GetJoypadAnalogInput(&InputX, &InputY, DX_INPUT_PAD2);
	int pad = GetJoypadInputState(DX_INPUT_PAD2);
	Stage* s = FindGameObject<Stage>();

	//if (CheckHitKey(KEY_INPUT_W)) {
	if (InputY <= -100) {
		position.y -= 2;
		Angel += 0.09f;
		int push = s->IsWallUp(position + VECTOR2(0, 0));
		position.y += push;
		push = s->IsWallUp(position + VECTOR2(39, 39));
		position.y += push;

		if (pad & PAD_INPUT_Y) {
			timer += Time::DeltaTime();
			if (timer < 0.1f) {
				position.y -= dashspeed + 8;
			}
			position.y -= dashspeed;
			if (timer < 0.3f) {
				position.y -= dashspeed - 1;
			}
			if (prevKey2 == true) {
				timer = 0.0f;
			}
			prevKey2 = false;
		}
		else {
			prevKey2 = true;
		}
	}
	//if (CheckHitKey(KEY_INPUT_S)) {
	if (InputY >= 100) {
		position.y += 2;
		int push = s->IsWallDown(position + VECTOR2(0, 39));
		position.y -= push;
		push = s->IsWallDown(position + VECTOR2(39, 39));
		position.y -= push;

		if (pad & PAD_INPUT_Y) {
			timer += Time::DeltaTime();
			if (timer < 0.1f) {
				position.y += dashspeed + 8;
			}
			position.y += dashspeed;
			if (timer < 0.3f) {
				position.y += dashspeed - 1;
			}
			if (prevKey2 == true) {
				timer = 0.0f;
			}
			prevKey2 = false;
		}
		else {
			prevKey2 = true;
		}
	}
	//if (CheckHitKey(KEY_INPUT_A)) {
	if (InputX <= -100) {
		position.x -= 2;
		int push = s->IsWallLeft(position + VECTOR2(0, 0));
		position.x += push;
		push = s->IsWallLeft(position + VECTOR2(0, 39));
		position.x += push;

		if (pad & PAD_INPUT_Y) {
			timer += Time::DeltaTime();
			if (timer < 0.1f) {
				position.x -= dashspeed + 8;
			}
			position.x -= dashspeed;
			if (timer < 0.3f) {
				position.x -= dashspeed - 1;
			}
			if (prevKey2 == true) {
				timer = 0.0f;
			}
			prevKey2 = false;
		}
		else {
			prevKey2 = true;
		}
	}
	//if (CheckHitKey(KEY_INPUT_D)) {
	if (InputX >= 100) {
		position.x += 2;
		int push = s->IsWallRight(position + VECTOR2(39, 0));
		position.x -= push;
		push = s->IsWallRight(position + VECTOR2(39, 39));
		position.x -= push;

		if (pad & PAD_INPUT_Y) {
			timer += Time::DeltaTime();
			if (timer < 0.1f) {
				position.x += dashspeed + 8;
			}
			position.x += dashspeed;
			if (timer < 0.3f) {
				position.x += dashspeed - 1;
			}
			if (prevKey2 == true) {
				timer = 0.0f;
			}
			prevKey2 = false;
		}
		else {
			prevKey2 = true;
		}
	}

	//if (CheckHitKey(KEY_INPUT_SPACE)) {
	if (pad & PAD_INPUT_Z) {
		if (prevKey == false) {
			Boll* st = Instantiate<Boll>();
			st->position = position;

			st->position.x += 30;
			st->position.y += 5;
		}
		prevKey = true;
	}
	else {
		prevKey = false;
	}
}

void Player2::Draw()
{
	DrawRectGraph(position.x, position.y, 0, 0, 50, 40, hImage, TRUE);
	DrawRectGraph(position.x, position.y , 40, 0, 80, 30, BaImage, TRUE);
}

