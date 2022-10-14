#include "Bullet02.h"
#include "Effect02.h"
#include "GameData02.h"

Bullet02::Bullet02(const CVector2D& pos) : Base(eType_Bullet){

	m_img.Load("Image/Bullet.png");
	m_img.Load("Image/Bullet2.png");
	m_pos = pos;
	//���a
	m_rad = 12;
	//�\���T�C�Y
	m_img.SetSize(32, 32);
	//�摜�̒��S�ɐݒ�
	m_img.SetCenter(16, 16);
}



void Bullet02::Update() {
	//�e�̑���
	//const int move_speed1 = 4;
	//m_pos.y -= move_speed;
}

void Bullet02::Draw() {
	m_img.SetPos (m_pos);
	m_img.Draw();
}

void Bullet02::Collision(Base* b) {
	//�Ώۂ̃I�u�W�F�N�g�̎�ނɂ���ĕ���
	switch (b->m_type) {
		//�G�̏ꍇ
	case eType_Enemy:

		//�~���m�̔���i�����A�Ώۂ��j
		if (Base::CollisionCircle(this, b)) {
			b->SetKill();
			SetKill();
			Base::Add(new Effect02(b->m_pos));
			GameData02::s_score += 100;
		}
		break;

	case eType_Player:

		//�~���m�̔���i�����A�Ώۂ��j
		if (Base::CollisionCircle(this, b)) {
			b->SetKill();
			//SetKill();
			Base::Add(new Effect02(b->m_pos));
			//GameData02::t_time += 10;
		}
		break;

	}
}