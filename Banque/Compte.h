#pragma once
#include<iostream>
#include"Transaction.h"
using namespace std;

/*
* enumertaion des types de comptes possible
*/
typedef enum
{
	courant,//0
	epargne //1
	//...
}TypeCompte;
class Compte
{
private:
	static int uniq_id;
	int id_compte;//Id du compte
	double solde;//solde du compte
	TypeCompte type_compte;//type de compte
	shared_ptr<Transaction> T[5];
	int nb_trans;
	//string client;//proprietaire du compte
	
	/*
	* je juge qu'il est obligatoire de preciser le type du compte
	* d'ou on ne pourra pas utiliser le constructeur sans parametre
	*/
	Compte() = delete;
	/*
	* Pour concerver l'unicité des identifiant, on desactive le constructeur de recopie
	  et l'operateur d'affectation
	*/
	Compte(const Compte& account) = delete;	
	Compte operator = (const Compte& account) = delete;
public:
	Compte(TypeCompte type);
	void Effectuer_depot(double somme);
	void Effectuer_retrait(double somme);
	void Transferer(double somme, Compte& recever);
	void consulter()const;
	void Afficher_compte();
	//~Compte();
	
};

