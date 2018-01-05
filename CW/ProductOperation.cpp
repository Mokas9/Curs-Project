#include "stdafx.h"
#include "ProductOperation.h"


Product EnterProduct(vector<Product> &products, string validKey) {
	Product product;
	do
	{
		system("cls");
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "(Подсказка) Фамилия не должна быть больше 15 знаков, не допустимы пробелы." << endl;
		cout << "(Подсказка) Имя не должно быть больше 15 знаков, не допустимы пробелы." << endl;
		cout << "(Подсказка) Отчество не должно быть больше 15 знаков, не допустимы пробелы." << endl;
		cout << "(Подсказка) Номер отдела не должно быть больше 20 знаков, не допустимы пробелы." << endl;
		cout << "(Подсказка) Наименование продукции не должна быть больше 20 знаков, не допустимы пробелы." << endl;
		cout << "(Подсказка) Количество продукции должно состоять только из цифр." << endl;
		cout << "(Подсказка) Дата должна состоять только из цифр в формате год.месяц.день без точек (2017.10.20 = 20171020)" << endl;
		cout << "Введите фамилию сотрудника: ";
		(cin >> product.lastNameResponsPers).get();
		cout << "Введите имя сотрудника: ";
		(cin >> product.nameResponsPers).get();
		cout << "Введите отчество сотрудника: ";
		cin >> product.middleNameResponsPers;
		cout << "Введите номер отдела: ";
		cin >> product.departmentNumber;
		cout << "Введите наименование продукции: ";
		cin >> product.productName;
		cout << "Введите количество выпущенной продукции: ";
		cin >> product.productCount;
		cout << "Введите дату: ";
		cin >> product.date;
		if (cin.fail()) {
			cout << "Не верный формат ввода количества..." << endl;
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
	if (isConfirmAction("добавление"))
	{
		products.push_back(product);
		AddProductToFile(product);
		ShowAddSuccess();
	}
}
void ShowAllProducts(vector <Product> &products) {
	//system("cls");
	cout << " =================================================Список выпускаемой продукции==================================================" << endl;
	cout << "|" << setw(3) << left << "№" << "|" << setw(16) << "Фамилия" << "|" << setw(16) << "Имя" << "|" << setw(16) << "Отчество" << "|"
		<< setw(21) << "Номер отдела" << "|" << setw(21) << "Наименование продукции" << "|" << setw(11) << "Количество продукции" << "|" << setw(11) << "Дата" << "|" << endl;
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
		cout << "Введите номер продукции, которую вы хотите удалить: ";
		cin >> index;
		index--;
		if (!cin.fail())
		{
			if (products.size() > index)
			{
				if (!isConfirmAction("удаление")) break;
				products.erase(products.begin() + index);
				ReplaceProductFile(products);
				ShowDeleteSuccess();
				break;
			}
			ShowDeleteProductError("Такой продукции не существует");
		}
		else {
			system("cls");
			ShowDeleteProductError("Введите число...");
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
		cout << "Введите номер продукции, которую вы хотите изменить ";
		cin >> index;
		index--;
		if (!cin.fail()) {
			if (products.size() > index) {
				product = products[index];
				products[index] = EnterProduct(products, "");
				if (!isConfirmAction("изменение")) {
					products[index] = product;
					break;
				}
				ReplaceProductFile(products);
				ShowEditSuccess();
				break;
			}
			ShowDeleteProductError("Такой продукции не существует");
		}
		else {
			system("cls");
			ShowDeleteProductError("Введите число...");
		}
	}
}
void FindProductByRespPerson(vector <Product> &products) {
	string soughtValue;
	vector<Product> resultProducts;
	resultProducts.reserve(products.size());
	system("cls");
	cout << "Введите фамилию сотрудника по которой будете искать: ";
	cin >> soughtValue;

	for each (Product product in products)
	{
		if (strstr(product.lastNameResponsPers.c_str(), soughtValue.c_str())) {
			resultProducts.push_back(product);
		}
	}

	if (resultProducts.size() == 0)
	{
		cout << "По заданным параметрам ничего не найдено..." << endl;
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
	cout << "Введите отдел, по которому будете искать: ";
	cin >> soughtValue;

	for each (Product product in products)
	{
		if (product.departmentNumber == soughtValue) {
			resultProducts.push_back(product);
		}
	}

	if (resultProducts.size() == 0)
	{
		cout << "По заданным параметрам ничего не найдено..." << endl;
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
	cout << "Введите наименование продукции, по которой будете искать: ";
	cin >> soughtValue;

	for each (Product product in products)
	{
		if (strstr(product.productName.c_str(), soughtValue.c_str())) {
			resultProducts.push_back(product);
		}
	}

	if (resultProducts.size() == 0)
	{
		cout << "По заданным параметрам ничего не найдено..." << endl;
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
		cout << "Введите минимальное количество произведенной продукции для вывода";
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
			ShowNANError("Введите число...");
		}
	}
	if (resultProducts.size() == 0) {
		ShowEmptyResultError("По вашему запросу ничего не найдено...");
	}
	else {
		cout << "Результаты запроса:" << countAmount << endl;
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
			cout << "Общее количество выпущенной продукции в отделе \"" << products[i].departmentNumber << "\" = " << totalCountByDeparment << endl;
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

	cout << "Введите номер цеха, по которому будет производится поиск: " << endl;
	cin >> dep_number;
	cout << "Введите дату (от): " << endl;
	cin >> first_date;
	cout << "Введите дату (до): " << endl;
	cin >> second_date;

	for each (Product product in products) {
		if (product.date >= first_date && product.date <= second_date && product.departmentNumber == dep_number) {
			resultProducts.push_back(product);
		}
	}
	if (resultProducts.size() == 0)
	{
		cout << "По заданным параметрам ничего не найдено..." << endl;
		system("pause");
	}
	else
		ShowAllProducts(resultProducts);
	resultProducts.clear();
}
