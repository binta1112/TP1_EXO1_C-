#include "Employe.h"
int Employe::comp = 0;
Employe::Employe(string name) :empl_id(comp), name(name)
{
}

void Employe::Afficher_emp()const
{
	cout << "Id_emp: " << this->empl_id << endl;
	cout << "Nom_emp: " << this->name << endl;
}
