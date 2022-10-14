#include "Enemy03.h"
#include"Slash03.h"
#include"Effect03.h"
#include"AnimData03.h"
#include"Field03.h"
#include"Map.h"

Enemy03::Enemy03(const CVector2D& pos, bool flip) :Base(eType_Enemy) {
	m_img = COPY_RESOURCE("Enemy03", CImage);//�摜����
	m_img.ChangeAnimation(0);//�Đ��A�j���[�V�����ݒ�
	m_pos_old=m_pos = pos;//���W�ݒ�
	m_img.SetCenter(128, 224);//���S�ʒu�ݒ�
	m_rect = CRect(-32,-128,32,0);//�����蔻��p��`
	m_flip = flip;//���]�ݒ�
	m_state = eState_Idle;
	m_cnt = rand() % 120 + 180;//�ҋ@����3�`5�b
	m_is_ground = true;
	m_attack_no = rand();
	m_damage_no = -1;
	m_hp = 100;
}

void Enemy03::Update(){
	m_pos_old = m_pos;
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
	case eState_Wait:
		StateWait();
	}
	if (m_is_ground && m_vec.y > GRAVITY * 4) {
		m_is_ground = false;
	}
	//�d�͂ɂ�闎��
	m_vec.y += GRAVITY;
	m_pos += m_vec;

	m_img.UpdateAnimation();//�A�j���[�V�����X�V
}

void Enemy03::Draw(){
	m_img.SetPos(GetScreenPos(m_pos));//���W�ݒ�
	m_img.SetFlipH(m_flip);//���]�ݒ�
	m_img.Draw();//�`��
	//DrawRect();//�����蔻��p��`�\��
}

void Enemy03::Collision(Base* b) {
	switch (b->m_type) {
	case eType_Player_Attack:
		if (Slash03* s = dynamic_cast<Slash03*>(b)) {
			if (m_damage_no != s->GetAttackNo() && Base::CollisionRect(this, s)) {
				m_damage_no = s->GetAttackNo();//�����U���̘A���_���[�W�h�~
				SOUND("SE_EnemyDamage03")->Play();
				m_hp -= 50;
				if (m_hp <= 0) {
					m_state = eState_Down;
				}
				else {
					m_state = eState_Damage;
				}
				Base::Add(new Effect03("Effect_Blood", m_pos + CVector2D(0, -128), m_flip));
			}
		}
		break;
	case eType_Field:
		/*
		if (Field03* f = dynamic_cast<Field03*>(b)) {
			//�n�ʂ�艺�ɍs�����Ƃ�
			if (m_pos.y > f->GetGroundY()) {
				m_pos.y = f->GetGroundY();//�n�ʂ̍����ɖ߂�
				m_vec.y = 0;//�������x���Z�b�g
				m_is_ground = true;//�ڒn�t���OON
			}
		}
		*/
		if (Map* m = dynamic_cast<Map*>(b)) {
			int t = m->CollisionMap(CVector2D(m_pos.x, m_pos_old.y));
			if (t != 0) {
				m_pos.x = m_pos_old.x;
			}
			t = m->CollisionMap(CVector2D(m_pos_old.x, m_pos.y));
			if (t != 0) {
				m_pos.y = m_pos_old.y;//���̍����ɖ߂�
				m_vec.y = 0;//�������x���Z�b�g
				m_is_ground = true;//�ڒn�t���OON
			}
		}
		break;
	}
}

void Enemy03::StateWait(){
	m_img.ChangeAnimation(eAnimIdle);
	if (--m_cnt <= 0) {
		m_cnt =rand()%120+180;//�ҋ@����3�`5�b
		m_state = eState_Idle;
	}
}

void Enemy03::StateIdle() {
	const float move_speed = 6;
	bool move_flag = false;
	const float jump_pow = 12;
	Base* player = Base::FindObject(eType_Player);

	if (player) {
		//���ړ�
		if (player->m_pos.x < m_pos.x - 64) {
			m_pos.x += -move_speed;
			m_flip = true;
			move_flag = true;
		}
		else
		//�E�ړ�
		if (player->m_pos.x > m_pos.x + 64) {
			m_pos.x += move_speed;
			m_flip = false;
			move_flag = true;
		}
		//�U��
		else {
			m_state = eState_Attack;
			m_attack_no++;
		}
	}
	if (move_flag) {
		//����A�j���[�V����
		m_img.ChangeAnimation(eAnimRun);
	}
	else {
		//�ҋ@�A�j���[�V����
		m_img.ChangeAnimation(eAnimIdle);
	}
	
	if (--m_cnt <= 0) {
		m_cnt =rand()%120+180;//�ҋ@����3�`�b
		m_state = eState_Wait;
	}
	
}

void Enemy03::StateAttack() {
	m_img.ChangeAnimation(eAnimAttack01, false);//�U���A�j���[�V�����֕ύX
	if (m_img.GetIndex() == 3) {
		if (m_flip) {
			Base::Add(new Slash03(m_pos + CVector2D(-64, -64), m_flip, eType_Enemy_Attack, m_attack_no));
		}
		else {
			Base::Add(new Slash03(m_pos + CVector2D(64, -64), m_flip, eType_Enemy_Attack, m_attack_no));
		}
	}

	//�A�j���[�V�������I��������
	if (m_img.CheckAnimationEnd()) {
		m_state = eState_Idle;//�ʏ��Ԃֈڍs
	}
}

void Enemy03::StateDamage() {
	m_img.ChangeAnimation(eAnimDamage, false);

	if (m_img.CheckAnimationEnd()) {
		m_state = eState_Idle;
	}
}

void Enemy03::StateDown() {
	m_img.ChangeAnimation(eAnimDown, false);

	if (m_img.CheckAnimationEnd()) {
		Base::Add(new Effect03("Effect_Smoke", m_pos + CVector2D(0,0), m_flip));
		SetKill();
	}
}