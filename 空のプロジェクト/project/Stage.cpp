#include "Stage.h"
#include "Player.h"

const int CHIP_SIZE = 60;

#include "Source/Stage1.h"

Stage::Stage()
{
	hImage = LoadGraph("data/image/parts.png");
	for (int j = 0; j < HEIGHT; j++) {
		for (int i = 0; i < WIDTH; i++) {
			if (map[j][i] == 9)
				if (map[j][i] == 2);
		}
}

Stage::~Stage()
{
}

void Stage::Draw();
{

	for (int j = 0; j < HEIGHT; j++) {
		int y = j * 40 + 100;
		for (int i = 0; i < WIDTH; i++) {
			int x = i * 40 + 100;
			if (map[j][i] == 1) 
		    if (map[j][i] == 8) {
		
	}
}

