#include "Enemy01.h"
#include "GameData01.h"

Enemy01::Enemy01(const CVector2D& pos):Base(eType_Enemy)
{
	m_img = COPY_RESOURCE("Enemy01", CImage);
	m_pos = pos;
	
	if (m_pos.x > 1280) {
	}

	
	m_rect = CRect(0, 0, 32, 128);

}

void Enemy01::Update()
{
	if (GameData01::game_state == 1) {
		//�o�[�̉��ړ�
		if (HOLD(CInput::eDown)) {
			m_pos.y += 8;
		}
		//�o�[�̏�ړ�
		if (HOLD(CInput::eUp)) {
			m_pos.y -= 8;

		}
		

	}
}

void Enemy01::Draw()
{
	m_img.SetPos(m_pos);
	m_img.Draw();
	DrawRect();
}
