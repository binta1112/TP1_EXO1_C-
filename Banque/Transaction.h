#pragma once
#include<iostream>
using namespace std;

class Transaction
{
	
private:
	static int id_t;
	int id_trans;
	string name_trans;
	Transaction() = delete;
	Transaction operator = (const Transaction& T) = delete;
public:
	Transaction(string name_t);
	void Afficher()const;
};

