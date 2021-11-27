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

void Sign::change() {
	string s, str;
	int c;
	bool f = 1;
	cout << "\n�������� ��� ����� ��������:\n"
		<< "1. ��� � �������\n2. ���� ������� � ���� ��������\n"
		<< "3. ����� ������ �� �����\n4. ��������� � ����\n";
	while (f) {
		cout << endl << ">> ";
		cin >> s;
		try {
			c = atoi(s.c_str());
			if (c < 1 || c > 4) {
				throw "\n������ ��� ������!\n���������� �����:";
			}
			switch (c) {
			case 1:
				cout << endl << "������� ��� � �������: ";
				cin.ignore();  cin.clear(); getline(cin, fullname);
				checkName(fullname);
				break;
			case 2:
				cout << endl << "������� ���� ��������, � ���� ������� ���������� �������������.";
				cout << endl << endl << "������� ���� ��������(���� ����� ��� ����� ������): ";				
				cin >> date[0] >> date[1] >> date[2];
				changeDateSign(date, sign);
				cout << endl << "���� ������� ������� - " << sign;
				break;
			case 3:
				cout << *this;
				break;
			case 4:
				f = 0;
				break;
			}
		}
		catch (const char* exc) {
			cout << exc << endl;
		}
	}
}
//true - ����� ���� ������ ��� ������, false - ����� ������
bool Sign::operator> (const Sign& S) { 
	if (date[2] > S.date[2]) return true;
	if (date[2] == S.date[2] && date[1] > S.date[1]) return true;
	if (date[1] == S.date[1] && date[0] > S.date[0]) return true;
	return false;
}


ostream& operator<< (ostream& stream, const Sign& S) {
	stream << "\n  ��� � �������: " << S.fullname;
	stream << "\n  ���� �������: " << S.sign;
	stream << "\n  ���� ��������: " << S.date[0] << "." << S.date[1] << "." << S.date[2] << endl << endl;
	return stream;
}

istream& operator>>(istream& in, Sign& s) {
	cout << endl << "������� ��� � �������: ";
	getline(in, s.fullname);
	checkName(s.fullname);
	cout << endl << "������� ���� �������: ";
	in >> s.sign;
	checkSign(s.sign);
	cout << endl << "������� ���� ��������(���� ����� ��� ����� ������): ";
	in >> s.date[0] >> s.date[1] >> s.date[2];
	checkDate(s.date, s.sign);
	return in;
}