#include "Game01.h"
#include "Ball01.h"


Game01::Game01()
	:Base(eType_Scene)
{
	Base::Add(new Ball01(CVector2D(600, 300)));

}
Game01::~Game01()
{
}

void Game01::Update()
{
}
