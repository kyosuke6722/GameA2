#include "Ball01.h"

Ball01::Ball01(const CVector2D& pos):Base(eType_Ball)
{
	m_img = COPY_RESOURCE("Ball01", CImage);
	m_pos = pos;
	m_img.SetSize(32, 32);
	
	m_vec = CVector2D(-4, 4);


	

}

void Ball01::Update()
{
	
	m_pos += m_vec;
	if (m_pos.y < 0 || m_pos.y > 720 - 32) {
		m_vec.y *= -1;
	}

	if (m_pos.x < 0 || m_pos.x > 1280 - 32) {
		m_vec.x *= -1;
	}

	


}

void Ball01::Draw()
{
	m_img.SetPos(m_pos);
	m_img.Draw();
	

	

}
