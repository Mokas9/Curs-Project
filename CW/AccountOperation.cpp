#include "stdafx.h"
#include "AccountOperation.h"


User EnterUser(vector<User> &users, string validKey) {
	User user;
	do
	{
		system("cls");
		cout << "(���������) ����� ������ ���� �� ������ 6 ������, �� ��������� �������." << endl;
		cout << "(���������) ������ ������ ���� �� ������ 10 ������, �� ��������� �������." << endl;
		cout << "(���������) ��� ��������: admin/guest." << endl;
		cout << "������� ����� ������������: ";
		cin >> user.login;
		cout << "������� ������ ������������: ";
		cin >> user.password;
		cout << "������� ��� �������� (admin/guest)";
		cin >> user.role;
		system("cls");
	} while (!ValidateWriteNewUserData(validKey, user, users));
	return user;
}

void AddAccount(vector<User> &users) {
	User user;
	user = EnterUser(users, "e");
	if (isConfirmAction("����������"))
	{
		users.push_back(user);
		AddAccountToFile(user);
		ShowAddSuccess();
	}
}

void ShowAllAccount(vector <User> &users) {
	system("cls");
	cout << " =========������������=========" << endl;
	cout << "|" << setw(3) << left << "�" << "|" << setw(7) << "�����" << "|" << setw(11) << "������" << "|" << setw(6) << "����" << "|" << endl;
	for (int i = 0; i < users.size(); i++) {
		cout << " ==============================" << endl;
		cout << "|" << setw(3) << left << i + 1 << "|" << setw(7) << left << users[i].login << "|"
			<< setw(11) << users[i].password << "|"
			<< setw(6) << users[i].role << "|" << endl;
	}
	system("pause");
}

void DeleteAccount(vector <User> &users) {
	int index;
	while (true)
	{
		system("cls");
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		ShowAllAccount(users);
		cout << "������� ����� ������������ �������� �� ������ �������: ";
		cin >> index;
		index--;
		if (!cin.fail())
		{
			if (users.size() > index)
			{
				if (!isConfirmAction("��������")) break;
				users.erase(users.begin() + index);
				ReplaceAccountFile(users);
				ShowDeleteSuccess();
				break;
			}
			ShowDeleteAccountError("������ ������������ �� ����������...");
		}
		else {
			system("cls");
			ShowDeleteAccountError("������� �����...");
		}
	}
}

void EditAccount(vector <User> &users) {
	int index;
	User user;
	while (true) {
		system("cls");
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		ShowAllAccount(users);
		cout << "������� ����� ������������ �������� �� ������ ��������: ";
		cin >> index;
		index--;
		if (!cin.fail()) {
			if (users.size() > index) {
				user = users[index];
				users[index] = EnterUser(users, "");
				if (!isConfirmAction("���������")) {
					users[index] = user;
					break;
				}
				ReplaceAccountFile(users);
				ShowEditSuccess();
				break;
			}
			ShowDeleteAccountError("������ ������������ �� ����������...");
		}
		else {
			system("cls");
			ShowDeleteAccountError("������� �����...");
		}
	}
}
