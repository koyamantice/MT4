#include "GamePlayScene.h"
#include "Audio.h"
#include "input.h"
#include "DebugText.h"
#include "TitleScene.h"
#include"Collision.h"
#include<sstream>
#include<iomanip>

void GamePlayScene::Initialize() {
	//オブジェクト初期化
	model= Model::CreateFromOBJ("chr_knight");
	Demo = new Object3d;
	Demo->Initialize();
	Demo->SetPosition({ 0,4,0 });
	Demo->SetModel(model);
	// モデル読み込み
//	Audio::GetInstance()->LoadSound(1, "Resources/BGM/NewWorld.wav");
	srand(NULL);
}

void GamePlayScene::Finalize() {
	//３ｄのモデルのデリート
}

void GamePlayScene::Update() {
	Input* input = Input::GetInstance();
	Demo->Update();
	if (isGravity) {
		XMFLOAT3 pos{0,4,0};
		vy += gravity;
		y += vy;
		pos.y = y;
		Demo->SetPosition(pos);
	}
	DebugText::GetInstance()->Print("R:Reset", 0, 680, 1.0f);
	DebugText::GetInstance()->Print("SPACE:Start", 0, 700, 1.0f);
}

void GamePlayScene::Draw() {
	{
		ImGui::Begin("test");
			ImGui::Checkbox("Gravity", &isGravity);
			if (ImGui::Button("Reset")) {
				vy = 0;
				y = 4.0f;
				Demo->SetPosition({ 0,4,0 });
			}
			//ImGui::SliderFloat("Position.x", &s, 50, -50);
			ImGui::Unindent();
			
		ImGui::End();
	}
	Sprite::PreDraw();
	//背景用
	//BG->Draw();
	Object3d::PreDraw();
	Demo->Draw();

}

