#include <iostream>
#include <stdexcept>
#include "rat.h"
using namespace std;


Rationnel::Rationnel(int num, int den) {
	if (den==0) throw invalid_argument("Denominateur nul");
	if (den > 0) {
		_num = num;
		_den = den;
	} else {
		_num = -num;
		_den = -den;
	}
	_reduire();
}

void Rationnel::_reduire() {
	int facteur = pgcd(_num, _den); // facteur commun
	_num /= facteur;
	_den /= facteur;
}

void Rationnel::afficher() const {
	cout << _num << '/' << _den;
}

int Rationnel::getNum() const {
	return _num;
}

int Rationnel::getDen() const {
	return _den;
}

int pgcd(int a, int b) {		// utilise pgcdRecursif
	int a2 = (a > 0) ? a : -a;
	if (a2 < b) {
		int temp = a2;
		a2 = b;
		b = temp;
	}
	return pgcdRecursif(a2, b);
}


int pgcdRecursif(int a, int b) {		// utilise l'algorithme d'Euclide
	return (b==0) ? a : pgcdRecursif(b, a%b);
}


// Fonctions de test
bool testConstructeurVideEtGetters() {
	bool ok = true;
	Rationnel r;
	if (!(r.getNum() == 0)) {
		ok = false;
		cout << "Erreur dans le constructeur vide ou getNum : le numerateur vaut " << r.getNum() << " (attendu : 0)" << endl;
	}
	if (!(r.getDen() == 1)) {
		ok = false;
		cout << "Erreur dans le constructeur vide ou getDen : le denominateur vaut " << r.getDen() << " (attendu : 1)" << endl;
	}
	return ok;
}

bool testConstructeurParamEtGetters(int n, int d, int nres, int dres, bool exc) {
	bool ok = true;
	if (exc) {
		try {
			Rationnel r(n, d);
			ok = false;
			cout << "Erreur dans le constructeur avec parametres : une exception aurait du etre lancee" << endl;
		} catch (const invalid_argument &) { }
	} else {
		try {
			Rationnel r(n,d);
			if (!(r.getNum() == nres)) {
				ok = false;
				cout << "Erreur dans le constructeur avec parametres ou getNum : le numerateur vaut " << r.getNum() << " (attendu : " << nres << ")" << endl;
			}
			if (!(r.getDen() == dres)) {
				ok = false;
				cout << "Erreur dans le constructeur avec parametres ou getDen : le denominateur vaut " << r.getDen() << " (attendu : " << dres << ")" << endl;
			}
		} catch (const invalid_argument &e) {
			ok = false;
			cout << "Erreur dans le constructeur avec parametres : l'exception " << e.what() << " a ete lancee" << endl;
		}
	}
	return ok;
}

bool testsConstructeurParamEtGetters() {
	bool ok = true;
	ok = ok && testConstructeurParamEtGetters(0, 1, 0, 1, false);
	ok = ok && testConstructeurParamEtGetters(1, 2, 1, 2, false);
	ok = ok && testConstructeurParamEtGetters(-1, 2, -1, 2, false);
	ok = ok && testConstructeurParamEtGetters(1, -2, -1, 2, false);
	ok = ok && testConstructeurParamEtGetters(-1, -2, 1, 2, false);
	ok = ok && testConstructeurParamEtGetters(2, 4, 1, 2, false);
	ok = ok && testConstructeurParamEtGetters(1, 0, 1, 0, true);
	return ok;
}

bool testOperateurs() {
	Rationnel r1(6, 1);
	Rationnel r1bis(6, 1);
	Rationnel r2(8, 3);
	Rationnel r3(48, 3);
	Rationnel r4 = -(-r1);
	Rationnel r5(6*3+8, 1*3);
	Rationnel r6(6*3, 1);
	Rationnel r7(7, 1);
	
	bool ok = true;
	ok = ok && ((r1 * r2) == r3);		//operator*
	ok = ok && ((r1 * 3) == r6);		//operator* (int)
	ok = ok && (r1 == r1);				//operator==
	ok = ok && (r1 == r4);				//operator-
	ok = ok && (r1+r2 == r5);			//operator+
	ok = ok && (r1 < r3);				//operator<
	ok = ok && (r1 != r3);				//operator!=
	ok = ok && (r1 <= r1 && r1 <= r3);	//operator<=
	ok = ok && (++r1 == r7);			//operator++ (prefix)
	r1 = Rationnel(6, 1);
	ok = ok && (r1++ == r1bis);			//operator++ (postfix)
	return ok;
}

Rationnel Rationnel::operator*(Rationnel &other) {
	return Rationnel(_num * other._num, _den * other._den);
}

bool Rationnel::operator==(Rationnel &other) {
	return ((_num == other._num) && (_den == other._den));
}

Rationnel Rationnel::operator-() {
	return Rationnel(-_num, _den);
}


std::ostream& operator<<(std::ostream& out, Rationnel &r) {
	out << r.getNum() << '/' << r.getDen();
	return out;
}
bool Rationnel::operator<(Rationnel &other) {
	if (_den != other._den) {
		int facteurDenom = std::max(_den, other._den) / std::min(_den, other._den);
		if (std::max(_den, other._den) == _den)
			return other._num * facteurDenom < _num;
		else
			return _num * facteurDenom < other._num;
	} else {
		return _num < other._num;
	}
}

Rationnel Rationnel::operator+(Rationnel &other) {
	if (_den != other._den) {

		int facteurDenom = std::max(_den, other._den) / std::min(_den, other._den);
		if (std::max(_den, other._den) == _den)
			return Rationnel(other._num * facteurDenom + _num, _den);
		else
			return Rationnel(_num * facteurDenom + other._num, other._den);
	} else {
		return Rationnel(_num + other._num, _den);
	}
}

void Rationnel::saisir(istream & in){
	cout << "numerateur ?";
	in>> _num;
	do{
		cout << "denominateur ?";
		in >> _den;
	} while(_den == 0);
	if (_den < 0) {
		_num = -_num;
		_den = -_den;
	}
	_reduire();
}

void Rationnel::operator>>(istream & in) {
	saisir(in);
}

Rationnel Rationnel::operator*(int other) {
	return Rationnel(_num * other, _den);
}

Rationnel operator*(int entier, Rationnel &rat) {
	return Rationnel(rat.getNum() * entier, rat.getDen());
}

bool Rationnel::operator!=(Rationnel &other) {
	return !operator==(other);
}

bool Rationnel::operator<=(Rationnel &other) {
	return (operator<(other) || operator==(other));
}

Rationnel Rationnel::operator++() {
	_num+=_den;
	return *this;
}

Rationnel Rationnel::operator++(int) {
	Rationnel temp(*this);
	_num+=_den;
	return temp;
}

void produitMaximumVecteurRationnel() {
	vector<Rationnel> rat = {Rationnel(1,2), Rationnel(4,2), Rationnel(8,4)};
	Rationnel rprod = rat[0];
	for (size_t i = 1; i < rat.size(); ++i)
		rprod = rprod * rat[i]; //L'opérateur =* ne fait pas partie du test.
	cout << "Produit du vecteur de r (cense donner 2): " << rprod << endl;

	Rationnel rmax = rat[0];
	for (size_t i = 1; i < rat.size(); ++i)
		if (!(rmax < rat[i])) //L'opérateur > ne fait pas partie du test.
			rmax = rat[i]; 
	cout << "Max du vecteur de rationnels (cense donne 2): " << rmax << endl;
}