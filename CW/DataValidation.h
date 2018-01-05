#pragma once
#include "stdafx.h"
#include "FileStream.h"
#include "Structures.h"
#include "ErrorHandler.h"
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

const int loginLength = 6;
const int passwordLength = 10;
const int fullNameLength = 15;
const int departmentLength = 20;
const int positionLength = 20;

string ValidateAccount(string login, string password, vector<User> &users);
bool isExistAccount(vector<User> &users, string login);
bool isExistProduct(vector<Product> &product, string lastName, string name, string middleName);
bool ValidateWriteNewUserData(string validKey, User &user, vector<User> &users);
bool ValidateWriteNewProduct(string validKey, Product &product, vector<Product> &products);
