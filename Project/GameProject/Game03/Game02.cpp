#include "Game02.h"
#include "../Game02/Player02.h"
#include "../Game02/Enemy02.h"
#include "../Game02/Bullet02.h"
#include "../Game02/Effect02.h"
#include "../Game02/UI02.h"
#include "../Game02/GameData02.h"
#include"../Title/Result.h"

Game02::Game02(bool tuto) :Base(eType_Scene) {
	Base::Add(new Player02(CVector2D(640, 600)));
	m_cnt = 0;
	Base::Add(new UI02());
	m_is_tuto = tuto;
}

void Game02::Update() {
	GameData02::t_time++;
	m_cnt++;
	if (m_cnt >= 180) {
		//Base::Add(new Enemy02(CVector2D(100, 200)));
		Base::Add(new Enemy02(CVector2D(200, 150)));
		Base::Add(new Enemy02(CVector2D(300, 100)));
		Base::Add(new Enemy02(CVector2D(400, 50)));
		Base::Add(new Enemy02(CVector2D(500, 0)));
		Base::Add(new Enemy02(CVector2D(600, 200)));
		Base::Add(new Enemy02(CVector2D(700, 150)));
		Base::Add(new Enemy02(CVector2D(800, 100)));
		Base::Add(new Enemy02(CVector2D(900, 50)));
		//Base::Add(new Enemy02(CVector2D(1000, 0)));
		m_cnt = 0;
	}
	if (GameData02::s_score >= 5000) {
		SetKill();
	}
}

Game02::~Game02()
{
	Base::KillAll();
	Result::finish_game = 2;
	Base::Add(new Result(m_is_tuto));
}