#include "DefVal.hpp"

#include "WindCompass.hpp"
#include "Parcour.hpp"

using namespace sf;

WindCompass::WindCompass(Parcour Par, float Xdep, float Ydep){
  float Radi = 25.f;
  float InRadi = Radi / -5.f;
  float CenterOffset = Radi*sqrt(2);
  float XOffset, YOffset;
  float RectX = Radi*2.4f;
  float RectY = RectX/4;
//Circle
  Outer.setRadius(Radi);
  Outer.setPointCount(20);
  Outer.setOutlineThickness(InRadi);
  Outer.setOutlineColor(Color(125, 125, 125));
  Outer.setPosition(Xdep, Ydep);
//Red Arrow Rectangle
  InArrow.setSize(Vector2f(RectX, RectY));
  InArrow.setFillColor(Color(255, 0, 0));
  XOffset = sqrt(pow(RectX/2, 2) + pow(RectY/2, 2))*cos((14.04f-Par.WdAng)*M_PI/180.f);
  YOffset = sqrt(pow(RectX/2, 2) + pow(RectY/2, 2))*sin((14.04f-Par.WdAng)*M_PI/180.f);
  InArrow.setPosition(Xdep+XOffset+Radi,Ydep+YOffset+Radi);
  InArrow.setRotation(180.f-Par.WdAng);
//Red Arrow Tip
  OutArrow.setPointCount(3);
  XOffset = sqrt(pow(RectX/2, 2) + pow(RectY/2, 2))*cos((14.04f-Par.WdAng)*M_PI/180.f);
  YOffset = sqrt(pow(RectX/2, 2) + pow(RectY/2, 2))*sin((14.04f-Par.WdAng)*M_PI/180.f);
  OutArrow.setPoint(0, Vector2f(Xdep+XOffset+Radi,Ydep+YOffset+Radi));
  XOffset = sqrt(pow(RectX/2, 2) + pow(RectY/2, 2))*cos((-14.04f-Par.WdAng)*M_PI/180.f);
  YOffset = sqrt(pow(RectX/2, 2) + pow(RectY/2, 2))*sin((-14.04f-Par.WdAng)*M_PI/180.f);
  OutArrow.setPoint(1, Vector2f(Xdep+XOffset+Radi,Ydep+YOffset+Radi));
  XOffset = sqrt(pow(RectX/1.5f, 2) + pow(RectY/2, 2))*cos((-Par.WdAng)*M_PI/180.f);
  YOffset = sqrt(pow(RectX/1.5f, 2) + pow(RectY/2, 2))*sin((-Par.WdAng)*M_PI/180.f);
  OutArrow.setPoint(2, Vector2f(Xdep+XOffset+Radi,Ydep+YOffset+Radi));
  OutArrow.setFillColor(Color(255, 0, 0));
//Text
  std::ostringstream out;
  out << std::setprecision(2) << std::fixed << Par.WdSpeed;
  //std::cout << out.str() << std::endl;
  WSpe.setString(out.str());
  WSpe.setCharacterSize(Radi/1.5f);
  WSpe.setFillColor(Color(225, 225, 225));
  WSpe.setPosition(Xdep, Ydep+(Radi*2.5f));
}
