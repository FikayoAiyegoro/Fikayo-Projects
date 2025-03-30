#include "Account.h"

Account::Account(){  				//defined default constructor
	AccountNumber = new int[4] {0,0,0,0};
	CustomerName ="";
}

Account::Account(int Num, const string& Name, double bal){	//defined overload constructor
	AccountNumber = new int[4];
	for(int i = 3; i >=0; --i) {
		AccountNumber[i] = Num %10;
		Num = Num/10;
	}
	CustomerName = Name;
	Balance.push_back(bal);
}

Account::~Account(){		//defined destructor to prevent a memory leak
	delete[] AccountNumber;
}

Account::Account(const Account& other) {
	AccountNumber = new int[4];
	for (int i =0; i < 4; ++i) {
		AccountNumber[i] = other.AccountNumber[i];
	}

	CustomerName = other.CustomerName;
	Balance = other.Balance;

}

Account& Account::operator =(const Account& other) {
	if(this != &other) {
		delete[]AccountNumber;

		AccountNumber = new int[4];

		for(int i = 0; i < 4; ++i) {
			AccountNumber[i] = other.AccountNumber[i];
		}

		CustomerName = other.CustomerName;
		Balance = other.Balance;

	}

	return *this;

}

void Account::setAccountNumber(int Num){ 	//defined function to set account number
	if(Num < 1000 || Num > 9999) {		// loop to place each number in its place
		cout <<"Invalid Account Number" << endl;
	}
	else {
		for(int i = 3; i >= 0; --i) {
			AccountNumber[i] = Num %10;
		Num = Num /10;
	}
}
}

void Account::setCustomerName(const string& Name){ //defined function for set customer name
	CustomerName = Name;
}

void Account::setBalance(double bal) {  //defined function for setbalance
	Balance.push_back(bal);
}







int Account::getAccountNumber() const{	//defined function for getaccount number 
	
	int number = 0;			// loop to place each number in its place
		for(int i = 0; i < 4; ++i) {
			number = number * 10 + AccountNumber[i];
			}
	return number;
}

string Account::getCustomerName() const{ //defined function for get customername
	return CustomerName;
}

double Account::getBalance() const{  	//defined function for get balance
	return Balance.back();
}

int Account::AccountNumCount = 1000; 	//set the starting accountNum



