#include "Result.h"
#include"Title.h"
#include"../Game03/Game02.h"
#include"../Game03/Game03.h"
#include"../Game04/Game04.h"

Result::Result():Base(eType_Scene), m_result_text("C:\\Windows\\Fonts\\msgothic.ttc", 64) {
	m_img = COPY_RESOURCE("Sky", CImage);
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

void Result::Draw(){
	m_img.Draw();
	m_result_text.Draw(128, 256, 0, 0, 0, "Game01:time");
	m_result_text.Draw(128, 320, 0, 0, 0, "Game02:time");
	m_result_text.Draw(128, 384, 0, 0, 0, "Game03:time");
	m_result_text.Draw(128, 448, 0, 0, 0, "Game04:time");
	m_result_text.Draw(128, 576, 0, 0, 0, "Enter:Next Game  Space:Title");
}