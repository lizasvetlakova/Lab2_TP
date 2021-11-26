#include "Menu.h"

void Add(List& list) {
	system("cls");
	Sign* S = new Sign;
	cout << endl << "Добавление объекта SIGN на любую позицию\n";
	cout << "\nВведите номер позиции (от 1 до " << list.get_size() + 1 << "): ";
	int i = checkIndex(1, list.get_size() + 1) - 1;
	S->dataInput();
	try {
		list.insert(*S, i);
    }
	catch (const char* exc) {
		cout << exc << endl;
		return;
	}
	cout << endl << "Объект успешно добавлен!" << endl;
}

void Delete(List& list) {
	system("cls");
	int i;
	try {
		if (list.get_size() == 0) throw "Список пуст!\n";
		Print(list);
		cout << "Введите номер объекта, который нужно удалить (от 1 до " << list.get_size() << "): ";
		int i = checkIndex(1, list.get_size()) - 1;
		list.remove(i);
		cout << endl << "Объект успешно удалён!" << endl;
	}
	catch (const char* exc) {
		cout << exc << endl;
	}
}

void Change(List& list) {
	system("cls");
	int i;
	try {
		if (list.get_size() == 0) throw "Список пуст!\n";
		Print(list);
		cout << "Введите номер объекта, который нужно изменить (от 1 до " << list.get_size() << "): ";
		int i = checkIndex(1, list.get_size()) - 1;
		list[i].change();
	}
	catch (const char* exc) {
		cout << exc << endl;
	}
}

void Sort(List& list) {
	system("cls");
	if (list.get_size() == 0) {
		cout << "Список пуст!" << endl;
	}
	else {
		list.sort();
		cout << endl << "Записи упорядочены по датам дней рождений:" << endl << endl;
		Print(list);
	}
}

void Print(List& list) {
	if (list.get_size() == 0) {
		cout << "Список пуст!" << endl;
	}
	else {
		cout << "_____________Список_____________" << endl;
		for (int i = 0; i < list.get_size(); i++) {
			cout << "#" << i + 1 << list[i];
		}
	}
}

void PrintSign(List& list) {
	system("cls");
	if (list.get_size() == 0) {
		cout << "Список пуст!" << endl;
	}
	else {
		string sign;
		bool flag = 0;
		cout << endl << "Введите знак зодиака: ";
		checkSign(sign);
		for (int i = 0; i < list.get_size(); i++) {
			if (list[i].get_sign() == sign) {
				cout << "#" << i + 1 << list[i];
				flag = 1;
			}
		}
		if (!flag) cout << endl << "Не существует объектов с введённым знаком зодиака" << endl;
	}
}