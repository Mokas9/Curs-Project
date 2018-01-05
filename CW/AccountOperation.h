#pragma once
#include "stdafx.h"
#include "Structures.h"
#include "FileStream.h"
#include "DataValidation.h"
#include "ActionHandler.h"
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

User EnterUser(vector<User> &users, string validKey);
void AddAccount(vector<User> &users);
void ShowAllAccount(vector <User> &users);
void DeleteAccount(vector <User> &users);
void EditAccount(vector <User> &users);
