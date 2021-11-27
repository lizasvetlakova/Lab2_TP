#include "Sign.h"

Sign::Sign() {
	fullname = sign = "None";
	date[0] = date[1] = date[2] = 0;
	cout << "Сработал конструктор объекта SIGN" << endl;
}

Sign::Sign(string& n, string& sg, int d[3])
	: fullname(n), sign(sg), date{ d[0], d[1], d[2] } {
	cout << "Сработал конструктор с параметрами объекта SIGN" << endl;
}

Sign::Sign(const Sign& S) {
	fullname = S.fullname;
	sign = S.sign;
	date[0] = S.date[0];
	date[1] = S.date[1];
	date[2] = S.date[2];
	cout << "Сработал конструктор копирования объекта SIGN" << endl;
}

Sign::~Sign() {
	cout << "Сработал деструктор объекта SIGN" << endl;
}

void Sign::set_fullname(string& n) {
	fullname = n;
}
void Sign::set_sign(string& sg) {
	sign = sg;
}
void Sign::set_date(int d[3]) {
	date[0] = d[0];
	date[1] = d[1];
	date[2] = d[2];
}

string Sign::get_fullname() {
	return fullname;
}
string Sign::get_sign() {
	return sign;
}
int* Sign::get_date() {
	return date;
}

void Sign::change() {
	string s, str;
	int c;
	bool f = 1;
	cout << "\nВыберите что нужно изменить:\n"
		<< "1. Имя и фамилия\n2. Знак зодиака\n3. Дата рождения\n"
		<< "4. Вывод данных на экран\n5. Вернуться в меню\n";
	while (f) {
		cout << endl << ">> ";
		cin >> s;
		try {
			c = atoi(s.c_str());
			if (c < 1 || c > 5) {
				throw "\nОшибка при выборе!\nПопробуйте снова:";
			}
			switch (c) {
			case 1:
				cout << endl << "Введите имя и фамилию: ";
				cin.ignore();  cin.clear(); getline(cin, fullname);
				checkName(fullname);
				break;
			case 2:
				cout << endl << "Введите знак зодиака: ";
				cin >> sign;
				checkSign(sign);
				break;
			case 3:
				cout << endl << "Введите дату рождения(день месяц год через пробел): ";
				cin >> date[0] >> date[1] >> date[2];
				checkDate(date);
				break;
			case 4:
				cout << *this;
				break;
			case 5:
				f = 0;
				break;
			}
		}
		catch (const char* exc) {
			cout << exc << endl;
		}
	}
}
//true - левая дата больше чем правая, false - левая меньше
bool Sign::operator> (const Sign& S) { 
	if (date[2] > S.date[2]) return true;
	if (date[2] == S.date[2] && date[1] > S.date[1]) return true;
	if (date[1] == S.date[1] && date[0] > S.date[0]) return true;
	return false;
}


ostream& operator<< (ostream& stream, const Sign& S) {
	stream << "\n  Имя и фамилия: " << S.fullname;
	stream << "\n  Знак зодиака: " << S.sign;
	stream << "\n  Дата рождения: " << S.date[0] << "." << S.date[1] << "." << S.date[2] << endl << endl;
	return stream;
}

istream& operator>>(istream& in, Sign& s) {
	cout << endl << "Введите имя и фамилию: ";
	getline(in, s.fullname);
	checkName(s.fullname);
	cout << endl << "Введите знак зодиака: ";
	in >> s.sign;
	checkSign(s.sign);
	cout << endl << "Введите дату рождения(день месяц год через пробел): ";
	in >> s.date[0] >> s.date[1] >> s.date[2];
	checkDate(s.date);
	return in;
}