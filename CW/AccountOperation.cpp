#include "stdafx.h"
#include "AccountOperation.h"


User EnterUser(vector<User> &users, string validKey) {
	User user;
	do
	{
		system("cls");
		cout << "(Подсказка) Логин должен быть не больше 6 знаков, не допустимы пробелы." << endl;
		cout << "(Подсказка) Пароль должен быть не больше 10 знаков, не допустимы пробелы." << endl;
		cout << "(Подсказка) Тип аккаунта: admin/guest." << endl;
		cout << "Введите логин пользователя: ";
		cin >> user.login;
		cout << "Введите пароль пользователя: ";
		cin >> user.password;
		cout << "Введите тип аккаунта (admin/guest)";
		cin >> user.role;
		system("cls");
	} while (!ValidateWriteNewUserData(validKey, user, users));
	return user;
}

void AddAccount(vector<User> &users) {
	User user;
	user = EnterUser(users, "e");
	if (isConfirmAction("добавление"))
	{
		users.push_back(user);
		AddAccountToFile(user);
		ShowAddSuccess();
	}
}

void ShowAllAccount(vector <User> &users) {
	system("cls");
	cout << " =========Пользователи=========" << endl;
	cout << "|" << setw(3) << left << "№" << "|" << setw(7) << "Логин" << "|" << setw(11) << "Пароль" << "|" << setw(6) << "Роль" << "|" << endl;
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
		cout << "Введите номер пользователя которого вы хотите удалить: ";
		cin >> index;
		index--;
		if (!cin.fail())
		{
			if (users.size() > index)
			{
				if (!isConfirmAction("удаление")) break;
				users.erase(users.begin() + index);
				ReplaceAccountFile(users);
				ShowDeleteSuccess();
				break;
			}
			ShowDeleteAccountError("Такого пользователя не существует...");
		}
		else {
			system("cls");
			ShowDeleteAccountError("Введите число...");
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
		cout << "Введите номер пользователя которого вы хотите изменить: ";
		cin >> index;
		index--;
		if (!cin.fail()) {
			if (users.size() > index) {
				user = users[index];
				users[index] = EnterUser(users, "");
				if (!isConfirmAction("изменение")) {
					users[index] = user;
					break;
				}
				ReplaceAccountFile(users);
				ShowEditSuccess();
				break;
			}
			ShowDeleteAccountError("Такого пользователя не существует...");
		}
		else {
			system("cls");
			ShowDeleteAccountError("Введите число...");
		}
	}
}
