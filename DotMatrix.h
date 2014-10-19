#pragma once
#include "DxLib.h"

// 7�i �j �j�~ 6�i �T �j����LED�h�b�g�}�g���b�N�X�̃G�~�����[�^�[�ł��B
class DotMatrix {
public:
	
	static const int COLNUM = 7;		// LED�h�b�g�}�g���b�N�X�̗񐔁i 7�i �j �j�j
	static const int ROWNUM = 6;		// LED�h�b�g�}�g���b�N�X�̍s���i 6�i �T �j�j

private:

	int LEDBOARD;						// LED�{�[�h�̉摜�n���h��
	static const int LEDSIZE = 40;		// LED�̃T�C�Y
	static const int COLOFF = 120;		// In-0, O-0��LED�̒��S���W
	static const int ROWOFF = 120;		// In-0, O-0��LED�̒��S���W
	static const int INTERVAL = 20;	// LED���m�̊Ԋu

	bool in[COLNUM],		// LED�h�b�g�}�g���b�N�X�̓��̓s���i �J�����_�[�̗�i 7�s�� �j �j
		out[ROWNUM];		// LED�h�b�g�}�g���b�N�X�̏o�̓s���i �J�����_�[�̍s�i 6�s�� �j �j

public:

	// �R���X�g���N�^�[
	DotMatrix();

	// ���́E�o�̓|�[�g�̔ԍ����w�肵�A�s����ON / OFF��؂�ւ��܂��B
	bool& InputPort( int );
	bool& OutputPort( int );

	// LED��_���E���������܂��B
	void Lighting();
};