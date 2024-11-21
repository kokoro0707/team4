#pragma once
#include"Source/stage1.h"
#include "Vector2.h"

class item : public GameObject
{
public:
	item();
	~item();
	void Update() override;
	void Draw() override;

	int hImage;
	VECTOR2 position;

	bool got; 
	int counter; 
};