#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>

#ifndef PARC_SIZE
# define PARC_SIZE 42000
#endif

#ifndef PARC_DIS_SIZE
# define PARC_DIS_SIZE 960.f
#endif

#ifndef TIME_MOD
# define TIME_MOD 2.f
#endif

#ifndef NB_RUNNER
# define NB_RUNNER 100
#endif

// 0 => load last parcour saved in .txt
// 1 => generate a new parcour
#ifndef GENERATE_OR_LOAD
# define GENERATE_OR_LOAD 1
#endif


#ifndef M_PI
# define M_PI 3.14159265
#endif
