#pragma once
#include <time.h>
#include "DxLib.h"
#include "DotMatrix.h"

class CalSystem {
private:
	
	DATEDATA now;	// 現在の日時
	int first;		// 当月1日の曜日
	int last;		// 当月末

	// LEDドットマトリックスのエミュレーター
	DotMatrix dmtx;

	// 入出力ポートの指定
	void SetIOPort( unsigned int );

public:

	// コンストラクター
	CalSystem();
	// メイン
	void CalMain();

	// Zellerの公式でddの1日目の曜日を求めます。
	static int Zeller( DATEDATA& dd ) {
		return ( dd.Year + dd.Year / 4 - dd.Year / 100 + dd.Year / 400 + ( 13 * dd.Mon + 8 ) / 5 + 1 ) % 7;
	}
	// ddの月末日を求めます。
	static int DaysInMonth( DATEDATA& dd ) {
		if( dd.Mon == 2 )
			return dd.Year % 4 == 0 ? 29 : 28;
		else
			return ( dd.Mon <= 7 && dd.Mon % 2 == 1 || dd.Mon >= 8 && dd.Mon % 2 == 0 ) ? 31 : 30;
	}
};

