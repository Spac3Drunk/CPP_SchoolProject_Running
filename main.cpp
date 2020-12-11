#include "DefVal.hpp"

#include "Runner.hpp"
#include "Parcour.hpp"
#include "WindCompass.hpp"

using namespace sf;

float reduct = PARC_SIZE/PARC_DIS_SIZE;
unsigned long long timer = 0;
//Fonctions Graphiques__________________________________________________________
VertexArray GraphParcour(Parcour Par, float Xdep, float Ydep, float Thik, VertexArray VArr){
  VArr.clear();
  VArr.setPrimitiveType(TriangleStrip);
  VArr.resize((Par.steps)*2);
  VArr.operator[](0) = Vertex(Vector2f(((float)Par.Phases[0])/reduct+Xdep, Ydep));
  VArr.operator[](1) = Vertex(Vector2f(((float)Par.Phases[0])/reduct+Xdep, Ydep+Thik));
  float dist;
  for (int i = 1; i < (Par.steps); i++) {
    dist = ((float)Par.Phases[i] - (float)Par.Phases[i-1])/reduct;
    Ydep += (float)dist*Par.Slopes[i-1]/-100;
    VArr.operator[](i*2) = Vertex(Vector2f(((float)Par.Phases[i])/reduct+Xdep, Ydep));
    VArr.operator[](i*2+1) = Vertex(Vector2f(((float)Par.Phases[i])/reduct+Xdep, Ydep+Thik));
  }
  return(VArr);
}

VertexArray WaterParcour(Parcour Par, float Xdep, float Ydep, VertexArray VArr){
  VArr.clear();
  VArr.setPrimitiveType(Quads);
  VArr.resize(8*4);
  for(int i=0; i<Par.WaterSup.size(); i++){
    VArr.operator[](4*i) = Vertex(Vector2f(((float)Par.WaterSup[i])/reduct+Xdep, Ydep+1250.f), Color::Blue);
    VArr.operator[](4*i+1) = Vertex(Vector2f(((float)Par.WaterSup[i])/reduct+Xdep, Ydep-1250.f), Color::Blue);
    VArr.operator[](4*i+2) = Vertex(Vector2f(((float)Par.WaterSup[i])/reduct+Xdep+2, Ydep-1250.f), Color::Blue);
    VArr.operator[](4*i+3) = Vertex(Vector2f(((float)Par.WaterSup[i])/reduct+Xdep+2, Ydep+1250.f), Color::Blue);
  }
  return(VArr);
}

//This Dawn Thing is Shitty Don't Touch it!
/*
VertexArray WindGraphParcour(Parcour Par, float Xdep, float Ydep, float Thik, VertexArray VArr){
  VArr.clear();
  VArr.setPrimitiveType(TriangleStrip);
  VArr.resize((Par.TurnSteps)*2);

  VArr.operator[](0) = Vertex(Vector2f(Xdep, Ydep));
  VArr.operator[](1) = Vertex(Vector2f(Xdep, Ydep+Thik));
  float dist;
  float LastX = Xdep;
  float LastY = Ydep;
  float CurAng = 0;
  float TurnSubAng = 0;
  for (int i = 1; i < (Par.TurnSteps); i++) {
    dist = ((float)Par.TurnsPhases[i] - (float)Par.TurnsPhases[i-1])/(1.75*reduct);
    CurAng += Par.Turns[i-1];
    CurAng = fmod(CurAng, 360.f);
    LastX += dist*cos(CurAng*M_PI/180.f);
    LastY += dist*-sin(CurAng*M_PI/180.f);
    VArr.operator[](i*2) = Vertex(Vector2f(LastX, LastY));
    TurnSubAng = fmod((CurAng*2+Par.Turns[i-1]-90.f), 360.f);
    VArr.operator[](i*2+1) = Vertex(Vector2f( LastX + Thik*cos(TurnSubAng*M_PI/180.f) , LastY + Thik*sin(TurnSubAng*M_PI/180.f)));
  }
  dist = ((float)Par.TurnsPhases[Par.TurnSteps - 1] - (float)Par.TurnsPhases[Par.TurnSteps - 1])/(1.75*reduct);
  CurAng += Par.Turns[Par.TurnSteps-1];
  CurAng = fmod(CurAng, 360.f);
  LastX = LastX + dist*cos(CurAng*M_PI/180.f);
  LastY = LastY + dist*-sin(CurAng*M_PI/180.f);
  VArr.operator[](Par.TurnSteps*2-1) = Vertex(Vector2f(LastX , LastY));
  VArr.operator[](Par.TurnSteps*2) = Vertex(Vector2f(LastX , LastY+Thik));
  return(VArr);
}
*/

