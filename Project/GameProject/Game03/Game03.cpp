#include "Game03.h"
#include"Player03.h"
#include"Enemy03.h"
#include"Field03.h"
#include"Map.h"
#include"Goal03.h"
#include"GameData03.h"
#include"UI03.h"
#include"../Title/Result.h"

Game03::Game03(bool tuto):Base(eType_Scene){
	m_cnt = 0;
	m_enemy_flag =true;
	m_is_tuto = tuto;
	Base::Add(new Field03());
	Base::Add(new Map());
	Base::Add(new Player03(CVector2D(72* 11, 72 * 20),false));
	Base::Add(new Enemy03(CVector2D(72*25,72*20), true));
	Base::Add(new Enemy03(CVector2D(72 * 38, 72 * 20), true));
	Base::Add(new Enemy03(CVector2D(72 * 15, 72 * 10), true));
	Base::Add(new Goal03(CVector2D(72*4,72*8+20)));
	Base::Add(new UI03());
}

Game03::~Game03(){
	Base::KillAll();
	SOUND("BGM_Game03")->Pause();
	Result::finish_game = 3;
	Base::Add(new Result(m_is_tuto));
}

void Game03::Update(){
	Player03* p = dynamic_cast<Player03*>(Base::FindObject(eType_Player));
	if (p) {
		if (p->m_pos.x < 72 * 13 && p->m_pos.y < 72 * 12&&m_enemy_flag) {
			Base::Add(new Enemy03(CVector2D(72 * 5, 72 * 5), true));
			Base::Add(new Enemy03(CVector2D(72 * 7, 72 * 5), true));
			Base::Add(new Enemy03(CVector2D(72 * 17, 72 * 5), false));
			m_enemy_flag = false;
		}
	}
	if (m_cnt-- <= 0) {
		SOUND("BGM_Game03")->Play();
		m_cnt = 37 * 60;
	}
	
	if (!Base::FindObject(eType_Goal)) {
		SetKill();
	}
	else {
		GameData03::t_time++;
	}
}
