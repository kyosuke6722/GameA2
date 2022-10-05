#include "Player01.h"

Player01::Player01(const CVector2D& pos) :Base(eType_Player)
{
	m_img = COPY_RESOURCE("Player01", CImage);
	m_pos = pos;


	m_rect = CRect(0,0,32,128);

}
void Player01::Update()
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

void Player01::Draw()
{


	m_img.SetPos(m_pos);
	m_img.Draw();




}



