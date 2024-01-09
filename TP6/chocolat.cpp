#include "chocolat.hpp"

string Chocolat::_natureVersString(int n)const {  // retourne la String équivalente à la nature

	if(n !=0 && n !=1 && n!=2) throw string ("nature incorrecte");

	string s;
	switch(n){
		case 0: s="noir";break;
		case 1: s="blanc";break;
		case 2: s="lait";break;
	}
	return s;
}

int Chocolat::_stringVersNature(string n)const{ // retourne la nature équivalente à la string
	if(n != NOIR && n != BLANC && n != LAIT) throw string ("nature incorrecte");
	int nature;
	if(n==NOIR) nature = CNOIR;
	else if(n==BLANC) nature = CBLANC;
	else nature = CLAIT;
	return nature;
}


Chocolat::Chocolat(const string nature, const int poids) {
	_nature = _stringVersNature(nature);
	_poids = poids;
}

Chocolat::Chocolat(const int poids) {
	_poids = poids;
	_nature = rand() % MAX_NATURE;
}

void Chocolat::display() {
	using std::cout, std::endl; // It's a good practice to do this. Requires C++17
	
	cout << "Nature: "	<< _natureVersString(_nature) << " ; ";
	cout << "Poids: "	<< _poids << 'g' << endl;
}

int Chocolat::lePoids() {
	return _poids;
}

string Chocolat::laNature() const {
	return _natureVersString(_nature);
}


std::ostream& operator<<(std::ostream &out, Chocolat &chocolat) {
	using std::cout, std::endl; // It's a good practice to do this. Requires C++17

	out << "Nature: "	<< chocolat.laNature() << " ; ";
	out << "Poids: "	<< chocolat.lePoids() << 'g' << endl;

	return out;
}

bool Chocolat::operator<(Chocolat &output) {
	return _poids < output.lePoids();
}

