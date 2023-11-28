#include "appartement.h"





/*
-----------------------------------------------
	CLASSE:	APPARTEMENT
-----------------------------------------------
*/

Appartement::Appartement() {
	adresse = "1 rue Joliot-Curie 91400 Orsay";
}

Appartement::Appartement(Piece &piece, string adresseFournie, uint8_t zone) {
	adresse = adresseFournie;
	pieces.push_back(piece);
	_zone = zone;
}

void Appartement::afficher() {
	cout	<< endl << "Appartement a l'adresse : " << adresse << endl;
	for (size_t i = 0; i < pieces.size(); ++i)
		pieces[i].afficher(); 
}

void Appartement::ajoutPiece(Piece &pieceFournie) {
	pieces.push_back(pieceFournie);
}

Piece Appartement::retraitPiece(size_t indice) {
	Piece temp;
	if (indice >= pieces.size())
		throw invalid_argument("Indice superieur au nombre de pieces");
	
	temp = pieces[indice];
	if (pieces.size() != 1) 
		pieces[indice] = pieces[pieces.size()-1];
	pieces.pop_back();
	return temp;
}

uint32_t Appartement::nbPieces() {
	return pieces.size();
}

uint32_t Appartement::surface() {
	uint32_t temp = 0;
	for (size_t i = 0; i < pieces.size(); ++i)
		temp += pieces[i].surface();
	return temp;
}

int8_t Appartement::compare(Appartement& autre) {
	//Permet de ne pas rappeler les fonctions à chaque test.
	uint32_t maSurface = surface(), autreSurface = autre.surface();

	if (maSurface > autreSurface)
		return -1;
	else if (maSurface == autreSurface)
		return 0;
	else //if (maSurface > autreSurface), ça n'a pas d'intérêt de refaire le test.
		return 1;
}

int Appartement::plusGrandePiece() {
	if (pieces.size() == 0)
		return -1;
	
	size_t plusGrandeSurface = 0;
	for (size_t i = 0; i < pieces.size(); ++i) {
		if (pieces[i].surface() > pieces[plusGrandeSurface].surface())
			plusGrandeSurface = i;
	}

	return (int)plusGrandeSurface;
}

uint32_t Appartement::valeur() {
	return surface() * ZONE_PRIX[_zone];
}

int8_t Appartement::comparePrix(Appartement &autre) {
	//Permet de ne pas rappeler les fonctions à chaque test.
	uint32_t maValeur = valeur(), autreValeur = autre.valeur();
	if (maValeur < autreValeur)
		return -1;
	else if (maValeur == autreValeur)
		return 0;
	else //if (maValeur > autreValeur), ça n'a pas d'intérêt de refaire le test.
		return 1;
}