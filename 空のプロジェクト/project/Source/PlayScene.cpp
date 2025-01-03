#include "PlayScene.h"
#include "../Library/SceneManager.h"
#include "Stage.h"
#include <DxLib.h>

PlayScene::PlayScene()
{
	Stage* s = Instantiate<Stage>();

}

PlayScene::~PlayScene()
{

}

void PlayScene::Update()
{
	if (CheckHitKey(KEY_INPUT_T)) {
		SceneManager::ChangeScene("TITLE");
		
	}
}

void PlayScene::Draw()
{
	SceneBase::Draw();

	DrawString(0, 0, "PLAY SCENE", GetColor(255, 255, 255));
	DrawString(100, 400, "Push [T]Key To Title", GetColor(255, 255, 255));
}
