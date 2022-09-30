#include "Player03.h"
#include"AnimData03.h"
#include"Slash03.h"
#include"Effect03.h"
#include"Field03.h"

Player03::Player03(const CVector2D& pos, bool flip):Base(eType_Player){
	m_img = COPY_RESOURCE("Player03", CImage);//�摜����
	m_img.ChangeAnimation(0);//�Đ��A�j���[�V�����ݒ�
	m_pos = pos;//���W�ݒ�
	m_img.SetCenter(128, 224);//���S�ʒu�ݒ�
	m_rect = CRect(-32, -128, 32, 0);//�����蔻��p��`
	m_flip = flip;//���]�t���O
	m_state = eState_Idle;//�������
	m_attack_no = rand();//�U���ԍ�
	m_damage_no = -1;//�_���[�W�ԍ�
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
	}
	//������Ԃֈڍs
	if (m_is_ground && m_vec.y > GRAVITY * 4) {
		m_is_ground = false;
	}
	//�d�͂ɂ�闎��
	m_vec.y += GRAVITY;
	m_pos += m_vec;

	m_img.UpdateAnimation();//�A�j���[�V�����X�V
	m_scroll.x = m_pos.x - 1280 / 2;//�X�N���[���ݒ�
}

void Player03::Draw(){
	m_img.SetPos(GetScreenPos(m_pos));//�ʒu�ݒ�
	m_img.SetFlipH(m_flip);//���]�ݒ�
	m_img.Draw();//�`��
	DrawRect();
}

void Player03::Collision(Base* b){
	switch (b->m_type) {
	case eType_Goal:
		if (Base::CollisionRect(this, b)) {
			b->SetKill();
		}
		break;
	case eType_Enemy_Attack:
		if (Slash03* s = dynamic_cast<Slash03*>(b)) {
			if (m_damage_no != s->GetAttackNo() && Base::CollisionRect(this, s)) {
				m_damage_no = s->GetAttackNo();//�����U���̘A���_���[�W�h�~
				Base::Add(new Effect03("Effect_Blood", m_pos + CVector2D(0, -128), m_flip));
			}
		}
		break;
	case eType_Field:
		if (Field03* f = dynamic_cast<Field03*>(b)) {
			//�n�ʂ�艺�ɍs�����Ƃ�
			if (m_pos.y > f->GetGroundY())
				m_pos.y = f->GetGroundY();//�n�ʂ̍����ɖ߂�
			    m_vec.y = 0;//�������x���Z�b�g
				m_is_ground = true;//�ڒn�t���OON
		}
		break;
	}
}

void Player03::StateIdle(){
	const float move_speed = 6;//�ړ���
	const float jump_pow = 12;//�W�����v��
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

	//�W�����v
	if (m_is_ground && PUSH(CInput::eButton2)) {
		m_vec.y=-jump_pow;
		m_is_ground = false;
	}

	//�U��
	if (PUSH(CInput::eButton1)) {
		m_state = eState_Attack;//�U����Ԃֈڍs
		m_attack_no++;
	}

	//�W�����v���Ȃ�
	if (!m_is_ground) {
		if (m_vec.y < 0) {
			m_img.ChangeAnimation(eAnimJumpUp, false);//	�㏸�A�j���[�V����
		}
		else {
			m_img.ChangeAnimation(eAnimJumpDown, false);//���~�A�j���[�V����
		}
	}
	//�ړ����Ȃ�
	else {
		if (move_flag) {
			m_img.ChangeAnimation(eAnimRun);//����A�j���[�V����
		}
		else {
			m_img.ChangeAnimation(eAnimIdle);//�ҋ@�A�j���[�V����
		}
	}
}

void Player03::StateAttack() {
	m_img.ChangeAnimation(eAnimAttack01, false);//�U���A�j���[�V�����֕ύX
	//3�Ԗڂ̃p�^�[���Ȃ�
	if (m_img.GetIndex() == 3) {
		if (m_flip) {
			Base::Add(new Slash03(m_pos + CVector2D(-64, -64), m_flip, eType_Player_Attack, m_attack_no));
		}
		else {
			Base::Add(new Slash03(m_pos + CVector2D(64, -64), m_flip, eType_Player_Attack, m_attack_no));
		}
	}

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