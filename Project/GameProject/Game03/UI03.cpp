#include "UI03.h"
#include"GameData03.h"

UI03::UI03():Base(eType_UI) {
	m_img = COPY_RESOURCE("UI03", CImage);
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
		m_img.SetSize(16, 16);
		m_img.SetPos(200 - 16 * i, 0);
		m_img.Draw();
	}
}