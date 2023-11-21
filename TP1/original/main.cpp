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
