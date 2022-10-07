#include"Game04.h"
#include"Player04.h"
#include"Enemy04.h"
#include"GameData04.h"
#include"UI04.h"
#include"../Title/Result.h"
#include"Map04.h"
Game04::Game04():Base(eType_Scene) {
	Base::Add(new Enemy04(CVector2D(32 * 3, 32 * 8)));
	//Base::Add(new Enemy04(CVector2D(32 * 17, 32 * 14)));
	//Base::Add(new Enemy04(CVector2D(3 * 37, 32 * 10)));
	Base::Add(new Player04(CVector2D(32 * 3, 32 * 4)));
	Base::Add(new Map04());


}

Game04::~Game04()
{
	Base::KillAll();
	Result::finish_game = 4;
	Base::Add(new Result());
}


	


void Game04::Update()
{if (!Base::FindObject(eType_Enemy)) {
		SetKill();
	}
	else {
		GameData04::t_time++;
	}
}
