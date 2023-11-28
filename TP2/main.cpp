//Galaad MARTINEAUX - BUT1 TP1K
#include "appartement.h"

int main() {

	vector<Piece> pieces;

	/*
	----------------
		PARTIE 1
	----------------
	*/
	try {
		//Test du constructeur vide
		pieces.push_back(Piece());
		//Test du constructeur incorrectement utilisé
		pieces.push_back(Piece(13, 12, "SALON"));
		//Test de la fonction saisir
		pieces.push_back(Piece());
		//Test de l'exception
		pieces.push_back(Piece(0,-1, "Salle qui de toute façon n'existera pas."));
	}	catch (invalid_argument e) {
		cerr << e.what() << endl;
		cout << "Test des constructeurs, et de l'exception passe" << endl;
	}

	pieces[2].saisir();

	//Test des affichages
	for (size_t i = 0; i < pieces.size(); ++i)
		pieces[i].afficher();

	//Test de la surface (interne, puis externe)
	if (pieces[1].surface() == 156)
		cout << "Test de surface interne reussi." << endl;
	else
		cout << "Test de surface interne rate." << endl;

	if (surface(pieces[1]) == 156)
		cout << "Test de surface externe reussi." << endl;
	else
		cout << "Test de surface externe rate." << endl;

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

	//Test de nbPiece
	bool nbPieceOK = (apparts[1].nbPieces() == 1 && apparts[0].nbPieces() == 0);
	//On evite de faire des tests qui dépendent de nbPieces.
	if (nbPieceOK) {
		cout << "Test de nbPieces passe" << endl;

		//Test de ajoutPiece
		apparts[1].ajoutPiece(pieces[1]);
		if (apparts[1].nbPieces() == 2)
			cout << "Test de ajoutPiece passe" << endl;
		else
			cout << "Test de ajoutPiece rate" << endl;

		//Test de retraitPiece
		apparts[1].retraitPiece(1);
		if (apparts[1].nbPieces() == 1)
			cout << "Test de retraitPiece passe" << endl;
		else
			cout << "Test de retraitPiece rate" << endl;

	} else {
		cout	<< "Test de nbPieces rate" << endl
				<< "Tests de Appartement::ajoutPiece()"
				<< ", Appartement::retraitPiece non fait"
				<< " puisque dependant de Appartement::nbPiece()."
				<< endl << endl;
	}

	//Test de Appartement::surface
	if (apparts[1].surface() == 156) {
		apparts[1].ajoutPiece(pieces[1]);
		if (apparts[1].surface() == 156+156)
			cout << "Test Appartement::surface() reussi" << endl;
		else 
			cout << "Test Appartement::surface() rate" << endl;
	}

	//Test de Appartement::compare()
	if (apparts[1].compare(apparts[0]) == -1)
		cout << "Test de Appartement::compare() reussi" << endl;
	else
		cout << "Test de Appartement::compare() rate" << endl;

	//Test de Appartement::plusGrandePiece()
	Piece temp(900, 800, "Espace imaginaire");
	apparts[1].ajoutPiece(temp);
	if (apparts[1].plusGrandePiece() == 2)
		cout << "Test de Appartement::plusGrandePiece() reussi." << endl;
	else
		cout << "Test de Appartement::plusGrandePiece() rate." << endl;


	/*
	----------------
		PARTIE 3
	----------------
	*/
	apparts[1].retraitPiece(1);
	if (apparts[1].valeur() == apparts[1].surface() * ZONE_PRIX[0])
		cout << "Test de Appartement::valeur() reussi" << endl;
	else
		cout << "Test de Appartement::valeur() rate" << endl;
	
	if (	
			apparts[1].comparePrix(apparts[2]) == 1
			&& apparts[2].comparePrix(apparts[1]) == -1
			&& apparts[0].comparePrix(apparts[0]) == 0
		)
		cout << "Test de Appartement::comparePrix() reussi" << endl;
	else
		cout << "Test de Appartement::comparePrix() rate" << endl;
	


	return 0;
}
/*

*/