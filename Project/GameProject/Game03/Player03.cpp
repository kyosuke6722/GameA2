#include "Player03.h"
#include"AnimData03.h"

Player03::Player03(const CVector2D& pos, bool flip):Base(eType_Player){
	m_img = COPY_RESOURCE("Player03", CImage);//�摜����
	m_img.ChangeAnimation(0);//�Đ��A�j���[�V�����ݒ�
	m_pos = pos;//���W�ݒ�
	m_img.SetCenter(128, 224);//���S�ʒu�ݒ�
	m_flip = flip;//���]�t���O
	m_state = eState_Idle;//�������
}

void Player03::Update(){
	switch (m_state) {
		//�ʏ���
	case eState_Idle:
		StateIdle();
		break;
		//�U�����
	case eState_Attack:
		StateAttack();
		break;
		//�_���[�W���
	case eState_Damage:
		StateDamage();
		break;
		//�_�E�����
	case eState_Down:
		StateDown();
		break;
	}

	m_img.UpdateAnimation();//�A�j���[�V�����X�V
}

void Player03::Draw(){
	m_img.SetPos(m_pos);//�ʒu�ݒ�
	m_img.SetFlipH(m_flip);//���]�ݒ�
	m_img.Draw();//�`��
}

void Player03::Collision(Base* b){
}

void Player03::StateIdle(){
	const float move_speed = 6;//�ړ���
	bool move_flag = false;//�ړ��t���O

	//���ړ�
	if (HOLD(CInput::eLeft)) {
		m_pos.x += -move_speed;//�ړ��ʂ�ݒ�
		m_flip = true;//���]�t���O
		move_flag = true;
	}
	//�E�ړ�
	if (HOLD(CInput::eRight)) {
		m_pos.x += move_speed;
		m_flip = false;
		move_flag = true;
	}

	//�U��
	if (PUSH(CInput::eButton1)) {
		//�U����Ԃֈڍs
	}

	//�ړ����Ȃ�
	if (move_flag) {
		m_img.ChangeAnimation(eAnimRun);//����A�j���[�V����
	}
	else {
		m_img.ChangeAnimation(eAnimIdle);//�ҋ@�A�j���[�V����
	}

}

void Player03::StateAttack() {
	m_img.ChangeAnimation(eAnimAttack01, false);//�U���A�j���[�V�����֕ύX

	//�A�j���[�V�������I��������
	if (m_img.CheckAnimationEnd()) {
		m_state = eState_Idle;//�ʏ��Ԃֈڍs
	}
}

void Player03::StateDamage(){
	m_img.ChangeAnimation(eAnimDamage, false);

	if (m_img.CheckAnimationEnd()) {
		m_state = eState_Idle;
	}
}

void Player03::StateDown() {
	m_img.ChangeAnimation(eAnimDown, false);

	if (m_img.CheckAnimationEnd()) {
		m_kill = true;
	}
}

