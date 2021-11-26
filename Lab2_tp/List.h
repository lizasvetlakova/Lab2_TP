#ifndef LIST_H
#define LIST_H
#include "Sign.h"

struct Element
{
	Sign* value;//элемент списка - указатель на объект Sign 
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
	void insert(Sign& val, int index); //добавление
	void remove(int index); //удаление

	Sign& operator[] (int index);
};
#endif 