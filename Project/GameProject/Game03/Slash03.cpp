#include "Slash03.h"

Slash03::Slash03(const CVector2D& pos, bool flip, int type, int attack_no):Base(type) {
	m_img = COPY_RESOURCE("Slash03", CImage);//�摜����
	m_flip = flip;//���]�ݒ�
	m_pos = pos;//���W�ݒ�
	m_img.SetSize(128,128);//�\���T�C�Y�ݒ�
	m_img.SetCenter(64,64);//���S�ʒu�ݒ�
	m_rect = CRect(-64, -64, 64, 64);//�����蔻��p��`
	m_img.ChangeAnimation(0, false);//�Đ��A�j���[�V�����ݒ�(�񃋁[�v)
	m_attack_no = attack_no;//�U���ԍ�
}

void Slash03::Update(){
	m_img.UpdateAnimation();//�A�j���[�V�����X�V
	//�A�j���[�V�����I���`�F�b�N
	if (m_img.CheckAnimationEnd()) {
		SetKill();//�G�t�F�N�g�폜
	}
}

void Slash03::Draw(){
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetFlipH(m_flip);
	m_img.Draw();
}
