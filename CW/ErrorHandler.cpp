#include "stdafx.h"
#include "ErrorHandler.h"

void ShowMenuError() {
	cout << "Вы выбрали не правильный элемент. Выберите еще раз." << endl;
}

void ShowValidateAccountError(int type) {
	if (type == 1) {
		cout << "Введен не верный пароль." << endl;
	}
	else {
		cout << "Такого аккаунта не существует." << endl;

	}
}

void ShowFileOpenError() {
	cout << "Такого файла не существует..." << endl;
}

void ShowWriteAccountError(string error) {
	cout << error.c_str() << endl;
	system("pause");
}

void ShowDeleteAccountError(string error) {
	cout << error.c_str() << endl;
	system("pause");
}

void ShowWriteProductError(string error) {
	cout << error.c_str() << endl;
	system("pause");
}

void ShowDeleteProductError(string error) {
	cout << error.c_str() << endl;
	system("pause");
}
void ShowEmptyResultError(string error) {
	system("cls");
	cout << error.c_str() << endl;
	system("pause");
}

void ShowNANError(string error) {
	system("cls");
	cout << error.c_str() << endl;
	system("pause");
}
