//GALAAD MARTINEAUX
//BUT1-INFO-TP1K
#include "cadeau.h"
#include "enfant.h"
#include "pereNoel.h"

PereNoel::PereNoel() {
	size_t tempSize = JEUX.size();
	for (size_t i = 0; i < tempSize; ++i)
		_hotte.push_back(Cadeau(JEUX[i]));
}


//J'ai demandé à la personne nous surveillant si la fonction
//devrait retourner faux si l'enfant a déjà le cadeau, et elle
//m'a dit oui.
bool PereNoel::offreCadeau(Enfant &enfant) {
	//Si la hotte est vide, retourner faux (car incapable)
	if (_hotte.size() == 0)
		return false;

	//Si l'enfant ne possède pas déjà le dernier cadeau de la hotte
	//lui offrir ce dit cadeau, le retirer de la hotte, et retourner vrai.
	if (!enfant.possede(_hotte[_hotte.size()-1])) {
		enfant.recoitCadeau(_hotte[_hotte.size()-1]);
		_hotte.pop_back();
	    return true;
	}
    return false;
}