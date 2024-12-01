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
	//当たり判定
	Boll* b = FindGameObject<Boll>();        //相手のインスタンスを取得　　　
	VECTOR2 bollPos = b->position;            //相手の座標を取得
	if (CircleHit(bollPos, position, 40)) {  //円の当たり判定　　　　　　　　　　　　　　　

		counter = 20;
	}
}

void Wall::Draw()
{
	Stage* s = FindGameObject<Stage>();

	//絵の表示をする

	DrawRectGraph(position.x - s->scroll, position.y, 120, 0, 40, 40, hImage, TRUE);

}
