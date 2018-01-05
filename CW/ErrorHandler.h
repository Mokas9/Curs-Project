#pragma once
#include "stdafx.h"
#include <iostream>

using namespace std;

void ShowMenuError();
void ShowValidateAccountError(int validType);
void ShowFileOpenError();
void ShowWriteAccountError(string error);
void ShowDeleteAccountError(string error);
void ShowWriteProductError(string error);
void ShowDeleteProductError(string error);
void ShowEmptyResultError(string error);
void ShowNANError(string error);



