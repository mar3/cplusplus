//GLib �� GList ��^�������X�g�̎���

//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>

#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "container.h"



const char* __safe(const char* s) {

	return s == NULL ? "" : s;
}

char* __strdup(const char* s) {

	s = __safe(s);
	char* ss = malloc(strlen(s) + 1);
	strcpy(ss, s);
	return ss;
}

x_list* a_list_end(x_list* list) {

	x_list* p = list;
	while (p != NULL && p->next != NULL) {
		p = p->next;
	}
	return p;
}

//
// ���S�� free()
//
void _free(void* p) {

	if (p == NULL)
		return;

	free(p);
}

//
// 1�̎��ȎQ�ƃG���g���[��������A���̗v�f�̃A�h���X��Ԃ��܂��B
//
void* _clear_entry(x_list* e) {

	x_list* save = e;

	if (e == NULL)
		return NULL;

	save = e->next;

	_free(e->id);
	_free(e->data);
	_free(e);

	return save;
}

//
// ���X�g�S�̂�������܂��B
//
void a_list_clear(x_list* e) {

	while (e != NULL)
		e = _clear_entry(e);
}

x_list* a_append_list(x_list* list, const char* id, const char* data) {

	x_list* new_entry = NULL;
	x_list* tail = NULL;



	new_entry = malloc(sizeof(x_list));
	new_entry->id = __strdup(id);
	new_entry->data = __strdup(data);
	new_entry->next = NULL;

	if (list == NULL) {
		//�ŏ��̗v�f
		return new_entry;
	}

	tail = a_list_end(list);
	if (tail == NULL) {
		return NULL;
	}
	tail->next = new_entry;
	return list;
}





