#pragma once
#include "../Library/gameObject.h"
#include "Vector2.h"

class Player:public GameObject
{
public:
	Player();
	~Player();
	void Update()override;
	void Draw() override;

	int hImage;
	VECTOR2 position;
	float velocity;
	bool prevJumpKey; // �O�̃W�����v�L�[
	bool onGround; // �n�ʂɂ���
	bool prevKey; //�O�̃L�[��ۑ�����
	float timeElapsed;     // �o�ߎ���
	bool isSpacePressed;   // �X�y�[�X�L�[�������ꂽ���ǂ����̃t���O

	int InputX, InputY;
	int Key;
	int speed = 2;

};

