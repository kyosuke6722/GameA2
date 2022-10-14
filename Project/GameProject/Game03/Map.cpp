#include "Map.h"
static int stage1data[MAP_HEIGHT][MAP_WIDTH] = {
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{ 1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{ 1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{ 1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{ 1,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{ 1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{ 1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{ 1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1},
	{ 1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{ 1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1},
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{ 1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};


Map::Map():Base(eType_Field) {
	m_img = COPY_RESOURCE("MapTip", CImage);
}

void Map::Draw(){
	//マップチップによる表示の繰り返し
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			//表示しない制御
			if (stage1data[i][j] == 0)continue;
			int t = stage1data[i][j];
			m_img.SetRect(32*t, 0, 32*t + 32, 32);//画像切り抜き
			m_img.SetSize(MAP_TIP_SIZE, MAP_TIP_SIZE);//表示サイズ設定
			m_img.SetPos(MAP_TIP_SIZE*j-m_scroll.x, MAP_TIP_SIZE*i-m_scroll.y);//表示位置設定
			m_img.Draw();//描画
		}
	}
}

int Map::GetTip(const CVector2D& pos){
	int col = pos.x / MAP_TIP_SIZE;//列を計算
	//列の制限(0〜MAP_WIDTH-1)
	if (col < 0)col = 0;
	if (col > MAP_WIDTH - 1)col = MAP_WIDTH - 1;

	int raw = pos.y / MAP_TIP_SIZE;//行を計算
	//行の制限(0〜MAP_HEIGHT-1)
	if (raw < 0)raw = 0;
	if (raw > MAP_HEIGHT - 1)raw = MAP_HEIGHT - 1;

	return GetTip(col,raw);//チップデータを返却
}

int Map::GetTip(int col, int raw){
	return stage1data[raw][col];
}

int Map::CollisionMap(const CVector2D& pos){
	//1点のみ検証
	int t = GetTip(pos);
	if (t != 0)
		return t;
	return 0;
}

int Map::CollisionMap(const CVector2D& pos, const CRect& rect){
	//左上
	int t = GetTip(CVector2D(pos.x + rect.m_left, pos.y + rect.m_top));
	if (t != 0)return t;
	//右上
	t = GetTip(CVector2D(pos.x + rect.m_right, pos.y + rect.m_top));
	if (t != 0)return t;
	//左下
	t = GetTip(CVector2D(pos.x + rect.m_left, pos.y +rect.m_bottom));
	if (t != 0)return t;
	//右下
	t = GetTip(CVector2D(pos.x + rect.m_right, pos.y + rect.m_bottom));
	if (t != 0)return t;
	return 0;
}
