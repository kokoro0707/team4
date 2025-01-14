#pragma once
#include "../Library/gameObject.h"
#include "Vector2.h"

class Player2 :public GameObject
{
public:
	Player2();
	~Player2();
	void Update()override;
	void Draw() override;

	int BaImage;
	int hImage;
	VECTOR2 position;
	float velocity;
	bool prevJumpKey; // �O�̃W�����v�L�[
	bool onGround; // �n�ʂɂ���
	bool prevKey; //�O�̃L�[��ۑ�����
	bool prevKey2;
	bool prevKeyUP;
	bool prevKeyDown;
	bool prevKeyRight;
	bool prevKeyLeft;
	float timeElapsed;     // �o�ߎ���
	bool isSpacePressed;   // �X�y�[�X�L�[�������ꂽ���ǂ����̃t���O

	int InputX, InputY;
	int Key;
	float speed = 0.0f;
	float a = 0.08;
	int dashspeed = 4;
	float timer;

private:
	VECTOR2 baseNormalize;
	VECTOR2 targetNormalize;
	float angle;
	VECTOR2 center;
};

