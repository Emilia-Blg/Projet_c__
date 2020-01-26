#ifndef ARCHER_HPP
#define ARCHER_HPP
#include "Pion.hpp"
#include "Base.hpp"
#include <vector>

#include <cstdlib>

#include <iostream>

using namespace std;

class Archer : public Pion{

protected :

    bool atq;

public :
    Archer();
    ~Archer();
    string affiche();
    string getNom();
    int action1(vector<Pion *> &allie, vector<Pion *> &ennemi, bool droite, Base &B, Plateau &plateau);
    void action2(vector<Pion*> &allie, vector<Pion*> &ennemi, bool droite, Base &B, Plateau &plateau);
    int action3(vector<Pion*> &allie, vector<Pion*> &ennemi, bool droite, Base &B, Plateau &plateau);
};
#endif
