#include "Boll.h"

Boll::Boll()
{
	hImage = LoadGraph("data/image/parts.png");

}

Boll::~Boll()
{
	DeleteGraph(hImage);
}

void Boll::Update()
{
	position.x += 2.0f;
	if (position.x > SCREEN_WIDTH / 2) {
		DestroyMe();
	}
}

void Boll::Draw()
{
}
