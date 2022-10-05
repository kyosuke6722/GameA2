#include "Player02.h"
#include "Bullet02.h"
Player02::Player02(const CVector2D& pos) : Base(eType_Player) {
	m_img.Load("Image/Player02.png");
	m_pos = pos;
	//半径設定
	m_rad = 12;
	//表示サイズ
	m_img.SetSize(32, 32);
	//画像の中心に設定
	m_img.SetCenter(16, 16);
}

void Player02::Update() {
	const int move_speed = 4;
	if (HOLD(CInput::eRight))
		m_pos.x += move_speed;
	if (HOLD(CInput::eLeft))
		m_pos.x -= move_speed;
	if (HOLD(CInput::eUp))
		m_pos.y -= move_speed;
	if (HOLD(CInput::eDown))
		m_pos.y += move_speed;
	if (PUSH(CInput::eButton5)) {
		Base::Add(new Bullet02(m_pos));
		m_pos.y -= 4;
	}
}

void Player02::Draw() {
	m_img.SetPos(m_pos);
	m_img.Draw();
}