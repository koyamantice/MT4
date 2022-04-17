﻿#include "TisGame.h"
#include "SceneFactory.h"

void TisGame::Initialize() {
	//基底クラスの初期化
	Framework::Initialize();
	//マネージャーセット
	sceneFactory_ = new SceneFactory();
	SceneManager::GetInstance()->SetSceneFactory(sceneFactory_);
	//SceneManager::GetInstance()->ChangeScene("TITLE");
	SceneManager::GetInstance()->ChangeScene("GAMEPLAY");

}

void TisGame::Finalize() {

	//基底クラスの初期化
	Framework::Finalize();
}

void TisGame::Update() {
	//基底クラスの更新
	Framework::Update();
	//DirectX毎フレーム処理 ここから

}

void TisGame::Draw() {
	//基底クラスの更新
	Framework::Draw();

}
