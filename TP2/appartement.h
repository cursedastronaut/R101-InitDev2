#pragma once
#include "piece.h"
using namespace std;

uint32_t surface(Piece &piece);


class Appartement {
	public:
		//Constructeur vide
		Appartement();
		//Constructeur qui construit un appartement avec une seule pièce passée en paramètre, et une adresse passée en paramètre.
		Appartement(Piece &piece, string adresse, uint8_t zone = 0);
		//Affiche les différentes pièces d'un appartement.
		void afficher();
		//Ajoute une pièce passée en paramètres.
		void ajoutPiece(Piece &pieceFournie);
		//Supprime la pièce à l'indice fourni, et renvoie une copie.
		Piece retraitPiece(size_t indice);
		//Renvoie le nombre de pièces d'un appartement
		uint32_t nbPieces();
		//Renvoie la surface totale d'un appartement
		uint32_t surface();
		//Renvoie -1 si l'appartement cible a une surface plus petite.
		//Renvoie  0 si l'appartement cible a une surface égale.
		//Renvoie  1 si l'appartement cible a une surface plus grande.
		int8_t compare(Appartement &autre);
		//Renvoie l'indice de la pièce de plus grande surface (-1 si aucune Piece dans l'appartement).
		int plusGrandePiece();
		//Renvoie la valeur estimée de l'appartement
		uint32_t valeur();
		//Renvoie -1 si l'appartement cible a un prix plus petit que celui passé en paramètre.
		//Renvoie  0 si l'appartement cible a un prix égal que celui passé en paramètre.
		//Renvoie  1 si l'appartement cible a un prix plus grand que celui passé en paramètre.
		int8_t comparePrix(Appartement &autre);

	private:
		//Adresse de l'appartement, pas de norme particulière
		string adresse;
		//Toutes les pièces d'un appartement.
		vector<Piece> pieces;
		//Zone d'un appartement
		uint8_t _zone;
};