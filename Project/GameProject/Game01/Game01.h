#pragma once
#include"../Base/Base.h"

class Game01 :public Base {
public:
	Game01(bool tuto);
	~Game01();
	void Update();
	bool m_is_tuto;//チュートリアル(tutorial)フラグ
private:
	
};

