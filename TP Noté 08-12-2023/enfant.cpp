//GALAAD MARTINEAUX
//BUT1-INFO-TP1K
#include "cadeau.h"
#include "enfant.h"

Enfant::Enfant(const string &n){
	_nom=n;
}
string Enfant::nom()const{
	return _nom;
}

void Enfant::affiche() {
	if (_sac.size() == 0)
		cout << _nom << " n'a pas encore de cadeaux." << endl;
	else {
		cout << _nom << " a pour cadeaux:" << endl; 
		for (size_t i = 0; i < _sac.size(); ++i)
			cout << "\t" << _sac[i].getDesc() << endl;
	}
}

void Enfant::recoitCadeau(Cadeau &cadeau) {
	_sac.push_back(cadeau);
}

bool Enfant::possede(Cadeau &cadeau) {
	bool cadeauDejaObtenu = false;
	for (size_t i = 0; i < _sac.size() && !cadeauDejaObtenu; ++i)
		cadeauDejaObtenu = _sac[i].memeCadeau(cadeau);
	return cadeauDejaObtenu;
}

size_t Enfant::combienDeCadeaux() {
	return _sac.size();
}