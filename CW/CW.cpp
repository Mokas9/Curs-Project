#include "stdafx.h"
#include "Structures.h"
#include "ErrorHandler.h"
#include "DataValidation.h"
#include "AccountOperation.h"
#include "ProductOperation.h"
#include "FileStream.h"
#include <string>
#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

vector<Product> products;
vector<User> users;

void ShowAdminMenu();
void ShowGuestMenu();
void ShowAccountControlMenu();
void ShowDataWorkingMenu();
void ShowEditModeMenu();
void ShowProcessingModeMenu();
void ShowDataSearchMenu();
void ShowSortMenu();




int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	products.reserve(100);
	users.reserve(100);
	User user;
	while (true) {
		system("cls");
		cout << "===============�����������===============" << endl;
		cout << "������� �����: ";
		cin >> user.login;
		cout << "������� ������: ";
		cin >> user.password;
		user.role = ValidateAccount(user.login, user.password, users);
		if (user.role == "admin" || user.role == "guest") {
			products = ReadProductFile(products);
			break;
		}
		system("pause");
	}

	if (user.role == "admin") {
		ShowAdminMenu();
	}
	else {
		ShowGuestMenu();
	}
	system("pause");
	return 0;
}

void ShowAdminMenu() {
	int choiseNumber;
	bool exit = true;
	while (exit) {
		system("cls");
		cout << "===============���� ��������������===============" << endl;
		cout << "1. ���������� �������� ��������." << endl;
		cout << "2. ������ � �������." << endl;
		cout << "3. ��������� ������." << endl;
		cin >> choiseNumber;

		switch (choiseNumber) {
		case 1:
			ShowAccountControlMenu();
			break;
		case 2:
			ShowDataWorkingMenu();
			break;
		case 3:
			exit = false;
			break;
		default:
			ShowMenuError();
			system("pause");
		}

	}

}
void ShowGuestMenu() {
	int choiseNumber;
	bool exit = true;
	while (exit) {
		system("cls");
		cout << "===============���� �����===============" << endl;
		cout << "1. �������� �������." << endl;
		cout << "2. ����� �������." << endl;
		cout << "3. ���������� �������." << endl;
		cout << "4. �������������� �������." << endl;
		cout << "5. ����� �� ����������." << endl;
		cin >> choiseNumber;

		switch (choiseNumber) {
		case 1:
			ShowAllProducts(products);
			break;
		case 2:
			ShowDataSearchMenu();
			break;
		case 3:
			ShowSortMenu();
			break;
		case 4:
			IndividualTask(products);
			break;
		case 5:
			exit = false;
			break;
		default:
			ShowMenuError();
			system("pause");
		}

	}
}

void ShowAccountControlMenu() {
	int choiseNumber;
	bool exit = true;
	while (exit) {
		system("cls");
		cout << "===============���� ���������� �������� ��������===============" << endl;
		cout << "1. �������� ���� ������� �������." << endl;
		cout << "2. ���������� ����� ������� ������." << endl;
		cout << "3. ������������� ������� �������." << endl;
		cout << "4. �������� ������� �������." << endl;
		cout << "5. �����." << endl;
		cin >> choiseNumber;

		switch (choiseNumber) {
		case 1:
			ShowAllAccount(users);
			break;
		case 2:
			AddAccount(users);
			break;
		case 3:
			EditAccount(users);
			break;
		case 4:
			DeleteAccount(users);
			break;
		case 5:
			exit = false;
			break;
		default:
			ShowMenuError();
			system("pause");
		}
	}
}


void ShowDataWorkingMenu() {
	int choiseNumber;
	bool exit = true;
	while (exit) {
		system("cls");
		cout << "===============���� ������ � �������===============" << endl;
		cout << "1. �������������� �������." << endl;
		cout << "2. ��������� �������." << endl;
		cout << "3. �����." << endl;
		cin >> choiseNumber;

		switch (choiseNumber) {
		case 1:
			ShowEditModeMenu();
			break;
		case 2:
			ShowProcessingModeMenu();
			break;
		case 3:
			exit = false;
			break;
		default:
			ShowMenuError();
			system("pause");
		}
	}
}

void ShowEditModeMenu() {
	int choiseNumber;
	bool exit = true;
	while (exit) {
		system("cls");
		cout << "===============���� �������������� ������===============" << endl;
		cout << "1. �������� �������." << endl;
		cout << "2. ���������� ������ ������." << endl;
		cout << "3. �������� ������." << endl;
		cout << "4. �������������� ������." << endl;
		cout << "5. �����." << endl;
		cin >> choiseNumber;

		switch (choiseNumber) {
		case 1:
			system("cls");
			ShowAllProducts(products);
			break;
		case 2:
			AddProduct(products);
			break;
		case 3:
			DeleteProduct(products);
			break;
		case 4:
			EditProduct(products);
			break;
		case 5:
			exit = false;
			break;
		default:
			ShowMenuError();
			system("pause");
		}
	}
}

void ShowProcessingModeMenu() {
	int choiseNumber;
	bool exit = true;
	while (exit) {
		system("cls");
		cout << "===============���� ��������� ������===============" << endl;
		cout << "1. ����� �������." << endl;
		cout << "2. ���������� �������." << endl;
		cout << "3. �������������� �������." << endl;
		cout << "4. �����." << endl;
		cin >> choiseNumber;

		switch (choiseNumber) {
		case 1:
			ShowDataSearchMenu();
			break;
		case 2:
			ShowSortMenu();
			break;
		case 3:
			IndividualTask(products);
			break;
		case 4:
			exit = false;
			break;
		default:
			ShowMenuError();
			system("pause");
		}
	}
}

void ShowDataSearchMenu() {
	int choiseNumber;
	bool exit = true;
	while (exit) {
		system("cls");
		cout << "===============���� ������ ������===============" << endl;
		cout << "1. �� ������������ ���������." << endl;
		cout << "2. �� ������ ����." << endl;
		cout << "3. �� ��� �������������� �� ����." << endl;
		cout << "4. �����." << endl;
		cin >> choiseNumber;

		switch (choiseNumber) {
		case 1:
			FindProductByRespPerson(products);
			break;
		case 2:
			FindProductByDepartment(products);
			break;
		case 3:
			FindProductByProductName(products);
			break;
		case 4:
			exit = false;
			break;
		default:
			ShowMenuError();
			system("pause");
		}
	}
}

void ShowSortMenu() {
	int choiseNumber;
	bool exit = true;
	while (exit) {
		system("cls");
		cout << "===============���� ���������� ������===============" << endl;
		cout << "1. �� ������������ ���������." << endl;
		cout << "2. �� ������ ����." << endl;
		cout << "3. �� ���������� ���������� ������." << endl;
		cout << "4. �����." << endl;
		cin >> choiseNumber;

		switch (choiseNumber) {
		case 1:
			SortProductByRespPerson(products);
			break;
		case 2:
			SortProductByDepartment(products);
			break;
		case 3:
			SortProductByCount(products);
			break;
		case 4:
			exit = false;
			break;
		default:
			ShowMenuError();
			system("pause");
		}
	}
}
