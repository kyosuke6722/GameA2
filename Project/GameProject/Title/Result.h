#pragma once
#include"../Base/Base.h"

class Result:public Base {
private:
	CImage m_img;
	CFont m_result_text;
public:
	Result();
	~Result();
	void Update();
	void Draw();
	static int finish_game;
};
