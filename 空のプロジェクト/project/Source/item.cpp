#include "item.h"
#include <DxLib.h>
#include "Player.h"
#include "Stage.h"

item::item()
{
	hImage = LoadGraph("data/iamge/Item2.png");

	got = false;
}


item::~item()
{
}

void item::Update()
{
	Player* p = FindGameObject<Player>();        //����̃C���X�^���X���擾�@�@�@
	VECTOR2 playerPos = p->position;            //����̍��W���擾
	if (CircleHit(playerPos, position, 60)) {  //�~�̓����蔻��@�@�@�@�@�@�@�@�@�@�@�@�@�@�@
		got = true;

		counter = 20;

	}
}

void item::Draw()
{

	Stage* s = FindGameObject<Stage>();

	DrawRectGraph(position.x, position.y, 120, 80, 64, 64, hImage, TRUE);
}





