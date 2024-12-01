#include "Source/Wall.h"
#include"player.h"
#include"Source/Stage.h"
#include <DxLib.h>
#include "Source/Boll.h"



Wall::Wall()
{
	hImage = LoadGraph("data/image/parts.png");
}

Wall::~Wall()
{
}

void Wall::Update()
{
	//�����蔻��
	Boll* b = FindGameObject<Boll>();        //����̃C���X�^���X���擾�@�@�@
	VECTOR2 bollPos = b->position;            //����̍��W���擾
	if (CircleHit(bollPos, position, 40)) {  //�~�̓����蔻��@�@�@�@�@�@�@�@�@�@�@�@�@�@�@

		counter = 20;
	}
}

void Wall::Draw()
{
	Stage* s = FindGameObject<Stage>();

	//�G�̕\��������

	DrawRectGraph(position.x - s->scroll, position.y, 120, 0, 40, 40, hImage, TRUE);

}
