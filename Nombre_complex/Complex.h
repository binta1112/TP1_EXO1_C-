#pragma once

#include <iostream>
using namespace std;
/*
* Classe Complex representant les nombre complexes
*/
class Complex
{
private:
	double re;//partie réel du nb complexe
	double img;//partie imaginaire du nb complexe
public:
	Complex();//constructeur sans param;
	Complex(double re,double img);//constructeur avec param;
	void Afficher() const;//methode pour afficher l'instance de la classe
	Complex conjugue() const;// methode qui envoie le conjugué du nombre complexe courant
	double module() const;//methode pour calculer le module d'un complexe

	
	Complex* operator + (const Complex& z)const;//permet de sommer deux complex 
	Complex* operator + (double nb) const;//permet de sommer un réel avec un nb complexe
	

	Complex* operator - (const Complex& z) const ;//soustraction entre deux complex
	Complex* operator - (double nb) const;//soustraction entre un double et un complexe
	

	Complex* operator * (const Complex& z)const;//multiplication entre deux complex
	Complex* operator * (double nb)const;//multiplication entre un double et un complexe
	

	Complex* operator / (const Complex& z)const;//division entre deux complex
	Complex* operator / (double nb)const;//division entre un double et un complexe
	

	bool operator == (const Complex& z) const;
	bool operator == (double nb) const;
	
};
/*
* ces sucharges des differents operateurs permettrons que l'operande a droite puisse etre un double
*/
Complex* operator - (double nb, const Complex& z);
Complex* operator + (double nb, const Complex& z);
Complex* operator * (double nb, const Complex& z);
Complex* operator / (double nb, const Complex& z);
bool operator == (double nb, const Complex& z);
/*
* surcharger une fonction c'est de la definir +sieurs fois avec de param diferent
* polymorphisme at compiter : car la fonction change au moment de la compilation
* En gros la surcharge (overloaded) nous donne le polymorphisme
* il est impossible de surcharger uniquement avec les types de retour
*/
