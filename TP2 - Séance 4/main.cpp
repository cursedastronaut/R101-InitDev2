//Galaad MARTINEAUX - BUT1 TP1K
#include "appartement.h"
#include <iostream>
using namespace std;

int main()
{
	string nomFic;
	ifstream entree;
	ofstream sortie;

	vector<string> tab(0);

	try {
		Piece test_d_ecriture;
		cout << "Nom du fichier à écrire ?"; cin >> nomFic;
		sortie.open(nomFic);
		if(!(sortie.is_open())) throw(nomFic);
		test_d_ecriture.ecrireFichier(sortie);
		sortie.close();

		cout << "Nom du fichier à lire ?"; cin >> nomFic;
		entree.open(nomFic);
		if(!(entree.is_open())) throw(nomFic);
		for (size_t i = 0; !entree.eof(); i++) {
			string val;
			entree >> val;
			tab.push_back(val);
		}
		Piece testLecture(entree);
		entree.close();
		cout << "Nous avons lu :";
		for (size_t i = 0; i < tab.size(); i++) {
			cout << " " << tab[i];
		}
		cout << endl << "La piece genere a pour caracteristiques: " << endl;
		testLecture.afficher();

		cout << endl << endl << endl;
		/* PARTIE APPARTEMENT */
		Appartement test_d_ecriture_app(test_d_ecriture, "1 rue de Yunme");
		cout << "Nom du fichier à écrire ?"; cin >> nomFic;
		sortie.open(nomFic);
		if(!(sortie.is_open())) throw(nomFic);
		test_d_ecriture_app.ecrireFichier(sortie);
		sortie.close();

		cout << "Nom du fichier à lire ?"; cin >> nomFic;
		entree.open(nomFic);
		if(!(entree.is_open())) throw(nomFic);
		for (size_t i = 0; !entree.eof(); i++) {
			string val;
			entree >> val;
			tab.push_back(val);
		}
		Appartement testLectureApp(entree);
		entree.close();
		cout << "Nous avons lu :";
		for (size_t i = 0; i < tab.size(); i++) {
			cout << " " << tab[i];
		}
		cout << endl << "L'appart genere a pour caracteristiques: " << endl;
		testLectureApp.afficher();

	} catch (const string & s) {
		cerr<< "pb ouverture du fichier : " << s;
	}

	return 0;
}