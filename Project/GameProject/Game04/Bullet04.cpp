#include "Bullet04.h"
#include "Map04.h"
#include "GameData04.h"

Bullet04::Bullet04(int type, const CVector2D& pos, float ang, float speed)
	:Base(type)
{
	if (type == eType_Player_Attack)
		m_img = COPY_RESOURCE("Bullet", CImage);
	else
		m_img = COPY_RESOURCE("Bullet2", CImage);
	m_pos = pos;
	m_img.SetCenter(16, 16);
	m_ang = ang;
	m_speed = speed;

}

void Bullet04::Update()
{
	m_vec = CVector2D(sin(m_ang), cos(m_ang)) * m_speed;
	m_pos += m_vec;
}

void Bullet04::Draw()
{
	m_img.SetPos(m_pos);
	m_img.SetAng(m_ang);
	m_img.Draw();

}

void Bullet04::Collision(Base* b)
{
	switch (b->m_type) {
	case eType_Field:
		if (Map04* m = dynamic_cast<Map04*>(b)) {
			int t = m->CollisionMap(m_pos);
			if (t != 0)
				SetKill();
		}
		break;
	case eType_Player:

		if (m_type == eType_Enemy_Attack && Base::CollisionCircle(this, b)) {
			SOUND("SE_Hit01")->Play();
			SetKill();
			GameData04::t_time += 600;
		}
		break;
	case eType_Enemy:
		if (m_type == eType_Player_Attack && Base::CollisionCircle(this, b)) {
			SetKill();
			b->SetKill();
		}
		break;

	}
}