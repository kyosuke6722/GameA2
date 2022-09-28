#include "Enemy03.h"
#include"AnimData03.h"

Enemy03::Enemy03(const CVector2D& pos, bool flip):Base(eType_Enemy) {
	m_img = COPY_RESOURCE("Enemy03", CImage);//画像複製
	m_img.ChangeAnimation(0);//再生アニメーション設定
	m_pos = pos;//座標設定
	m_img.SetCenter(128,224);//中心位置設定
	m_flip = flip;//反転設定
}

void Enemy03::Update(){
	const float move_speed = 6;
	bool move_flag = false;
	const float jump_pow = 12;
	Base* player = Base::FindObject(eType_Player);

	//左移動
	if (player->m_pos.x < m_pos.x - 64) {
		m_pos.x += -move_speed;
		m_flip = true;
		move_flag = true;
	}
	//右移動
	if (player->m_pos.x > m_pos.x + 64) {
		m_pos.x += move_speed;
		m_flip = false;
		move_flag = true;
	}

	if (move_flag) {
		//走るアニメーション
		m_img.ChangeAnimation(eAnimRun);
	}
	else {
		//待機アニメーション
		m_img.ChangeAnimation(eAnimIdle);
	}

	m_img.UpdateAnimation();//アニメーション更新
}

void Enemy03::Draw(){
	m_img.SetPos(m_pos);//座標設定
	m_img.SetFlipH(m_flip);//反転設定
	m_img.Draw();//描画
}

void Enemy03::Collision(){
}

void Enemy03::StateIdle() {
}

void Enemy03::StateAttack() {
	m_img.ChangeAnimation(eAnimAttack01, false);//攻撃アニメーションへ変更

	//アニメーションが終了したら
	if (m_img.CheckAnimationEnd()) {
		m_state = eState_Idle;//通常状態へ移行
	}
}

void Enemy03::StateDamage() {
}

void Enemy03::StateDown() {
}