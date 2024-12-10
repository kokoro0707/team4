#pragma once
#include"../Library/GameObject.h"
#include"Vector2.h"

class itam : public GameObject
{
public:
	itam();
	~itam();
	void Update()override;
	void Draw()override;

	int hImage;
	VECTOR2 position;

	bool got;
	int counter;

};