#ifndef SUPERSOLDAT_HPP
#define SUPERSOLDAT_HPP
#include "Fantassin.hpp"

#include <iostream>

using namespace std;

class SuperSoldat : public Pion {

public :
    SuperSoldat(Fantassin f);
    ~SuperSoldat();
    string affiche();
    virtual void action1(vector<Pion*> &allie,vector<Pion*> &ennemi, bool droite);
};
#endif
