#include "UI02.h"
#include "GameData02.h"

UI::UI() :Base(eType_UI) {
	m_img.Load("Image/UI.png");
}

void UI::Draw() {
	int score = GameData::s_score;
	for (int i = 0; i < 8; i++, score /= 10) {
		int s = score % 10;
		m_img.SetRect(16 * s, 16, 16 * s + 16, 32);
		m_img.SetSize(16, 16);
		m_img.SetPos(200 - 16 * i, 0);
		m_img.Draw();
	}
}