#include "Effect03.h"

Effect03::Effect03(const char* name, const CVector2D& pos, bool flip):Base(eType_Effect) {
	m_img = COPY_RESOURCE(name, CImage);//画像複製
	m_pos = pos;//座標設定
	m_img.SetSize(128,128);//表示サイズ設定
	m_img.SetCenter(64, 64);//中心位置設定
	m_img.ChangeAnimation(0, false);//再生アニメーション設定(非ループ)
	m_flip = flip;//反転設定
}

void Effect03::Update(){
	m_img.UpdateAnimation();
	if (m_img.CheckAnimationEnd()) {
		SetKill();
	}
}

void Effect03::Draw(){
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetFlipH(m_flip);
	m_img.Draw();
}
