#include "Stage.h"
#include "Player.h"

const int CHIP_SIZE = 64;

#include "Stage1.h"
#include "Boll.h"
#include "Wall.h"

Stage::Stage()
{
	hImage = LoadGraph("data/image/parts.png");
	for (int j = 0; j < HEIGHT; j++) {
		for (int i = 0; i < WIDTH; i++) {
			if (map[j][i] == 9) {
				Player* p = Instantiate<Player>();
				p->position.x = i * 60 + 100;
				p->position.y = j * 60 + 100;
			}
			if (map[j][i] == 5) {
				Wall* w = Instantiate<Wall>();
				w->position.x = i * 40 + 100;
				w->position.y = j * 40 + 100;
			}

		}
	}
}

Stage::~Stage()
{
}

void Stage::Update()
{
	std::list<Boll*> boll = FindGameObjects<Boll>();//�S���̐�
	for (Boll* bo : boll) { //st��1���΂̃|�C���^�[������
		{
			//�@�΂Ɠ����蔻��̒��S���W�����߂�
			VECTOR2 sCenter;
			sCenter.x = bo->position.x + 8;
			sCenter.y = bo->position.y + 8;
			//�A���̓����蔻��̒��S���W�����߂�
			VECTOR2 bCenter;
			bCenter.x = position.x + 32;
			bCenter.y = position.y + 32;
			//�@�ƇA�̉~�̓����蔻�������
			bo->position; //�΂̍��W
			position;//���̍��W
			if (CircleHit(sCenter, bCenter, 40)) {
				deed = true;
				deedCounter = 0;
				patternY = 4;
				bo->DestroyMe();
			}
			std::list<Boll*> birds = FindGameObjects<Boll>();  //�@std::list  �z��̗l�Ȃ���

			for (Boll* b : birds) {

				if (CircleHit(position, b->position, 56)) {
					//positin1��bird->positin�̋�����56��菬����
					patternY = 4;
				}
			}
		}
	}
}

void Stage::Draw()
{
	for (int j = 0; j < HEIGHT; j++) {
		int y = j * 60 + 100;
		for (int i = 0; i < WIDTH; i++) {
			int x = i * 60 + 100;
			if (map[j][i] == 1) {
				DrawRectGraph(x, y, 0, 64, 64, 64, hImage, TRUE);
			}
		}
	}
}

int Stage::IsWallRight(VECTOR2 pos)
{
	int i = (pos.x - 100) / 60;
	int j = (pos.y - 100) / 60;
	if (map[j][i] == 1) {
		int push = ((int)pos.x - 100) % 60 + 1;
		return push;
	}
	return 0;
}

int Stage::IsWallDown(VECTOR2 pos)
{
	int i = (pos.x - 100) / 60;
	int j = (pos.y - 100) / 60;
	if (map[j][i] == 1) {
		int push = ((int)pos.y - 100) % 60 + 1;
		return push;
	}
	return 0;
}

int Stage::IsWallLeft(VECTOR2 pos)
{
	int i = (pos.x - 100) / 60;
	int j = (pos.y - 100) / 60;
	if (map[j][i] == 1) {
		int push = 60 - ((int)pos.x - 100) % 60;
		return push;
	}
	return 0;
}

int Stage::IsWallUp(VECTOR2 pos)
{
	int i = (pos.x - 100) / 60;
	int j = (pos.y - 100) / 60;
	if (map[j][i] == 1) {
		int push = 60 - ((int)pos.y - 100) % 60;
		return push;
	}
	return 0;
}