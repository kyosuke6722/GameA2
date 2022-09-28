#pragma once
#include"../Base/Base.h"

class Player03 :public Base {
private:
	CImage m_img;
	bool m_flip;
public:
	Player03(const CVector2D& pos,bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);
};