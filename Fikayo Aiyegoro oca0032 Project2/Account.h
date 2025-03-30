#ifndef ACCOUNTH
#define ACCOUNTH

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>


using namespace std;

class Account{
private:			//Private variable functions for class
	int* AccountNumber;	// Pointer to save the 4 digits each
	string CustomerName;	
	vector<double>Balance;

public:
	Account(); // creating default constructor
	
	Account(int Num,const string& Name, double bal); //creating overloaded constructor

	~Account(); // deconstructor
	Account(const Account& other);
	Account& operator=(const Account& other);

	void setAccountNumber(int Num); //setter mutator functions dont return 
	void setCustomerName(const string& Name);
	void setBalance(double bal);

	int getAccountNumber()const; //getter accessor functions that return values
	string getCustomerName()const;
	double getBalance()const;

	static int AccountNumCount; // tobe able to add to account number
};






#endif
