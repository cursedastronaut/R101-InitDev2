//Galaad MARTINEAUX - BUT1 TP1K
#include "piece.h"
//Transforme une chaine de caractère en int strictement positif.
int toInt(const char* index) {
	std::string temp = index;
	if (temp.size() == 0) {
        cout << "mama";
		return -1;
    }
	int result = 0;	

	for (size_t i = temp.size()-1; i < temp.size(); --i)
	{
		if (temp[i] < '0' || temp[i] > '9') {
            cout << "baguette" << endl;
			return -1;
		}
		result += (temp[i] - '0') * std::pow(10, temp.size()-1-i);
	}
	return result;
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
				temp = "nombre positif representant la largeur";
				break;
			
			case 1:
				temp = "nombre positif representant la longueur";
				break;
			
			case 2:
				temp = "nom representant le nom";
				break;
			default: break;
		}

		cout << "Veuillez saisir un " <<
		temp << " de la piece." << endl;

		while (!(cin >> input) || ( i < 2 && toInt(input.c_str()) == -1)) {
			cout << "Saisie invalide, veuillez recommencer." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
		}
		if (i == 0) {
			taille.largeur = toInt(input.c_str());
        } else if (i == 1) {
        	taille.longueur = toInt(input.c_str());
        } else if (i == 2) {
            nom = "";
			for (size_t i = 0; i < input.size(); ++i)
				nom.push_back(tolower(input[i]));
        }
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

uint32_t Piece::surface() {
	return taille.largeur * taille.longueur;
}