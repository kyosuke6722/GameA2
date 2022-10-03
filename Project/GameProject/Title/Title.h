#pragma once
#include"../Base/Base.h"

class Title :public Base {
private:
	CImage m_img;
	CFont m_title_text;
public:
	Title();
	~Title();
	void Update();
	void Draw();
};