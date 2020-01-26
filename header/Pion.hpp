#ifndef PION_HPP
#define PION_HPP

#include <iostream>
#include <cstdlib>
#include "Unite.hpp"
#include "Base.hpp"
#include "Plateau.hpp"
#include <vector>

using namespace std;

class Pion : public Unite {

protected :
    string nom;
    int prix;
    int pointVie;
    int pointAttaque;
    int portee;
    //int posCase;

public :
    Pion();
    ~Pion();

    virtual string getNom()=0;
    virtual string affiche()=0;
    int getPointAttaque();
    virtual void avancer(bool droite);
    virtual void attaque(Pion *p);
    int getPortee();
    virtual int action1(vector<Pion *> &allie, vector<Pion *> &ennemi, bool droite, Base &B)=0;
    virtual void action2(vector<Pion*> &allie,vector<Pion*> &ennemi, bool droite, Base &B, Plateau plateau)=0;

    };

#endif
