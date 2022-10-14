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
	if (GameData01::game_state == 1)
	{
		Base* ball = Base::FindObject(eType_Ball);
		if (ball) {
			//バーの下移動
			if (ball->m_pos.y > m_pos.y + 64+48) {
				m_pos.y += 8;

			}
			//バーの上移動
			if (ball->m_pos.y < m_pos.y -48+64) {
				m_pos.y -= 8;

			}
		}
		
		
		

	}
}

void Enemy01::Draw()
{
	m_img.SetPos(m_pos);
	m_img.Draw();
	
}
