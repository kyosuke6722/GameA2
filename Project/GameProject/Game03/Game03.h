#pragma once
#include"../Base/Base.h"

class Game03 :public Base {
private:
	bool m_enemy_flag;//敵出現フラグ
public:
	Game03(bool tuto);
	~Game03();
	void Update();
	bool m_is_tuto;//チュートリアル(tutorial)フラグ
};