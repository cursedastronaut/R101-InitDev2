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

	vector<Appartement> apparts;
	//Test du constructeur vide.
	apparts.push_back(Appartement());
	//Test du constructeur plein
	apparts.push_back(Appartement(pieces[1], "1 rue des reves 91400 Orsay"));
	//Test du constructeur plein avec une zone précisée
	apparts.push_back(Appartement(pieces[1], "1 rue d'Andromede 91400 Orsay", 1));

	for (size_t i = 0; i < apparts.size(); ++i) {
		apparts[i].afficher();
	}

	apparts[1].ajoutPiece(pieces[2]);
	apparts[1].retraitPiece(1);
	apparts[1].nbPieces();
	apparts[1].surface();
	apparts[1].compare(apparts[0]);
	apparts[1].plusGrandePiece();

	/*
	----------------
		PARTIE 3
	----------------
	*/

	apparts[1].valeur();
	apparts[1].comparePrix(apparts[2]);


	return 0;
}