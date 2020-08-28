#include <Windows.h>
#include <crtdbg.h>
#include <tchar.h>
#include "string.h"
#include "myprocess.h"
#include "..\common\mutex.h"

// �A�v���P�[�V�����{��
class application
{
public:
	void run();
};

void application::run()
{
	{
		mymutex lock;
		_tprintf(_T("### �J�n ###\n"));
	}

	process process1(_T("app1.exe"));
	process process2(_T("app1.exe"));
	process process3(_T("app1.exe"));
	process process4(_T("app1.exe"));
	process process5(_T("app1.exe"));

	process1.join();
	process2.join();
	process3.join();
	process4.join();
	process5.join();

	{
		mymutex lock;
		_tprintf(_T("--- �I�� ---\n"));
	}
}

// �G���g���[�|�C���g
int _tmain(int argc, _TCHAR* argv[])
{
	UNREFERENCED_PARAMETER(argc);
	UNREFERENCED_PARAMETER(argv);

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	_tsetlocale(LC_ALL, _T("Japanese"));

	application app;
	app.run();

	return 0;
}