#include "Result.h"
#include"Title.h"
#include"../Game01/GameData01.h"
#include"../Game03/Game02.h"
#include"../Game02/GameData02.h"
#include"../Game03/Game03.h"
#include"../Game03/GameData03.h"
#include"../Game04/Game04.h"
#include"../Game04/GameData04.h"

Result::Result(bool tuto):Base(eType_Scene), m_result_text("C:\\Windows\\Fonts\\msgothic.ttc", 64) {
	m_img = COPY_RESOURCE("Result", CImage);
	m_time = COPY_RESOURCE("UI", CImage);
	m_time.SetSize(48, 48);
	total_time = 0;
	anatora = COPY_RESOURCE("Anatora", CImage);
	m_is_tuto = tuto;
	if (finish_game == 4&&!m_is_tuto)//4��ڐ��e�����Ƃ�
		SOUND("SE_AllClear")->Play();
	else
		SOUND("SE_Clear")->Play();
}
int Result::finish_game = 0;

Result::~Result(){
	//�Q�[���I��
	if(m_is_tuto||finish_game==4) {
		if (Title::best_time < total_time*60) {
			Title::best_time = total_time*60;//�x�X�g�^�C���X�V
		}
	GameData01::t_time = 0;
	GameData02::t_time = 0;
	GameData03::t_time = 0;
	GameData04::t_time = 0;
 	Base::Add(new Title());
	}
	//���̃Q�[����
	else if (finish_game == 1) {
		Base::Add(new Game02(false));
	}
	else if(finish_game==2){
		Base::Add(new Game03(false));
	}
	else if (finish_game == 3) {
		Base::Add(new Game04(false));
	}
}

void Result::Update(){
	//enter�������Ǝ��̃Q�[����
	if (PUSH(CInput::eButton10)) {
		SetKill();
	}
	//space�������ƃ^�C�g����
	if (PUSH(CInput::eButton2)) {
		finish_game = 4;
		SetKill();
	}
}

void Result::Draw() {
	m_img.SetSize(1280, 720);
	m_img.Draw();
	anatora.SetPos(0, 630);
	anatora.Draw();
	for (int i = 3; i <= 6; i++) {
		m_result_text.Draw(128, 64 * i-30, 0, 0, 0, "Game0%d:", i - 2);
	}

	for (int j = 1; j <= 4; j++) {
		int time = 0;
		int t = 0;
		if      (j == 1)time = GameData01::t_time / 60;
		else if (j == 2)time = GameData02::t_time / 60;
		else if (j == 3)time = GameData03::t_time / 60;
		else if (j == 4)time = GameData04::t_time / 60;
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
					m_time.SetPos((100 - 48 * i) + 64 * 7, 80 + 64 * j-30);
				else
					m_time.SetPos((100 - 48 * (i + 1)) + 64 * 7, 80 + 64 * j-30);
				m_time.Draw();
			}
	}

	if (!m_is_tuto) {
		total_time = GameData01::t_time/60 + GameData02::t_time/60 + GameData03::t_time/60 + GameData04::t_time/60;
		int time = total_time;
		int t = 0;
		for (int i = 0; i < 4; i++) {
			if (i < 1) {
				t = total_time % 10;
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
				m_time.SetPos((100 - 48 * i) + 64 * 7, 80 + 64 * 6 - 30);
			else
				m_time.SetPos((100 - 48 * (i + 1)) + 64 * 7, 80 + 64 * 6 - 30);
			m_time.Draw();
		}
		m_result_text.Draw(128 + 30, 64 * 8 - 30, 0, 0, 0, "Total:");
	}
	m_result_text.Draw(128, 64 * 10-30, 0, 0, 0, "Enter:Next Game  X:Title");
}