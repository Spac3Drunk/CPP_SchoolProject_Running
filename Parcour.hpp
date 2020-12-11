#if !defined(_parcour)
#define _parcour

#include "DefVal.hpp"

class Parcour
{
  public:
    //Slopes Related
      int steps;
      std::vector<int> Phases;
      std::vector<int> Slopes;
    //Water Related
      std::vector<int> WaterSup;
    //Wind Related
      float WdSpeed;
      float WdAng;

      int TurnSteps;
      std::vector<int> TurnsPhases;
      std::vector<float> Turns;

      Parcour();
      Parcour(const std::string& file);

      const void MakeTxt(const std::string& file);
};


#endif
