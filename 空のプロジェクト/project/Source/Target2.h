#pragma once
#include "../Library/gameObject.h"
#include "Vector2.h"
class Target2 :public GameObject
{
public:
	Target2();
	~Target2();
	void Update()override;
	void Draw() override;

	int TrImage;
	VECTOR2 position2;
	int InputX2, InputY2;

	const VECTOR2 GetCenterPosition();
};

