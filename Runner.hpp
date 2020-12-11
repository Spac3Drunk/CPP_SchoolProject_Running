#if !defined(_runner)
#define _runner

#include "DefVal.hpp"

#include "Parcour.hpp"

class Runner
{
    public:
      //runner relative
      int mass;
      int size;
      int poids_chauss;
      float speed;
      int prep;
      int abandon = 0;

      //Wind
      float WPtMax;
      float WRSp;
      int CurrentWPhase = 0;

      //water
      float hydr;
      float hydrImp = 1;
      float dehydrPos;
      int dehydr = 0;
      int WRavPas = 0;

      //Position
      float Xpos = 0;
      float Ypos = 0;

      //identity
      int NumDoss;
    	std::string Nom;
      sf::Color Col;

      //parcours relative
      float SpeedMod = 1;
    	float CurrentSpeed = 0.f;
      int CurrentPhase = 0;

      Runner();
      void RuShow();
      void RunDeHydr();
      void RunHydr(Parcour Par, double Timer);
      void SpeedModif(Parcour Par);
      bool operator< (const Runner &other) const {return Xpos < other.Xpos;}
};


#endif
