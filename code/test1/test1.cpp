// test1.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include <sstream>
#include <tchar.h>
#include "logger.h"

int main()
{
	setlocale(LC_ALL, "Japanese");
	_wsetlocale(LC_ALL, _T("Japanese"));

	logger(std::wstringstream() << _T("### START ###"));
	logger(std::wstringstream() << _T("�R�j�`�n�I"));
	logger(std::wstringstream() << _T("-- END ---"));
}
