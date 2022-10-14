#pragma once
#include"../Base/Base.h"

class Game03 :public Base {
private:
	int m_cnt;//BGMループ用カウント
public:
	Game03();
	~Game03();
	void Update();
};