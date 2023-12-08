//GALAAD MARTINEAUX
//BUT1-INFO-TP1K
#include "cadeau.h"


string Cadeau::getDesc() const{
	return _description;
}	 

//Retourne vrai si deux cadeaux ont une description identiques.
bool Cadeau::memeCadeau(Cadeau &cadeau) {
	return _description == cadeau._description;
}