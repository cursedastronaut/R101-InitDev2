#include <string>
#include <iostream>
#include <vector>
#include "permis.h"

using namespace std;


int main() {
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

  return 0;
}

/*
1.  a.  Que contient le fichier permis.h ?
            Une classe "Permis" permettant de gérer les points d'un permis de conduire.
    b.  Que contient le fichier permis.cpp ? À quoi sert la présence de Permis:: ? Retirez Permis:: de la définition de la fonction membre affiche. Que se passe-t-il ?
            Les définitions des procédures de la classe "Permis" ainsi que la définition de
            son constructeur.
            Le "Permis::" sert à préciser que l'on définit une procédure de la classe "Permis"
            et non une nouvelle procédure en dehors de cette dernière.
            En le retirant de la procédure affiche, affiche devient une procédure indépendante
            de la classe "Permis". Lorsque main() tente d'appeler la procédure "affiche" de
            "Permis", elle cherche une définition correspondant à sa déclaration, mais n'en
            trouve pas.
    c.  Que contient le fichier main.cpp ?
            Divers tests de la classe permis. Plusieurs fois, l'objet "p" est réinitialisé grâce
            au constructeur de "Permis" pour tester de nouvelles valeurs.
    d.  Compilez et exécutez le projet. Quels affichages sont produits ? Expliquez.

2.  a.  Complétez le fichier main.cpp en déclarant deux autres instance p1 et p2 (= deux variables) de la classe (= de type) Permis, en choisissant des noms, des prénoms, des dates, des numéros de permis, et des nombres de points. Vérifiez en appelant la fonction membre affiche.
    b.  Testez l'instruction cout << p1 << endl dans main.cpp. Que se passe-t-il ? Pourquoi ?
    c.  Testez l'instruction cout << p1._nom << endl dans main.cpp. Que se passe-t-il ? Pourquoi ?
    d.  Pourquoi le prototype de la fonction affiche se termine-t-il par le mot-clé const et pas celui de la fonction retraitPoints ?

3.  a.  Ajoutez une méthode getNom qui retourne le nom du détenteur de l'objet cible. Testez.
    b.  Ajoutez une méthode incrementePoints qui augmente le nombre de points du permis de 1. Si le permis a déjà MAXP points, la méthode lance une exception de type invalid_argument précisant la raison de l'exception. Testez.
    c.  Ajoutez une méthode decrementePoints qui diminue le nombre de points du permis de 1. Si le permis a déjà MINP points, la méthode lance une exception invalid_argument précisant la raison de l'exception. Testez.

4.  a.  En utilisant une des méthodes définies précédemment, ajoutez dans les fichiers permis.h et permis.cpp une fonction externe (à la classe Permis) ajoutePoints de prototype :
        void ajoutePoints(Permis&, int);

        avec deux arguments : un permis et un entier positif. Cette fonction ajoute les points passés en deuxième argument au permis passé en premier argument, en ne dépassant jamais MAXP (si trop de points sont ajoutés, on reste sur MAXP points). Testez.

    b.  Que se passe-t-il si on modifie le prototype de la fonction membre ajoutePoints :
        void ajoutePoints(const Permis&, int);

5.  a.  Modifiez les fichiers permis.h et permis.cpp pour ajouter à la classe Permis le destructeur suivant :
        Permis::~Permis() {
            cout << "Destruction du Permis" << endl;
        }

    b.  Ajoutez l'affichage des données membres dans la définition du destructeur. Compilez. Expliquez les affichages à l'exécution : quand le destructeur est-il appelé ? Dans quel ordre les objets sont-il détruits ?

6.  Un constructeur doit s'assurer que l'objet est bien formé. Modifiez le constructeur non vide pour déclencher une exception type invalid_argument si le nombre de points donné est aberrant. Traitez l'exception dans main.cpp.
    Grâce à l'encapsulation, les permis auront dorénavant toujours un nombre de points valide : les constructeurs ne créent que des permis valides, les méthodes publiques préservent cette propriété, et l'utilisateur n'a pas accès à l'attribut _nbpoints et ne peut donc pas y mettre une valeur aberrante.


7.  Testez l'instruction suivante dans le programme principal : if (p1 == p2) cout << "c'est pareil" << endl;
    Que se passe-t-il ? Pourquoi ?

8.  Ajoutez une fonction membre (= une méthode) compare pour comparer deux permis : la fonction renvoie true si les deux permis ont le même nombre de points. Testez.

9.  Déclarez un vecteur de Permis de taille 10. Observez la construction et la destruction des instances créées. Affichez le contenu du vecteur.

10.

11.

12.

13.

14.

*/