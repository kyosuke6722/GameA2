#include "Player03.h"
#include"AnimData03.h"

Player03::Player03(const CVector2D& pos, bool flip):Base(eType_Player){
	m_img = COPY_RESOURCE("Player03", CImage);//画像複製
	m_img.ChangeAnimation(0);//再生アニメーション設定
	m_pos = pos;//座標設定
	m_img.SetCenter(128, 224);//中心位置設定
	m_flip = flip;//反転フラグ
	m_state = eState_Idle;//初期状態
}

void Player03::Update(){
	switch (m_state) {
		//通常状態
	case eState_Idle:
		StateIdle();
		break;
		//攻撃状態
	case eState_Attack:
		StateAttack();
		break;
		//ダメージ状態
	case eState_Damage:
		StateDamage();
		break;
		//ダウン状態
	case eState_Down:
		StateDown();
		break;
	}

	m_img.UpdateAnimation();//アニメーション更新
}

void Player03::Draw(){
	m_img.SetPos(m_pos);//位置設定
	m_img.SetFlipH(m_flip);//反転設定
	m_img.Draw();//描画
}

void Player03::Collision(Base* b){
}

void Player03::StateIdle(){
	const float move_speed = 6;//移動量
	bool move_flag = false;//移動フラグ

	//左移動
	if (HOLD(CInput::eLeft)) {
		m_pos.x += -move_speed;//移動量を設定
		m_flip = true;//反転フラグ
		move_flag = true;
	}
	//右移動
	if (HOLD(CInput::eRight)) {
		m_pos.x += move_speed;
		m_flip = false;
		move_flag = true;
	}

	//攻撃
	if (PUSH(CInput::eButton1)) {
		//攻撃状態へ移行
	}

	//移動中なら
	if (move_flag) {
		m_img.ChangeAnimation(eAnimRun);//走るアニメーション
	}
	else {
		m_img.ChangeAnimation(eAnimIdle);//待機アニメーション
	}

}

void Player03::StateAttack() {
	m_img.ChangeAnimation(eAnimAttack01, false);//攻撃アニメーションへ変更

	//アニメーションが終了したら
	if (m_img.CheckAnimationEnd()) {
		m_state = eState_Idle;//通常状態へ移行
	}
}

void Player03::StateDamage(){
	m_img.ChangeAnimation(eAnimDamage, false);

	if (m_img.CheckAnimationEnd()) {
		m_state = eState_Idle;
	}
}

void Player03::StateDown() {
	m_img.ChangeAnimation(eAnimDown, false);

	if (m_img.CheckAnimationEnd()) {
		m_kill = true;
	}
}

