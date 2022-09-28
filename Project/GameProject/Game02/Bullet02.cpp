#include "Bullet02.h"
#include "Effect02.h"
#include "GameData02.h"

Bullet::Bullet(const CVector2D& pos) : Base(eType_Bullet) {
	m_img.Load("Image/Bullet.png");
	m_pos = pos;
	//半径
	m_rad = 12;
	//表示サイズ
	m_img.SetSize(32, 32);
	//画像の中心に設定
	m_img.SetCenter(16, 16);
}

void Bullet::Update() {
	const int move_speed = 4;
	m_pos.y -= move_speed;
}

void Bullet::Draw() {
	m_img.SetPos (m_pos);
	m_img.Draw();
}

void Bullet::Collision(Base* b) {
	//対象のオブジェクトの種類によって分岐
	switch (b->m_type) {
		//敵の場合
	case eType_Enemy:
		//円同士の判定（自分、対象ｂ）
		if (Base::CollisionCircle(this, b)) {
			b->SetKill();
			SetKill();
			Base::Add(new Effect(b->m_pos));
			GameData::s_score += 100;
		}
		break;
	}
}