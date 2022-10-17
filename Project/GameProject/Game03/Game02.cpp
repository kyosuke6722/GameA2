#include "Game02.h"
#include "../Game02/Player02.h"
#include "../Game02/Enemy02.h"
#include "../Game02/Bullet02.h"
#include "../Game02/Effect02.h"
#include "../Game02/UI02.h"
#include "../Game02/GameData02.h"
#include"../Title/Result.h"

Game02::Game02() :Base(eType_Scene) {
	Base::Add(new Player02(CVector2D(640, 700)));
	m_cnt = 0;
	Base::Add(new UI02());
}

void Game02::Update() {
	m_cnt++;
	GameData02 :: t_time++;
	if (m_cnt >= 180) {
		Base::Add(new Enemy02(CVector2D(500, 200)));
		Base::Add(new Enemy02(CVector2D(600, 150)));
		Base::Add(new Enemy02(CVector2D(700, 100)));
		Base::Add(new Enemy02(CVector2D(800, 50)));
		Base::Add(new Enemy02(CVector2D(900, 0)));
		m_cnt = 0;
	}
}

Game02::~Game02(){

}