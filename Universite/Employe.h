#pragma once
#include <iostream>
using namespace std;
class Employe
{
private:
	static int comp;
	int empl_id;
	string name;
	Employe() = delete;
	//Employe operator = (const Employe& e) = delete;
public:
	Employe(string name);
	void Afficher_emp() const;
};

