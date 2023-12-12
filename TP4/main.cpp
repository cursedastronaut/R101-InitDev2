#include <cstdlib>
#include <iostream>

#include "rat.h"

using namespace std;

int main(){
	cout << "----- Tests automatiques -----------------------------------------------" << endl;
	if (testConstructeurVideEtGetters()) cout << "Constructeur vide et getters ok" << endl;
	if (testsConstructeurParamEtGetters()) cout << "Constructeur avec parametres et getters ok" << endl;
	if (testOperateurs()) cout << "Operateurs ok" << endl;
	cout << "------------------------------------------------------------------------" << endl;

	cout << "----- Programme principal ----------------------------------------------" << endl;
	cout << "Veuillez saisir le numérateur et le dénominateur" << endl;
	int n, d; cin >> n >> d;
	try {
		Rationnel r(n,d);
		Rationnel r2(n*2, d*2);
		Rationnel r3(r2+r);
		cout << "Voici votre rationnel réduit : ";
		cout << r << endl;
		produitMaximumVecteurRationnel();

	}catch (const invalid_argument &e) {
		cout << "Erreur : " << e.what() << endl;
	}
	cout << "------------------------------------------------------------------------" << endl;
	return 0;
}
