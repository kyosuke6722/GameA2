#include "Bullet02.h"
#include "Effect02.h"
#include "GameData02.h"

Bullet02::Bullet02(const CVector2D& pos) : Base(eType_Bullet){

	m_img.Load("Image/Bullet.png");
	m_img.Load("Image/Bullet2.png");
	m_pos = pos;
	//半径
	m_rad = 12;
	//表示サイズ
	m_img.SetSize(32, 32);
	//画像の中心に設定
	m_img.SetCenter(16, 16);
}



void Bullet02::Update() {
	//弾の速さ
	//const int move_speed1 = 4;
	//m_pos.y -= move_speed;
}

void Bullet02::Draw() {
	m_img.SetPos (m_pos);
	m_img.Draw();
}

void Bullet02::Collision(Base* b) {
	//対象のオブジェクトの種類によって分岐
	switch (b->m_type) {
		//敵の場合
	case eType_Enemy:

		//円同士の判定（自分、対象ｂ）
		if (Base::CollisionCircle(this, b)) {
			b->SetKill();
			SetKill();
			Base::Add(new Effect02(b->m_pos));
			GameData02::s_score += 100;
		}
		break;

	case eType_Player:

		//円同士の判定（自分、対象ｂ）
		if (Base::CollisionCircle(this, b)) {
			b->SetKill();
			//SetKill();
			Base::Add(new Effect02(b->m_pos));
			//GameData02::t_time += 10;
		}
		break;

	}
}