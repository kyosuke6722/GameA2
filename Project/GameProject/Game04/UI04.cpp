#include "UI04.h"
#include "GameData04.h"

UI04::UI04() :Base(eType_UI) {
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
			m_img.SetPos(100 - 24 * i, 0);
		else
			m_img.SetPos(100 - 24 * (i + 1), 0);
		m_img.Draw();
	}

}
