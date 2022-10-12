#include "Game02.h"
#include "../Game02/Player02.h"
#include "../Game02/Enemy02.h"
#include "../Game02/Bullet02.h"
#include "../Game02/Effect02.h"
#include "../Game02/UI02.h"
#include "../Game02/GameData02.h"

Game02::Game02() :Base(eType_Scene) {
	Base::Add(new Player02(CVector2D(640, 700)));
	//for (i = 0;i<0;i++) {
		if (m_cnt >= 180) {
			Base::Add(new Enemy02(CVector2D(500, 200)));
			Base::Add(new Enemy02(CVector2D(600, 150)));
			Base::Add(new Enemy02(CVector2D(700, 100)));
			Base::Add(new Enemy02(CVector2D(800, 50)));
			Base::Add(new Enemy02(CVector2D(900, 0)));
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