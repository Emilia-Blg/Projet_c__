#include <iostream>
#include "../header/Archer.hpp"
#include "../header/Pion.hpp"
#include <cstdlib>

using namespace std;

Archer::Archer(){
    prix = 12;
    pointVie = 7;
    pointAttaque = 3;
    portee = 3;
}

Archer::~Archer(){}

string Archer::affiche(){
    return " A ";
}

void Archer::action1(vector<Pion*> &allie,vector<Pion*> &ennemi, bool droite){std::cout<<"SALUT";}
