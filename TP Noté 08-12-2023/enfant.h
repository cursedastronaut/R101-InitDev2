//GALAAD MARTINEAUX
//BUT1-INFO-TP1K
#ifndef _ENFANT_
#define _ENFANT_

class Enfant {
   private:
		string _nom;
      vector<Cadeau> _sac;
   public:
		Enfant(const string & n="toto");
		string nom()const;
      void affiche(); //Affiche tout les cadeaux de l'Enfant.
      void recoitCadeau(Cadeau &);  //Ajoute le cadeau passé en paramètre au _sac.
		bool possede(Cadeau &); //Retourne vrai si le cadeau passé en paramètre est déjà présent dans le _sac.
      size_t combienDeCadeaux(); //Retourne le nombre de cadeaux reçus par l'enfant.
};

#endif
