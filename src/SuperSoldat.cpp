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
int SuperSoldat::action3(vector<Pion*> &allie,vector<Pion*> &ennemi, bool droite, Base &B, Plateau &plateau){
    if(allie.size() != 0){
        if (droite){
            if(ennemi.size() != 0){
                vector<Pion*>::iterator it=ennemi.begin();
                for (Pion* p : ennemi){
                    if (((portee) == (p->getPos()-posCase))){
                        this->attaque(p);
                        if (p->getPointVie()<=0){
                            cout<<"Pion tué par un fantassin"<<endl;
                            plateau.viderCase(p->getPos());
                            if(p->getNom() == "F"){
                                return 1;
                            }
                            if(p->getNom() == "A"){
                                return 2;
                            }
                            if(p->getNom() == "C"){
                                return 3;
                            }


                            //Pion *pp = ennemi.front();
                            ennemi.erase(ennemi.begin());
                            //pp = nullptr;
                            //cout<<"remove"<<endl;
                            //p++;

                        }
                    }
                    it++;
                }
            }
            if ((ennemi.empty())&&(posCase+portee == 12)){
                B.setPointVie(B.getPointVie()-pointAttaque);
            }
        }
        else{
            if(ennemi.size() != 0){
                vector<Pion*>::iterator it=ennemi.begin();
                for (Pion* p : ennemi){
                    if (((portee)==(posCase-p->getPos()))){
                        this->attaque(p);
                        if (p->getPointVie()<=0){
                            cout<<"Pion tué par un fantassin"<<endl;
                            plateau.viderCase(p->getPos());

                            if(p->getNom() == "F"){
                                return 1;
                            }
                            if(p->getNom() == "A"){
                                return 2;
                            }
                            if(p->getNom() == "C"){
                                return 3;
                            }


                            //Pion *pp = ennemi.front();
                            ennemi.erase(ennemi.begin());
                            //pp = nullptr;
                            //cout<<"remove"<<endl;
                            //p++;
                        }
                    }
                    it++;
                }
            }
            if ((ennemi.empty())&&(posCase-portee == 0)){
                B.setPointVie(B.getPointVie()-pointAttaque);
            }
        }
    }
    return 0;
}


