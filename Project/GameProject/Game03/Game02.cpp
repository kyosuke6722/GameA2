#include "Game02.h"
#include "../Game02/Player02.h"
#include "../Game02/Enemy02.h"
#include "../Game02/Bullet02.h"
#include "../Game02/Effect02.h"
#include "../Game02/UI02.h"
#include "../Game02/GameData02.h"

Game02::Game02() :Base(eType_Scene) {
	//for (i = 0;i<0;i++) {
	Base::Add(new Player02(CVector2D(600, 600)));
		if (m_cnt >= 180) {
			Base::Add(new Enemy02(CVector2D(600, 200)));
			Base::Add(new Enemy02(CVector2D(700, 150)));
			Base::Add(new Enemy02(CVector2D(800, 100)));
			Base::Add(new Enemy02(CVector2D(900, 50)));
			Base::Add(new Enemy02(CVector2D(1000, 0)));
			m_cnt = 0;
		}
	//}
}

void Game02::Update() {
	m_cnt++;
	t_time++;
}

Game02::~Game02(){

}