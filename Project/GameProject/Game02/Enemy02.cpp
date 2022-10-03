#include "Enemy02.h"
#include "Bullet02.h"
Enemy02::Enemy02(const CVector2D& pos) : Base(eType_Enemy) {
	m_img.Load("Image/Enemy02.png");
	m_pos = pos;
	//半径
	m_rad = 16;
	//表示サイズ
	m_img.SetSize(32, 32);
	//画像の中心に設定
	m_img.SetCenter(16, 16);
}

void Enemy02::Update() {
	//敵を下へ
	const int move_speed = 32;
	//カウントアップ
	m_cnt++;
	if (m_cnt >= 60) {
		//移動
		m_pos.y += move_speed;
		//カウントリセット
		m_cnt = 0;
	}
	if (m_cnt >= 40) {
		Base::Add(new Bullet02(m_pos));
	}
}

void Enemy02::Draw() {
	m_img.SetPos(m_pos);
	m_img.Draw();
}