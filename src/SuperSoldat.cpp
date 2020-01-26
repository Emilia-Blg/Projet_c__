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

//action 1 et 2 de fantassin

//ACTION 3 : ATTAQUER -> attaque TOUJOURS
int SuperSoldat::action3(std::vector<Pion*> &allie,std::vector<Pion*> &ennemi, bool droite, Base &B, Plateau &plateau){
    if (droite){
        vector<Pion*>::iterator it=ennemi.begin();
        for (Pion* p : ennemi){
            if (((portee) >= (p->getPos()-posCase))){
                this->attaque(p);
                if (p->getPointVie()<=0){
                    cout<<"Pion tué par un fantassin"<<endl;
                    allie.erase(allie.end());
                    allie.push_back(new SuperSoldat(*this));
                    if(p->getNom() == "F"){
                        return 1;
                    }
                    if(p->getNom() == "A"){
                        return 2;
                    }
                    if(p->getNom() == "C"){
                        return 3;
                    }
                    plateau.viderCase((*it.base())->getPos());
                    ennemi.erase(it);
                }
            }
            it++;
        }
        if ((ennemi.empty())&&(posCase+portee >= 12)){ //12 à voir
            B.setPointVie(B.getPointVie()-pointAttaque);
        }
    }
    else{
        vector<Pion*>::iterator it=ennemi.begin();
        for (Pion* p : ennemi){
            if (((portee)>=(posCase-p->getPos()))){
                this->attaque(p);
                if (p->getPointVie()<=0){
                    cout<<"Pion tué par un fantassin"<<endl;
                    allie.erase(allie.end());
                    allie.push_back(new SuperSoldat(*this));
                    if(p->getNom() == "F"){
                        return 1;
                    }
                    if(p->getNom() == "A"){
                        return 2;
                    }
                    if(p->getNom() == "C"){
                        return 3;
                    }
                    plateau.viderCase((*it.base())->getPos());
                    ennemi.erase(it);
                }
            }
            it++;
        }
        if ((ennemi.empty())&&(posCase-portee >= 1)){ //1 à voir
            B.setPointVie(B.getPointVie()-pointAttaque);
        }
    }
    return 0;
}


