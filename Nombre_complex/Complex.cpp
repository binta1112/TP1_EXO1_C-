#include "Complex.h"
#include<cmath>
using namespace std;
/*
*Nom_methode:Complex
* Parametres:Aucun
* Valeur de retour:
* Description:Contructeur sans paramtere de la classe Complex,il 
              initialise les champs par 0 que nous avons jugé valeurs par defaut
*/
Complex::Complex()
{
	this->re = 0;
	this->img = 0;
}
/*
*Nom_methode:Complex
* Parametres: - re de type double qui represente la partie entière
              - img de type double pour la partie imaginaire
* Valeur de retour:
* Description:constructeur avec parametre invoqué lorsque que l'on souhaite donner des valeurs 
*             pour l'objet complex que l'on souhaite creer
*/
Complex::Complex(double re,double img)
{
	this->re = re;
	this->img = img;
}
/*
*Nom_methode:Afficher
* Parametres:Aucun
* Valeur de retour:Affichage à l'ecran
* Description:Cette methode affiche a l'ecran les valeurs des champs d'un objet complexe
*/
void Complex::Afficher() const
{
	cout << this->re<<" + " << this->img << "i" << endl;
}
/*
*Nom_methode:conjugue
* Parametres:Aucun
* Valeur de retour:return un complex 
* Description:Cette methode retourne le conjugué de l'objet courant
*/
Complex Complex::conjugue() const
{
	
	return {this->re,-1*this->img};
}
/*
*Nom_methode:module
* Parametres:Aucun
* Valeur de retour:return un double
* Description:Cette methode retourne le modul de l'objet courant
*/
double Complex::module() const
{
	return sqrt(pow(this->re,2)+pow(this->img,2));
}
/*
*Nom_methode:operator+
* Parametres: - z reference d'un objet complexe
* Valeur de retour:un pointeur sur un objet complexe
* Description:Cette definition de l'operateur + de la classe Complexe fait l'addition
*             entre deux nombres complexe (l'objet courant et celui passé en argument)
*             puis renvoie un pointeur qui sur un nouveau objet complexe contenant le resultat
*/
Complex* Complex::operator+(const Complex& z)const
{
	Complex* z2 = new Complex();
	z2->re = this->re+z.re;
	z2->img = this->img+z.img;
	return z2;
}
/*
*Nom_methode:operator+
* Parametres:- nb de type double
* Valeur de retour:Complexe*,un pointeur sur un objet complexe
* Description:Une surcharge de l'operateur + de la classe Complexe qui permet d'dditionner
*             un double et un complex puis renvoie un pointeur qui sur un nouveau objet 
              complexe contenant le resultat
*NB: l'operande droite est un double    
*/
Complex* Complex::operator+(double nb) const
{
	Complex* z2 = new Complex();
	z2->re = this->re + nb;
	z2->img = this->img;
	return z2;
}
/*
*Nom_methode:operator-
* Parametres:- nb de type double
* Valeur de retour:Complexe*,un pointeur sur un objet complexe
* Description: permet de faire la soustraction de deux nombre complexes
               puis renvoie un pointeur qui sur un nouveau objet 
              complexe contenant le resultat
*NB: l'operande droite est un double
*/
Complex* Complex::operator-(const Complex& z)const
{
	Complex* z2 = new Complex();
	z2->re = this->re - z.re;
	z2->img = this->img - z.img;
	return z2;
}
/*
*Nom_methode:operator-
*Parametres : -nb de type double
* Valeur de retour : Complexe*, un pointeur sur un objet complexe
* Description : Une surcharge de l'operateur - de la classe Complexe qui permet d'effectuer
*              la soustraction entre un double et un complex puis renvoie un pointeur 
               sur un nouveau objet complexe contenant le resultat
* NB : l'operande droite est un double    
*/

Complex* Complex::operator-(double nb)const
{
	Complex* z2 = new Complex();
	z2->re = this->re - nb;
	z2->img = this->img;
	return z2;
}

