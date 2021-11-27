#include "Check.h"

string SZ[12] = {
	"����","�����","��������",
	"���", "���", "����",
	"����", "��������", "�������",
	"�������", "�������", "����" };

void checkName(string& str){
	while (str.size() < 1) {
		cin.clear();
		cout << "\n�������� ����!\n���������� �����: ";
		getline(cin, str);
    }
}
void checkDate(int* D) {
	while (true) {
		if (cin.fail() || D[0] < 1 || D[0] > 31 || D[1] < 1 || D[1] > 12 || D[2] < 1920 || D[2] > 2021) {
			cin.clear();
			cout << "\n�������� ����!\n���������� �����: ";
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
			if (str == SZ[i]) {
				flag = 1;
				break;
			}
		}
		if (cin.fail() || !flag) {
			cin.clear();
			cout << "\n�������� ����! �������� ���� ������� � ������� ����� �� ������� �����.\n���������� �����: ";
			cin >> str;
		}
		else break;
	}
}

int checkIndex(int minInd, int maxInd) {
	while (true) {
		int Ind;
		cin >> Ind;
		if (cin.fail() || Ind < minInd || Ind > maxInd) {
			cin.clear();
			cout << "\n������: ������������ �����!\n������� �����: ";
		}
		else {
			cin.ignore(32767, '\n');
			cin.clear();
			return Ind;
		}
		cin.ignore(32767, '\n');
	}
	
}