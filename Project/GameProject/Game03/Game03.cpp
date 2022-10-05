#include "Game03.h"
#include"Player03.h"
#include"Enemy03.h"
#include"Field03.h"
#include"Goal03.h"
#include"GameData03.h"

Game03::Game03():Base(eType_Scene){
	Base::Add(new Field03());
	Base::Add(new Player03(CVector2D(0, 540), false));
	Base::Add(new Enemy03(CVector2D(1280 + 256 * 1, 540), true));
	//Base::Add(new Enemy03(CVector2D(1280 + 256 * 2, 540), true));
	//Base::Add(new Enemy03(CVector2D(1280 + 256 * 3, 540), true));
	Base::Add(new Goal03(CVector2D(2048, 540)));
}

Game03::~Game03(){
}

void Game03::Update(){
	if (!Base::FindObject(eType_Goal)) {
		SetKill();
	}
	else {
		GameData03::t_time++;
	}
}
