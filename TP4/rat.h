	/**	Classe	Rationnel
	*	HB
	*
	*	Classe	permettant	de	representer	des	nombres	rationnels
	*	L'encapsulation	garantit	que	:
	*			-	le	denominateur	est	toujours	un	entier	scrictement	positif
	*			-	la	fraction	est	toujours	reduite.
	*	Ainsi,	la	représentation	des	rationnels	est	unique.
	*/


#ifndef	_RAT_H_
#define	_RAT_H_

#include	<iostream>
#include	<cstdlib>
#include	<vector>

using	namespace	std;

class	Rationnel	{
	private:

		int	_num;	//	Numérateur,	positif	ou	négatif
		int	_den;	//	dénominateur,	strictement
		//	réduction	d'une	fraction:	_num	/	_den	devient	irréductible
		void	_reduire();

	public:
		//	Constructeur	avec	numérateur	et	dénominateur
		//	vérification	et	mise	sous	forme	irreductible
		Rationnel(int=0,	int=1);
		//		Méthode	d'affichage,	par	exemple	1/2
		void	afficher()	const;
		//Renvoie	le	numérateur
		int	getNum()	const;
		//	Renvoie	le	dénominateur
		int	getDen()	const;

		void saisir(istream & in);

		//	Opérateur multiplication (Rationnel * Rationnel)
		Rationnel operator*(Rationnel &);
		//	Opérateur d'égalité (Rationnel == Rationnel)
		bool operator==(Rationnel &);
		//	Opérateur soustraction unaire (0-Rationnel)
		Rationnel operator-();
		//	Opérateur addition (Rationnel + Rationnel)
		Rationnel operator+(Rationnel &);
		//	Opérateur inférieur à (Rationnel < Rationnel)
		bool operator<(Rationnel &);
		//	Opérateur >> (std::istream & >> Rationnel)
		void operator>>(std::istream& in);	
		//	Opérateur multiplication (Rationnel * int)
		Rationnel operator*(int);
		//	Opérateur de non-egalité (Rationnel != Rationnel)
		bool operator!=(Rationnel &);
		//	Opérateur inférieur ou égal à (Rationnel <= Rationnel)
		bool operator<=(Rationnel &);
		//	Opérateur d'incrémentation préfix (++Rationnel)
		Rationnel operator++();
		//	Opérateur d'incrémentation suffix (Rationnel++)
		Rationnel operator++(int);

};

//	Calcul	du	pgcd	de	deux	entiers	quelconques
int	pgcd(int	a,	int	b);
//	Calcul	du	pgcd	de	deux	entiers	a	et	b	tels	que	a	>=	b	>=	0
int	pgcdRecursif(int	a,	int	b);

std::ostream& operator<<(std::ostream& out, Rationnel &);
Rationnel operator*(int, Rationnel &);
//	Fonctions	de	test
bool	testConstructeurVideEtGetters();
bool	testConstructeurParamEtGetters(int	n,	int	d,	int	nres,	int	dres,	bool	exc);
bool	testsConstructeurParamEtGetters();
bool	testOperateurs();

//Calcul le produit, et le maximum d'un vecteur de rationnel
void	produitMaximumVecteurRationnel();
#endif
