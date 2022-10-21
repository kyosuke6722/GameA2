#pragma once
#include "../Base/Base.h"

class UI02 : public Base {
public:
	CImage m_img;
	CFont m_text;
public:
	UI02();
	void Draw();
};