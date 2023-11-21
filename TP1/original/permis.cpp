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
