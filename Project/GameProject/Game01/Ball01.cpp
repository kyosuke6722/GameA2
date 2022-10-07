#include "Ball01.h"
#include "GameData01.h"
Ball01::Ball01(const CVector2D& pos):Base(eType_Ball)
{
	m_img = COPY_RESOURCE("Ball01", CImage);
	m_pos = pos;
	m_img.SetSize(32, 32);
	
	m_vec = CVector2D(-4, 4);
	m_img.SetCenter(16, 16);
	m_rect = CRect(-16, -16, 16, 16);
	CVector2D mouse_pos = CInput::GetMousePoint();

	

	
}

void Ball01::Update()
{
	if (GameData01::game_state == 1) {
		if (PUSH(CInput::eMouseL)) {

		}


		m_pos += m_vec;
		if (m_pos.y < 0 || m_pos.y > 720 - 32) {
			m_vec.y *= -1;
		}

		if (m_pos.x < 0)
		{
			GameData01::point[1]++;
			GameData01::t_time += 600;
			GameData01::game_state = 0;
			m_vec = CVector2D(4,4);
		}
		if (m_pos.x > 1280 - 32) {
			GameData01::point[0]++;
			GameData01::game_state = 0;
			m_vec = CVector2D(-4,4);
		}




	}
	else {
		m_pos = CVector2D(600, 300);
	}


}

void Ball01::Draw()
{
	m_img.SetPos(m_pos);
	m_img.Draw();
	DrawRect();



}

void Ball01::Collision(Base* b)
{
	switch (b->m_type) {
	case eType_Player:
	case eType_Enemy:
		if (Base::CollisionRect(this, b)) {
			m_vec.x *= -1;
			m_vec *= 1.2f;

		}
	break;
	}


}
