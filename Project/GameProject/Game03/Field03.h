#pragma once
#include"../Base/Base.h"

class Field03:public Base {
private:
	CImage m_foreground;//�O�i
	CImage m_town;//���i
	CImage m_sky;//�ŉ��i
	float m_ground_y;//�n�ʂ̍���
public:
	Field03();
	void Draw();
	float GetGroundY() {
		return m_ground_y;
	}
};