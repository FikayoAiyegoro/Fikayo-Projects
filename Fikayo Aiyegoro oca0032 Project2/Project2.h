#include "Account.h"
#ifndef PROJECT2H
#define PROJECT2H


	enum Menu{Open_New_Account = 1, Deposit_Into_Account = 2, Withdraw_From_Account = 3, Print_A_List_Of_All_Accounts = 4, End_Transaction(Exit) = 5};

//making enum for menu option

void OpenAccount(vector<Account>& accounts);
void DepositAccount(vector<Account>& accounts);
void WithdrawAccount(vector<Account>& accounts);
void PrintAccount(const vector<Account>& accounts);
void ExitAll(vector<Account>& accounts);


//functions for menu options












#endif
