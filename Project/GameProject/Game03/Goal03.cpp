#include "Goal03.h"

Goal03::Goal03(const CVector2D& pos):Base(eType_Goal) {
	m_img = COPY_RESOURCE("Goal", CImage);
	m_pos = pos;
	m_img.SetSize(128, 128);
	m_img.SetCenter(64, 64);
	m_rect = CRect(-64, -64, 64, 64);
	//m_rect = CRect(-32, -128, 32, 0);
}

void Goal03::Draw(){
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}
