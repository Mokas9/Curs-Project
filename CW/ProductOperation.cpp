#include "stdafx.h"
#include "ProductOperation.h"


Product EnterProduct(vector<Product> &products, string validKey) {
	Product product;
	do
	{
		system("cls");
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "(���������) ������� �� ������ ���� ������ 15 ������, �� ��������� �������." << endl;
		cout << "(���������) ��� �� ������ ���� ������ 15 ������, �� ��������� �������." << endl;
		cout << "(���������) �������� �� ������ ���� ������ 15 ������, �� ��������� �������." << endl;
		cout << "(���������) ����� ������ �� ������ ���� ������ 20 ������, �� ��������� �������." << endl;
		cout << "(���������) ������������ ��������� �� ������ ���� ������ 20 ������, �� ��������� �������." << endl;
		cout << "(���������) ���������� ��������� ������ �������� ������ �� ����." << endl;
		cout << "(���������) ���� ������ �������� ������ �� ���� � ������� ���.�����.���� ��� ����� (2017.10.20 = 20171020)" << endl;
		cout << "������� ������� ����������: ";
		(cin >> product.lastNameResponsPers).get();
		cout << "������� ��� ����������: ";
		(cin >> product.nameResponsPers).get();
		cout << "������� �������� ����������: ";
		cin >> product.middleNameResponsPers;
		cout << "������� ����� ������: ";
		cin >> product.departmentNumber;
		cout << "������� ������������ ���������: ";
		cin >> product.productName;
		cout << "������� ���������� ���������� ���������: ";
		cin >> product.productCount;
		cout << "������� ����: ";
		cin >> product.date;
		if (cin.fail()) {
			cout << "�� ������ ������ ����� ����������..." << endl;
			system("pause");
			continue;
		}
		system("cls");
	} while (!ValidateWriteNewProduct(validKey, product, products) || cin.fail());
	return product;
}

void AddProduct(vector<Product> &products) {
	Product product;

	product = EnterProduct(products, "e");
	if (isConfirmAction("����������"))
	{
		products.push_back(product);
		AddProductToFile(product);
		ShowAddSuccess();
	}
}
void ShowAllProducts(vector <Product> &products) {
	//system("cls");
	cout << " =================================================������ ����������� ���������==================================================" << endl;
	cout << "|" << setw(3) << left << "�" << "|" << setw(16) << "�������" << "|" << setw(16) << "���" << "|" << setw(16) << "��������" << "|"
		<< setw(21) << "����� ������" << "|" << setw(21) << "������������ ���������" << "|" << setw(11) << "���������� ���������" << "|" << setw(11) << "����" << "|" << endl;
	for (int i = 0; i < products.size(); i++) {
		cout << " =============================================================================================================" << endl;
		cout << "|" << setw(3) << left << i + 1 << "|" << setw(16) << products[i].lastNameResponsPers << "|" << setw(16) << products[i].nameResponsPers << "|" << setw(16) << products[i].middleNameResponsPers << "|"
			<< setw(21) << products[i].departmentNumber << "|" << setw(21) << products[i].productName << "|" << setw(11) << products[i].productCount << "|" << setw(11) << products[i].date << "|" << endl;
	}
	system("pause");
}
void DeleteProduct(vector <Product> &products) {
	int index;
	while (true)
	{
		system("cls");
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		ShowAllProducts(products);
		cout << "������� ����� ���������, ������� �� ������ �������: ";
		cin >> index;
		index--;
		if (!cin.fail())
		{
			if (products.size() > index)
			{
				if (!isConfirmAction("��������")) break;
				products.erase(products.begin() + index);
				ReplaceProductFile(products);
				ShowDeleteSuccess();
				break;
			}
			ShowDeleteProductError("����� ��������� �� ����������");
		}
		else {
			system("cls");
			ShowDeleteProductError("������� �����...");
		}
	}
}
void EditProduct(vector <Product> &products) {
	int index;
	Product product;
	while (true) {
		system("cls");
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		ShowAllProducts(products);
		cout << "������� ����� ���������, ������� �� ������ �������� ";
		cin >> index;
		index--;
		if (!cin.fail()) {
			if (products.size() > index) {
				product = products[index];
				products[index] = EnterProduct(products, "");
				if (!isConfirmAction("���������")) {
					products[index] = product;
					break;
				}
				ReplaceProductFile(products);
				ShowEditSuccess();
				break;
			}
			ShowDeleteProductError("����� ��������� �� ����������");
		}
		else {
			system("cls");
			ShowDeleteProductError("������� �����...");
		}
	}
}
void FindProductByRespPerson(vector <Product> &products) {
	string soughtValue;
	vector<Product> resultProducts;
	resultProducts.reserve(products.size());
	system("cls");
	cout << "������� ������� ���������� �� ������� ������ ������: ";
	cin >> soughtValue;

	for each (Product product in products)
	{
		if (strstr(product.lastNameResponsPers.c_str(), soughtValue.c_str())) {
			resultProducts.push_back(product);
		}
	}

	if (resultProducts.size() == 0)
	{
		cout << "�� �������� ���������� ������ �� �������..." << endl;
		system("pause");
	}
	else
		ShowAllProducts(resultProducts);
	resultProducts.clear();

}
void FindProductByDepartment(vector <Product> &products) {
	int soughtValue;
	vector<Product> resultProducts;
	resultProducts.reserve(products.size());
	system("cls");
	cout << "������� �����, �� �������� ������ ������: ";
	cin >> soughtValue;

	for each (Product product in products)
	{
		if (product.departmentNumber == soughtValue) {
			resultProducts.push_back(product);
		}
	}

	if (resultProducts.size() == 0)
	{
		cout << "�� �������� ���������� ������ �� �������..." << endl;
		system("pause");
	}
	else
		ShowAllProducts(resultProducts);
	resultProducts.clear();
}
void FindProductByProductName(vector <Product> &products) {
	string soughtValue;
	vector<Product> resultProducts;
	resultProducts.reserve(products.size());
	system("cls");
	cout << "������� ������������ ���������, �� ������� ������ ������: ";
	cin >> soughtValue;

	for each (Product product in products)
	{
		if (strstr(product.productName.c_str(), soughtValue.c_str())) {
			resultProducts.push_back(product);
		}
	}

	if (resultProducts.size() == 0)
	{
		cout << "�� �������� ���������� ������ �� �������..." << endl;
		system("pause");
	}
	else
		ShowAllProducts(resultProducts);
	resultProducts.clear();
}
void SortProductByRespPerson(vector <Product> &products) {
	system("cls");

	sort(products.begin(), products.end(), [](const Product& productA, const Product& productB) {
		return productA.lastNameResponsPers < productB.lastNameResponsPers;
	});

	ShowAllProducts(products);
}
void SortProductByDepartment(vector <Product> &products) {
	system("cls");

	sort(products.begin(), products.end(), [](const Product& productA, const Product& productB) {
		return productA.departmentNumber < productB.departmentNumber;
	});

	ShowAllProducts(products);
}
void SortProductByCount(vector <Product> &products) {
	system("cls");

	sort(products.begin(), products.end(), [](const Product& productA, const Product& productB) {
		return productA.productCount > productB.productCount;
	});

	ShowAllProducts(products);
}
void IndividualTask(vector <Product> &products) {
	ShowProductByCount(products);
	CalculateTotalCountByDepartment(products);
	CountByDate(products);
	system("pause");
}

