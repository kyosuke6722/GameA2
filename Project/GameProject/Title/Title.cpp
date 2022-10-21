#include "Title.h"
#include"../Game01/Game01.h"
#include"../Game03/Game02.h"
#include"../Game03/Game03.h"
#include"../Game04/Game04.h"

Title::Title() :Base(eType_Scene), m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64) {
	m_img1 = COPY_RESOURCE("Title1", CImage);
	m_img2 = COPY_RESOURCE("Title2", CImage);
	m_time = COPY_RESOURCE("UI", CImage);
	m_time.SetSize(48, 48);
	m_title = COPY_RESOURCE("Title_text", CImage);
	m_title.SetSize(560 * 1.2, 86 * 1.2);
	title_flag = false;
	SOUND("BGM_Title")->Play();
}
int Title::best_time = 0;

Title::~Title(){
	SOUND("BGM_Menu")->Pause();
}

void Title::Update(){
	if (title_flag) {
		//本番
		if ( PUSH(CInput::eButton10)) {
			SOUND("SE_Button2")->Play();
			SetKill();
			Base::KillAll();
			Base::Add(new Game01(false));
		}
		//各種チュートリアル
		if (PUSH(CInput::eUp)) {
			SOUND("SE_Button2")->Play();
			SetKill();
			Base::KillAll();
			Base::Add(new Game01(true));
		}
		if (PUSH(CInput::eRight)) {
			SOUND("SE_Button2")->Play();
			SetKill();
			Base::KillAll();
			Base::Add(new Game02(true));
		}
		if (PUSH(CInput::eDown)) {
			SOUND("SE_Button2")->Play();
			SetKill();
			Base::KillAll();
			Base::Add(new Game03(true));
		}
		if (PUSH(CInput::eLeft)) {
			SOUND("SE_Button2")->Play();
			SetKill();
			Base::KillAll();
			Base::Add(new Game04(true));
		}
	}
	else {
		if (PUSH(CInput::eButton10)) {
			SOUND("BGM_Title")->Pause();
			SOUND("SE_Button1")->Play();
			title_flag = true;
			SOUND("BGM_Menu")->Play(true);
		}
	}
}

void Title::Draw() {
	if (title_flag) {
		m_img2.SetSize(1280, 720);
		m_img2.Draw();
		m_title_text.Draw(640 - 64 * 2, 70, 0, 0, 0, "W:Game01");
		m_title_text.Draw(1280 - 64 * 6, 64 * 4, 0, 0, 0, "D:Game02");
		m_title_text.Draw(640 - 64 * 2, 720 - 8, 0, 0, 0, "S:Game03");
		m_title_text.Draw(100, 64 * 8, 0, 0, 0, "A:Game04");
		m_title_text.Draw(640 - 192, 400, 0, 0, 0, "Enter:PlayAll");
	}
	else {
		m_img1.Draw();
		m_title.SetPos(640-320, 360-100);
		m_title.Draw();
		m_title_text.Draw(640 - 160, 400, 0, 0, 0, "PUSH:Enter");
	}

	m_title_text.Draw(1280-64*5, 650, 0, 0, 0, "BEST TIME");
	int time = best_time/60;
	int t = 0;
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
		m_time.SetRect(16 * t, 32, 16 * t + 16, 48);
		if (i < 2)
			m_time.SetPos(1200 - 48 * i, 650);
		else
			m_time.SetPos(1200 - 48 * (i + 1), 650);
		m_time.Draw();
	}
}