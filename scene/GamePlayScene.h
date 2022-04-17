﻿#pragma once

#include "BaseScene.h"
#include "Sprite.h"
#include "Object3d.h"
#include "Enemy.h"
#include "Player.h"
#include <DirectXMath.h>
#include<memory>
#include"CollisionPrimitive.h"

/// <summary>
/// ゲームプレイシーン
/// </summary>
class GamePlayScene : public BaseScene{
private:
	// DirectX::を省略
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMVECTOR = DirectX::XMVECTOR;
	using XMMATRIX = DirectX::XMMATRIX;

public:

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize() override;
	/// <summary>
	/// 終了
	/// </summary>
	void Finalize() override;

	/// <summary>
	/// 毎フレーム更新
	/// </summary>
	void Update() override;
	/// <summary>
	/// 描画
	/// </summary>
	void Draw() override;
private:
	Model* model = nullptr;
	Object3d* Demo = nullptr;
	Sprite* BG = { nullptr };
	bool isGravity = false;
	float vy = 0.0f;
	const float gravity = -9.8 / 60.0f;
	float y = 4.0f;
};

