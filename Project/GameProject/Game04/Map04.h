#pragma once
#include "../Base/Base.h"
//マップの横のチップ数
#define MAP_WIDTH    40
//マップの縦のチップ数
#define MAP_HEIGHT   22
//マップマップの大きさ
#define MAP_TIP_SIZE    32

class Map04 : public Base {
private:
	CImage m_img;
public:
	Map04();
	void Draw();
	//指定座標のチップ番号を取得
	int GetTip(const CVector2D& pos);
	//指定列、指定行のマップチップを取得
	int GetTip(int col, int raw);
	//マップとの当たり判定
	int CollisionMap(const CVector2D& pos);
	int CollisionMap(const CVector2D& pos, const CRect& rect);


};