/*
*Nom_methode:operator*
* Parametres: - z reference d'un objet complexe
* Valeur de retour:un pointeur sur un objet complexe
* Description:Cette definition de l'operateur * de la classe Complexe fait la multiplication
*             entre deux nombres complexe (l'objet courant et celui passé en argument)
*             puis renvoie un pointeur qui sur un nouveau objet complexe contenant le resultat
*/
Complex* Complex::operator*(const Complex& z)const
{
	Complex* z2 = new Complex();
	z2->re = this->re * z.re - this->img * z.img;
	z2->img = this->re * z.img - this->img * z.re;
	return z2;
}
/*
*Nom_methode:operator*
*Parametres : -nb de type double
* Valeur de retour : Complexe*, un pointeur sur un objet complexe
* Description : Une surcharge de l'operateur * de la classe Complexe qui permet
*              la multiplication d'un double par un complex puis renvoie un pointeur
			   sur un nouveau objet complexe contenant le resultat
* NB : l'operande droite est un double
*/
Complex* Complex::operator*(double nb)const
{
	Complex* z2 = new Complex();
	z2->re = this->re * nb;
	z2->img = this->img * nb;
	return z2;
}
/*
*Nom_methode:operator/
* Parametres: - z reference d'un objet complexe
* Valeur de retour:un pointeur sur un objet complexe
* Description:Cette definition de l'operateur / de la classe Complexe fait la division
*             de deux nombres complexe (l'objet courant et celui passé en argument)
*             puis renvoie un pointeur qui sur un nouveau objet complexe contenant le resultat
* 
* (a+ib)/(c+id)=[(a+ib)*(c-id)]/(c^2+d^2) 
*/
Complex* Complex::operator/(const Complex& z) const
{
	//si z est le complex null alors la division est impossble
	if (z.re == 0 && z.img == 0) return nullptr;
	Complex *z2 =*this*z.conjugue();//(a+ib)*(c-id)
	double denom = pow(z.re, 2) + pow(z.img, 2);//(c^2+d^2) 
	z2->re /= denom;
	z2->img /= denom;
	return z2;

}
/*
*Nom_methode:operator/
*Parametres : -nb de type double
* Valeur de retour : Complexe*, un pointeur sur un objet complexe
* Description : Une surcharge de l'operateur / de la classe Complexe qui permet
*              la division d'un complex  par un double puis renvoie un pointeur
			   sur un nouveau objet complexe contenant le resultat
* NB : l'operande droite est un double
*/
Complex* Complex::operator/(double nb) const
{
	if (nb == 0) return nullptr;//le cas de division par 0
	Complex* z2 = new Complex();
	z2->re = this->re/nb;
	z2->img = this->img/nb;
	return z2;
}
/*
*Nom_methode:operator==
* Parametres: - z reference d'un objet complexe
* Valeur de retour: booleen
* Description:Cette definition de l'operateur / de la classe Complexe fait la comparaison
*             de deux nombres complexe (l'objet courant et celui passé en argument)
*             
*
* 
*/
bool Complex::operator==(const Complex& z)const
{
	return this->re==z.re && this->img==z.img;
}
/*
*Nom_methode:operator==
*Parametres : -nb de type double
* Valeur de retour :un booleen
* Description : Une surcharge de l'operateur == de la classe Complexe qui permet
*              la comparaison entre double et complex
* NB : l'operande droite est un double
*/
bool Complex::operator==(double nb)const
{
	return this->re == nb && this->img == 0 ;
}
/********************************************************Fonctions hors de la class ******************************************/

/*
*Nom_methode:operator+
*Parametres : -nb de type double
*            - z: la reference d'un objet complexe
* Valeur de retour : Complexe*, un pointeur sur un objet complexe
* Description : represente une  surcharge de l'operateur +  qui permet
*              l'addition d'un double et un complex puis renvoie un pointeur
			   sur un nouveau objet complexe contenant le resultat
* NB : l'operande gauche est un double
*/
Complex* operator+(double nb, const Complex& z)
{
	
	return z+nb;	
}
/*
*Nom_methode:operator-
*Parametres : -nb de type double
*            - z: la reference d'un objet complexe
* Valeur de retour : Complexe*, un pointeur sur un objet complexe
* Description :represente une  surcharge de l'operateur -  qui permet
*              la soustraction entre un double et un complex puis renvoie un pointeur
			   sur un nouveau objet complexe contenant le resultat
* NB : l'operande gauche est un double
*/
Complex* operator-(double nb, const Complex& z)
{
	Complex* z2 = new Complex(nb,0);//on cree un new complex temporaire avec nb puisque la soustraction n'est pas commutative
	Complex *z3 = *z2 - z  ;//puis faire la soustraction de deux complex
	delete z2;//on supprime l'objet temporaire
	return z3;
}
/*
*Nom_methode:operator*
*Parametres : -nb de type double
*            - z: la reference d'un objet complexe
* Valeur de retour : Complexe*, un pointeur sur un objet complexe
* Description : represente une  surcharge de l'operateur *  qui permet
*              la multiplication d'un double par un complex puis renvoie un pointeur
			   sur un nouveau objet complexe contenant le resultat
* NB : l'operande gauche est un double
*/
Complex* operator*(double nb, const Complex& z)
{
	
	return z*nb;//multiplication est commutative
}
/*
*Nom_methode:operator/
*Parametres : -nb de type double
*            - z: la reference d'un objet complexe
* Valeur de retour : Complexe*, un pointeur sur un objet complexe
* Description : represente une  surcharge de l'operateur / qui permet
*              la division d'un double par un complex puis renvoie un pointeur
			   sur un nouveau objet complexe contenant le resultat
* NB : l'operande gauche est un double
*/
Complex* operator/(double nb, const Complex& z)
{
	
	
	Complex* z2 = new Complex(nb,0);
	Complex* z3 = *z2 / z;
	delete z2;
	return z3;
}
/*
*Nom_methode:operator==
*Parametres : -nb de type double
*            - z: la reference d'un objet complexe
* Valeur de retour : un booleen
* Description : represente une  surcharge de l'operateur == qui permet
*              la comparaison entre un double et un complex 
* NB : l'operande gauche est un double
*/
bool operator==(double nb, const Complex& z)
{ 
	return z==nb;
}
