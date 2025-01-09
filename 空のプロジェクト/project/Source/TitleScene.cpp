#include <DxLib.h>
#include <cassert>
#include "TitleScene.h"
#include "../Library/Time.h"
#include <iostream>
#include <chrono>
#include <thread>



TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Update()
{
	if (CheckHitKey(KEY_INPUT_P))
	{
		for (int i = 0; i < 3; ++i) {
	
			std::this_thread::sleep_for(std::chrono::seconds(1));

		}
		SceneManager::ChangeScene("PLAY");
		if (CheckHitKey(KEY_INPUT_ESCAPE)) {
			SceneManager::Exit();
		}
	}
}



void TitleScene::Draw()
{
	DrawString(0, 0, "TITLE SCENE", GetColor(255,255,255));
	DrawString(100, 400, "Push [P]Key To Play", GetColor(255, 255, 255));
}
