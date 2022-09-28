#include "Enemy03.h"
#include"AnimData03.h"

Enemy03::Enemy03(const CVector2D& pos, bool flip):Base(eType_Enemy) {
	m_img = COPY_RESOURCE("Enemy03", CImage);//�摜����
	m_img.ChangeAnimation(0);//�Đ��A�j���[�V�����ݒ�
	m_pos = pos;//���W�ݒ�
	m_img.SetCenter(128,224);//���S�ʒu�ݒ�
	m_flip = flip;//���]�ݒ�
}

void Enemy03::Update(){
	const float move_speed = 6;
	bool move_flag = false;
	const float jump_pow = 12;
	Base* player = Base::FindObject(eType_Player);

	//���ړ�
	if (player->m_pos.x < m_pos.x - 64) {
		m_pos.x += -move_speed;
		m_flip = true;
		move_flag = true;
	}
	//�E�ړ�
	if (player->m_pos.x > m_pos.x + 64) {
		m_pos.x += move_speed;
		m_flip = false;
		move_flag = true;
	}

	if (move_flag) {
		//����A�j���[�V����
		m_img.ChangeAnimation(eAnimRun);
	}
	else {
		//�ҋ@�A�j���[�V����
		m_img.ChangeAnimation(eAnimIdle);
	}

	m_img.UpdateAnimation();//�A�j���[�V�����X�V
}

void Enemy03::Draw(){
	m_img.SetPos(m_pos);//���W�ݒ�
	m_img.SetFlipH(m_flip);//���]�ݒ�
	m_img.Draw();//�`��
}

void Enemy03::Collision(){
}

void Enemy03::StateIdle() {
}

void Enemy03::StateAttack() {
	m_img.ChangeAnimation(eAnimAttack01, false);//�U���A�j���[�V�����֕ύX

	//�A�j���[�V�������I��������
	if (m_img.CheckAnimationEnd()) {
		m_state = eState_Idle;//�ʏ��Ԃֈڍs
	}
}

void Enemy03::StateDamage() {
}

void Enemy03::StateDown() {
}