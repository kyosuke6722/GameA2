#include "Effect02.h"

static TexAnim _effect_bomb[] = {
	{0,2},
	{1,2},
	{2,2},
	{3,2},
	{4,2},
};

TexAnimData effectAnimData[] = {
	ANIMDATA(_effect_bomb),
};

Effect02::Effect02(const CVector2D& pos) :Base(eType_Effect) {
	m_img.Load("Image/Effect_Bomb.png", effectAnimData, 96, 96);
	m_pos = pos;
	m_img.ChangeAnimation(0, false);
	m_img.SetCenter(96 / 2, 96 / 2);
}

void Effect02::Update() {
	m_img.UpdateAnimation();
	if (m_img.CheckAnimationEnd())
		m_kill = true;
}

void Effect02::Draw() {
	m_img.SetPos(m_pos);
	m_img.Draw();
}