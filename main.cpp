// ���O : Myoga S. Tomonaka
// Twitter : https://twitter.com/Myoga1012

#include "DxLib.h"
#include "CalSystem.h"

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow ) {

	SetMainWindowText( "LED �h�b�g�}�g���b�N�X�J�����_�[" );					// �E�C���h�E�^�C�g���̕ύX
    ChangeWindowMode( TRUE );							// �E�B���h�E���[�h
	SetGraphMode( 600, 540, 16 );						// �E�B���h�E�T�C�Y�̕ύX
	SetOutApplicationLogValidFlag( false );				// ���O���o�͂��Ȃ�

	// DX���C�u�����̏�����
	if( DxLib_Init() == -1 ) {
		MessageBox(
			GetMainWindowHandle(),
			"DX���C�u�����̏������Ɏ��s���܂����B\n�A�v���P�[�V�������I�����܂��B",
			"�G���[���������܂���",
			MB_OK + MB_ICONEXCLAMATION
			);
		return -1;
	}

	// ��ʂ̕`�������A�o�b�t�@�[�ɐݒ肵�܂��B
	SetDrawScreen( DX_SCREEN_BACK );

	// ��������J�n
	CalSystem cals;
	cals.CalMain();

	// DX���C�u�����I������
	DxLib_End();

	return 0;
}

// Copyright (c) 2014 Myoga S. Tomonaka All Rights Reserved.
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php