VertexArray WindGraphParcour(Parcour Par, float Xdep, float Ydep, float Thik, VertexArray VArr){
  VArr.clear();
  VArr.setPrimitiveType(TriangleStrip);
  VArr.resize((Par.TurnSteps)*2);
  VArr.operator[](0) = Vertex(Vector2f(((float)Par.TurnsPhases[0])/reduct+Xdep, Ydep));
  VArr.operator[](1) = Vertex(Vector2f(((float)Par.TurnsPhases[0])/reduct+Xdep, Ydep+Thik));
  float dist;
  for (int i = 1; i < (Par.TurnSteps); i++) {
    dist = ((float)Par.TurnsPhases[i] - (float)Par.TurnsPhases[i-1])/reduct;
    Ydep += (float)dist*Par.Turns[i-1]/-100;
    VArr.operator[](i*2) = Vertex(Vector2f(((float)Par.TurnsPhases[i])/reduct+Xdep, Ydep));
    VArr.operator[](i*2+1) = Vertex(Vector2f(((float)Par.TurnsPhases[i])/reduct+Xdep, Ydep+Thik));
  }
  return(VArr);
}

void SaveClassment(const std::string& file, const std::vector<Runner> &AllRunner){
  std::ofstream OpenFile (file);
  if(!OpenFile.is_open()) {
    std::cout << "Error opening file" << std::endl;
    exit (EXIT_FAILURE);
  }

  std::ostringstream out;
  out << "Classement : " << "\n";
  for (int i =0; i < AllRunner.size(); i++) {
    out << "Rang : " << (i+1) << "\n" << "Numero de dossard : " << AllRunner[i].NumDoss << "\n" << "Nom : " << AllRunner[i].Nom << "\n" << std::endl;
  }
  OpenFile << out.str();

  OpenFile.close();

}

