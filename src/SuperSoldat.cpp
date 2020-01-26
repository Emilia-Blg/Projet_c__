#include <iostream>
#include "../header/SuperSoldat.hpp"
#include "../header/Fantassin.hpp"

using namespace std;

SuperSoldat::SuperSoldat(Fantassin f){
    nom = "SS";
    pointVie = f.getPointVie();
    posCase = f.getPos();
}

SuperSoldat::~SuperSoldat(){}

string SuperSoldat::affiche(){
    return " SS ";
}

//void SuperSoldat::action1(vector<Pion *> &allie, vector<Pion *> &ennemi, bool droite, Base base) {

//}

