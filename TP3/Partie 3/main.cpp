#include <iostream>
#include "appartement.h"

int main(int argc, char** argv) {
	Appartement r1;
	for (uint8_t i = 0; i < 10; ++i)
		r1.ajoutPiece(Piece(3, 3, string("chambre") + to_string(i)));
	
	if (r1.recherche("chambre5") == 5)
		cout << "Test de Appartement::recherche reussi" << endl;
	else
		cout << "Test de Appartement::recherche rate" << endl;

	Appartement r2;
	for (uint8_t i = 0; i < 10; ++i) {
        for (uint8_t j = 0; i == 5 && j < 5; ++j)
		    r2.ajoutPiece(Piece(3, 3, string("chambre") + to_string(i)));
	    r2.ajoutPiece(Piece(3, 3, string("chambre") + to_string(i)));

    }

    if (r2.recherchePremier("chambre5") == 5)
		cout << "Test de Appartement::recherchePremier reussi" << endl;
	else
		cout << "Test de Appartement::recherchePremier rate" << r2.recherchePremier("chambre5") << endl;


    return 0;
}