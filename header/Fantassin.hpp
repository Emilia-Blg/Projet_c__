#ifndef FANTASSIN_HPP
#define FANTASSIN_HPP
#include "Pion.hpp"
#include "Base.hpp"
#include <vector>

#include <cstdlib>

#include <iostream>

using namespace std;

class Fantassin : public Pion {
    bool atq;

public :

    Fantassin();
    ~Fantassin();
    void action1(std::vector<Pion*> &allie,std::vector<Pion*> &ennemi, bool droite, Base &B);
    void action2(std::vector<Pion*> allie,std::vector<Pion*> ennemi, bool droite);
    void action3(std::vector<Pion*> allie,std::vector<Pion*> ennemi, bool droite);
};
#endif
