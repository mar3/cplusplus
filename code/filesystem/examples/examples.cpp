// examples.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"


bool touch(const _TCHAR* path)
{
	FILE* file = NULL;
	_tfopen_s(&file, path, _T("w+"));
	if (file == NULL) return false;
	fprintf(file, "hello!\n");
	fclose(file);
	return true;
}

int main()
{
    return 0;
}
