#include "Target2.h"
#include "Player2.h"
#include"Boll.h"
#include "Pad.h"
#include "Vector2.h"
#include <cmath>

Target2::Target2()
{
	TrImage = LoadGraph("data/image/Effect.png");
	position2.x = 0;
	position2.y = 0;
}

Target2::~Target2()
{

}

void Target2::Update()
{
	GetJoypadAnalogInputRight(&InputX2, &InputY2, DX_INPUT_PAD2);
	if (InputY2 <= -100) {
		position2.y -= 2;
	}
	if (InputY2 >= 100) {
		position2.y += 2;
	}
	if (InputX2 <= -100) {
		position2.x -= 2;
	}
	if (InputX2 >= 100) {
		position2.x += 2;
	}
}
void Target2::Draw()
{
	DrawRectGraph(position2.x, position2.y, 90, 0, 30, 40, TrImage, TRUE);
}
