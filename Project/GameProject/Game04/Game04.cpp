#include"Game04.h"
#include"Player04.h"
#include"Enemy04.h"
#include"GameData04.h"
#include"UI04.h"
#include"../Title/Result.h"
#include"Map04.h"
Game04::Game04(bool tuto):Base(eType_Scene) {
	Base::Add(new Enemy04(CVector2D(32 * 3, 32 * 8)));
	Base::Add(new Enemy04(CVector2D(32 * 17, 32 * 14)));
	Base::Add(new Enemy04(CVector2D(3 * 37, 32 * 10)));
	Base::Add(new Enemy04(CVector2D(3 * 50, 32 * 20)));
	Base::Add(new Enemy04(CVector2D(32 * 10, 32 * 8)));
	Base::Add(new Enemy04(CVector2D(32 * 25, 32 * 13)));
	Base::Add(new Enemy04(CVector2D(32 * 35, 32 * 12)));
	Base::Add(new Enemy04(CVector2D(32 * 30, 32 * 6)));
	Base::Add(new Enemy04(CVector2D(32 * 28, 32 * 20)));
	Base::Add(new Player04(CVector2D(32 * 3, 32 * 4)));
	m_cnt = 0;
	Base::Add(new Map04());
	Base::Add(new UI04());
	m_is_tuto = tuto;

}

Game04::~Game04()
{
	Base::KillAll();
	SOUND("BGM_Game04")->Pause();
	Result::finish_game = 4;
	Base::Add(new Result(m_is_tuto));
}


	


void Game04::Update()

{
	if (m_cnt-- <= 0)
	{
		SOUND("BGM_Game04")->Play();
		m_cnt = 71 * 60;
}
	if (!Base::FindObject(eType_Enemy)) {
		SetKill();
	}
	else {
		GameData04::t_time++;
	}
}
