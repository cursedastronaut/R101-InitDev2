//GALAAD MARTINEAUX
//BUT1-INFO-TP1K
#include "cadeau.h"
#include "enfant.h"
#include "pereNoel.h"

#include <iostream>
#include <vector>
using namespace std;


int main(){
	vector<Enfant>lesEnfants; // les enfants qui attendent leurs cadeaux
	
	cout << "o o o Bonjour les enfants o o o " << endl;
	/// --------- Vous pouvez d�clarer de nouvelles variables
	/// --------- appeler les m�thodes �crites, et faire des affichages
	/// ------- ceci ne sera pas �valu�
	PereNoel petitPapaNoel;
	size_t nombreCadeaux = JEUX.size()-1;

	
	/// --------------- ins�rer ici les instructions de la question 5
	/// Obligatoire : tests automatiques de la m�thode *possede* de la classe Enfant)
	lesEnfants.push_back(Enfant("Pimprenelle"));
	Cadeau nounours("Nounours");
	lesEnfants[0].recoitCadeau(nounours);
	if (lesEnfants[0].possede(nounours))
		cout << "Test de Enfant::possede() reussi." << endl;
	else
		cout << "Test de Enfant::posedde() rate" << endl;
	lesEnfants.pop_back(); //Preparation pour la q9
	
	///---------------	Question 9 : ajouter 4 enfants au vector lesEnfants
	const vector<string> NOM_ENFANTS = {"Asterix", "Boul", "Bill", "Kirikou"};
	for (size_t i = 0; i < NOM_ENFANTS.size(); ++i)
		lesEnfants.push_back(Enfant(NOM_ENFANTS[i]));

	/// --------------- Question	10
	/// Compl�ter les instructions ci-dessous pour la distribution des cadeaux
	int i=0;
	bool encoreDesCadeaux; // le pere Noel a-t-il encore des cadeaux dans sa hotte ?
	// �crire	l'instruction d'amor�age	:
	// - le pere No�l offre un cadeau au 1er enfant : lesEnfants[0]
	// - le booleen encoreDesCadeaux est initialis�.
	if (lesEnfants.size() > 0)
		petitPapaNoel.offreCadeau(lesEnfants[0]);
	encoreDesCadeaux = nombreCadeaux > 0;

	while (encoreDesCadeaux){	/// tant qu'il a des cadeaux 
		i++;
		if(i==lesEnfants.size())i=0;	// recommence au 1er enfant
	// �crire l'instruction de relance :
	// - le pere No�l offre un cadeau � l'enfant num�ro i
	// - le booleen encoreDesCadeaux est mis � jour
		if (petitPapaNoel.offreCadeau(lesEnfants[i]))
			--nombreCadeaux;
		encoreDesCadeaux = nombreCadeaux > 0;
	}
	
	/// --------------- Question 11 ----------
	/// trouver l'enfant qui a le plus de cadeaux et afficher ses cadeaux
	size_t enfantMaxCadeaux = 0;
	for (size_t i = 0; i < lesEnfants.size(); ++i)
	{
		if (lesEnfants[i].combienDeCadeaux() > lesEnfants[enfantMaxCadeaux].combienDeCadeaux())
			enfantMaxCadeaux = i;
	}
	lesEnfants[enfantMaxCadeaux].affiche();
	return 0;
}

