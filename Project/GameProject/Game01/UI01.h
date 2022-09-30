#pragma once
#include "../Base/Base.h"

class UI01 :public Base {

private:
	CImage m_score;
	CImage m_time;
public:
	UI01();

	void Draw();


};