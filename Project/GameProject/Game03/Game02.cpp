#include "Game02.h"
#include "../Game02/Player02.h"
#include "../Game02/Enemy02.h"
#include "../Game02/Bullet02.h"
#include "../Game02/Effect02.h"
#include "../Game02/UI02.h"
#include "../Game02/GameData02.h"

Game::Game() :Base(eType_Scene) {
	Base::Add(new Player(CVector2D(600, 600)));
	Base::Add(new Enemy(CVector2D(600, 200)));
	Base::Add(new Enemy(CVector2D(650, 150)));
	Base::Add(new Enemy(CVector2D(700, 100)));
	Base::Add(new Enemy(CVector2D(750, 50)));
	Base::Add(new Enemy(CVector2D(800, 0)));
}

void Game::Update() {

}