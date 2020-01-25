#include <iostream>
#include "../header/Pion.hpp"
#include "../header/Unite.hpp"

using namespace std;

Pion::Pion(){}

Pion::~Pion(){}

int Pion :: getPointAttaque(){
    return pointAttaque;
}

void Pion::avancer(bool droite){
    if(droite){setPos(this->getPos() + 1);}
    else{setPos(this->getPos() -1);}
}

void Pion::attaque(Pion p){
    p.setPointVie(p.getPointVie() - (this->getPointAttaque()));
}
void Pion::action1(vector<Pion*> &allie,vector<Pion*> &ennemi, bool droite){std::cout<<"Action 1 du pion";}
int Pion :: getPortee(){
    return portee;
}



