#include "Menu.h"

void Add(List& list) {
	system("cls");
	Sign* S = new Sign;
	cout << endl << "���������� ������� SIGN �� ����� �������\n";
	cout << "\n������� ����� ������� (�� 1 �� " << list.get_size() + 1 << "): ";
	int i = checkIndex(1, list.get_size() + 1) - 1;
	S->dataInput();
	try {
		list.insert(*S, i);
    }
	catch (const char* exc) {
		cout << exc << endl;
		return;
	}
	cout << endl << "������ ������� ��������!" << endl;
}

void Delete(List& list) {
	system("cls");
	int i;
	try {
		if (list.get_size() == 0) throw "������ ����!\n";
		Print(list);
		cout << "������� ����� �������, ������� ����� ������� (�� 1 �� " << list.get_size() << "): ";
		int i = checkIndex(1, list.get_size()) - 1;
		list.remove(i);
		cout << endl << "������ ������� �����!" << endl;
	}
	catch (const char* exc) {
		cout << exc << endl;
	}
}

void Change(List& list) {
	system("cls");
	int i;
	try {
		if (list.get_size() == 0) throw "������ ����!\n";
		Print(list);
		cout << "������� ����� �������, ������� ����� �������� (�� 1 �� " << list.get_size() << "): ";
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
		cout << "������ ����!" << endl;
	}
	else {
		list.sort();
		cout << endl << "������ ����������� �� ����� ���� ��������:" << endl << endl;
		Print(list);
	}
}

void Print(List& list) {
	if (list.get_size() == 0) {
		cout << "������ ����!" << endl;
	}
	else {
		cout << "_____________������_____________" << endl;
		for (int i = 0; i < list.get_size(); i++) {
			cout << "#" << i + 1 << list[i];
		}
	}
}

void PrintSign(List& list) {
	system("cls");
	if (list.get_size() == 0) {
		cout << "������ ����!" << endl;
	}
	else {
		string sign;
		bool flag = 0;
		cout << endl << "������� ���� �������: ";
		checkSign(sign);
		for (int i = 0; i < list.get_size(); i++) {
			if (list[i].get_sign() == sign) {
				cout << "#" << i + 1 << list[i];
				flag = 1;
			}
		}
		if (!flag) cout << endl << "�� ���������� �������� � �������� ������ �������" << endl;
	}
}