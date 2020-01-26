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

    //action1 et 2 de fantassin

    int action3(std::vector<Pion*> &allie,std::vector<Pion*> &ennemi, bool droite, Base &B, Plateau &plateau);

    };
#endif
