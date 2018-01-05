#pragma once
#include "stdafx.h"
#include "FileStream.h"
#include "Structures.h"
#include "ErrorHandler.h"
#include <fstream>
#include <vector>

using namespace std;

const string ACCOUNT_FILE_PAS = "Account.txt";
const string DATA_FILE_PAS = "Products.txt";

void  AddAccountToFile(User user);
void ReplaceAccountFile(vector<User> users);
vector<User> ReadAccountFile(vector<User> users);

void  AddProductToFile(Product products);
void ReplaceProductFile(vector<Product> products);
vector<Product> ReadProductFile(vector<Product> products);


