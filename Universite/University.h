#pragma once
#include "Employe.h"

class University
{
private:
	static int comp_id;
	int id_univ;
	string univ_name;
	shared_ptr<Employe>employes[10];//Table de n pointeur sur des employés
	int nb_e;//nombre d'employé dans l'univ
	University() = delete;
public:
	University(string name);
	void Ajouter_Employe(shared_ptr<Employe> e);
	void Afficher_univ()const;
};

