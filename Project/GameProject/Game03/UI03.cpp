#include "UI03.h"
#include"GameData03.h"
#include"Game03.h"

UI03::UI03():Base(eType_UI), m_text("C:\\Windows\\Fonts\\msgothic.ttc", 32) {
	m_img = COPY_RESOURCE("UI", CImage);
}

void UI03::Draw() {
	int time = GameData03::t_time/60;
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
			m_img.SetPos(100 - 24 * i, 0);
		else
			m_img.SetPos(100 - 24 * (i+1), 0);
		m_img.Draw();
	}

	//チュートリアル用操作説明
	Game03* g = dynamic_cast<Game03*>(Base::FindObject(eType_Scene));
	if (g) {
		if (g->m_is_tuto) {
			m_text.Draw(0, 720-(32*5), 255, 255, 255, "A:左移動");
			m_text.Draw(0, 720-(32*4), 255, 255, 255, "D:右移動");
			m_text.Draw(0, 720-(32*3), 255, 255, 255, "W:ジャンプ");
			m_text.Draw(0, 720-(32*2), 255, 255, 255, "左クリック:攻撃");
		}
	}
}