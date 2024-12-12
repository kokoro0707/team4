#include "Target.h"
#include "Player.h"
#include "Stage.h"
#include"Boll.h"
#include "Pad.h"
#include "Vector2.h"
#include <cmath>

Target::Target()
{
	TrImage = LoadGraph("data/image/Effect.png");
	position.x = 0;
	position.y = 0;
}
Target::~Target()
{

}
void Target::Update()
{
	GetJoypadAnalogInputRight(&InputX, &InputY, DX_INPUT_PAD1);
	if (InputY <= -100) {
		position.y -= 2;
	}
	if (InputY >= 100) {
		position.y += 2;
	}
	if (InputX <= -100) {
		position.x -= 2;
	}
	if (InputX >= 100) {
		position.x += 2;
	}
}

void Target::Draw()
{
	DrawRectGraph(position.x, position.y, 90, 0, 30, 40, TrImage, TRUE);
}

