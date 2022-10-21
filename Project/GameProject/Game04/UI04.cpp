#include "UI04.h"
#include "GameData04.h"
#include "Game04.h"

UI04::UI04() :Base(eType_UI), m_text("C:\\Windows\\Fonts\\msgothic.ttc", 32) { 
	m_img = COPY_RESOURCE("UI", CImage); 



}

void UI04::Draw()
{

	int time = GameData04::t_time / 60;
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
			m_img.SetPos(100 + 32 - 24 * (i + 1),32);
		m_img.Draw();
	}
	//チュートリアル用操作説明
	Game04* g = dynamic_cast<Game04*>(Base::FindObject(eType_Scene));
	if (g) {
		if (g->m_is_tuto) {
			m_text.Draw(0, 720 - (32 * 4), 255, 255, 255, "W:上移動");
			m_text.Draw(0, 720 - (32 * 3), 255, 255, 255, "A:左移動");
			m_text.Draw(0, 720 - (32 * 2), 255, 255, 255, "S:下移動");
			m_text.Draw(0, 720 - (32 * 1), 255, 255, 255, "D:右移動");
			m_text.Draw(0, 720 - (32 * 0), 255, 255, 255, "左クリック:発射");
		}
	}
}