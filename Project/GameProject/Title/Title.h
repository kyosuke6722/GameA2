#pragma once
#include"../Base/Base.h"

class Title :public Base {
private:
	CImage m_img1;
	CImage m_img2;//背景
	CImage m_title;//タイトル画像「あなぶきリミックス」
	CFont m_title_text;
	bool title_flag;
public:
	Title();
	~Title();
	void Update();
	void Draw();
};