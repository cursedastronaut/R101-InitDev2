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
	if (_hotte.size() == 0)
		return false;

	if (!enfant.possede(_hotte[_hotte.size()-1])) {
		enfant.recoitCadeau(_hotte[_hotte.size()-1]);
		_hotte.pop_back();
	    return true;
	}
    return false;
}