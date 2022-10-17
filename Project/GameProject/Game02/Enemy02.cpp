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
	const int move_speed = 4;
	//カウントアップ
	m_cnt++;
	if (m_cnt >= 120) {
		//移動
		m_pos.y += move_speed;
		//カウントリセット
		
	}
	//弾
	if (m_cnt >= 180) {
		//Enemy_Attack();
		//m_img.Load("Image/Bullet2.png");

		Base::Add(new Bullet02(eType_Enemy_Attack, m_pos, m_ang, 4));
		//m_pos.y += 4;
		m_cnt = 0;
	}
}

void Enemy02::Draw() {
	m_img.SetPos(m_pos);
	m_img.Draw();
}