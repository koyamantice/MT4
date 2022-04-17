#pragma once
#include "BaseScene.h"
#include "AbstractSceneFactory.h"

/// <summary>
/// �V�[���}�l�[�W���[
/// </summary>
class SceneManager {
public:
	static SceneManager* GetInstance();
/// <summary>
/// �X�V
/// </summary>
	void Update();
	/// <summary>
	/// �`��
	/// </summary>
	void Draw();


public:
	//���V�[���\��
	void ChangeScene(const std::string& sceneName);

	void SetSceneFactory(AbstractSceneFactory* sceneFactory) { sceneFactory_ = sceneFactory; }
private:
	//���̃V�[��
	BaseScene* scene_ = nullptr;
	//���̃V�[��
	BaseScene* nextScene_ = nullptr;

	AbstractSceneFactory* sceneFactory_ = nullptr;

	~SceneManager()=default;
	SceneManager()=default;
	SceneManager(const SceneManager&)=delete;
	void operator =(const SceneManager&)=delete;
};

