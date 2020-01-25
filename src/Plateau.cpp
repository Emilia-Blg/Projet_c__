#include <iostream>
#include <cstdlib>
#include "../header/Plateau.hpp"


using namespace std;

Plateau::Plateau(){
    vector<Unite*> tab(12);
}

Plateau::~Plateau(){}

//setter de tab
void Plateau::placer(Unite& u, int index){
    //TODO dans plateau : (dans la fonction placer) attention qu'elle set pas sur une case pleine
    if()


    tab[index];
}

//getter de tab
Unite Plateau::getTab(int index){
    return tab[index];
}

void Plateau::viderCase(int index){
    //TODO dans plateau : fonction pour vider case
}


