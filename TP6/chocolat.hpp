#include "constants.hpp"
#include <string>
#include <ctime>
#include <random>
#include <iostream>
using std::string;

class Chocolat{
	private:
		int _nature; // 0 noir, 1 blanc, 2 lait
		int _poids; // poids du chocolat
		string _natureVersString(int n)const;// retourne la String équivalente à la nature
		int _stringVersNature(string)const;// retourne la nature équivalente à la string
	public:
		Chocolat(const string = NOIR, const int = POIDS);
		Chocolat(const int);

		void display(); //Affiche nature et poids du chocolat
		int lePoids(); //Retourne le poids
		string laNature() const; //retourne la nature

		bool operator<(Chocolat &);
};

std::ostream& operator<<(std::ostream &, Chocolat &);