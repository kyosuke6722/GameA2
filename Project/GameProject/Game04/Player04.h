#include"../Base/Base.h"
#pragma once
class Player04 : public Base {
	CImage m_img;
public:
	Player04(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);





};