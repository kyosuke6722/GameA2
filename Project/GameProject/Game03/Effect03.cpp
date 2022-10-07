#include "Effect03.h"

Effect03::Effect03(const char* name, const CVector2D& pos, bool flip):Base(eType_Effect) {
	m_img = COPY_RESOURCE(name, CImage);//�摜����
	m_pos = pos;//���W�ݒ�
	m_img.SetSize(128,128);//�\���T�C�Y�ݒ�
	m_img.SetCenter(64, 64);//���S�ʒu�ݒ�
	m_img.ChangeAnimation(0, false);//�Đ��A�j���[�V�����ݒ�(�񃋁[�v)
	m_flip = flip;//���]�ݒ�
}

void Effect03::Update(){
	m_img.UpdateAnimation();
	if (m_img.CheckAnimationEnd()) {
		SetKill();
	}
}

void Effect03::Draw(){
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetFlipH(m_flip);
	m_img.Draw();
}
