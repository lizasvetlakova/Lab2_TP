#include "Check.h"

string SZ[12] = {
	"����","�����","��������",
	"���", "���", "����",
	"����", "��������", "�������",
	"�������", "�������", "����" };

void checkName(string& str){
	while (str.size() < 1) {
		cout << "\n�������� ����!\n���������� �����: ";
		getline(cin, str);
    }
}
void checkDate(int* D) {
	while (true) {
		cin >> D[0] >> D[1] >> D[2];
		if (cin.fail() || D[0] < 1 || D[0] > 31 || D[1] < 1 || D[1] > 12 || D[2] < 1920 || D[2] > 2021) {
			cin.clear();
			cout << "\n�������� ����!\n���������� �����: ";
		}
		else break;
		cin.ignore(32767, '\n');
	}
}

void checkSign(string& str) {

}