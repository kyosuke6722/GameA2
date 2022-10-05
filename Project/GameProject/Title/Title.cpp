#include "Title.h"
#include"../Game01/Game01.h"
#include"../Game03/Game02.h"
#include"../Game03/Game03.h"
#include"../Game04/Game04.h"

Title::Title():Base(eType_Scene),m_title_text("C:\\Windows\\Fonts\\msgothic.ttc",64) {
	m_img = COPY_RESOURCE("Title", CImage);
}

Title::~Title(){
}

void Title::Update(){
	if (PUSH(CInput::eUp)) {
		SetKill();
		Base::KillAll();
		Base::Add(new Game01());
	}
	if (PUSH(CInput::eRight)) {
		SetKill();
		Base::KillAll();
		Base::Add(new Game02());
	}
	if (PUSH(CInput::eDown)) {
		SetKill();
		Base::KillAll();
		Base::Add(new Game03());
	}
	if (PUSH(CInput::eLeft)) {
		SetKill();
		Base::KillAll();
		Base::Add(new Game04());
	}
}

void Title::Draw() {
	m_img.Draw();
	m_title_text.Draw(64, 256, 0, 0, 0, "W:Game01");
	m_title_text.Draw(64, 320, 0, 0, 0, "D:Game02");
	m_title_text.Draw(64, 384, 0, 0, 0, "S:Game03");
	m_title_text.Draw(64, 448, 0, 0, 0, "A:Game04");
}