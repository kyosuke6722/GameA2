#pragma once
#include"../Base/Base.h"

class Game04 :public Base {
public:
	 Game04(bool tuto);
	~Game04();
	int m_cnt;

	

	void Update();
	bool m_is_tuto;//�`���[�g���A��(tutorial)�t���O
};