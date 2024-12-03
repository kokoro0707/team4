#include "Player.h"
#include "Stage.h"
#include"Boll.h"
//#include"../ImGui/imgu.h"

Player::Player()
{
	hImage = LoadGraph("data/image/TankBlue.png");
	position.x = 0;
	position.y = 0;

}

Player::~Player()
{

}

void Player::Update()
{
	GetJoypadAnalogInput(&InputX, &InputY, DX_INPUT_KEY_PAD1);
	int pad = GetJoypadInputState(DX_INPUT_PAD1);

	//ImGuiを使うとき(使うときは関数を.hに入力してから)
	/* timer += Time::DeltaTime();
	int count = 3;
	ImGui::Begin("Variables");
	ImGui::InputFloat("position", &position); positionの所は使っている関数を入力する
	ImGui::InputInt("COUNT", &count);
	ImGui::End(); */


	Stage* s = FindGameObject<Stage>();

	//if (CheckHitKey(KEY_INPUT_W)) {
	if(InputY<=200){
		position.y -= 2;
		int push = s->IsWallUp(position + VECTOR2(0, 0));
		position.y += push;
		push = s->IsWallUp(position + VECTOR2(39, 39));
		position.y += push;
	}
	//if (CheckHitKey(KEY_INPUT_S)) {
	if(InputY>=200){
		position.y += 2;
		int push = s->IsWallDown(position + VECTOR2(0, 39));
		position.y -= push;
		push = s->IsWallDown(position + VECTOR2(39, 39));
		position.y -= push;
	}
	//if (CheckHitKey(KEY_INPUT_A)) {
	if (InputX <= -200) {
		position.x -= 2;
		int push = s->IsWallLeft(position + VECTOR2(0, 0));
		position.x += push;
		push = s->IsWallLeft(position + VECTOR2(0, 39));
		position.x += push;
	}
	//if (CheckHitKey(KEY_INPUT_D)) {
	if(InputX>=200){
		position.x += 2;
		int push = s->IsWallRight(position + VECTOR2(39, 0));
		position.x -= push;
		push = s->IsWallRight(position + VECTOR2(39, 39));
		position.x -= push;
	}
<<<<<<< HEAD

	if (CheckHitKey(KEY_INPUT_SPACE)) {
		if (prevKey == false) {
			Boll* st = Instantiate<Boll>();
			st->position = position;

=======
	
	//if (CheckHitKey(KEY_INPUT_SPACE)) {
	if(pad&PAD_INPUT_Z){
		if (prevKey == false) {
			Boll* st = Instantiate<Boll>();
			st->position = position;
			
>>>>>>> 5c95bcf4d6dde1faf22398a59ddeb03df4ffed40
			st->position.x += 30;
			st->position.y += 5;
		}
		prevKey = true;
	}
	else {
		prevKey = false;
	}
}

void Player::Draw()
{
	Stage* s = FindGameObject<Stage>();
	DrawRectGraph(position.x, position.y, 0, 0, 50, 50, hImage, TRUE);
}
