#include <string>
#include <iostream>
#include <vector>
#include "permis.h"

using namespace std;


int main() {
	try {
		Permis pdef;
		Permis p("Duck", "Donald", "09/06/1934", "012345", 7);

		cout << endl << "----- Tests manuels de affiche -----------------------------------------" << endl;
		pdef.affiche();
		p.affiche();
		cout << endl << "----- Tests automatiques de getNbpoints --------------------------------" << endl;
		bool ok = true;
		if (!(p.getNbpoints() == 7)) {
			ok = false;
			cout << "Erreur : p.getNbpoints() = " << p.getNbpoints() << " (attendu : 7)" << endl;
		}
		if (ok) cout << "Methode getNbpoints correcte" << endl;

		cout << endl << "----- Tests automatiques de retraitPoints ------------------------------" << endl;
		ok = true;
		p.retraitPoints(3);
		if (!(p.getNbpoints() == 4)) {
			ok = false;
			cout << "Erreur : apres avoir retire 3 points a un permis a 7 points, on obtient un permis a " << p.getNbpoints() << " points (attendu : 4)" << endl;
		}
		p = Permis ("Duck", "Donald", "09/06/1934", "012345", 7);
		p.retraitPoints(0);
		if (!(p.getNbpoints() == 7)) {
			ok = false;
			cout << "Erreur : apres avoir retire 0 points a un permis a 7 points, on obtient un permis a " << p.getNbpoints() << " points (attendu : 7)" << endl;
		}
		p = Permis ("Duck", "Donald", "09/06/1934", "012345", 7);
		p.retraitPoints(7);
		if (!(p.getNbpoints() == 0)) {
			ok = false;
			cout << "Erreur : apres avoir retire 7 points e un permis a 7 points, on obtient un permis a " << p.getNbpoints() << " points (attendu : 0)" << endl;
		}
		p = Permis ("Duck", "Donald", "09/06/1934", "012345", 7);
		p.retraitPoints(10);
		if (!(p.getNbpoints() == 0)) {
			ok = false;
			cout << "Erreur : après avoir retire 10 points a un permis a 7 points, on obtient un permis a " << p.getNbpoints() << " points (attendu : 0)" << endl;
		}
		p = Permis ("Duck", "Donald", "09/06/1934", "012345", 7);
		if (ok) cout << "Methode retraitPoints correcte" << endl;

		cout << endl << "----- Partie etudiante --------------------------------" << endl;
		Permis p1("MARTINEAUX", "Galaad", "06/09/2004", "002023", 7);
		Permis p2("NOUNOURS", "Pimprenelle", "23/04/2024", "002023", 7);
		p1.affiche();
		p2.affiche();
		//cout << p1 << endl;
		//cout << p1._nom << endl;
		if (p1.getNom() == "MARTINEAUX")
			cout << "Methode getNom correcte" << endl;
		else
			cout << "Erreur: Methode getNom incorrecte" << endl;
		
		try {
			p1.incrementePoints();
			cout << "Methode incrementePoints correcte." << endl;
		} catch(invalid_argument e) {
			cerr << "Erreur: Nombre de point au dessus de la limite!" << endl;
		}

		try {
			p1.decrementePoints();
			cout << "Methode decrementePoints correcte." << endl;
		} catch(invalid_argument e) {
			cerr << "Erreur: Nombre de point en dessous de la limite!" << endl;
		}

		ajoutePoints(p1, 5);
		if (p1.getNbpoints() == 7+5)
			cout << "Methode ajoutePoints correcte si l'argument est positif" << endl;
		else
			cout << "Erreur: Methode ajoutePoints incorrecte si l'argument est positif." << endl;
		ajoutePoints(p1, -5);
		if (p1.getNbpoints() == 7)
			cout << "Methode ajoutePoints correcte si l'argument est negatif" << endl;
		else
			cout << "Erreur: Methode ajoutePoints incorrecte si l'argument est negatif." << endl;

		
		if (!p1.compare(p2))
			cout << "Methode compare correcte." << endl;
		else
			cout << "Methode compare incorrecte." << endl;

		cout << "--- Destruction de p1" << endl;
		p1.~Permis();

		vector<Permis> vecPermis(10, Permis());
		for (size_t i = 0; i < vecPermis.size(); ++i)
			vecPermis[i].affiche();


		cout << "-----------------------------------------" << endl;
	} catch (invalid_argument e) {
		cerr << "Erreur: Constructeur incorrect" << endl;
	}
	

	return 0;
}

