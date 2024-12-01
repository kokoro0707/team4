#pragma once
#include "../Library/GameObject.h"
#include "Vector2.h"
class Stage : public GameObject {
public:
	Stage();
	~Stage();
	void Update() override;
	void Draw() override;

	int IsWallRight(VECTOR2 pos);
	int IsWallDown(VECTOR2 pos);
	int IsWallLeft(VECTOR2 pos);
	int IsWallUp(VECTOR2 pos);
	int hImage;

	int scroll;
	VECTOR2 position;
	VECTOR2 speed;

	bool deed;
	int deedCounter;
	int patternX;
	int patternY;
};

