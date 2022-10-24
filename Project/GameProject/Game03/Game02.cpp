#include "Game02.h"
#include "../Game02/Player02.h"
#include "../Game02/Enemy02.h"
#include "../Game02/Bullet02.h"
#include "../Game02/Effect02.h"
#include "../Game02/UI02.h"
#include "../Game02/GameData02.h"
#include"../Title/Result.h"

Game02::Game02(bool tuto) :Base(eType_Scene) {
	SOUND("BGM_Game02")->Play(true);
	Base::Add(new Player02(CVector2D(640, 600)));
	m_cnt = 0;
	Base::Add(new UI02());
	m_is_tuto = tuto;
}

void Game02::Update() {
	GameData02::t_time++;
	m_cnt--;
	float m_spawn = rand()%(1280-900-16);
	if (m_cnt <= 0) {
		//Base::Add(new Enemy02(CVector2D(100, 200)));
		Base::Add(new Enemy02(CVector2D(200+m_spawn, 150)));
		Base::Add(new Enemy02(CVector2D(300+m_spawn, 100)));
		Base::Add(new Enemy02(CVector2D(400+m_spawn, 50)));
		Base::Add(new Enemy02(CVector2D(500+m_spawn, 0)));
		Base::Add(new Enemy02(CVector2D(600+m_spawn, 200)));
		Base::Add(new Enemy02(CVector2D(700+m_spawn, 150)));
		Base::Add(new Enemy02(CVector2D(800+m_spawn, 100)));
		Base::Add(new Enemy02(CVector2D(900+m_spawn, 50)));
		//Base::Add(new Enemy02(CVector2D(1000, 0)));
		m_cnt = 180;
	}
	if (GameData02::s_score >= 5000) {
		SetKill();
	}
}

Game02::~Game02(){
	SOUND("BGM_Game02")->Pause();
	Base::KillAll();
	Result::finish_game = 2;
	Base::Add(new Result(m_is_tuto));
}