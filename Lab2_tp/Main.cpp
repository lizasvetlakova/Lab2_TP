#include <Windows.h>
#include "Sign.h"

int main(void) {
	SetConsoleCP(1251); SetConsoleOutputCP(1251);
	int D[3] = { 11, 9, 2001 };
	string N = "Иван Иванов";
	string I = "Лев";
	Sign S(N, I, D);
	Sign S1(S);
	D[0] = 21; D[1] = 10; D[2] = 2003; 
	//обязательно проверка данных, введённых пользователем
	S1.set_date(D);
	S.edit();
	if (S > S1) {
		cout << S1;
		cout << S;
	}
	return 0;
}