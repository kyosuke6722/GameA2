#include "Game01.h"
#include "Ball01.h"
#include"Player01.h"
#include"Enemy01.h"
#include"UI01.h"
#include "GameData01.h"
#include"../Title/Result.h"
#include"Field01.h"
Game01::Game01(bool tuto)
	:Base(eType_Scene)
{
	Base::Add(new Field01());
	Base::Add(new Ball01(CVector2D(600, 300)));
	Base::Add(new Player01(CVector2D(0, 300)));
	Base::Add(new Enemy01(CVector2D(1280 - 32,300)));
	Base::Add(new UI01());
	SOUND("BGM_Game01")->Play();
	m_is_tuto = tuto;
}
Game01::~Game01()
{
	SOUND("BGM_Game01")->Pause();
	Base::KillAll();
	Result::finish_game = 1;
	Base::Add(new Result(m_is_tuto));
}

void Game01::Update()
{
	if (GameData01::game_state == 0 && PUSH(CInput::eButton1))
		GameData01::game_state = 1;
	if (GameData01::point[0]>=3) {
		SetKill();

	}
	if (GameData01::game_state ==1) {
		GameData01::t_time++;
		
	}

}

