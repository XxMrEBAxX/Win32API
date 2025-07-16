#pragma once
#include "CScene.h"

class CScene_Start : public CScene
{

public:
	CScene_Start();
	~CScene_Start();

	virtual void Enter() override;
	virtual void Exit() override;
};

