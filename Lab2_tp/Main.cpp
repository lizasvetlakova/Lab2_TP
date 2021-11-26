#include <Windows.h>
#include "Sign.h"
#include "List.h"

int main(void) {
	SetConsoleCP(1251); SetConsoleOutputCP(1251);
	/*
	int D[3] = { 11, 9, 1998 };
	string N = "Иван Иванов";
	string I = "Лев";
	Sign S(N, I, D);
	Sign S1(S);
	Sign S2(S);
	D[0] = 21; D[1] = 10; D[2] = 2003; 
	//обязательно проверка данных, введённых пользователем
	S1.set_date(D);
	S1.change();
	S2.change();

	List list;
	try {
		list.insert(S2, 0);
		list.insert(S, 1);
		list.insert(S1, 1);
	}
	catch (const char* exc) {
		cout << exc << endl;
	}
	cout << list[0] << list[1] << list[2] << endl;
	list.sort();
	cout << list[0] << list[1] << list[2] << endl; //оператор вствки << в поток и извлечени [] элемента из списка
	list.remove(1);
	cout << list[0] << list[1] <<  endl;
	*/
	
	return 0;
}