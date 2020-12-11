#if !defined(_WindCompass)
#define _WindCompass

#include "DefVal.hpp"

#include "Parcour.hpp"

class WindCompass
{
  public:
    sf::CircleShape Outer;
    sf::RectangleShape InArrow;
    sf::ConvexShape OutArrow;
    sf::Text WSpe;

    WindCompass(Parcour Par, float Xdep, float Ydep);
};


#endif
