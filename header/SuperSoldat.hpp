#ifndef SUPERSOLDAT_HPP
#define SUPERSOLDAT_HPP
#include "Fantassin.hpp"

#include <iostream>

using namespace std;

class SuperSoldat : public Fantassin {

public :
    SuperSoldat(Fantassin f);
    ~SuperSoldat();
    string affiche();
    //int action1(vector<Pion *> &allie, vector<Pion *> &ennemi, bool droite, Base &B);
};
#endif
