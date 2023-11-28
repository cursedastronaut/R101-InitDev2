#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <vector>
using namespace std;
#define ZONE_PRIX (vector<uint32_t>){2500, 3100, 3500, 4150, 4500}
static const vector<uint32_t> test = {2500, 3100, 3500, 4150, 4500};

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