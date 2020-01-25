#include <iostream>
#include <cstdlib>
#include "../header/Plateau.hpp"
#include "../header/Pion.hpp"


using namespace std;

Plateau::Plateau(){
    tab = vector<Unite*>(12);
    for(Unite* unit : tab) {
        unit = nullptr;
    }
}

Plateau::~Plateau(){}

//setter de tab
void Plateau::placer(Unite& u, int index){
    //TODO dans plateau : (dans la fonction placer) attention qu'elle set pas sur une case pleine
    //if()


        tab[index] = &u;
}

//getter de tab
Unite Plateau::getTab(int index){
    return *tab[index];
}

void Plateau::affiche(){
    cout<<endl<<"---------------------------------------------------------"<<endl<<"Plateau"<<endl;
    cout<<"Base A |";
    string pions = "";
    for(int cpt=1; cpt<11; cpt++) { //Boucle de 1 a 11 pour enlever les bases qui ne sont pas des pions
        if(tab[cpt] != nullptr) {
            Pion *p = (Pion *) tab[cpt];
            pions += p->affiche();
        } else
            pions += "   ";
        pions += "|";
    }
    cout<<pions<<" Base B"<<endl<<"---------------------------------------------------------"<<endl<<endl;
}

void Plateau::viderCase(int index){
    //TODO dans plateau : fonction pour vider case
}


