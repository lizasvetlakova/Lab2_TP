#include "List.h"

List::List() {
	head = nullptr;
	size = 0;
}

List::~List() {
	clear();
}

void List::clear() {
	if (size == 0) { return; }
	while (head != NULL) {
		Element* buf = head;
		head = buf->next;
		buf->value->~Sign();
		delete buf;
	}
	size = 0;
}

int List::get_size() {
	return size;
}

void List::sort() {
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - i; j++) {
			if ((*this)[j] > (*this)[j + 1]) {
				swap((*this)[j], (*this)[j + 1]);
			}
		}
	}
}

void List::insert(Sign& val, int index) {
	if (index > size || index < 0) {
		throw "\nОшибка: неккоректный номер!";
	}
	if (size == 0){ //добавляем самый первый элемент
		head = new Element;
		head->value = &val;
		head->next = nullptr;
		size++;
		return;
	}
	if (index == size) { //добавляем в конец
		Element* buf = head;
		while (buf->next != nullptr) {
			buf = buf->next;
		}
		Element* tmp = new Element;
		buf->next = tmp;
		tmp->value = &val;
		tmp->next = nullptr;
		size++;
		return;
	}
	
	Element* curr = head;
	Element* prev = head;
	for (int i = 0; i < index; i++) {
		prev = curr;
		curr = curr->next;
	}
	Element* add = new Element; //добавляемый элемент
	add->value = &val;
	if (prev == curr) { //когда добавляем первый элемент(индекс = 0) 
		add->next = curr;
		head = add;
	}
	else {
		prev->next = add;
		add->next = curr;
	}
	size++;
}

void List::remove(int index) {
	if (index >= size || index < 0) {
		throw "\nОшибка: неккоректный индекс!";
	}
	if (size == 1) {
		this->clear();
		return;
	}
	Element* del = head; //удаляемый элемент
	Element* prev = head;

	for (int i = 0; i < index; i++) {
		prev = del;
		del = del->next;
	}
	if (del == prev) { //когда удаляем первый элемент(индекс = 0) 
		head = del->next;
	}
	else {
		prev->next = del->next; //предыдущий ссылается на следующий за удаляемым элементом
	}
	del->value->~Sign();
	delete del;
	size--;
}

Sign& List::operator[] (int index) {
	if (index >= size || index < 0) {
		throw "\nОшибка: неккоректный индекс!";
	}
	Element* buf = head;
	for (int i = 0; i < index; i++)
	{
		buf = buf->next;
	}
	return *(buf->value);
}