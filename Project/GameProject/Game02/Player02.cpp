#include "Player02.h"
#include "Bullet02.h"
Player::Player(const CVector2D& pos) : Base(eType_Player) {
	m_img.Load("Image/Player02.png");
	m_pos = pos;
	//���a�ݒ�
	m_rad = 12;
	//�\���T�C�Y
	m_img.SetSize(32, 32);
	//�摜�̒��S�ɐݒ�
	m_img.SetCenter(16, 16);
}

void Player::Update() {
	const int move_speed = 4;
	if (HOLD(CInput::eRight))
		m_pos.x += move_speed;
	if (HOLD(CInput::eLeft))
		m_pos.x -= move_speed;
	if (PUSH(CInput::eButton1)) {
		Base::Add(new Bullet(m_pos));
	}
}

void Player::Draw() {
	m_img.SetPos(m_pos);
	m_img.Draw();
}