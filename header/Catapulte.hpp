#ifndef CATAPULTE_HPP
#define CATAPULTE_HPP
#include "Pion.hpp"

#include <iostream>

using namespace std;

class Catapulte : public Pion {

public :
    Catapulte();
    ~Catapulte();

    string affiche();
    void action1(vector<Pion*> &allie,vector<Pion*> &ennemi, bool droite);
};
#endif
