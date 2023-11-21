// HB novembre 2022
// classe Permis pour gerer un permis de conduire
#ifndef _PERMIS_H_
#define _PERMIS_H_

#include <string>
using namespace std;


const int MAXP = 12; // Nombre de points maximal pour un permis
const int MINP = 0; //  Nombre de points minimal
 

class Permis {
  string _nom;  //  Nom du détenteur du permis
  string _prenom;//  Prenom du détenteur du permis
  string _date;//  Date de dÃ©livrance du permis, au format JJ/MM/AAAA (ex: 09/10/2021)
  string _numero;//Numero du permis (ex: 0123456789)
  int _nbpoints;//  Nombre du points du permis, compris entre MINP et MAXP

 public:
  /*--------------  Permis(); 
    constructeur vide
    Construit le permis d'une personne inconnue, avec 12 points par défaut
  */
  Permis ();
  
 /*-------------  Permis (const string&, const string&, const string&, const string&, int); constructeur a partir des informations
   Construit un permis à partir du nom et du prénom du détenteur, de
   la date de délivrance, du numéro, et du nombre de points
 */
  Permis (const string&, const string&, const string&, const string&, int);
  /* ----------- void affiche() const; 
     affichage d'un permis
     Affiche toutes les données associées au permis cible
  */
  void affiche() const;

  /*------------- int getNbpoints() const;
    Nombre de points d'un permis
    Renvoie le nombre de points du permis cible
   */
  int getNbpoints() const;

  /*--------------  string getNom() const;
    Nom du détenteur d'un permis
    Renvoie le nom du détenteur du permis cible
   */
   /*----------- void retraitPoints(int); 
    Retire des points à un permis
    Retire au permis cible le nombre de points passé en paramètre, pour
    un minimum de MINP.
   */

  void retraitPoints(int); 

};

#endif
