#pragma once
#include "../Vector2.h"
#include"../Library/gameObject.h"

class Boll : public GameObject
{
public:
	Boll();
	~Boll();
	void Update()override;
	void Draw()override;

	int hImage;
	VECTOR2 position;

};

