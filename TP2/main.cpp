#include "appartement.h"

int main() {

	vector<Piece> pieces;

	/*
	----------------
		PARTIE 1
	----------------
	*/

	//Test du constructeur vide
	pieces.push_back(Piece());
	//Test du constructeur incorrectement utilisé
	pieces.push_back(Piece(13, 12, "SALON"));
	//Test de la fonction saisir
	pieces.push_back(Piece());

	pieces[2].saisir();

	//Test des affichages
	for (size_t i = 0; i < pieces.size(); ++i)
		pieces[i].afficher();

	//Test de la surface (interne, puis externe)
	pieces[1].surface();
	surface(pieces[1]);

	//Test de plusGrande
	if (pieces[1].plusGrande(pieces[0]))
		cout << "Test de plusGrande passe" << endl;
	else
		cout << "Test de plus grande RATE" << endl;
	
	/*
	----------------
		PARTIE 2
	----------------
	*/

	


	return 0;
}