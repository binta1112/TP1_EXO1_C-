#include "Transaction.h"
#include<iostream>
using namespace std;
int Transaction::id_t = 0;
Transaction::Transaction(string name_t):id_trans(id_t++),name_trans(name_t)
{}

void Transaction::Afficher()const
{
	cout << "Transation_id: " << this->id_trans << endl;
	cout << "Transation_name: " << this->name_trans << endl;

}
