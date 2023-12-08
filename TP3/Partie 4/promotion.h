/// TP recherche, R101-2 2023-2024
/// promotion.h

#ifndef PROMOTION_H_INCLUDED
#define PROMOTION_H_INCLUDED

#include <iostream>
#include <vector>
#include "etudiant.h"
using namespace std;

class Promotion
{
private :
	vector<Etudiant> _promo;
	string _nom;

public:
	Promotion() {}; /// constructeur vide d�fini inline
	void init(const string & ficEtudiants); /// lire fichier
	void afficher()const; /// afficher toute la promo
	void afficherBornes(int deb, int fin) const; /// afficher la promo entre indices d�b et fin
	Etudiant getEtud(int ind) const; /// retourner l'�tudiant en position ind du vecteur
    int rechercheEtudiant(const string &groupe, const string &nom);
    void afficher(int);
};

#endif // PROMOTION_H_INCLUDED

