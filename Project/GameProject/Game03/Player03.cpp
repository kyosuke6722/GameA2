#include "Player03.h"
#include"AnimData03.h"
#include"Slash03.h"
#include"Effect03.h"
#include"Field03.h"

Player03::Player03(const CVector2D& pos, bool flip):Base(eType_Player){
	m_img = COPY_RESOURCE("Player03", CImage);//画像複製
	m_img.ChangeAnimation(0);//再生アニメーション設定
	m_pos = pos;//座標設定
	m_img.SetCenter(128, 224);//中心位置設定
	m_rect = CRect(-32, -128, 32, 0);//当たり判定用矩形
	m_flip = flip;//反転フラグ
	m_state = eState_Idle;//初期状態
	m_attack_no = rand();//攻撃番号
	m_damage_no = -1;//ダメージ番号
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
	}
	//落下状態へ移行
	if (m_is_ground && m_vec.y > GRAVITY * 4) {
		m_is_ground = false;
	}
	//重力による落下
	m_vec.y += GRAVITY;
	m_pos += m_vec;

	m_img.UpdateAnimation();//アニメーション更新
	m_scroll.x = m_pos.x - 1280 / 2;//スクロール設定
}

void Player03::Draw(){
	m_img.SetPos(GetScreenPos(m_pos));//位置設定
	m_img.SetFlipH(m_flip);//反転設定
	m_img.Draw();//描画
	DrawRect();
}

void Player03::Collision(Base* b){
	switch (b->m_type) {
	case eType_Goal:
		if (Base::CollisionRect(this, b)) {
			b->SetKill();
		}
		break;
	case eType_Enemy_Attack:
		if (Slash03* s = dynamic_cast<Slash03*>(b)) {
			if (m_damage_no != s->GetAttackNo() && Base::CollisionRect(this, s)) {
				m_damage_no = s->GetAttackNo();//同じ攻撃の連続ダメージ防止
				Base::Add(new Effect03("Effect_Blood", m_pos + CVector2D(0, -128), m_flip));
			}
		}
		break;
	case eType_Field:
		if (Field03* f = dynamic_cast<Field03*>(b)) {
			//地面より下に行ったとき
			if (m_pos.y > f->GetGroundY())
				m_pos.y = f->GetGroundY();//地面の高さに戻す
			    m_vec.y = 0;//落下速度リセット
				m_is_ground = true;//接地フラグON
		}
		break;
	}
}

void Player03::StateIdle(){
	const float move_speed = 6;//移動量
	const float jump_pow = 12;//ジャンプ力
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

	//ジャンプ
	if (m_is_ground && PUSH(CInput::eButton2)) {
		m_vec.y=-jump_pow;
		m_is_ground = false;
	}

	//攻撃
	if (PUSH(CInput::eButton1)) {
		m_state = eState_Attack;//攻撃状態へ移行
		m_attack_no++;
	}

	//ジャンプ中なら
	if (!m_is_ground) {
		if (m_vec.y < 0) {
			m_img.ChangeAnimation(eAnimJumpUp, false);//	上昇アニメーション
		}
		else {
			m_img.ChangeAnimation(eAnimJumpDown, false);//下降アニメーション
		}
	}
	//移動中なら
	else {
		if (move_flag) {
			m_img.ChangeAnimation(eAnimRun);//走るアニメーション
		}
		else {
			m_img.ChangeAnimation(eAnimIdle);//待機アニメーション
		}
	}
}

void Player03::StateAttack() {
	m_img.ChangeAnimation(eAnimAttack01, false);//攻撃アニメーションへ変更
	//3番目のパターンなら
	if (m_img.GetIndex() == 3) {
		if (m_flip) {
			Base::Add(new Slash03(m_pos + CVector2D(-64, -64), m_flip, eType_Player_Attack, m_attack_no));
		}
		else {
			Base::Add(new Slash03(m_pos + CVector2D(64, -64), m_flip, eType_Player_Attack, m_attack_no));
		}
	}

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