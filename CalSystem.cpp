#include "CalSystem.h"
#include <stdio.h>

CalSystem::CalSystem() {
	GetDateTime( &now );			// 現在の日時を取得します。
	first = Zeller( now );			// 当月1日の曜日を求めます。
	last = DaysInMonth( now );		// 当月末日を求めます。

	// YYYY年MM月とタイトルバーに表示します。
	char ds[256];
	sprintf_s( ds, "LED ドットマトリックスカレンダー - %4d年%02d月", now.Year, now.Mon );
	SetMainWindowText( ds );
}

// メインの処理です。
void CalSystem::CalMain() {

	unsigned int counter = 0;		// カウンター（ 0～6 ）

	while( ProcessMessage() == 0 ) {
		SetIOPort( counter );		// 入出力ポートの設定
		dmtx.Lighting();			// LEDの点灯・消灯

		// LEDの点灯・消灯状態遷移を確認する時は、以下のコメントアウトを解除します。
		//WaitTimer( 500 );

		// カウントアップします。（ 6の時は0にリセットします。 ）
		counter++; if( counter == DotMatrix::ROWNUM ) counter = 0;
	}
}

void CalSystem::SetIOPort( unsigned int counter ) {

	counter %= DotMatrix::ROWNUM;

	// 入力ポート側は
	for( int i = 0; i < DotMatrix::COLNUM; i++ ) {
		int seqInWeek = counter * DotMatrix::COLNUM + i + 1;
		dmtx.InputPort( i ) = ( seqInWeek > first && seqInWeek <= first + last );
	}
	// 出力ポート側はカウンターと同じ番号をONに、それ以外はOFFにします。
	for( int i = 0; i < DotMatrix::ROWNUM; i++ ) {
		dmtx.OutputPort( i ) = ( i == counter );
	}
}