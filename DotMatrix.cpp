#include "DotMatrix.h"

DotMatrix::DotMatrix() {
	LEDBOARD = LoadGraph( "LED.png" );		// ボードの画像を読み込みます。
	DrawGraph( 0, 0, LEDBOARD, true );		// ボードを画面上に表示します。
	// 入出力ポートのピンを全てOFFにします。
	for( int i = 0; i < COLNUM; i++ ) {
		in[i] = false;
	}
	for( int i = 0; i < ROWNUM; i++ ) {
		out[i] = false;
	}
}

// 指定した入力ポート番号のピンのON / OFFを取得 or 設定します。
bool& DotMatrix::InputPort( int ip_num ) {
	if( ip_num < 0 )
		return in[0];
	else if( ip_num >= COLNUM )
		return in[COLNUM - 1];
	else
		return in[ip_num];
}

// 指定した出力ポート番号のピンのON / OFFを取得 or 設定します。
bool& DotMatrix::OutputPort( int op_num ) {
	if( op_num < 0 )
		return in[0];
	else if( op_num >= ROWNUM )
		return out[ROWNUM - 1];
	else
		return out[op_num];
}

void DotMatrix::Lighting() {
	for( int i = 0; i < ROWNUM; i++ ) {
		for( int j = 0; j < COLNUM; j++ ) {
			// 入力ピンと出力ピンがともにONの時、対象のLEDを点灯させます。
			if( in[j] && out[i] ) {
				SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 0 );
				DrawCircle(
					j * ( LEDSIZE + INTERVAL ) + COLOFF,
					i * ( LEDSIZE + INTERVAL ) + ROWOFF,
					LEDSIZE / 2,
					// 日曜は赤系、土曜は青系、それ以外は白です。
					j == 0 ? 0xFF00CC : ( j == COLNUM - 1 ? 0x00CCFF : 0xF8F0FF ),
					true
					);
			}
			// そうでない時は対象のLEDを消灯させます。
			else {
				SetDrawBlendMode( DX_BLENDMODE_ALPHA, 48 );	// 残像効果のシミュレートです。
				DrawCircle(
					j * ( LEDSIZE + INTERVAL ) + COLOFF,
					i * ( LEDSIZE + INTERVAL ) + ROWOFF,
					LEDSIZE / 2, 0x67696C, true
					);
			}
		}
	}
	ScreenFlip();
}