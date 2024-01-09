#include "magasin.hpp"
void testAuto(uint8_t partie);

int main(int argc, char* argv[]) {
	using std::cout, std::endl;
	srand(time(0));

	//Partie 1
	testAuto(0);

	//Partie 2
	testAuto(1);
	{
		Chocolat last;
		BoiteChoco boite;
		boite.ajoutChocolat(Chocolat(10));
		boite.ajoutChocolat(Chocolat(15));
		boite.ajoutChocolat(Chocolat(20));
		boite.ajoutChocolat(Chocolat(25));
		while (boite.mangeChocolat(last)) {
			cout << last.laNature() << ", ";
		}
		cout << endl;
	}



	return 0;
}

void testAuto(uint8_t partie) {
	using std::cout, std::endl;

	//I won't use a switch for clarity purposes.
	if (partie == 0) {
		std::vector<Chocolat> chocolats;
		chocolats.push_back(Chocolat("blanc",20));    // chocolat blanc de 20g
		chocolats.push_back(Chocolat());  // chocolat noir de 30g
		chocolats.push_back(Chocolat(10));  // chocolat de 10g, nature tirée au sort
		chocolats.push_back(Chocolat("blanc") ); // chocolat blanc de 30g
		if (chocolats[0].lePoids() == 20 && (chocolats[1].lePoids() == chocolats[3].lePoids() && chocolats[3].lePoids() == POIDS) && chocolats[2].lePoids() == 10)
			cout << "Test de Chocolat::lePoids passe." << endl;
		else
			cout << "Test de Chocolat::lePoids NON PASSE." << endl;

		if (chocolats[0].laNature() == "blanc" && chocolats[1].laNature() == "noir" && chocolats[3].laNature() == "blanc")
			cout << "Test de Chocolat::laNature passe." << endl;
		else
			cout << "Test de Chocolat::laNature NON PASSE." << endl;

		if (chocolats[2] < chocolats[0] && chocolats[0] < chocolats[1])
			cout << "Test de Chocolat::operator< passe." << endl;
		else
			cout << "Test de Chocolat::operator< NON PASSE." << endl;
	} else if (partie == 1) {
		{
			BoiteChoco boite;
			if (boite.leNom() == CLASSIQUE) {
				cout << "Test de BoiteChoco::BoiteChoco() passe" << endl;
				cout << "Test de BoiteChoco::leNom() passe" << endl;
			}
			else {
				cout << "Test de BoiteChoco::leNom() NON PASSE" << endl;
				cout << "Test de BoiteChoco::BoiteChoco() NON PASSE" << endl;
			}
			boite.ajoutChocolat(Chocolat(5));
			if (boite.lePoids() == 5) {
				cout << "Test de BoiteChoco::LePoids() passe." << endl;
				cout << "Test de BoiteChoco::ajoutChocolat passe." << endl;
			} else {
				cout << "Test de BoiteChoco::LePoids() NON PASSE." << endl;
				cout << "Test de BoiteChoco::ajoutChocolat NON PASSE." << endl;
			} 
		}
		{
			BoiteChoco boite("Pimprenelle", 7);
			if (boite.leNom() == "Pimprenelle" && boite.lePoids() == 7*POIDS_BOITE)
				cout << "Test de BoiteChoco::BoiteChoco(...) passe" << endl;
			else
				cout << "Test de BoiteChoco::BoiteChoco(...) NON PASSE" << endl;
		}
	} else if (partie == 2) {

	}
}