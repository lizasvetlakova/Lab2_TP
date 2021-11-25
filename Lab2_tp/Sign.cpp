#include "Sign.h"

Sign::Sign() {
	fullname = sign = "None";
	date[0] = date[1] = date[2] = 0;
	cout << "�������� ����������� ������� SIGN" << endl;
}

Sign::Sign(string& n, string& sg, int d[3])
	: fullname(n), sign(sg), date{ d[0], d[1], d[2] } {
	cout << "�������� ����������� � ����������� ������� SIGN" << endl;
}

Sign::Sign(const Sign& S) {
	fullname = S.fullname;
	sign = S.sign;
	date[0] = S.date[0];
	date[1] = S.date[1];
	date[2] = S.date[2];
	cout << "�������� ����������� ����������� ������� SIGN" << endl;
}

Sign::~Sign() {
	cout << "�������� ���������� ������� SIGN" << endl;
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

void Sign::edit() {
	string s, str;
	int c;
	bool f = 1;
	cout << "\n�������� ��� ����� ��������:\n"
		<< "1. ��� � �������\n2. ���� �������\n3. ���� ��������\n"
		<< "4. ����� ������ �� �����\n5. ��������� � ����\n";
	while (f) {
		cout << endl << ">> ";
		cin >> s;
		try {
			c = atoi(s.c_str());
			if (c < 1 || c > 5) {
				throw "\n������ ��� ������!\n���������� �����:";
			}
			switch (c) {
			case 1:
				cout << endl << "������� ��� � �������: ";
				cin.get(); getline(cin, fullname);
				checkName(fullname);
				break;
			case 2:
				cout << endl << "������� ���� �������: ";
				cin.get(); getline(cin, sign);
				checkSign(sign);
				break;
			case 3:
				cout << endl << "������� ���� ��������(���� ����� ��� ����� ������): ";
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
//true - ������ ������ ��� �����, false - ������ ������
bool Sign::operator> (const Sign& S) { 
	if (date[2] < S.date[2]) return true;
	if (date[2] == S.date[2]) {
		if (date[1] < S.date[1]) return true;
		if (date[1] == S.date[1]) {
			if(date[0] < S.date[0]) return true;
		}
	}
	return false;
}


ostream& operator<< (ostream& stream, const Sign& S) {
	stream << "��� � �������: " << S.fullname << endl;
	stream << "���� �������: " << S.sign << endl;
	stream << "���� ��������: " << S.date[0] << "." << S.date[1] << "." << S.date[2] << endl;
	return stream;
}

