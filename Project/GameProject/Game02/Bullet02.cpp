#include "Bullet02.h"
#include "Effect02.h"
#include "GameData02.h"

Bullet02::Bullet02(int Type, const CVector2D& pos, float ang, float speed)
	: Base(Type)
	{
	if (Type == eType_Player_Attack) {
		m_img = COPY_RESOURCE("Bullet", CImage);
	}
	else{
		m_img = COPY_RESOURCE("Bullet2", CImage);
	}
	m_pos = pos;
	m_ang = ang;
	m_speed = speed;
	//画像の中心に設定
	m_img.SetCenter(16, 16);
}




void Bullet02::Update() {
	//弾の速さ
	const int move_speed = 4;
	if (m_type == eType_Player_Attack) {
		m_pos.y -= move_speed;
	}
	if (m_type == eType_Enemy_Attack) {
		m_pos.y += move_speed;
	}
	//m_vec = CVector2D(sin(m_ang), cos(m_ang)) * m_speed;
	//m_pos += m_vec;
}

void Bullet02::Draw() {
	m_img.SetPos (m_pos);
	m_img.SetAng(m_ang);
	m_img.Draw();
}

void Bullet02::Collision(Base* b) {

	//対象のオブジェクトの種類によって分岐
	switch (b->m_type) {
	
	case eType_Player:

		//円同士の判定（自分、対象ｂ）
		if (m_type == eType_Enemy_Attack && Base::CollisionCircle(this, b)) {
			SetKill();
			Base::Add(new Effect02(b->m_pos));
			GameData02::t_time += 600;
		}
		break;

	case eType_Enemy:

		//円同士の判定（自分、対象ｂ）
		if (m_type == eType_Player_Attack && Base::CollisionCircle(this, b)) {
			b->SetKill();
			SetKill();
			Base::Add(new Effect02(b->m_pos));
			GameData02::s_score += 200;
		}
		break;

	}
}