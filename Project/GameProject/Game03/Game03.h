#pragma once
#include"../Base/Base.h"

class Game03 :public Base {
private:
	bool m_enemy_flag;//�G�o���t���O
public:
	Game03(bool tuto);
	~Game03();
	void Update();
	bool m_is_tuto;//�`���[�g���A��(tutorial)�t���O
};