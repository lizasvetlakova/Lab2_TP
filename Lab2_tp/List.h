#ifndef LIST_H
#define LIST_H
#include "Sign.h"

struct Element
{
	Sign* value;//������� ������ - ��������� �� ������ Sign 
	Element* next;
};

class List {
	Element* head;
	int size;
public:
	List();
	~List();

	int get_size();
	void clear();
	void sort();
	void insert(Sign& val, int index); //����������
	void remove(int index); //��������

	Sign& operator[] (int index);
};
#endif 