#pragma once
#include"../Library/gameObject.h"
#include"Vector2.h"

class Wall : public GameObject {
public:
	Wall();
	~Wall();
	void Update()override;
	void Draw()override;

	int hImage;
	VECTOR2 position;

	int counter;
};
