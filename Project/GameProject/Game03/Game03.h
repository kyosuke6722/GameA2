#pragma once
#include"../Base/Base.h"

class Game03 :public Base {
private:
	int m_cnt;//BGM���[�v�p�J�E���g
	bool m_enemy_flag;//�G�o���t���O
public:
	Game03();
	~Game03();
	void Update();
};