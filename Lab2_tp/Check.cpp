#include "Check.h"

struct SignOfZodiac {
	string sign;
	int period[4];
};

struct SignOfZodiac SZ[12] = { 
	"Овен", {21, 3, 20, 4}, "Телец", {21, 4, 20, 5}, "Близнецы", {21, 5, 21, 6},
	"Рак", {22, 6, 22, 7}, "Лев", {23, 7, 23, 8}, "Дева", {24, 8, 23, 9},
	"Весы", {24, 9, 23, 10}, "Скорпион", {24, 10, 22, 11}, "Стрелец", {23, 11, 21, 12},
	"Козерог",  {22, 12, 20, 1}, "Водолей", {21, 1, 18, 2}, "Рыбы", {19, 2, 20, 3}
};

void checkName(string& str){
	while (str.size() < 1) {
		cin.clear();
		cout << "\nНеверный ввод!\nПопробуйте снова: ";
		getline(cin, str);
    }
}
void checkDate(int* D, string& str) {
	bool flag; int n = 0;
	for (int i = 0; i < 12; i++) {
		if (str == SZ[i].sign) {
			flag = 1; n = i;
			break;
		}
	}
	while (true) {
		if (cin.fail() || D[0] < 1 || D[0] > 31 || D[1] < 1 || D[1] > 12 || D[2] < 1920 || D[2] > 2021) {
			cin.clear();
			cout << "\nНеверный ввод!\nПопробуйте снова: ";
			cin >> D[0] >> D[1] >> D[2];
		}		
		else if ((D[0] < SZ[n].period[0] || D[1] != SZ[n].period[1]) && (D[0] > SZ[n].period[2] || D[1] != SZ[n].period[3])) {
			cin.clear();
			cout << "\nДата не совпадает с введённым ранее знаком зодиака!\nБудьте внимательны!"
				<< " Для знака зодиака - " << str << " соответсвуют даты " 
				<< SZ[n].period[0] << "." << SZ[n].period[1] << " - " << SZ[n].period[2] << "." << SZ[n].period[3] << "\nПопробуйте ввести дату рождения снова: ";
			cin >> D[0] >> D[1] >> D[2];
		}
	    else break;
		cin.ignore(32767, '\n');
	}
}

void checkSign(string& str) {
	bool flag = 0;
	while (true) {
		for (int i = 0; i < 12; i++) {
			if (str == SZ[i].sign) {
				flag = 1;
				break;
			}
		}
		if (cin.fail() || !flag) {
			cin.clear();
			cout << "\nНеверный ввод! Напишите знак зодиака с большой буквы на русском языке.\nПопробуйте снова: ";
			cin >> str;
		}
		else break;
	}
}

void changeDateSign(int* D, string& str) {
	while (true) {
		if (cin.fail() || D[0] < 1 || D[0] > 31 || D[1] < 1 || D[1] > 12 || D[2] < 1920 || D[2] > 2021) {
			cin.clear();
			cout << "\nНеверный ввод!\nПопробуйте снова: ";
			cin >> D[0] >> D[1] >> D[2];
		}
		else break;
		cin.ignore(32767, '\n');
	}
	for (int i = 0; i < 12; i++) {
		if (( D[0] >= SZ[i].period[0] && D[1] == SZ[i].period[1]) || ( D[0] <= SZ[i].period[2] && D[1] == SZ[i].period[3])) {
			str = SZ[i].sign;
			break;
		}
	}
}

int checkIndex(int minInd, int maxInd) {
	while (true) {
		int Ind;
		cin >> Ind;
		if (cin.fail() || Ind < minInd || Ind > maxInd) {
			cin.clear();
			cout << "\nОшибка: неккоректный номер!\nВведите снова: ";
		}
		else {
			cin.ignore(32767, '\n');
			cin.clear();
			return Ind;
		}
		cin.ignore(32767, '\n');
	}
	
}