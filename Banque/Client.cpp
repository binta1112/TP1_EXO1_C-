#include "Client.h"
int Client::c_id = 0;
Client::Client(string name, TypeCompte compte):id_clt(c_id++),name(name)
{
	this->accounts = new Compte(compte);
}

void Client::depot(double somme)
{
	this->accounts->Effectuer_depot(somme);
}

void Client::retrait(double somme)
{
	this->accounts->Effectuer_retrait(somme);
}

void Client::Transferer(double somme, Client& recever)
{
	this->accounts->Transferer(somme, *recever.accounts);
}

void Client::Afficher() const
{
	cout << "Id_client: " << this->id_clt << endl;
	cout << "Nom_client: " << this->name << endl;
	cout << "***** Compte Infos " << endl;
	this->accounts->Afficher_compte();


}

Client::~Client()
{
	delete this->accounts;
}
