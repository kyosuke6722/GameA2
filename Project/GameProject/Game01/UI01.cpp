#include "UI01.h"
#include"GameData01.h"




UI01::UI01()
	:Base(eType_UI)
{
	m_score = COPY_RESOURCE("Number",CImage);
	m_time = COPY_RESOURCE("UI", CImage);
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

}
