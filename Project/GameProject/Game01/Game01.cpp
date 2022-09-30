#include "Game01.h"
#include "Ball01.h"
#include"Player01.h"
#include"Enemy01.h"
#include"UI01.h"
Game01::Game01()
	:Base(eType_Scene)
{

	Base::Add(new Ball01(CVector2D(600, 300)));
	Base::Add(new Player01(CVector2D(0, 300)));
	Base::Add(new Enemy01(CVector2D(1280 - 32,300)));
	Base::Add(new UI01());

}
Game01::~Game01()
{
}

void Game01::Update()
{
}
