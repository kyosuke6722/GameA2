#include "Game03.h"
#include"Player03.h"
#include"Enemy03.h"
#include"Field03.h"
#include"Map.h"
#include"Goal03.h"
#include"GameData03.h"
#include"UI03.h"
#include"../Title/Result.h"

Game03::Game03():Base(eType_Scene){
	//Base::Add(new Field03());
	Base::Add(new Map());
	Base::Add(new Player03(CVector2D(200, 540), false));
	Base::Add(new Enemy03(CVector2D(1280 + 256 * 1, 540), true));
	//Base::Add(new Enemy03(CVector2D(1280 + 256 * 2, 540), true));
	//Base::Add(new Enemy03(CVector2D(1280 + 256 * 3, 540), true));
	Base::Add(new Goal03(CVector2D(2048, 540-54)));
	Base::Add(new UI03());
}

Game03::~Game03(){
	Base::KillAll();
	Result::finish_game = 3;
	Base::Add(new Result());
}

void Game03::Update(){
	if (!Base::FindObject(eType_Goal)) {
		SetKill();
	}
	else {
		GameData03::t_time++;
	}
}
