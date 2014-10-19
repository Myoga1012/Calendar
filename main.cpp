// 名前 : Myoga S. Tomonaka
// Twitter : https://twitter.com/Myoga1012

#include "DxLib.h"
#include "CalSystem.h"

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow ) {

	SetMainWindowText( "LED ドットマトリックスカレンダー" );					// ウインドウタイトルの変更
    ChangeWindowMode( TRUE );							// ウィンドウモード
	SetGraphMode( 600, 540, 16 );						// ウィンドウサイズの変更
	SetOutApplicationLogValidFlag( false );				// ログを出力しない

	// DXライブラリの初期化
	if( DxLib_Init() == -1 ) {
		MessageBox(
			GetMainWindowHandle(),
			"DXライブラリの初期化に失敗しました。\nアプリケーションを終了します。",
			"エラーが発生しました",
			MB_OK + MB_ICONEXCLAMATION
			);
		return -1;
	}

	// 画面の描画先をリアバッファーに設定します。
	SetDrawScreen( DX_SCREEN_BACK );

	// ここから開始
	CalSystem cals;
	cals.CalMain();

	// DXライブラリ終了処理
	DxLib_End();

	return 0;
}

// Copyright (c) 2014 Myoga S. Tomonaka All Rights Reserved.
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php