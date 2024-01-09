#include "boitechoco.hpp"

using std::string;

BoiteChoco::BoiteChoco(const string nom, const uint64_t nombre) {
	_nom = nom;
	
	for (uint64_t i = 0; i < nombre; ++i)
	_contenu.push_back(Chocolat(POIDS_BOITE));
}

void BoiteChoco::affiche(ostream &out) const {
	using std::endl;
	out << "Nom: " << _nom << endl;
	out << "Nombre: " << _contenu.size() << endl;
	for (size_t i = 0; i < _contenu.size(); ++i)
		out << "Nature " << i << _contenu[i].laNature() << endl;
	
}

ostream& operator<<(ostream &out, BoiteChoco &bc) {
	bc.affiche(out);
	return out;
}

void BoiteChoco::ajoutChocolat(const Chocolat &chocolat) {
	_contenu.push_back(chocolat);
}

void BoiteChoco::operator+=(const Chocolat &chocolat) {
	_contenu.push_back(chocolat);
}

bool BoiteChoco::mangeChocolat(Chocolat &chocolat) {
	bool out = false;

	if (_contenu.size() > 0) {
		chocolat = _contenu[_contenu.size()-1];
		_contenu.pop_back();
		out = true;
	}

	return out;
	/*
	Here is why you should not declare a boolean in this
	function, then return it at the end.
	It allocates more memory than needed in a function that
	should not allocate memory at all. It also returns a
	registered byte in RAM while returning true or false
	directly in the if else statement would return what
	is already loaded in the stack.
	The "more readable version" (which, by being further
	from normal-english, is for many less readable) is
	not only slower (by returning a registered byte that
	is not in stack) but is also taking more memory.
	*/
}

string BoiteChoco::leNom() {
	return _nom;	
}

int BoiteChoco::lePoids() {
	int sum = 0;
	for (size_t i = 0; i < _contenu.size(); ++i)
		sum += _contenu[i].lePoids();
	return sum;
}

void BoiteChoco::retire() {
	srand(time(0));

	if (!_contenu.size())
		throw std::out_of_range("contenu est vide");

	size_t index = rand() % _contenu.size() - 1;
	for (size_t i = index; i < _contenu.size() - 1; ++i)
		_contenu[i] = _contenu[i+1];
	_contenu.pop_back();
}

