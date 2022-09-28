#include "Game03.h"
#include"Player03.h"
#include"Enemy03.h"

Game03::Game03():Base(eType_Scene){
	Base::Add(new Player03(CVector2D(0, 540), false));
	Base::Add(new Enemy03(CVector2D(1280 + 256 * 1, 540), true));
	//Base::Add(new Enemy03(CVector2D(1280 + 256 * 2, 540), true));
	//Base::Add(new Enemy03(CVector2D(1280 + 256 * 3, 540), true));
}

Game03::~Game03(){
}

void Game03::Update(){
}
