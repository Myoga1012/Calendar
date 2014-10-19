#include "DotMatrix.h"

DotMatrix::DotMatrix() {
	LEDBOARD = LoadGraph( "LED.png" );		// �{�[�h�̉摜��ǂݍ��݂܂��B
	DrawGraph( 0, 0, LEDBOARD, true );		// �{�[�h����ʏ�ɕ\�����܂��B
	// ���o�̓|�[�g�̃s����S��OFF�ɂ��܂��B
	for( int i = 0; i < COLNUM; i++ ) {
		in[i] = false;
	}
	for( int i = 0; i < ROWNUM; i++ ) {
		out[i] = false;
	}
}

// �w�肵�����̓|�[�g�ԍ��̃s����ON / OFF���擾 or �ݒ肵�܂��B
bool& DotMatrix::InputPort( int ip_num ) {
	if( ip_num < 0 )
		return in[0];
	else if( ip_num >= COLNUM )
		return in[COLNUM - 1];
	else
		return in[ip_num];
}

// �w�肵���o�̓|�[�g�ԍ��̃s����ON / OFF���擾 or �ݒ肵�܂��B
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
			// ���̓s���Əo�̓s�����Ƃ���ON�̎��A�Ώۂ�LED��_�������܂��B
			if( in[j] && out[i] ) {
				SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 0 );
				DrawCircle(
					j * ( LEDSIZE + INTERVAL ) + COLOFF,
					i * ( LEDSIZE + INTERVAL ) + ROWOFF,
					LEDSIZE / 2,
					// ���j�͐Ԍn�A�y�j�͐n�A����ȊO�͔��ł��B
					j == 0 ? 0xFF00CC : ( j == COLNUM - 1 ? 0x00CCFF : 0xF8F0FF ),
					true
					);
			}
			// �����łȂ����͑Ώۂ�LED�����������܂��B
			else {
				SetDrawBlendMode( DX_BLENDMODE_ALPHA, 48 );	// �c�����ʂ̃V�~�����[�g�ł��B
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