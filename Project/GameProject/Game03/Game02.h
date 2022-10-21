#pragma once
#include "../Base/Base.h"
class Game02 : public Base {
private:
	int m_cnt;
	int t_time;
	//int i;
public:
	Game02(bool tuto);
	~Game02();
	void Update();
	bool m_is_tuto;//チュートリアル(tutorial)フラグ
};