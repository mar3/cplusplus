#pragma once

#include <Windows.h>

// �N���e�B�J���Z�N�V�����̐������Ԃ�ۏ؂��܂��B
class critical_section_lifetime
{
public:
	// �R���X�g���N�^�[
	critical_section_lifetime();
	// �f�X�g���N�^�[
	~critical_section_lifetime();
private:
};

// �N���e�B�J���Z�N�V�����̊Ǘ���񋟂���ȈՓI�ȃN���X�ł��B
class critical_section
{
	friend critical_section_lifetime;
public:
	// �R���X�g���N�^�[
	critical_section();
	// �f�X�g���N�^�[
	~critical_section();
private:
	// �N���e�B�J���Z�N�V�����̏�����
	// �v���Z�X�J�n���Ɉ�x�������s����K�v������܂��B
	static void init();
	// �N���e�B�J���Z�N�V�����̔j��
	// �v���Z�X�I�����Ɉ�x�������s����K�v������܂��B
	static void free();
	// �N���e�B�J���Z�N�V�����̖{��
	static CRITICAL_SECTION _section;
};
