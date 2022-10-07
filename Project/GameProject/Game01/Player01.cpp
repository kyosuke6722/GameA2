#include "Player01.h"
#include "GameData01.h"


Player01::Player01(const CVector2D& pos) :Base(eType_Player)
{
	m_img = COPY_RESOURCE("Player01", CImage);
	m_pos = pos;
	m_rect = CRect(0,0,32,128);

	



}
void Player01::Update()
{
	if (GameData01::game_state == 1) {

		//バーの下移動
		if (HOLD(CInput::eDown)) {
			m_pos.y += 10;
		}
		//バーの上移動
		if (HOLD(CInput::eUp)) {
			m_pos.y -= 10;

		}


	}
}

void Player01::Draw()
{


	m_img.SetPos(m_pos);
	m_img.Draw();




}



