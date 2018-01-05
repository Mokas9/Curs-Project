#pragma once
#include "stdafx.h"
#include "Structures.h"
#include "FileStream.h"
#include "DataValidation.h"
#include "ActionHandler.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>

using namespace std;

Product EnterProduct(vector<Product> &product, string validKey);
void AddProduct(vector<Product> &product);
void ShowAllProducts(vector <Product> &product);
void DeleteProduct(vector <Product> &product);
void EditProduct(vector <Product> &product);
void FindProductByRespPerson(vector <Product> &product);
void FindProductByDepartment(vector <Product> &product);
void FindProductByProductName(vector <Product> &product);
void SortProductByRespPerson(vector <Product> &product);
void SortProductByDepartment(vector <Product> &product);
void SortProductByCount(vector <Product> &product);
void IndividualTask(vector <Product> &product);
void ShowProductByCount(vector <Product> &product);
void CalculateTotalCountByDepartment(vector <Product> &product);
void CountByDate(vector <Product> &product);

