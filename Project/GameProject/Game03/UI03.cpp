#include "UI03.h"
#include"GameData03.h"

UI03::UI03():Base(eType_UI) {
	m_img = COPY_RESOURCE("UI03", CImage);
}

void UI03::Draw() {
	int time = GameData03::t_time/60;
	for (int i = 0; i < 4; i++,time/10) {
		int t = time % 10;
		m_img.SetRect(16*t,16,16*t+16,32);
		

	}
}