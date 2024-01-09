#include "chocolat.hpp"
#include <vector>
using std::string, std::vector, std::ostream;

class BoiteChoco{
	string _nom; // nom de la boite
	vector<Chocolat> _contenu;   // les Chocolats contenus dans la boite
public :
	BoiteChoco(const string = CLASSIQUE, const uint64_t = 0);

	void affiche(ostream &) const;
	void ajoutChocolat(const Chocolat &);
	void operator+=(const Chocolat &);
	bool mangeChocolat(Chocolat &);
	string leNom();
	int lePoids();
	void retire();
};

ostream& operator<<(ostream &, BoiteChoco &);