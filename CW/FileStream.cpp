#include "stdafx.h"
#include "FileStream.h"


void AddAccountToFile(User user) {

	ofstream file(ACCOUNT_FILE_PAS, ios::app);
	file << endl;
	file << user.login << " "
		<< user.password << " "
		<< user.role;

	file.close();
}

void ReplaceAccountFile(vector<User> users) {
	ofstream file(ACCOUNT_FILE_PAS, ios::out);
	for (int i = 0; i < users.size(); i++) {
		file << users[i].login << " "
			<< users[i].password << " "
			<< users[i].role;
		if (i < users.size() - 1)
			file << endl;
	}
}

vector<User> ReadAccountFile(vector<User> users) {
	User user;
	ifstream file(ACCOUNT_FILE_PAS, ios::in);
	if (!file.is_open()) ShowFileOpenError();
	else {
		int i = 0;
		while (!file.eof()) {
			file >> user.login
				>> user.password
				>> user.role;
			users.push_back(user);
			i++;
		}
	}
	file.close();
	return users;
}

void  AddProductToFile(Product product) {
	ofstream file(DATA_FILE_PAS, ios::app);
	file << endl;
	file << product.lastNameResponsPers << " "
		<< product.nameResponsPers << " "
		<< product.middleNameResponsPers << " "
		<< product.departmentNumber << " "
		<< product.productName << " "
		<< product.productCount;

	file.close();
}
void ReplaceProductFile(vector<Product> products) {
	ofstream file(DATA_FILE_PAS, ios::out);
	for (int i = 0; i < products.size(); i++) {
		file << products[i].lastNameResponsPers << " "
			<< products[i].nameResponsPers << " "
			<< products[i].middleNameResponsPers << " "
			<< products[i].departmentNumber << " "
			<< products[i].productName << " "
			<< products[i].productCount;
		if (i < products.size() - 1)
			file << endl;
	}
}
vector<Product> ReadProductFile(vector<Product> products) {
	Product product;
	ifstream file(DATA_FILE_PAS, ios::in);
	if (!file.is_open()) ShowFileOpenError();
	else {
		int i = 0;
		while (!file.eof()) {
			file >> product.lastNameResponsPers
				>> product.nameResponsPers
				>> product.middleNameResponsPers
				>> product.departmentNumber
				>> product.productName
				>> product.productCount;
			products.push_back(product);
			i++;
		}
	}
	file.close();
	return products;
}