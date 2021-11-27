#include "Menu.h"

int main(void) {
	SetConsoleCP(1251); SetConsoleOutputCP(1251);
	char c;
	bool flag = 1;
	List list;

	while (flag) {
		system("cls");
		cout << "\t\tМеню\n1. Добавить\n2. Удалить\n3. Изменить данные\n4. Упорядочить по датам дней рождений\n"
			<< "5. Вывести на экран\n6. Вывести по знаку зодиака\n7. Выйти\n";
		cout << "\nВыберите действие >> ";
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
			cout << "\nОшибка при выборе! Попробуйте снова.\n";
			break;
		}
		cout << endl;
		system("pause");
	}

	return 0;
}