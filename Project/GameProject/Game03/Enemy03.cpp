#include "Enemy03.h"
#include"Slash03.h"
#include"Effect03.h"
#include"AnimData03.h"
#include"Field03.h"
#include"Map.h"

Enemy03::Enemy03(const CVector2D& pos, bool flip) :Base(eType_Enemy) {
	m_img = COPY_RESOURCE("Enemy03", CImage);//画像複製
	m_img.ChangeAnimation(0);//再生アニメーション設定
	m_pos_old=m_pos = pos;//座標設定
	m_img.SetCenter(128, 224);//中心位置設定
	m_rect = CRect(-32,-128,32,0);//当たり判定用矩形
	m_flip = flip;//反転設定
	m_state = eState_Idle;
	m_cnt = rand() % 120 + 180;//待機時間3～5秒
	m_is_ground = true;
	m_attack_no = rand();
	m_damage_no = -1;
	m_hp = 100;
}

void Enemy03::Update(){
	m_pos_old = m_pos;
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
	case eState_Wait:
		StateWait();
	}
	if (m_is_ground && m_vec.y > GRAVITY * 4) {
		m_is_ground = false;
	}
	//重力による落下
	m_vec.y += GRAVITY;
	m_pos += m_vec;

	m_img.UpdateAnimation();//アニメーション更新
}

void Enemy03::Draw(){
	m_img.SetPos(GetScreenPos(m_pos));//座標設定
	m_img.SetFlipH(m_flip);//反転設定
	m_img.Draw();//描画
	//DrawRect();//当たり判定用矩形表示
}

void Enemy03::Collision(Base* b) {
	switch (b->m_type) {
	case eType_Player_Attack:
		if (Slash03* s = dynamic_cast<Slash03*>(b)) {
			if (m_damage_no != s->GetAttackNo() && Base::CollisionRect(this, s)) {
				m_damage_no = s->GetAttackNo();//同じ攻撃の連続ダメージ防止
				SOUND("SE_EnemyDamage03")->Play();
				m_hp -= 50;
				if (m_hp <= 0) {
					m_state = eState_Down;
				}
				else {
					m_state = eState_Damage;
				}
				Base::Add(new Effect03("Effect_Blood", m_pos + CVector2D(0, -128), m_flip));
			}
		}
		break;
	case eType_Field:
		/*
		if (Field03* f = dynamic_cast<Field03*>(b)) {
			//地面より下に行ったとき
			if (m_pos.y > f->GetGroundY()) {
				m_pos.y = f->GetGroundY();//地面の高さに戻す
				m_vec.y = 0;//落下速度リセット
				m_is_ground = true;//接地フラグON
			}
		}
		*/
		if (Map* m = dynamic_cast<Map*>(b)) {
			int t = m->CollisionMap(CVector2D(m_pos.x, m_pos_old.y));
			if (t != 0) {
				m_pos.x = m_pos_old.x;
			}
			t = m->CollisionMap(CVector2D(m_pos_old.x, m_pos.y));
			if (t != 0) {
				m_pos.y = m_pos_old.y;//元の高さに戻す
				m_vec.y = 0;//落下速度リセット
				m_is_ground = true;//接地フラグON
			}
		}
		break;
	}
}

void Enemy03::StateWait(){
	m_img.ChangeAnimation(eAnimIdle);
	if (--m_cnt <= 0) {
		m_cnt =rand()%120+180;//待機時間3～5秒
		m_state = eState_Idle;
	}
}

void Enemy03::StateIdle() {
	const float move_speed = 6;
	bool move_flag = false;
	const float jump_pow = 12;
	Base* player = Base::FindObject(eType_Player);

	if (player) {
		//左移動
		if (player->m_pos.x < m_pos.x - 64) {
			m_pos.x += -move_speed;
			m_flip = true;
			move_flag = true;
		}
		else
		//右移動
		if (player->m_pos.x > m_pos.x + 64) {
			m_pos.x += move_speed;
			m_flip = false;
			move_flag = true;
		}
		//攻撃
		else {
			m_state = eState_Attack;
			m_attack_no++;
		}
	}
	if (move_flag) {
		//走るアニメーション
		m_img.ChangeAnimation(eAnimRun);
	}
	else {
		//待機アニメーション
		m_img.ChangeAnimation(eAnimIdle);
	}
	
	if (--m_cnt <= 0) {
		m_cnt =rand()%120+180;//待機時間3～秒
		m_state = eState_Wait;
	}
	
}

void Enemy03::StateAttack() {
	m_img.ChangeAnimation(eAnimAttack01, false);//攻撃アニメーションへ変更
	if (m_img.GetIndex() == 3) {
		if (m_flip) {
			Base::Add(new Slash03(m_pos + CVector2D(-64, -64), m_flip, eType_Enemy_Attack, m_attack_no));
		}
		else {
			Base::Add(new Slash03(m_pos + CVector2D(64, -64), m_flip, eType_Enemy_Attack, m_attack_no));
		}
	}

	//アニメーションが終了したら
	if (m_img.CheckAnimationEnd()) {
		m_state = eState_Idle;//通常状態へ移行
	}
}

void Enemy03::StateDamage() {
	m_img.ChangeAnimation(eAnimDamage, false);

	if (m_img.CheckAnimationEnd()) {
		m_state = eState_Idle;
	}
}

void Enemy03::StateDown() {
	m_img.ChangeAnimation(eAnimDown, false);

	if (m_img.CheckAnimationEnd()) {
		Base::Add(new Effect03("Effect_Smoke", m_pos + CVector2D(0,0), m_flip));
		SetKill();
	}
}