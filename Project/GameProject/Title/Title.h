#pragma once
#include"../Base/Base.h"

class Title :public Base {
private:
	CImage m_img1;
	CImage m_img2;//�w�i
	CImage m_title;//�^�C�g���摜�u���ȂԂ����~�b�N�X�v
	CFont m_title_text;
	bool title_flag;
public:
	Title();
	~Title();
	void Update();
	void Draw();
};