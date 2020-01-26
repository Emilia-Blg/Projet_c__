#include <iostream>
#include "../header/Pion.hpp"
#include "../header/Unite.hpp"

using namespace std;

Pion::Pion(){}

Pion::~Pion(){}

int Pion::getPointAttaque(){
    return pointAttaque;
}

void Pion::avancer(bool droite){
    if(droite){setPos(this->getPos() + 1);}
    else{setPos(this->getPos() -1);}
}

 void Pion::attaque(Pion *p){
    p->setPointVie(p->getPointVie() - (this->getPointAttaque()));
}

int Pion::getPortee(){
    return portee;
}
//void Pion::action2(vector<Pion*> &allie,vector<Pion*> &ennemi, bool droite, Base &B, Plateau plateau){}




