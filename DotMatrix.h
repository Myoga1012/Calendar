#pragma once
#include "DxLib.h"

// 7（ 曜 ）× 6（ 週 ）分のLEDドットマトリックスのエミュレーターです。
class DotMatrix {
public:
	
	static const int COLNUM = 7;		// LEDドットマトリックスの列数（ 7（ 曜 ））
	static const int ROWNUM = 6;		// LEDドットマトリックスの行数（ 6（ 週 ））

private:

	int LEDBOARD;						// LEDボードの画像ハンドル
	static const int LEDSIZE = 40;		// LEDのサイズ
	static const int COLOFF = 120;		// In-0, O-0のLEDの中心座標
	static const int ROWOFF = 120;		// In-0, O-0のLEDの中心座標
	static const int INTERVAL = 20;	// LED同士の間隔

	bool in[COLNUM],		// LEDドットマトリックスの入力ピン（ カレンダーの列（ 7ピン ） ）
		out[ROWNUM];		// LEDドットマトリックスの出力ピン（ カレンダーの行（ 6ピン ） ）

public:

	// コンストラクター
	DotMatrix();

	// 入力・出力ポートの番号を指定し、ピンのON / OFFを切り替えます。
	bool& InputPort( int );
	bool& OutputPort( int );

	// LEDを点灯・消灯させます。
	void Lighting();
};