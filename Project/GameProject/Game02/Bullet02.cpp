#include "Bullet02.h"
#include "Effect02.h"
#include "GameData02.h"

Bullet::Bullet(const CVector2D& pos) : Base(eType_Bullet) {
	m_img.Load("Image/Bullet.png");
	m_pos = pos;
	//���a
	m_rad = 12;
	//�\���T�C�Y
	m_img.SetSize(32, 32);
	//�摜�̒��S�ɐݒ�
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
	//�Ώۂ̃I�u�W�F�N�g�̎�ނɂ���ĕ���
	switch (b->m_type) {
		//�G�̏ꍇ
	case eType_Enemy:
		//�~���m�̔���i�����A�Ώۂ��j
		if (Base::CollisionCircle(this, b)) {
			b->SetKill();
			SetKill();
			Base::Add(new Effect(b->m_pos));
			GameData::s_score += 100;
		}
		break;
	}
}