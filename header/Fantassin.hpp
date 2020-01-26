#ifndef FANTASSIN_HPP
#define FANTASSIN_HPP
#include "Pion.hpp"
#include "Base.hpp"
#include <vector>

#include <cstdlib>

#include <iostream>

using namespace std;

class Fantassin : public Pion {

protected :

    bool atq;

public :

    Fantassin();
    ~Fantassin();
    string getNom();
    string affiche();
    int action1(vector<Pion*> &allie,std::vector<Pion*> &ennemi, bool droite, Base &B, Plateau &plateau);
    void action2(vector<Pion*> &allie,std::vector<Pion*> &ennemi, bool droite, Base &B, Plateau &plateau);
    int action3(vector<Pion*> &allie,std::vector<Pion*> &ennemi, bool droite, Base &B, Plateau &plateau);
};
#endif
