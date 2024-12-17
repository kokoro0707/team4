#pragma once
#include "../Library/gameObject.h"
#include "Vector2.h"
class Target :public GameObject
{
public:
	Target();
	~Target();
	void Update()override;
	void Draw() override;

	int TrImage;
	VECTOR2 position;
	int InputX, InputY;

	const VECTOR2 GetCenterPosition();
};

