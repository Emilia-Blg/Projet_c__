#include <iostream>
#include <cstdlib>
#include "../header/Plateau.hpp"
#include "../header/Pion.hpp"


using namespace std;

Plateau::Plateau(){
    tab = vector<Unite*>(12);
    for(Unite* unit : tab) {
        unit = nullptr ;
    }
}

Plateau::~Plateau(){}

/** vérifie que pas de pion sur la case en question*/
/**
 * true : pion sur la
 * false : pas de pion --> ajout du pion mis en paramètre
 * */
//setter de tab
bool Plateau::placer(Unite& u, int index){
    if(tab[index] == nullptr ){
        tab[index] = &u;
        u.setPos(index);
        return true;
    }else{
        return false;
    }
}

//getter de tab
Unite Plateau::getTab(int index){
    return *tab[index];
}

vector<Unite*> Plateau::getPlateau(){
    return tab;
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


//supprime l'élément dans la case i de tab
void Plateau::viderCase(int index){
    tab[index] = nullptr;
}


