#pragma once
#include <time.h>
#include "DxLib.h"
#include "DotMatrix.h"

class CalSystem {
private:
	
	DATEDATA now;	// ���݂̓���
	int first;		// ����1���̗j��
	int last;		// ������

	// LED�h�b�g�}�g���b�N�X�̃G�~�����[�^�[
	DotMatrix dmtx;

	// ���o�̓|�[�g�̎w��
	void SetIOPort( unsigned int );

public:

	// �R���X�g���N�^�[
	CalSystem();
	// ���C��
	void CalMain();

	// Zeller�̌�����dd��1���ڂ̗j�������߂܂��B
	static int Zeller( DATEDATA& dd ) {
		return ( dd.Year + dd.Year / 4 - dd.Year / 100 + dd.Year / 400 + ( 13 * dd.Mon + 8 ) / 5 + 1 ) % 7;
	}
	// dd�̌����������߂܂��B
	static int DaysInMonth( DATEDATA& dd ) {
		if( dd.Mon == 2 )
			return dd.Year % 4 == 0 ? 29 : 28;
		else
			return ( dd.Mon <= 7 && dd.Mon % 2 == 1 || dd.Mon >= 8 && dd.Mon % 2 == 0 ) ? 31 : 30;
	}
};

