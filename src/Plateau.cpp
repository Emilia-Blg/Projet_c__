#include <iostream>
#include <cstdlib>
#include "../header/Plateau.hpp"


using namespace std;

Plateau::Plateau(){
    vector<Unite> tab(12);
}

Plateau::~Plateau(){}

//setter de tab
void Plateau::placer(Unite u, int index){
    tab[index] = u;
}

//getter de tab
Unite Plateau::getTab(int index){
    return tab[index];
}