int main()
{
//Init Things___________________________________________________________________
  srand(time(NULL));
/*
  Font font;
  if ( !font.loadFromFile("res/fonts/arial.ttf")){
    std::cout << "Error loadFromFile <arial.ttf>" << std::endl;
    system("pause");
  }
*/
  Font FontHSp;
  if ( !FontHSp.loadFromFile("res/fonts/High Speed.ttf")){
    std::cout << "Error loadFromFile <High Speed.ttf>" << std::endl;
    system("pause");
  }
  Font FontSFSp;
  if ( !FontSFSp.loadFromFile("res/fonts/SF Sports Night.ttf")){
    std::cout << "Error loadFromFile <SF Sports Night.ttf>" << std::endl;
    system("pause");
  }

  float DepX = 50.f;
  float DepY = 300.f;

  std::vector<Runner>AllRunners;
  AllRunners.resize(NB_RUNNER);
  for (int i = 0; i < NB_RUNNER; i++){
    AllRunners.operator[](i) = Runner();
    AllRunners[i].Ypos = (int)DepY+2;
  }

//GENERATE_OR_LOAD______________________________________________________________
  //Generate a new Parcour
  Parcour Parc;
  //Load the last Parcour
  //Parcour Parc("LastParcour.txt");
//GENERATE_OR_LOAD______________________________________________________________

  VertexArray ParcG;
  ParcG = GraphParcour(Parc, DepX, DepY, 15.f, ParcG);
  VertexArray ParW;
  ParW = WaterParcour(Parc, DepX, DepY, ParW);
  VertexArray ParcWd;
  ParcWd = WindGraphParcour(Parc, DepX, 800.f, 10.f, ParcG);

  RenderWindow window(VideoMode(1920, 1080), "Projet CoursePied", Style::Default);
  window.setFramerateLimit(240);

  Parc.MakeTxt("LastParcour.txt");

//Big While_____________________________________________________________________
  while(window.isOpen())
  {
    Event event;
    while(window.pollEvent(event))
    {
      switch (event.type)
      {
        case Event::Closed:
          window.close();
          break;
        default:
          break;
      }
    }
//Set Background________________________________________________________________
    window.clear();
    window.draw(ParW);
    window.draw(ParcG);
    window.draw(ParcWd);
    WindCompass Wcomp(Parc, 30.f, 600.f);
    window.draw(Wcomp.Outer);
    window.draw(Wcomp.InArrow);
    window.draw(Wcomp.OutArrow);
    Wcomp.WSpe.setFont(FontSFSp);
    window.draw(Wcomp.WSpe);

      //Make wind variable over time
    Parc.WdAng = fmod(Parc.WdAng+((float)rand()/((float)RAND_MAX/6.f)-3.f), 360.f);
    Parc.WdSpeed = fabs(Parc.WdSpeed+((float)(rand()%20)-10.f)/100.f);
    if(Parc.WdSpeed < (rand()%3)){Parc.WdSpeed+=((float)(rand()%5))/100.f;}

//Set Things____________________________________________________________________
    timer+=(1*TIME_MOD);

    Text TimShow;
    std::ostringstream StrTime;
    StrTime << std::setprecision(0) << std::fixed << timer/3600 << " : " << timer/60%60 << " : " << timer%60;
    //std::cout << StrTime.str() << std::endl;
    TimShow.setFont(FontSFSp);
    TimShow.setString(StrTime.str());
    TimShow.setCharacterSize(25);
    TimShow.setFillColor(Color(225, 225, 225));
    TimShow.setPosition(200.f, 50.f);
    window.draw(TimShow);

//Process Runners_______________________________________________________________
    float ClaSize = 20.f;
    float YRank = 0.f;
    Text RunName;
    CircleShape RIcon;
    VertexArray Rprogress;
    Rprogress.clear();
    Rprogress.setPrimitiveType(Quads);
    Rprogress.resize(4);
    Rprogress.operator[](0) = Vertex(Vector2f(0, 0), Color(175, 155, 10));
    Rprogress.operator[](1) = Vertex(Vector2f(0, 0), Color(175, 155, 10));
    Rprogress.operator[](2) = Vertex(Vector2f(0, 0));
    Rprogress.operator[](3) = Vertex(Vector2f(0, 0));

    bool RunIsFinished = true;
    std::sort(AllRunners.rbegin(), AllRunners.rend());

    for (int i = 0; i < (AllRunners.size()); i++){
      //std::cout << AllRunners[i].Xpos << std::endl;
      RIcon.setRadius(5.f);
      RIcon.setPointCount(AllRunners[i].NumDoss%4+4);
      RIcon.setFillColor(AllRunners[i].Col);
    //Classement___________________________________________//
      YRank += ClaSize;
      RunName.setFont(FontHSp);
      RunName.setString(AllRunners[i].Nom);
      RunName.setCharacterSize(ClaSize-2);
      RunName.setFillColor(Color(225, 225, 225));
      RunName.setPosition(DepX + PARC_DIS_SIZE*1.1f+25.f, YRank-11.5f);
      Rprogress.operator[](0) = Vertex(Vector2f(DepX + PARC_DIS_SIZE*1.1f+25.f, YRank-9.f), Color(175, 155, 10));
      Rprogress.operator[](1) = Vertex(Vector2f(DepX + PARC_DIS_SIZE*1.1f+25.f, YRank+9.f), Color(175, 155, 10));
      float ColRedTmp = AllRunners[i].Xpos;
      if (AllRunners[i].Xpos > PARC_SIZE) { ColRedTmp = PARC_SIZE; }
      Rprogress.operator[](2) = Vertex(Vector2f(DepX+(500.f*(ColRedTmp/PARC_SIZE))+PARC_DIS_SIZE*1.1f+25.f, YRank-9.f), Color((int)(80*ColRedTmp/PARC_SIZE)+175, 125-(int)(110*ColRedTmp/PARC_SIZE), 0));
      Rprogress.operator[](3) = Vertex(Vector2f(DepX+(500.f*(ColRedTmp/PARC_SIZE))+PARC_DIS_SIZE*1.1f+25.f, YRank+9.f), Color((int)(80*ColRedTmp/PARC_SIZE)+175, 125-(int)(110*ColRedTmp/PARC_SIZE), 0));
      window.draw(Rprogress);
      window.draw(RunName);
      RIcon.setPosition(DepX + PARC_DIS_SIZE*1.1f, YRank-5.f);
      window.draw(RIcon);


      if (AllRunners[i].Xpos > (float)PARC_SIZE){
        AllRunners[i].CurrentPhase = 0;
        AllRunners[i].speed = 0;
      }
      else{
        for(int j = 0; j < Parc.steps; j++){
          if (AllRunners[i].Xpos > (float)Parc.Phases[j]){
            AllRunners[i].CurrentPhase = j;}
        }
        for(int k = 0; k < Parc.TurnSteps; k++){
          if (AllRunners[i].Xpos > (float)Parc.TurnsPhases[k]){
            AllRunners[i].CurrentWPhase = k;}
        }
      }

      if (AllRunners[i].Xpos <= PARC_SIZE){
        AllRunners[i].RunDeHydr();
        if (!AllRunners[i].abandon){
          AllRunners[i].RunHydr(Parc, timer);
          AllRunners[i].SpeedModif(Parc); //    /!\ contain bit of water things
          AllRunners[i].Xpos += (AllRunners[i].CurrentSpeed);
          if(AllRunners[i].Xpos > PARC_SIZE){
            for(int t = 0; t < AllRunners.size(); t++){
              if (AllRunners[t].Xpos > PARC_SIZE){
                AllRunners[t].Xpos += 15.f;
              }
            }
          }

          AllRunners[i].Ypos += ((AllRunners[i].CurrentSpeed)/reduct)*Parc.Slopes[AllRunners[i].CurrentPhase]/-100;
        }
      }
      if(AllRunners[i].Xpos > PARC_SIZE){
        RIcon.setPosition(PARC_SIZE/reduct+DepX, AllRunners[i].Ypos);
      }
      else{
        RIcon.setPosition(AllRunners[i].Xpos/reduct+DepX, AllRunners[i].Ypos);
        if(!AllRunners[i].abandon){RunIsFinished = false;}
      }
      window.draw(RIcon);
    }

    if(RunIsFinished){
      SaveClassment("Classement.txt", AllRunners);
      return 0;
    }

    window.display();

  }
  return 0;
}