void ShowProductByCount(vector <Product> &products) {
	double countAmount;
	vector<Product> resultProducts;
	resultProducts.reserve(products.size());

	while (true)
	{
		system("cls");
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "������� ����������� ���������� ������������� ��������� ��� ������";
		cin >> countAmount;
		if (!cin.fail()) {
			for each (Product product in products)
			{
				if (product.productCount > countAmount) {
					resultProducts.push_back(product);
				}
			}
			break;
		}
		else {
			ShowNANError("������� �����...");
		}
	}
	if (resultProducts.size() == 0) {
		ShowEmptyResultError("�� ������ ������� ������ �� �������...");
	}
	else {
		cout << "���������� �������:" << countAmount << endl;
		ShowAllProducts(resultProducts);
	}
}
void CalculateTotalCountByDepartment(vector <Product> &products) {
	system("cls");
	double totalCountByDeparment = .0;
	sort(products.begin(), products.end(), [](const Product& productA, const Product& productB) {
		return productA.departmentNumber < productB.departmentNumber;
	});

	for (int i = 0; i < products.size(); i++) {
		if (i + 1 < products.size() && products[i].departmentNumber == products[i + 1].departmentNumber) {
			totalCountByDeparment += products[i].productCount;
		}
		else {
			totalCountByDeparment += products[i].productCount;
			cout << "����� ���������� ���������� ��������� � ������ \"" << products[i].departmentNumber << "\" = " << totalCountByDeparment << endl;
			totalCountByDeparment = 0;
		}
	}
	system("pause");
}

void CountByDate(vector <Product> &products) {
	system("cls");

	vector<Product> resultProducts;
	resultProducts.reserve(products.size());

	int dep_number;
	int first_date;
	int second_date;

	cout << "������� ����� ����, �� �������� ����� ������������ �����: " << endl;
	cin >> dep_number;
	cout << "������� ���� (��): " << endl;
	cin >> first_date;
	cout << "������� ���� (��): " << endl;
	cin >> second_date;

	for each (Product product in products) {
		if (product.date >= first_date && product.date <= second_date && product.departmentNumber == dep_number) {
			resultProducts.push_back(product);
		}
	}
	if (resultProducts.size() == 0)
	{
		cout << "�� �������� ���������� ������ �� �������..." << endl;
		system("pause");
	}
	else
		ShowAllProducts(resultProducts);
	resultProducts.clear();
}
