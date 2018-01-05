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
		cout << "===============Авторизация===============" << endl;
		cout << "Введите логин: ";
		cin >> user.login;
		cout << "Введите пароль: ";
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
		cout << "===============Меню Администратора===============" << endl;
		cout << "1. Управление учетными записями." << endl;
		cout << "2. Работа с данными." << endl;
		cout << "3. Завершить работу." << endl;
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
		cout << "===============Меню Гостя===============" << endl;
		cout << "1. Просмотр товаров." << endl;
		cout << "2. Поиск товаров." << endl;
		cout << "3. Сортировка товаров." << endl;
		cout << "4. Индивидуальное задание." << endl;
		cout << "5. Выйти из приложения." << endl;
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
		cout << "===============Меню управления учетными записями===============" << endl;
		cout << "1. Просмотр всех учетных записей." << endl;
		cout << "2. Добавление новой учетной записи." << endl;
		cout << "3. Редактироване учетных записей." << endl;
		cout << "4. Удаление учетных записей." << endl;
		cout << "5. Назад." << endl;
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
		cout << "===============Меню работы с данными===============" << endl;
		cout << "1. Редактирование товаров." << endl;
		cout << "2. Обработка товаров." << endl;
		cout << "3. Назад." << endl;
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
		cout << "===============Меню редактирование данных===============" << endl;
		cout << "1. Просмотр товаров." << endl;
		cout << "2. Добавление нового товара." << endl;
		cout << "3. Удаление товара." << endl;
		cout << "4. Редактирование товара." << endl;
		cout << "5. Назад." << endl;
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
		cout << "===============Меню обработки данных===============" << endl;
		cout << "1. Поиск товаров." << endl;
		cout << "2. Сортировка товаров." << endl;
		cout << "3. Индивидуальное задание." << endl;
		cout << "4. Назад." << endl;
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
		cout << "===============Меню поиска данных===============" << endl;
		cout << "1. По наименованию продукции." << endl;
		cout << "2. По номеру цеха." << endl;
		cout << "3. По ФИО ответственного по цеху." << endl;
		cout << "4. Назад." << endl;
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
		cout << "===============Меню сортировки данных===============" << endl;
		cout << "1. По наименованию продукции." << endl;
		cout << "2. По номеру цеха." << endl;
		cout << "3. По количеству выпущенных единиц." << endl;
		cout << "4. Назад." << endl;
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
