#pragma once
#include <iostream>
#include"Compte.h"
using namespace std;
class Client
{
private:
	static int c_id;
	int id_clt;
	string name;
	Compte* accounts;
	int nb_cpt;
	Client() = delete;
	Client operator =(const Client& clt) = delete;
public:
	
	Client(string name,TypeCompte compte);
	void depot(double somme);
	void retrait(double somme);
	void Transferer(double somme, Client& recever);
	void Afficher()const;
	~Client();
};

