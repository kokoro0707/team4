#include "Stage.h"
#include "Player.h"
#include "Target.h"
#include "Player2.h"
#include "Target2.h"
#include"item.h"

const int CHIP_SIZE = 64;

#include "Stage1.h"

Stage::Stage()
{
	hImage = LoadGraph("data/image/Tile.png");
	for (int j = 0; j < HEIGHT; j++) {
		for (int i = 0; i < WIDTH; i++) {
			if (map[j][i] == 9) {
				Player* p = Instantiate<Player>();
				Target* t = Instantiate<Target>();
				p->position.x = i * 60 + 100;
				p->position.y = j * 60 + 100;
				t->position.x = i * 60 + 100;
				t->position.y = j * 60 + 100;
			}
			if (map[j][i] == 8) {
				Player2* p2 = Instantiate<Player2>();
				Target2* t2 = Instantiate<Target2>();
				p2->position.x = i * 60 + 100;
				p2->position.y = j * 60 + 100;
				t2->position2.x = i * 60 + 100;
				t2->position2.y = j * 60 + 100;
			}
			if (map[j][i] == 2) {
				item* it = Instantiate<item>();
				it->position.x = i * 60 + 100;
				it->position.y = j * 60 + 100;
			}
		}
	}
}

Stage::~Stage()
{
}

void Stage::Draw()
{
	for (int j = 0; j < HEIGHT; j++) {
		int y = j * 60 + 100;
		for (int i = 0; i < WIDTH; i++) {
			int x = i * 60 + 100;
#if false
			if (map[j][i] == 1) {
				DrawRectGraph(x, y, 0, 64, 64, 64, hImage, TRUE);
			}
#endif
			switch (map[j][i])
			{
				//	‰ó‚¹‚È‚¢•Ç
			 case 1:
				DrawRectGraph(x, y, 0, 64, 64, 64, hImage, TRUE);
				break;
				//	‰ó‚¹‚é•Ç(1’iŠK)
			case 13:
				DrawRectGraph(x, y, 0, 64, 64, 64, hImage, TRUE);
				break;
				//	‰ó‚¹‚é•Ç(2’iŠK)
			case 12:
				DrawRectGraph(x, y, 0, 0, 64, 64, hImage, TRUE);
				break;
				//	‰ó‚¹‚é•Ç(3’iŠK)
			case 11:
				DrawRectGraph(x, y, 64, 0, 64, 64, hImage, TRUE);
				break;
			}
		}
	}
}

int Stage::IsWallRight(VECTOR2 pos)
{
	int i = (pos.x - 100) / 60;
	int j = (pos.y - 100) / 60;

	if (map[j][i] > 0) {
		int push = ((int)pos.x - 100) % 60 + 1;
		return push;
	}
	return 0;
}

int Stage::IsWallDown(VECTOR2 pos)
{
	int i = (pos.x - 100) / 60;
	int j = (pos.y - 100) / 60;
	if (map[j][i] > 0) {
		int push = ((int)pos.y - 100) % 60 + 1;
		return push;
	}
	return 0;
}

int Stage::IsWallLeft(VECTOR2 pos)
{
	int i = (pos.x - 100) / 60;
	int j = (pos.y - 100) / 60;
	if (map[j][i] > 0) {
		int push = 60 - ((int)pos.x - 100) % 60;
		return push;
	}
	return 0;
}

int Stage::IsWallUp(VECTOR2 pos)
{
	int i = (pos.x - 100) / 60;
	int j = (pos.y - 100) / 60;
	if (map[j][i] > 0) {
		int push = 60 - ((int)pos.y - 100) % 60;
		return push;
	}
	return 0;
}

void Stage::Damage(VECTOR2 pos)
{
	int i = (pos.x - 100) / 60;
	int j = (pos.y - 100) / 60;
	switch (map[j][i])
	{
		//	‰ó‚¹‚È‚¢•Ç
	case 1:
		break;
		//	‰ó‚¹‚é•Ç(1’iŠK)
	case 13:
		map[j][i] = 12;		//	‰ó‚¹‚é•Ç(2’iŠK)‚É•ÏX
		//	‰ó‚¹‚é•Ç(2’iŠK)
		break;
	case 12:
		map[j][i] = 11;		//	‰ó‚¹‚é•Ç(3’iŠK)‚É•ÏX
		//	‰ó‚¹‚é•Ç(3’iŠK)
		break;
	case 11:
		map[j][i] = 0;		//	•Ç‚ğ”j‰ó
		break;
	}

}