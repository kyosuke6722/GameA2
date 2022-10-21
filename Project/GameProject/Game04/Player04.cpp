#include "Player04.h"
#include "Bullet04.h"
#include "Map04.h"
Player04::Player04(const CVector2D& pos)
	:Base(eType_Player)
{

	m_img = COPY_RESOURCE("Player04", CImage);
	m_pos = m_pos_old = pos;
	m_img.SetCenter(16, 16);
	//’ZŒ`‚ðÝ’è
	m_rect = CRect(-16, -16, 16, 16);
	//”¼Œa
	m_rad = 16;


}
void Player04::Update()
{
	m_pos_old = m_pos;

	const float speed = 4;
	//¶‚ÉˆÚ“®
	if (HOLD(CInput::eLeft))
		m_pos.x -= speed;
	//‰E‚ÉˆÚ“®
	if (HOLD(CInput::eRight))
		m_pos.x += speed;
	//ã‚ÉˆÚ“®
	if (HOLD(CInput::eUp))
		m_pos.y -= speed;
	//‰º‚ÉˆÚ“®
	if (HOLD(CInput::eDown))
		m_pos.y += speed;


	//ƒ}ƒEƒX‚ÌƒxƒNƒgƒ‹
	CVector2D vec = CInput::GetMousePoint() - m_pos;
	//‰ñ“]’l‚ð‹tŽZ
	m_ang = atan2(vec.x, vec.y);

	if (PUSH(CInput::eMouseL)) {
		SOUND("SE_Hit01")->Play();
		Base::Add(new Bullet04(eType_Player_Attack, m_pos, m_ang, 4));

	}


}


void Player04::Collision(Base* b)
{
	switch (b->m_type) {
	case eType_Field:
		if (Map04* m = dynamic_cast<Map04*>(b)) {
			int t = m->CollisionMap(CVector2D(m_pos.x, m_pos_old.y)), m_rect=0;
			if (t != 0)
				m_pos.x = m_pos_old.x;
			t = m->CollisionMap(CVector2D(m_pos_old.x, m_pos.y)), m_rect;
			if (t != 0)
				m_pos.y = m_pos_old.y;



		}
	case eType_Enemy:
		if (Base::CollisionCircle(this, b))
		
			m_pos = m_pos_old;
		break;

	}

}


void Player04::Draw() {
	m_img.SetPos(m_pos);
	m_img.SetAng(m_ang);
	m_img.Draw();

}