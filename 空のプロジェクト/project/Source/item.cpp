#include "item.h"

itam::itam()
{
	hImage = LoadGraph("data/iamge/item.png");

}

itam::~itam()
{

}

void itam::Update()
{

}

void itam::Draw()
{
	DrawRectGraph(position.x, position.y, 120, 0, 80, 80, hImage, TRUE);
}
