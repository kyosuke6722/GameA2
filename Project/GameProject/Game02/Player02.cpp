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
	m_cnt++;
	//速度
	const int move_speed = 4;
	//右
	if (HOLD(CInput::eRight))
		m_pos.x += move_speed;
	//左
	if (HOLD(CInput::eLeft))
		m_pos.x -= move_speed;
	//上
	if (HOLD(CInput::eUp))
		m_pos.y -= move_speed;
	//下
	if (HOLD(CInput::eDown))
		m_pos.y += move_speed;
	//弾
	if (PUSH(CInput::eButton5)) {
		if (m_cnt >= 50) {
				Base::Add(new Bullet02(eType_Player_Attack, m_pos, m_ang, 4));
			m_cnt = 0;
		}
	}
}

void Player02::Draw() {
	m_img.SetPos(m_pos);
	m_img.Draw();
}