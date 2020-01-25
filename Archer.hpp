#ifndef ARCHER_HPP
#define ARCHER_HPP
#include "Pion.hpp"

#include <iostream>

using namespace std;

class Archer : public Pion{

 public :

        Archer();

        ~Archer();
        void action1(vector<Pion*> &allie,vector<Pion*> &ennemi, bool droite);


};
#endif
