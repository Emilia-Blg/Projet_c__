#ifndef PION_HPP
#define PION_HPP

#include <iostream>
#include <cstdlib>
#include "Unite.hpp"
#include <vector>

using namespace std;

class Pion : public Unite {

protected :
    int prix;
    int pointVie;
    int pointAttaque;
    int portee;
    //int posCase;

public :
    Pion();
    ~Pion();

    virtual string affiche()=0;
    int getPointAttaque();
    virtual void avancer(bool droite);
    virtual void attaque(Pion p);
    int getPortee();
    virtual void action1(vector<Pion*> &allie,vector<Pion*> &ennemi, bool droite);
};

#endif
