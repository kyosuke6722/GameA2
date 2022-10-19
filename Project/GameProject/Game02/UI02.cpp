#include "UI02.h"
#include "GameData02.h"

UI02::UI02() :Base(eType_UI) {
	//m_img.Load("Image/UI.png");
	m_img = COPY_RESOURCE("UI", CImage);
}

void UI02::Draw() {
	int score = GameData02::s_score;
	for (int i = 0; i < 8; i++, score /= 10) {
		int s = score % 10;
		m_img.SetRect(16 * s, 16, 16 * s + 16, 32);
		m_img.SetSize(16, 16);
		m_img.SetPos(200 - 16 * i, 0);
		m_img.Draw();
	}

	int time = GameData02::t_time / 60;
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
		m_img.SetRect(16 * t, 16, 16 * t + 16, 32);
		m_img.SetSize(24, 24);
		if (i < 2)
			m_img.SetPos(100 + 32 - 24 * i, 32);
		else
			m_img.SetPos(100 + 32 - 24 * (i + 1), 32);
		m_img.Draw();
	}
}