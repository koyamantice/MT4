#include "Player.h"
#include "Input.h"
#include"Collision.h"
#include"Easing.h"
#include "DebugText.h"
#include<sstream>
#include<iomanip>
using namespace DirectX;

Player::Player() {
	model = Model::CreateFromOBJ("chr_knight");
	object3d = new Object3d();
}

void Player::Initialize() {
	object3d = Object3d::Create();
	object3d->SetModel(model);
	object3d->SetPosition(pos);
	object3d->SetScale({ 1,1,1 });
	collider.radius = rad;
}

void Player::Update() {
	Input* input = Input::GetInstance();
	object3d->Update();
	if (input->PushKey(DIK_R)) {

	}
}

void Player::Draw() {
	Object3d::PreDraw();
	object3d->Draw();
}

