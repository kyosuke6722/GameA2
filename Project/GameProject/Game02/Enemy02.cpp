#include "Enemy02.h"
Enemy::Enemy(const CVector2D& pos) : Base(eType_Enemy) {
	m_img.Load("Image/Enemy02.png");
	m_pos = pos;
	//���a
	m_rad = 16;
	//�\���T�C�Y
	m_img.SetSize(32, 32);
	//�摜�̒��S�ɐݒ�
	m_img.SetCenter(16, 16);
}

void Enemy::Update() {
	//�G������
	const int move_speed = 32;
	//�J�E���g�A�b�v
	m_cnt++;
	if (m_cnt >= 60) {
		//�ړ�
		m_pos.y += move_speed;
		//�J�E���g���Z�b�g
		m_cnt = 0;
	}
}

void Enemy::Draw() {
	m_img.SetPos(m_pos);
	m_img.Draw();
}