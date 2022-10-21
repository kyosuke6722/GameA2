#pragma once
#include "../Base/Base.h"

class UI01 :public Base {

private:
	CImage m_score;
	CImage m_img;
	CFont m_text;
public:
	UI01();

	void Draw();


};