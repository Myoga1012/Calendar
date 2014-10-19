#include "CalSystem.h"
#include <stdio.h>

CalSystem::CalSystem() {
	GetDateTime( &now );			// ���݂̓������擾���܂��B
	first = Zeller( now );			// ����1���̗j�������߂܂��B
	last = DaysInMonth( now );		// �������������߂܂��B

	// YYYY�NMM���ƃ^�C�g���o�[�ɕ\�����܂��B
	char ds[256];
	sprintf_s( ds, "LED �h�b�g�}�g���b�N�X�J�����_�[ - %4d�N%02d��", now.Year, now.Mon );
	SetMainWindowText( ds );
}

// ���C���̏����ł��B
void CalSystem::CalMain() {

	unsigned int counter = 0;		// �J�E���^�[�i 0�`6 �j

	while( ProcessMessage() == 0 ) {
		SetIOPort( counter );		// ���o�̓|�[�g�̐ݒ�
		dmtx.Lighting();			// LED�̓_���E����

		// LED�̓_���E������ԑJ�ڂ��m�F���鎞�́A�ȉ��̃R�����g�A�E�g���������܂��B
		//WaitTimer( 500 );

		// �J�E���g�A�b�v���܂��B�i 6�̎���0�Ƀ��Z�b�g���܂��B �j
		counter++; if( counter == DotMatrix::ROWNUM ) counter = 0;
	}
}

void CalSystem::SetIOPort( unsigned int counter ) {

	counter %= DotMatrix::ROWNUM;

	// ���̓|�[�g����
	for( int i = 0; i < DotMatrix::COLNUM; i++ ) {
		int seqInWeek = counter * DotMatrix::COLNUM + i + 1;
		dmtx.InputPort( i ) = ( seqInWeek > first && seqInWeek <= first + last );
	}
	// �o�̓|�[�g���̓J�E���^�[�Ɠ����ԍ���ON�ɁA����ȊO��OFF�ɂ��܂��B
	for( int i = 0; i < DotMatrix::ROWNUM; i++ ) {
		dmtx.OutputPort( i ) = ( i == counter );
	}
}