#include "Menu.h"

int main(void) {
	SetConsoleCP(1251); SetConsoleOutputCP(1251);
	char c;
	bool flag = 1;
	List list;

	while (flag) {
		system("cls");
		cout << "\t\t����\n1. ��������\n2. �������\n3. �������� ������\n4. ����������� �� ����� ���� ��������\n"
			<< "5. ������� �� �����\n6. ������� �� ����� �������\n7. �����\n";
		cout << "\n�������� �������� >> ";
		c = _getch();
		switch (c) {
		case '1':
			Add(list);
			break;
		case '2':
			Delete(list);
			break;
		case '3':
			Change(list);
			break;
		case '4':
			Sort(list);
			break;
		case '5':
			system("cls");
			Print(list);
			break;
		case '6':
			PrintSign(list);
			break;
		case '7':
			flag = 0;
			break;
		default:
			cout << "\n������ ��� ������! ���������� �����.\n";
			break;
		}
		cout << endl;
		system("pause");
	}

	return 0;
}