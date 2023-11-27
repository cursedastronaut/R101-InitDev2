#pragma once
#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <vector>
using namespace std;


struct uint2 {
	uint32_t longueur;
	uint32_t largeur;
};

class Piece {
	public:
		//Constructeur vide
		Piece();
		//Constructeur avec arguments (Largeur (en mètres), longueur (en mètres), nom (minuscule, sans accents.))
		Piece(int largeur, int longueur, string nom);

		//Permets d'afficher les caractéristiques de la pièce.
		void afficher();
		//Permets de demander à l'utilisateur les caractéristiques de la pièce.
		void saisir();
		//Renvoie la superficie d'une pièce
		uint32_t surface();
		//Renvoie true si la superficie de la cible est plus grande que celle de la pièce passée en paramètre.
		bool plusGrande(Piece &autre);
		//Renvoie la taille
		uint2 obtenirTaille();
	private:
		//Taille de la pièce (longueur x largeur)
		uint2 taille;
		//Nom de la pièce, en minuscule (Ex: "sejour")
		string nom;
};

uint32_t surface(Piece &piece);

class Appartement {
	public:
		//Constructeur vide
		Appartement();
		//Constructeur qui construit un appartement avec une seule pièce passée en paramètre, et une adresse passée en paramètre.
		Appartement(Piece &piece, string adresse);
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
		int8_t compare(Appartement& autre);
		//Renvoie l'indice de la pièce de plus grande surface (-1 si aucune Piece dans l'appartement).
		int plusGrandePiece();

	private:
		//Adresse de l'appartement, pas de norme particulière
		string adresse;
		//Toutes les pièces d'un appartement.
		vector<Piece> pieces;
};