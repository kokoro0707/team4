#include "Player.h"
#include "Stage.h"
#include"Boll2.h"
#include"Boll.h"
#include "Screen.h"
#include "Target.h"
#include <iostream>

#define M_PI 3.14159265358979323846f
//#include"../ImGui/imgu.h"

Player::Player()
{
	BaImage = LoadGraph("data/image/Turret_Blue.png");
	hImage = LoadGraph("data/image/Player.png");
	position.x = 0;
	position.y = 0;

	center = VECTOR2(position.x, position.y);
	baseNormalize = VECTOR2(0.0f, -1.0f);

	angle = 0.0f;

}

Player::~Player()
{

}

void Player::Update()
{
	if (hp <= 0) {
		hImage = FALSE;
		BaImage = FALSE;
		SceneManager::ChangeScene("TITLE");
	}
	center = VECTOR2(position.x, position.y);
	GetJoypadAnalogInput(&InputX, &InputY, DX_INPUT_KEY_PAD1);
	int pad = GetJoypadInputState(DX_INPUT_PAD1);

	//ImGui‚ðŽg‚¤‚Æ‚«(Žg‚¤‚Æ‚«‚ÍŠÖ”‚ð.h‚É“ü—Í‚µ‚Ä‚©‚ç)
	/* timer += Time::DeltaTime();
	int count = 3;
	ImGui::Begin("Variables");
	ImGui::InputFloat("position", &position); position‚ÌŠ‚ÍŽg‚Á‚Ä‚¢‚éŠÖ”‚ð“ü—Í‚·‚é
	ImGui::InputInt("COUNT", &count);
	ImGui::End(); */


	Stage* s = FindGameObject<Stage>();

	//if (CheckHitKey(KEY_INPUT_W)) {
	if (InputY <= -100) {
		if (speed <= 2) {
			speed += a;
		}
		if (prevKeyUP == true) {
			speed = 0.0f;
		}
		prevKeyUP = false;
		position.y -= speed;
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
	else {
		prevKeyUP = true;
	}
	//if (CheckHitKey(KEY_INPUT_S)) {
	if (InputY >= 100) {
		if (speed <= 2) {
			speed += a;
		}
		if (prevKeyDown == true) {
			speed = 0.0f;
		}
		prevKeyDown = false;
		position.y += speed;
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
	else {
		prevKeyDown = true;
	}
	//if (CheckHitKey(KEY_INPUT_A)) {
	if (InputX <= -100) {
		if (speed <= 2) {
			speed += a;
		}
		if (prevKeyLeft == true) {
			speed = 0.0f;
		}
		prevKeyLeft = false;
		position.x -= speed;
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
	else {
		prevKeyLeft = true;
	}

	//if (CheckHitKey(KEY_INPUT_D)) {
	if (InputX >= 100) {
		if (speed <= 2) {
			speed += a;
		}
		if (prevKeyRight == true) {
			speed = 0.0f;
		}
		prevKeyRight = false;
		position.x += speed;
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
	else {
		prevKeyRight = true;
	}

	//if (CheckHitKey(KEY_INPUT_SPACE)) {
	if (pad & PAD_INPUT_Z) {
		if (prevKey == false) {
			Boll* st = Instantiate<Boll>();
			//st->position = position;
			Target* target = FindGameObject<Target>();
			st->Shot(target->position, position);
		}
		prevKey = true;
	}
	else {
		prevKey = false;
	}

	Target* target = FindGameObject<Target>();
	if (target == nullptr) {
		return;
	}

	VECTOR2 targetVector = target->GetCenterPosition() - center;
	float distance = sqrtf(pow(targetVector.x, 2.0f) + pow(targetVector.y, 2.0f));
	targetNormalize = targetVector / distance;

	float innerProduct = baseNormalize.x * targetNormalize.x + baseNormalize.y * targetNormalize.y;
	angle = acos(innerProduct);

	float outerProduct = baseNormalize.x * targetNormalize.y - baseNormalize.y * targetNormalize.x;
	if (outerProduct < 0)
	{
		angle = (2.0f * M_PI) - angle;
	}
	std::list<Boll2*>bolls = FindGameObjects<Boll2>();
	for (Boll2* bo : bolls) {
		VECTOR2 bCenter;
		bCenter.x = bo->position.x + 10;
		bCenter.y = bo->position.y + 10;

		VECTOR2 pCenter;
		pCenter.x = position.x + 30;
		pCenter.y = position.y + 30;

		if (CircleHit(bCenter, pCenter, 10 + 30)) {
			hp -= 1;
			bo->DestroyMe();
		}
	}
}

void Player::Draw()
{
	Stage* s = FindGameObject<Stage>();
	DrawRectGraph(position.x, position.y, 0, 40, 40, 40, hImage, TRUE);
	DrawRotaGraph(static_cast<int>(center.x) + 20, static_cast<int>(center.y) + 20, 1.0f, angle, BaImage, TRUE, TRUE);
}
