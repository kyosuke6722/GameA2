#include "Enemy04.h"
#include "Bullet04.h"


Enemy04::Enemy04(const CVector2D& pos)
	:Base(eType_Enemy)
{
	m_img = COPY_RESOURCE("Enemy04", CImage);
	m_pos = pos;
	m_img.SetCenter(16, 16);
	m_rad = 16;

}


void Enemy04::Update()
{

	m_cnt++;
	Base* b = Base::FindObject(eType_Player);

	if (b) {

		CVector2D vec = b->m_pos - m_pos;
		m_ang = atan2(vec.x, vec. y);
		if (m_cnt >= 120) {
			Base::Add(new Bullet04(eType_Enemy_Attack, m_pos, m_ang, 4));
			m_cnt = 0;

		}

	}
	





}

void Enemy04::Draw()
{
	m_img.SetAng(m_ang);
	m_img.SetPos(m_pos);
	m_img.Draw();
}

void Enemy04::Collision(Base* b)
{
}



