#ifndef CATAPULTE_HPP
#define CATAPULTE_HPP
#include "Pion.hpp"

#include <iostream>

using namespace std;

class Catapulte : public Pion {

protected :
    string nom;
    bool atq;


public :
    Catapulte();
    ~Catapulte();

    string affiche();
    string getNom();

    int action1(vector<Pion *> &allie, vector<Pion *> &ennemi, bool droite, Base &B,Plateau &plateau);
    void action2(vector<Pion*> &allie,std::vector<Pion*> &ennemi, bool droite, Base &B, Plateau &plateau);
    int action3(vector<Pion*> &allie,std::vector<Pion*> &ennemi, bool droite, Base &B,Plateau &plateau);};
#endif
