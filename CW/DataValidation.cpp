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
		ShowWriteAccountError("Логин  превышает допустимое количество знаков...");
		return false;
	}
	if (validKey == "e")
	{
		if (isExistAccount(users, user.login)) {
			ShowWriteAccountError("Такой аккаунт уже существует...");
			return false;
		}
	}
	if (user.password.length() > passwordLength) {
		ShowWriteAccountError("Пароль превышает допустимое количество знаков...");
		return false;
	}
	if (user.role != "admin" && user.role != "guest")
	{
		ShowWriteAccountError("Вы ввели не верный тип аккаунта...");
		return false;
	}
	return true;
}

bool ValidateWriteNewProduct(string validKey, Product &product, vector<Product> &products) {
	if (product.lastNameResponsPers.length() > fullNameLength) {
		ShowWriteProductError("Фамилия не должно быть больше 15 знаков...");
		return false;
	}
	if (product.lastNameResponsPers.length() > fullNameLength) {
		ShowWriteProductError("Имя не должно быть больше 15 знаков...");
		return false;
	}
	if (product.lastNameResponsPers.length() > fullNameLength) {
		ShowWriteProductError("Отчество не должно быть больше 15 знаков...");
		return false;
	}
	if (validKey == "e")
	{
		if (isExistProduct(products, product.lastNameResponsPers, product.nameResponsPers, product.middleNameResponsPers)) {
			ShowWriteProductError("Такой сотрудник уже сущесвует...");
			return false;
		}
	}
	if (product.productName.length() > positionLength) {
		ShowWriteProductError("Назване продукции первышает 20 символов...");
		return false;
	}
	return true;
}

