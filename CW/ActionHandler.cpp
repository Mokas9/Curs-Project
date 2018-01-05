#include "stdafx.h"
#include "ActionHandler.h"

void ShowDeleteSuccess() {
	cout << "������ ������� �������." << endl;
	system("pause");
}
void ShowEditSuccess() {
	cout << "������ ������� ��������." << endl;
	system("pause");
}
void ShowAddSuccess() {
	cout << "������ ������� ���������." << endl;
	system("pause");
}
bool isConfirmAction(string action) {
	int confirmNumber;
	do
	{
		system("cls");
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "����������� " << action.c_str() << " ������(1 - �� / 0 - ���): ";
		cin >> confirmNumber;
		if (cin.fail() || confirmNumber < 0 || confirmNumber > 1) {
			cout << "�� ������ ����..." << endl;
			system("pause");
			continue;
		}
		break;

	} while (true);
	if (confirmNumber == 1)
		return true;
	system("cls");
	cout << "�� �������� " << action.c_str() << " ������." << endl;
	system("pause");
	return false;
}