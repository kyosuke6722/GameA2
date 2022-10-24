#include "Player02.h"
#include "Bullet02.h"
Player02::Player02(const CVector2D& pos) : Base(eType_Player) {
	m_img.Load("Image/Player02.png");
	m_pos_old=m_pos = pos;
	//���a�ݒ�
	m_rad = 12;
	//�\���T�C�Y
	m_img.SetSize(32, 32);
	//�摜�̒��S�ɐݒ�
	m_img.SetCenter(16, 16);
}

void Player02::Update() {
	m_pos_old = m_pos;
	m_cnt++;
	//���x
	const int move_speed = 4;
	//�E
	if (HOLD(CInput::eRight))
		m_pos.x += move_speed;
	//��
	if (HOLD(CInput::eLeft))
		m_pos.x -= move_speed;
	//��
	if (HOLD(CInput::eUp))
		m_pos.y -= move_speed;
	//��
	if (HOLD(CInput::eDown))
		m_pos.y += move_speed;
	//�e
	if (PUSH(CInput::eButton5)) {
		if (m_cnt >= 30) {
			SOUND("SE_Hit01")->Play();
				Base::Add(new Bullet02(eType_Player_Attack, m_pos, m_ang, 4));
			m_cnt = 0;
		}
	}
	if (m_pos.x < 16 || m_pos.x>1280 - 16 || m_pos.y < 16 || m_pos.y>720 - 16)
		m_pos = m_pos_old;//��ʊO�ɍs���Ɖ����߂����
}

void Player02::Draw() {
	m_img.SetPos(m_pos);
	m_img.Draw();
}

void Player02::Collision(Base* b){
	if (Base::CollisionCircle(this, b)) {
		m_pos = m_pos_old;
	}
}
