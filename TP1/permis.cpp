#include <string>
#include <iostream>
#include <stdexcept>
#include "permis.h"

using namespace std;


// constructeur vide
Permis::Permis(){
	cout << "Construction d'un permis" << endl;
	_nom = "inconnu";
	_prenom = "inconnu";
	_date = "non renseigne";
	_numero = "00000";
	_nbpoints = MAXP;
}


// constructeur
Permis::Permis(const string& nom, const string& prenom, const string& date, const string& numero, int points){
	cout << "Construction d'un permis" << endl;
	_nom = nom;
	_prenom = prenom;
	_date = date;
	_numero = numero;
	_nbpoints = points;
	if (_nbpoints > MAXP)
		throw invalid_argument("Invalid argument");
}

// affichage du permis
void Permis::affiche() const {
	cout << "Informations sur le permis de " << _prenom << " "<< _nom << " :" << endl;
	cout << _numero << endl;
	cout << _date << endl;
	cout << "Nombre de points : "<< _nbpoints << endl;
}

// nombre de points
int Permis::getNbpoints() const {
	return _nbpoints;
}

// retrait de points
void Permis::retraitPoints(int nbpointsretires) {
	if (_nbpoints < MINP + nbpointsretires) {
		_nbpoints = MINP;
	} else {
		_nbpoints -= nbpointsretires;
	}
}

// nom
string Permis::getNom() const {
	return _nom;
}

// ajout d'un points
void Permis::incrementePoints() {
	if (_nbpoints + 1 > MAXP) {
		throw invalid_argument("Invalid argument");
	}

	_nbpoints ++;
}

// retrait d'un points
void Permis::decrementePoints() {
	if (_nbpoints - 1 < MINP) {
		throw invalid_argument("Invalid argument");
	}

	_nbpoints --;
}

void ajoutePoints(Permis& permis, int nbPoints) {
	if (permis.getNbpoints() + nbPoints > MAXP) {
		while (permis.getNbpoints() != MAXP)
			permis.incrementePoints();
	}
	else if (permis.getNbpoints() + nbPoints < MINP) {
		while (permis.getNbpoints() != MINP)
			permis.decrementePoints();
	} else {
		int pointAvantModification = permis.getNbpoints();
		while (permis.getNbpoints() != pointAvantModification + nbPoints) {
			if (nbPoints < 0)
				permis.decrementePoints();
			else
				permis.incrementePoints();
		}
	}
}

Permis::~Permis() {
	cout << "Destruction du Permis" << endl;
	affiche();
}

bool Permis::compare(Permis& other) {
	return ( _nbpoints == other._nbpoints );
}