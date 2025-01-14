#include <DxLib.h>
#include <cassert>
#include "TitleScene.h"
#include "../Library/Time.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "Screen.h"

int hImageRed;
int hImageBlue;
int TitleTextImage;
int TitleLogo;

VECTOR redTankPos;
VECTOR blueTankPos;
VECTOR TitleTextPos;
VECTOR TitleLogoPos;

float redTankStartPos;
float redTankEndPos;
float blueTankStartPos;
float blueTankEndPos;

float tankSpeed;

bool isMoveRedTank;

TitleScene::TitleScene()
{
	redTankStartPos = Screen::WIDTH + 200.0f;
	blueTankStartPos = -300.0f;
	redTankEndPos = blueTankStartPos;
	blueTankEndPos = redTankStartPos;
	tankSpeed = 500.0f;
	isMoveRedTank = true;


	hImageRed = LoadGraph("D:\\ゲームプログラミング　チーム制作\\team\\空のプロジェクト\\project\\data\\image\\戦車（横） のコピー.png");
	hImageBlue = LoadGraph("D:\\ゲームプログラミング　チーム制作\\team\\空のプロジェクト\\project\\data\\image\\戦車２ のコピー.png");
	TitleTextImage = LoadGraph("D:\\ゲームプログラミング　チーム制作\\team\\空のプロジェクト\\project\\data\\image\\PUSH TO SPACE.png");
	TitleLogo = LoadGraph("D:\\ゲームプログラミング　チーム制作\\team\\空のプロジェクト\\project\\data\\image\\BOOM BOUND タイトルロゴ のコピー.png");

	redTankPos.x = redTankStartPos;
	blueTankPos.x = blueTankStartPos;

	redTankPos.y = 900;
	blueTankPos.y = 900;
	TitleTextPos = VGet(Screen::WIDTH / 5 +10, 700.0f, 0.0f);
	TitleLogoPos = VGet(Screen::WIDTH / 17, 50.0f, 0.0f);
}

TitleScene::~TitleScene()
{
}

void TitleScene::Update()
{
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		
		SceneManager::ChangeScene("PLAY");
		if (CheckHitKey(KEY_INPUT_ESCAPE)) {
			SceneManager::Exit();
		}
	}
}



void TitleScene::Draw()
{
	if (isMoveRedTank) {
		redTankPos.x -= tankSpeed * Time::DeltaTime();
		if (redTankPos.x <= redTankEndPos) {
			redTankPos.x = redTankStartPos;
			isMoveRedTank = false;
		}
	}
	else {
		blueTankPos.x += tankSpeed * Time::DeltaTime();
		if (blueTankPos.x >= blueTankEndPos) {
			blueTankPos.x = blueTankStartPos;
			isMoveRedTank = true;
		}
	}

	DrawBox(0, 0, Screen::WIDTH, Screen::HEIGHT, GetColor(255, 255, 255), TRUE);
	DrawGraph(redTankPos.x, redTankPos.y, hImageRed, TRUE);
	DrawGraph(blueTankPos.x, blueTankPos.y, hImageBlue, TRUE);
	DrawGraph(TitleLogoPos.x, TitleLogoPos.y ,TitleLogo, TRUE);


	static int alphaCol;
	static float time;


	// 時間を少しずつ進める
	time += 0.05f;

	if (time < 2.0f) {
		// フェードイン
		alphaCol = (int)(time * 127.5f);  // 0から255に
	}
	else if (time < 4.0f) {
		alphaCol = (int)((4.0f - time) * 127.5f);  // 255から0に
	}
	else {
		// 時間をリセットしてループ
		time = 0.0f;
	}




	// 
	SetDrawBlendMode(DX_BLENDMODE_PMA_ALPHA, alphaCol);
	DrawGraph(TitleTextPos.x, TitleTextPos.y, TitleTextImage, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_PMA_ALPHA, 255);	// 透明度リセット


}
