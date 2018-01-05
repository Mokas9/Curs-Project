#include "stdafx.h"
#include "DataValidation.h"

string ValidateAccount(string login, string password, vector<User> &users) {
	users = ReadAccountFile(users);
	if (isExistAccount(users, login)) {
		auto it = find_if(users.begin(), users.end(), [&](const User & user)->bool { return user.login == login; });
		size_t index = it - users.begin();
		if (users[index].password == password)
			return users[index].role;
		else
		{
			ShowValidateAccountError(1);
			return "none";
		}
	}
	ShowValidateAccountError(2);
	return "none";
}


bool isExistAccount(vector<User> &users, string login) {
	auto it = find_if(users.begin(), users.end(), [&](const User & user)->bool { return user.login == login; });
	if (it != users.end())
	{
		return true;
	}
	return false;
}

bool isExistProduct(vector<Product> &products, string lastNameResponsPers, string nameResponsPers, string middleNameResponsPers) {
	auto it = find_if(products.begin(), products.end(), [&](const Product & product)->bool { return product.lastNameResponsPers == lastNameResponsPers && product.nameResponsPers == nameResponsPers && product.middleNameResponsPers == middleNameResponsPers; });
	if (it != products.end())
	{
		return true;
	}
	return false;
}

bool ValidateWriteNewUserData(string validKey, User &user, vector<User> &users) {
	if (user.login.length() > loginLength) {
		ShowWriteAccountError("�����  ��������� ���������� ���������� ������...");
		return false;
	}
	if (validKey == "e")
	{
		if (isExistAccount(users, user.login)) {
			ShowWriteAccountError("����� ������� ��� ����������...");
			return false;
		}
	}
	if (user.password.length() > passwordLength) {
		ShowWriteAccountError("������ ��������� ���������� ���������� ������...");
		return false;
	}
	if (user.role != "admin" && user.role != "guest")
	{
		ShowWriteAccountError("�� ����� �� ������ ��� ��������...");
		return false;
	}
	return true;
}

bool ValidateWriteNewProduct(string validKey, Product &product, vector<Product> &products) {
	if (product.lastNameResponsPers.length() > fullNameLength) {
		ShowWriteProductError("������� �� ������ ���� ������ 15 ������...");
		return false;
	}
	if (product.lastNameResponsPers.length() > fullNameLength) {
		ShowWriteProductError("��� �� ������ ���� ������ 15 ������...");
		return false;
	}
	if (product.lastNameResponsPers.length() > fullNameLength) {
		ShowWriteProductError("�������� �� ������ ���� ������ 15 ������...");
		return false;
	}
	if (validKey == "e")
	{
		if (isExistProduct(products, product.lastNameResponsPers, product.nameResponsPers, product.middleNameResponsPers)) {
			ShowWriteProductError("����� ��������� ��� ���������...");
			return false;
		}
	}
	if (product.productName.length() > positionLength) {
		ShowWriteProductError("������� ��������� ��������� 20 ��������...");
		return false;
	}
	return true;
}

