#include "Player.h"
#include "Stage.h"
#include"Boll.h"
//#include"../ImGui/imgu.h"

Player::Player()
{
	BaImage = LoadGraph("data/image/Player.png");
	hImage = LoadGraph("data/image/Player.png");
	position.x = 0;
	position.y = 0;

}

Player::~Player()
{

}

void Player::Update()
{
	GetJoypadAnalogInput(&InputX, &InputY, DX_INPUT_KEY_PAD1);
	int pad = GetJoypadInputState(DX_INPUT_PAD1);

	//ImGui‚ğg‚¤‚Æ‚«(g‚¤‚Æ‚«‚ÍŠÖ”‚ğ.h‚É“ü—Í‚µ‚Ä‚©‚ç)
	/* timer += Time::DeltaTime();
	int count = 3;
	ImGui::Begin("Variables");
	ImGui::InputFloat("position", &position); position‚ÌŠ‚Íg‚Á‚Ä‚¢‚éŠÖ”‚ğ“ü—Í‚·‚é
	ImGui::InputInt("COUNT", &count);
	ImGui::End(); */

	
	Stage* s = FindGameObject<Stage>();

	if (CheckHitKey(KEY_INPUT_W)) {
	//if (InputY <= -100) {
		position.y -= 2;
		int push = s->IsWallUp(position + VECTOR2(0,0));
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
	if(InputY>=100){
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

			if (pad & PAD_INPUT_Y ) {
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
	
	if (CheckHitKey(KEY_INPUT_SPACE)) {
	//if(pad&PAD_INPUT_Z){
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

void Player::Draw()
{
	Stage* s = FindGameObject<Stage>();
	DrawRectGraph(position.x, position.y, 0, 40, 40, 40, hImage, TRUE);
	DrawRectGraph(position.x, position.y, 40, 40, 80, 70, BaImage, TRUE);
}
