// projet2.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
using namespace std;
#include "Complex.h"
int main()
{
	Complex z1(4,4);
	z1.Afficher();
	Complex* z2 =  8/z1;
	z2->Afficher();
	bool t = *z2 == 8;
	cout << t << endl;
	
	
}


