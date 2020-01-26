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

    int action1(vector<Pion *> &allie, vector<Pion *> &ennemi, bool droite, Base &B);
    void action2(std::vector<Pion*> &allie,std::vector<Pion*> &ennemi, bool droite, Base &B, Plateau plateau);
    void action3(std::vector<Pion*> &allie,std::vector<Pion*> &ennemi, bool droite, Base &B);};
#endif
