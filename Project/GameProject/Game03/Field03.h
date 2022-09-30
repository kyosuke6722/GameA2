#pragma once
#include"../Base/Base.h"

class Field03:public Base {
private:
	CImage m_foreground;//‘OŒi
	CImage m_town;//‰“Œi
	CImage m_sky;//Å‰“Œi
	float m_ground_y;//’n–Ê‚Ì‚‚³
public:
	Field03();
	void Draw();
	float GetGroundY() {
		return m_ground_y;
	}
};