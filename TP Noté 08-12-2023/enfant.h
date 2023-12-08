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
      void affiche();
      void recoitCadeau(Cadeau &);
		bool possede(Cadeau &);
      size_t combienDeCadeaux();
};

#endif
