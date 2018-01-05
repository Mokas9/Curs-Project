#include "stdafx.h"
#include "ActionHandler.h"

void ShowDeleteSuccess() {
	cout << "Запись успешно удалена." << endl;
	system("pause");
}
void ShowEditSuccess() {
	cout << "Запись успешно изменена." << endl;
	system("pause");
}
void ShowAddSuccess() {
	cout << "Запись успешно добавлена." << endl;
	system("pause");
}
bool isConfirmAction(string action) {
	int confirmNumber;
	do
	{
		system("cls");
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Подтвердите " << action.c_str() << " записи(1 - да / 0 - нет): ";
		cin >> confirmNumber;
		if (cin.fail() || confirmNumber < 0 || confirmNumber > 1) {
			cout << "Не верный ввод..." << endl;
			system("pause");
			continue;
		}
		break;

	} while (true);
	if (confirmNumber == 1)
		return true;
	system("cls");
	cout << "Вы отменили " << action.c_str() << " записи." << endl;
	system("pause");
	return false;
}