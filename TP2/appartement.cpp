#include "appartement.h"

//Transforme une chaine de caractère en int strictement positif.
int toInt(const char* index) {
	std::string temp = index;
	if (temp.size() == 0)
		return -1;
	int result = 0;	

	for (size_t i = temp.size()-1; i < temp.size(); --i)
	{
		if (temp[i] < '0' || temp[i] > '9') {
			return -1;
		}
		result += (temp[i] - '0') * std::pow(10, temp.size()-1-i);
	}
	return result;
}

uint32_t Piece::surface() {
	return taille.largeur * taille.longueur;
}

/*
-----------------------------------------------
	CLASSE:	PIECE
-----------------------------------------------
*/

//Constructeur vide
Piece::Piece() {
	taille.largeur = 3;
	taille.longueur = 4;
	nom = "piecevide";
}

//Constructeur avec arguments (Largeur (en mètres), longueur (en mètres), nom (minuscule, sans accents.))
Piece::Piece(int largeur, int longueur, string nomPiece) {

	//Déclenche une exception si la largeur ou longueur fournie est negative.
	if (largeur < 0 || longueur < 0) {
		throw invalid_argument("Largeur ou longueur negative.");
	}

	//Vérifie si la longueur est bien supérieure à la largeur, et permute si besoin
	if (longueur < largeur) {
		taille.largeur = longueur;
		taille.longueur = largeur;
	} else {
		taille.largeur = largeur;
		taille.longueur = longueur;
	}

	//Mets en minuscules chaque caractère du nom envoyé par l'utilisateur et l'assigne
	//au nom de la pièce.
	for (size_t i = 0; i < nomPiece.size(); ++i)
		nom.push_back(tolower(nomPiece[i]));
}

void Piece::afficher() {
	cout	<< endl << "Piece '" << nom << "':" << endl
			<< "\tLongueur: " << taille.longueur << "\tLargeur: "
			<< taille.largeur << endl; 
}

void Piece::saisir() {
	string input;
	for (uint8_t i = 0; i < 3; ++i) {
		string temp;
		switch (i)
		{
			case 0:
				temp = "a largeur";
				break;
			
			case 1:
				temp = "a longueur";
				break;
			
			case 2:
				temp = "e nom";
				break;
			default: break;
		}

		cout << "Veuillez saisir un nombre positif representant l" <<
		temp << " de la piece." << endl;

		while (!(cin >> input) || ( i < 2 || toInt(input.c_str()) == -1)) {
			cout << "Saisie invalide, veuillez recommencer." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
		}
		if (i == 0)
			taille.largeur = toInt(input.c_str());
		else if (i == 1)
			taille.longueur = toInt(input.c_str());
		else if (i == 2)
			for (size_t i = 0; i < input.size(); ++i)
				nom.push_back(tolower(input[i]));
	}
	
}



bool Piece::plusGrande(Piece &autre) {
	return (surface() > autre.surface());
}

uint2 Piece::obtenirTaille() {
	return taille;
}

uint32_t surface(Piece &piece) {
	return piece.obtenirTaille().largeur * piece.obtenirTaille().longueur;
}

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

	if (maSurface < autreSurface)
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