/*
1.	a.	Que contient le fichier permis.h ?
						Une classe "Permis" permettant de gérer les points d'un permis de conduire.
		b.	Que contient le fichier permis.cpp ? À quoi sert la présence de Permis:: ? Retirez Permis:: de la définition de la fonction membre affiche. Que se passe-t-il ?
						Les définitions des procédures de la classe "Permis" ainsi que la définition de
						son constructeur.
						Le "Permis::" sert à préciser que l'on définit une procédure de la classe "Permis"
						et non une nouvelle procédure en dehors de cette dernière.
						En le retirant de la procédure affiche, affiche devient une procédure indépendante
						de la classe "Permis". Lorsque main() tente d'appeler la procédure "affiche" de
						"Permis", elle cherche une définition correspondant à sa déclaration, mais n'en
						trouve pas.
		c.	Que contient le fichier main.cpp ?
						Divers tests de la classe permis. Plusieurs fois, l'objet "p" est réinitialisé grâce
						au constructeur de "Permis" pour tester de nouvelles valeurs.
		d.	Compilez et exécutez le projet. Quels affichages sont produits ? Expliquez.
			Construction d'un permis
			Construction d'un permis

			----- Tests manuels de affiche -----------------------------------------
			Informations sur le permis de inconnu inconnu :
			00000
			non renseigne
			Nombre de points : 12
			Informations sur le permis de Donald Duck :
			012345
			09/06/1934
			Nombre de points : 7

			----- Tests automatiques de getNbpoints --------------------------------
			Methode getNbpoints correcte

			----- Tests automatiques de retraitPoints ------------------------------
			Construction d'un permis
			Construction d'un permis
			Construction d'un permis
			Construction d'un permis
			Methode retraitPoints correcte

			À chaque fois que l'on voit "Construction d'un permis", c'est que le constructeur
			de la classe "Permis" est appelé.
			Celui-ci requiert un nom, un prénom, une date, un numero, et les points.
			Il y a des tests de chaque fonction.

2.	a.	Complétez le fichier main.cpp en déclarant deux autres instance p1 et p2 (= deux variables) de la classe (= de type) Permis, en choisissant des noms, des prénoms, des dates, des numéros de permis, et des nombres de points. Vérifiez en appelant la fonction membre affiche.
			Fait.
	b.	Testez l'instruction cout << p1 << endl dans main.cpp. Que se passe-t-il ? Pourquoi ?
			Cela ne compile pas. On ne peut pas "cout" un objet de type classe "Permis"
			sans un opérateur spécifique qui lui dit comment faire.
	c.	Testez l'instruction cout << p1._nom << endl dans main.cpp. Que se passe-t-il ? Pourquoi ?
			Cela ne fonctionne pas non plus, puisque _nom est un membre privé de la classe "Permis".
			Autrement dit, seules les fonctions internes à "Permis", ou d'une classe qui en hérite,
			peuvent y accéder. Il n'y a pas écrit qu'elle est privée, mais puisque ce n'est pas
			précisé dans la déclaration de la classe, il est privé par défaut.
	d.	Pourquoi le prototype de la fonction affiche se termine-t-il par le mot-clé const et pas celui de la fonction retraitPoints ?
			Son prototype n'agit pas sur l'objet.
			C'est une fonction qui peut lire le contenu de l'objet, mais pas le modifier.
3.	a.	Ajoutez une méthode getNom qui retourne le nom du détenteur de l'objet cible. Testez.
		Fait
	b.	Ajoutez une méthode incrementePoints qui augmente le nombre de points du permis de 1. Si le permis a déjà MAXP points, la méthode lance une exception de type invalid_argument précisant la raison de l'exception. Testez.
		Fait
	c.	Ajoutez une méthode decrementePoints qui diminue le nombre de points du permis de 1. Si le permis a déjà MINP points, la méthode lance une exception invalid_argument précisant la raison de l'exception. Testez.
		Fait

4.	a.	En utilisant une des méthodes définies précédemment, ajoutez dans les fichiers permis.h et permis.cpp une fonction externe (à la classe Permis) ajoutePoints de prototype :
		void ajoutePoints(Permis&, int);
		avec deux arguments : un permis et un entier positif. Cette fonction ajoute les points passés en deuxième argument au permis passé en premier argument, en ne dépassant jamais MAXP (si trop de points sont ajoutés, on reste sur MAXP points). Testez.
			Fait
	b.	Que se passe-t-il si on modifie le prototype de la fonction membre ajoutePoints :
		void ajoutePoints(const Permis&, int);
			Le programme ne compile pas, puisque l'on doit modifier le contenu du permis
			et que l'on ne peut pas puisqu'il est constant.

5.	a.	Modifiez les fichiers permis.h et permis.cpp pour ajouter à la classe Permis le destructeur suivant :
		Permis::~Permis() {
			cout << "Destruction du Permis" << endl;
		}
			Fait
	b.	Ajoutez l'affichage des données membres dans la définition du destructeur. Compilez. Expliquez les affichages à l'exécution : quand le destructeur est-il appelé ? Dans quel ordre les objets sont-il détruits ?
		Les destructeurs sont appelés à la fin du programme dans leur ordre de déclaration.
			Fait
		
6.	Un constructeur doit s'assurer que l'objet est bien formé. Modifiez le constructeur non vide pour déclencher une exception type invalid_argument si le nombre de points donné est aberrant. Traitez l'exception dans main.cpp.
	Grâce à l'encapsulation, les permis auront dorénavant toujours un nombre de points valide : les constructeurs ne créent que des permis valides, les méthodes publiques préservent cette propriété, et l'utilisateur n'a pas accès à l'attribut _nbpoints et ne peut donc pas y mettre une valeur aberrante.
		Fait

7.	Testez l'instruction suivante dans le programme principal : if (p1 == p2) cout << "c'est pareil" << endl;
	Que se passe-t-il ? Pourquoi ?
		Le programme ne compile pas puisque le compilateur ne sait pas comment
		comparer p1 et p2 pour voir s'ils sont identiques. Pour remédier à celà,
		il faudrait faire un opérateur "==" prenant deux classes Permis.
8.	Ajoutez une fonction membre (= une méthode) compare pour comparer deux permis : la fonction renvoie true si les deux permis ont le même nombre de points. Testez.
		Fait.

9.	Déclarez un vecteur de Permis de taille 10. Observez la construction et la destruction des instances créées. Affichez le contenu du vecteur.
	Fait

10. (s'il vous reste du temps) Modifiez la déclaration du constructeur avec des paramètres pour ajouter des valeurs par défaut à tous ses paramètres.
	1. Déclarer un Permis avec un argument de type string. Que se passe-t-il ? pourquoi ?
		Cela fonctionne, le compilateur prend le premier argument de l'utilisateur,
		et utilise les valeurs par défaut pour le reste.
	2. Déclarer un Permis avec aucun argument. Que se passe-t-il ? Pourquoi ? Quelle solution peut-on adopter pour ne plus avoir d'erreur ?
		Ça ne compile pas, puisque le compilateur ne sait pas quoi choisir entre
		le constructeur vide, et le constructeur avec des valeurs par défaut.

11. Ajouter les instructions suivante s:
	Permis pa("Toto");
	if (pa.compare(string("Toto"))) cout << "on ne peut pas comparer un permis à un string << endl;
	else cout << "on peut comparer un permis à un string" << endl;

	if (pa.compare(string("Titi"))) cout << "on ne peut pas comparer un permis à un string << endl;
	else cout << "on peut comparer un permis à un string" << endl;
	Que se passe-t-il ?

		Si l'on corrige les erreurs telles que les guillemets non finies,
		le code compile et réussit à comparer le string au permis, puisqu'il
		le convertit implicitement à l'aide du constructeur par défaut de Permis.

*/