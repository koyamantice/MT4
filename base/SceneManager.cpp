#include "SceneManager.h"
#include<cassert>
//SceneManager::~SceneManager() {
//	//�Ō�̃V�[���̏I���ƊJ��
//	scene_->Finalize();
//	delete scene_;
//}

SceneManager* SceneManager::GetInstance() {
	static SceneManager instance;
	return &instance;
}

void SceneManager::Update() {
	//�V�[���؂�ւ�
	if (nextScene_) {
		//���V�[���̏I��
		if (scene_) {
			scene_->Finalize();
			delete scene_;
		}
		scene_ = nextScene_;
		nextScene_ = nullptr;
		scene_->Initialize();
	}
	scene_->Update();
}

void SceneManager::Draw() {
	scene_->Draw();
}

void SceneManager::ChangeScene(const std::string& sceneName) {
	assert(sceneFactory_);
	assert(nextScene_ == nullptr);
	//���̃V�[������
	nextScene_=sceneFactory_->CreateScene(sceneName);
}
