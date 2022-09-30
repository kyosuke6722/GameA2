#pragma once
#include"../Base/Base.h"

class Effect03 :public Base {
private:
	CImage m_img;
	bool m_flip;
public:
	Effect03(const char* name, const CVector2D& pos, bool flip);
	void Update();
	void Draw();
};
