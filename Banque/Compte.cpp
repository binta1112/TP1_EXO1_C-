#include "Compte.h"
int Compte::uniq_id = 0;
/*
* Nom_methode:Compte
* Parametres:le type du compte a creer 
* Description:Constructeur de la classe Compte,cree un compte nouveau avec le type donné
*/
Compte::Compte( TypeCompte type) :id_compte(uniq_id++), solde(0.0),type_compte(type),nb_trans(0)
{}
/*
* Nom_methode:Effectuer_depot
* Parametres:somme:type double
* Description:Incremente le solde du compte par la somme donnée
*/
void Compte::Effectuer_depot(double somme)
{
	this->solde += somme;	
	this->T[nb_trans++] = make_shared<Transaction>("depot");
}
/*
* Nom_methode:Effectuer_retrait
* Parametres:somme:type double
* Description:Decremente le solde du compte par la somme donnée
*/
void Compte::Effectuer_retrait(double somme)
{
	if (somme <= this->solde)
	{
		this->solde -= somme;
		this->T[nb_trans++] = make_shared<Transaction>("retrait");
	}

}
/*
* Nom_methode:Transferer
* Parametres:somme:type double et un objet Compte
* Description:fait un retait de somme sur le solde du compte courant
*             et ajoute somme qu solde du compte passé en parametre
*/
void Compte::Transferer(double somme, Compte& recever)
{
	if (this->solde >= somme)
	{
		this->solde -= somme;
		recever.solde += somme;	
		this->T[nb_trans++] = recever.T[recever.nb_trans++] = make_shared<Transaction>("transfert");
		
	}
}
/*
* Nom_methode:consulter
* Parametres:Aucun
* Description:Affichage a l'ecran
*/
void Compte::consulter() const{
	
	cout << "Solde: " << this->solde << endl;
}

void Compte::Afficher_compte()
{
	cout << "Account_id:" << this->id_compte << endl;
	cout << "Solde: " << this->solde << endl;
	cout << "History Transaction" << endl;
	for (int i = 0; i < this->nb_trans; i++) this->T[i]->Afficher();

}


