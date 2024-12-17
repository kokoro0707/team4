#pragma once
#include "../Library/SceneBase.h"


class TitleScene : public SceneBase
{
private:

private:
	int bgHandle;			//	�摜�n���h��(�^�C�g�����)
	int pushKeyHandle;		//	�摜�n���h��(PUSH SPACE KEY)
	int alpha;				//	[PUSH SPACE KEY]�̃A���t�@�l
	int ofset;				//	���Z����A���t�@�l
	float DrawKeyTimer;		//	�^�C�}�[


public:
	TitleScene();
	~TitleScene();
	void Update() override;
	void Draw() override;
};
