#include "Slash03.h"

Slash03::Slash03(const CVector2D& pos, bool flip, int type, int attack_no):Base(type) {
	m_img = COPY_RESOURCE("Slash03", CImage);//画像複製
	m_flip = flip;//反転設定
	m_pos = pos;//座標設定
	m_img.SetSize(128,128);//表示サイズ設定
	m_img.SetCenter(64,64);//中心位置設定
	m_rect = CRect(-64, -64, 64, 64);//当たり判定用矩形
	m_img.ChangeAnimation(0, false);//再生アニメーション設定(非ループ)
	m_attack_no = attack_no;//攻撃番号
}

void Slash03::Update(){
	m_img.UpdateAnimation();//アニメーション更新
	//アニメーション終了チェック
	if (m_img.CheckAnimationEnd()) {
		SetKill();//エフェクト削除
	}
}

void Slash03::Draw(){
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetFlipH(m_flip);
	m_img.Draw();
}
