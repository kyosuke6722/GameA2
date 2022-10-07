#include "Result.h"
#include"Title.h"
#include"../Game01/GameData01.h"
#include"../Game03/Game02.h"
#include"../Game02/GameData02.h"
#include"../Game03/Game03.h"
#include"../Game03/GameData03.h"
#include"../Game04/Game04.h"
#include"../Game04/GameData04.h"

Result::Result():Base(eType_Scene), m_result_text("C:\\Windows\\Fonts\\msgothic.ttc", 64) {
	m_img = COPY_RESOURCE("Sky", CImage);
	m_time = COPY_RESOURCE("UI", CImage);
	m_time.SetSize(48, 48);
}
int Result::finish_game = 0;

Result::~Result(){
	if (finish_game == 1) {
		Base::Add(new Game02());
	}
	else if(finish_game==2){
		Base::Add(new Game03());
	}
	else if (finish_game == 3) {
		Base::Add(new Game04());
	}
	else{
		//GameData01::t_time = 0;
		//GameData02::t_time = 0;
		GameData03::t_time = 0;
		//GameData04::t_time = 0;
		Base::Add(new Title());
	}
}

void Result::Update(){
	//enterを押すと次のゲームへ
	if (PUSH(CInput::eButton10)) {
		SetKill();
	}
	//spaceを押すとタイトルへ
	if (PUSH(CInput::eButton5)) {
		finish_game = 5;
		SetKill();
	}
}

void Result::Draw() {
	m_img.Draw();
	for (int i = 3; i <= 6; i++) {
		m_result_text.Draw(128, 64 * i, 0, 0, 0, "Game0%d:", i - 2);
	}
	m_result_text.Draw(128, 64 * 8, 0, 0, 0, "Total:");

	for (int j = 1; j <= 6; j++) {
		int time = 0;
		int t = 0;
		if      (j == 1)time = GameData01::t_time / 60;
		else if (j == 2)time = GameData02::t_time / 60;
		else if (j == 3)time = GameData03::t_time / 60;
		else if (j == 4)time = 0;//GameData04::t_time / 60;
		else            time = GameData01::t_time / 60 + GameData02::t_time / 60 +
			                   GameData03::t_time / 60;//+GameData04::t_time/60;
		if (j != 5) {
			for (int i = 0; i < 4; i++) {
				if (i < 1) {
					t = time % 10;
					time /= 10;
				}
				else if (i < 2) {
					t = time % 6;
				}
				else if (i < 3) {
					t = time / 6;
					time /= 6;
				}
				else {
					t = time / 10;
				}
				m_time.SetRect(16 * t, 16, 16 * t + 16, 32);
				if (i < 2)
					m_time.SetPos((100 - 48 * i) + 64 * 7, 80 + 64 * j);
				else
					m_time.SetPos((100 - 48 * (i + 1)) + 64 * 7, 80 + 64 * j);
				m_time.Draw();
			}
		}
	}

	m_result_text.Draw(128, 64 * 10, 0, 0, 0, "Enter:Next Game  Space:Title");
}