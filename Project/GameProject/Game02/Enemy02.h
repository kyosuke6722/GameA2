#pragma once
#include "../Base/Base.h"

class Enemy02 : public Base {
public:
	CImage m_img;

	int m_cnt;

public:
	Enemy02(const CVector2D& pos);
	void Update();
	void Draw();
};