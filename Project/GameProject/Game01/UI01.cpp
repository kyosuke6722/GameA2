#include "UI01.h"
#include"GameData01.h"
#include "Game01.h"




UI01::UI01()
	:Base(eType_UI)
{
	m_score = COPY_RESOURCE("Number",CImage);
	m_img = COPY_RESOURCE("UI", CImage);

}



void UI01::Draw()
{
	int base_x[2] = { 640 - 48,640 + 48 };
	for (int j = 0; j < 2; j++) {
		int n = GameData01::point[j];


		for (int i = 0; i < 2; i++, n /= 10) {
			int p = n % 10;

			m_score.SetRect(48 * p, 48 * j, 48 * (p + 1), 48 * (j + 1));

			m_score.SetSize(48, 48);
			m_score.SetPos(base_x[j] - i * 48, 0);
			m_score.Draw();

		}

	}
	int time = GameData01::t_time / 60;
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
			m_img.SetPos(640+48 - 24 * i, 48);
		else
			m_img.SetPos(640+48 - 24 * (i + 1), 48);
		m_img.Draw();
	}
	//チュートリアル用操作説明
	Game01* g = dynamic_cast<Game01*>(Base::FindObject(eType_Scene));
	if (g) {
		if (g->m_is_tuto) {
			m_text.Draw(90, 720 - (32 * 2), 255, 255, 255, "W:上移動");
			m_text.Draw(90, 720 - (32 * 1), 255, 255, 255, "S:下移動");
			m_text.Draw(90, 720 - (32 * 0), 255, 255, 255, "Z:ゲームスタート");
		}
	}

}
