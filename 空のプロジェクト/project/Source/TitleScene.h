#pragma once
#include "../Library/SceneBase.h"


class TitleScene : public SceneBase
{
private:

private:
	int bgHandle;			//	画像ハンドル(タイトル画面)
	int pushKeyHandle;		//	画像ハンドル(PUSH SPACE KEY)
	int alpha;				//	[PUSH SPACE KEY]のアルファ値
	int ofset;				//	加算するアルファ値
	float DrawKeyTimer;		//	タイマー


public:
	TitleScene();
	~TitleScene();
	void Update() override;
	void Draw() override;
};
