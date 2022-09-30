#include "Enemy01.h"

Enemy01::Enemy01(const CVector2D& pos):Base(eType_Enemy)
{
	m_img = COPY_RESOURCE("Enemy01", CImage);
	m_pos = pos;
	
	if (m_pos.x > 1280) {
	}
}

void Enemy01::Update()
{
	//�o�[�̉��ړ�
	if (HOLD(CInput::eDown)) {
		m_pos.y += 8;
	}
	//�o�[�̏�ړ�
	if (HOLD(CInput::eUp)) {
		m_pos.y -= 8;

	}

}

void Enemy01::Draw()
{
	m_img.SetPos(m_pos);
	m_img.Draw();

}
