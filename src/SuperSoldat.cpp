#include <iostream>
#include "../header/SuperSoldat.hpp"
#include "../header/Fantassin.hpp"

using namespace std;

SuperSoldat::SuperSoldat(Fantassin f){
    pointVie = f.getPointVie();
    posCase = f.getPos();
}

SuperSoldat::~SuperSoldat(){
    //delete[] pointVie;
}
void SuperSoldat::action1(vector<Pion*> &allie,vector<Pion*> &ennemi, bool droite){std::cout<<"SALUT";}

