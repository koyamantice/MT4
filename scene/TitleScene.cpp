#include "TitleScene.h"
#include"SceneManager.h"
#include "Audio.h"
#include "input.h"
#include "DebugText.h"

void TitleScene::Initialize() {
	// �e�N�X�`���ǂݍ���
	Sprite::LoadTexture(1, L"Resources/2d/title.png");
	//�w�i�X�v���C�g����
	sprite = Sprite::Create(1, { 0.0f,0.0f });
	


}

void TitleScene::Finalize() {
	//�R���̃��f���̃f���[�g
	delete sprite;
}

void TitleScene::Update() {
	Input* input = Input::GetInstance();
	if (input->PushKey(DIK_RETURN)) {
		SceneManager::GetInstance()->ChangeScene("GAMEPLAY");
	}
	DebugText::GetInstance()->Print("ENTER to GAMEPLAY!!", 200, 100, 1.0f);
}

void TitleScene::Draw() {
	sprite->PreDraw();
	//�w�i�p
	sprite->Draw();

	//�O�ʗp

}

