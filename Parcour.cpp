#include "DefVal.hpp"

#include "Parcour.hpp"

using namespace std;

Parcour::Parcour() {
  steps = rand() % 30 + 10;
  //cout << "Parcour steps: " << steps << endl;
  Phases.push_back(0);
  for (int i = 0; i < steps-2; i++) {Phases.push_back((rand()%(PARC_SIZE/2-1))+(rand()%(PARC_SIZE/2-1))+1);}
  Phases.push_back(PARC_SIZE);
  sort (Phases.begin(), Phases.end());
  for (int i = 0; i < steps - 1; i++){
    Slopes.push_back(rand() % 80 - 40);
  }
  for (int i = 1; i < 9; i++){
    WaterSup.push_back((PARC_SIZE/9)*i+(rand()%(PARC_SIZE/20)-(PARC_SIZE/40)));
  }

  WdSpeed = (float)(rand() % 7000)/360.f; //pour avoir un vent entre 0 et 70 Km/h
  //mais avec beaucoup plus entre 10 et 30 Km/h
  if (WdSpeed < 2.777f) {WdSpeed += (float)(rand() % 20)/3.6f;}
  if (WdSpeed > 13.888f) {WdSpeed -= (float)(rand() % 20)/3.6f;} //et beaucoup moins > 50 Km/h
  if (WdSpeed > 8.333f) {WdSpeed -= (float)(rand() % 20)/3.6f;}
  //WdSpeed est en m/s
  WdAng = (float)rand()/((float)RAND_MAX/360.f);
  TurnSteps = rand() % 30 + 10;
  TurnsPhases.push_back(0);
  for (int i = 0; i < TurnSteps-2; i++) {TurnsPhases.push_back((rand()%(PARC_SIZE/2-1))+(rand()%(PARC_SIZE/2-1))+1);}
  TurnsPhases.push_back(PARC_SIZE);
  sort (TurnsPhases.begin(), TurnsPhases.end());
  for (int i = 0; i < TurnSteps - 1; i++){
    Turns.push_back((float)rand()/((float)RAND_MAX/200.f) - 100);
  }
};

Parcour::Parcour(const std::string& file) {
  ifstream OpenFile (file);

  if(!OpenFile.is_open()) {
    cout << "Error opening file" << endl;
    exit (EXIT_FAILURE);
  }
  string line;
  istringstream Proline;
  getline(OpenFile, line);
  steps = stoi(line);
  getline(OpenFile, line);
  Proline.str(line);
  while (Proline >> line){Phases.push_back(stoi(line));}
  getline(OpenFile, line);
  Proline.clear();
  Proline.str(line);
  while (Proline >> line){Slopes.push_back(stoi(line));}
  getline(OpenFile, line);
  Proline.clear();
  Proline.str(line);
  while (Proline >> line){WaterSup.push_back(stoi(line));}
  getline(OpenFile, line);
  WdSpeed = stoi(line);
  getline(OpenFile, line);
  WdAng = stoi(line);
  getline(OpenFile, line);
  TurnSteps = stoi(line);
  getline(OpenFile, line);
  Proline.clear();
  Proline.str(line);
  while (Proline >> line){TurnsPhases.push_back(stoi(line));}
  getline(OpenFile, line);
  Proline.clear();
  Proline.str(line);
  while (Proline >> line){Turns.push_back(stoi(line));}

  OpenFile.close();
}

const void Parcour::MakeTxt(const std::string& file){
  ofstream OpenFile (file);

  if(!OpenFile.is_open()) {
    cout << "Error opening file" << endl;
    exit (EXIT_FAILURE);
  }

  ostringstream out;
  out << steps << "\n";
  for (int i = 0; i < steps; i++){
    out << " ";
    out << Phases[i];
  }
  out << "\n";
  for (int i = 0; i < steps; i++){
    out << " ";
    out << Slopes[i];
  }
  out << "\n";
  for (int i = 0; i < 8; i++){
    out << " ";
    out << WaterSup[i];
  }
  out << "\n" << WdSpeed << "\n" << WdAng << "\n" << TurnSteps << "\n";
  for (int i = 0; i < TurnsPhases.size(); i++){
    out << " ";
    out << TurnsPhases[i];
  }
  out << "\n";
  for (int i = 0; i < Turns.size(); i++){
    out << " ";
    out << Turns[i];
  }
  OpenFile << out.str();

  OpenFile.close();

}
