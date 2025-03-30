#include "Account.h"

void OpenAccount(vector<Account>& accounts) { //defined function when user selects menu option 1
	string name;
	double StartDeposit;
	
	cout << "Enter customer account name: " << endl;
	cin.ignore();

	getline(cin, name);

	cout << "Enter depsit amount: $" << endl;
	cin >> StartDeposit;

	Account OpenAccount;

	OpenAccount.setCustomerName(name);
	OpenAccount.setBalance(StartDeposit);
	OpenAccount.setAccountNumber(Account::AccountNumCount++);

	accounts.push_back(OpenAccount);

	cout <<"Account opened: " << OpenAccount.getAccountNumber() << "----" << OpenAccount.getCustomerName() << " : $" << fixed << setprecision(2) << OpenAccount.getBalance() << endl;

}

void DepositAccount(vector<Account>& accounts) { //defined function when user selects menu option 2
	int AccountNum;
	double DepositAmount;

	cout << "Enter account number: " << endl;

	cin >> AccountNum;

	cout << "Enter deposit amount: $" << endl;
	cin >> DepositAmount;
	
	bool found = false;

	for (Account& ACCOUNT : accounts) {
		if(ACCOUNT.getAccountNumber() == AccountNum) {
			ACCOUNT.setBalance(DepositAmount);
			cout << "Deposit succesful. your new balance: $" << fixed << setprecision(2) << ACCOUNT.getBalance() << endl;
			found = true;

		}
		else {
			cout << "Account number not found" << endl;
		}
	}
}

void WithdrawAccount(vector<Account>& accounts) { //defined function when user selects menu option 3
	int accNum;
	double Withdraw;

	cout << "Enter account number: " << endl;
	cin >> accNum;

	cout << "Enter amount to withdrawl" << endl;
	cin >> Withdraw;

	bool found = false;

	for (Account& ACCOUNT : accounts) {
		if(ACCOUNT.getAccountNumber() == accNum) {
			found = true;

			double currentBal = ACCOUNT.getBalance();

	if(Withdraw <= currentBal) {
		ACCOUNT.setBalance(-Withdraw);
		cout << "Withdraw was succesful, New balance: $" << fixed << setprecision(2) << ACCOUNT.getBalance() << endl;
	} else {
		cout << "Your withdrawing more than you have" << endl;
	}
		}
		else {
		cout << "That account Number was not found" << endl;
	}
}

}

void PrintAccount(vector<Account>& accounts) { //defined function when user selects menu option 4
	if(accounts.empty()) {
		cout << "account not found" << endl;
	}
	else {
		cout << "+----------------------------------------------------+" << endl;
		cout << "|Account Number|	Name	|	Balance	      |" << endl;
		cout << "|						      |" << endl;
		cout << "|						      |" << endl;
		cout << "+----------------------------------------------------+" << endl;
	
	for (const Account& ACCOUNT : accounts) {

		cout << "| " << setw(11) << ACCOUNT.getAccountNumber() << " | " << setw(14) << ACCOUNT.getCustomerName() << " | $" << fixed << setprecision(2) << setw(7) << ACCOUNT.getBalance() << " |" << endl;
	}
	
	cout << "+------------------------------------------+" << endl;

}

}

void ExitAll(vector<Account>& accounts) { //defined function when user selects menu option 5
	cout << "Exiting" << endl;
}

int main() {


	cout <<" +---------------------------------------+" << endl;
	cout <<" |     Computer Science and Engineering  |" << endl;
	cout <<" |	CSCE 1040 - Computer Program II  |" << endl;
	cout <<" |		Fikayo Aiyegoro 	 |" << endl;
	cout <<" | 	FikayoAiyegoro@my.unt.edu 	 |" << endl;
	cout <<" +---------------------------------------+" << endl;

	vector<Account> accounts;

	int pick;
				//display menu option
	do {
		cout << " 1. Open an New Account \n"
			" 2. Deposit into Account \n"
			" 3. Withdrawn From Account \n"
			" 4. Print All Accounts \n"
			" 5. Exit(All) \n" << endl;

		cin >> pick;

		switch(pick) {
			case 1:
				OpenAccount(accounts);
				break;
			case 2:
				DepositAccount(accounts);
				break;
			case 3:
				WithdrawAccount(accounts);
				break;
			case 4:
				PrintAccount(accounts);
				break;
			case 5:
				cout << "Exiting" << endl;
				break;
			default:
				cout << "Not an option try again" << endl;


			}
	}while (pick !=5); //loops until the user pick option 5

	return 0;

}
