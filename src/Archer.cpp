#include <iostream>
#include "../header/Archer.hpp"
#include <cstdlib>

using namespace std;

Archer::Archer(){
    nom = "A";
    prix = 12;
    pointVie = 7;
    pointAttaque = 3;
    portee = 3;
    bool atq = false;

}

Archer::~Archer(){}

string Archer::affiche(){
    return " A ";
}

string Archer::getNom(){
    return nom;
}

int Archer::action1(vector<Pion *> &allie, vector<Pion *> &ennemi, bool droite, Base &B, Plateau &plateau) {
    int res =0;
    if (droite){
        if(ennemi.size() != 0){
            vector<Pion*>::iterator it=ennemi.begin();
            for (Pion* p : ennemi){
                if (    ((portee)>=(p->getPos()-posCase))  &&  (!atq)    ){       //si position ennemie + proche - position actuel <= 3 alors attaque
                    this->attaque(p);
                    if (p->getPointVie()<=0){
                        cout<<"Pion tué par un archer"<<endl;
                        plateau.viderCase(p->getPos());
                        ennemi.erase(it);
                        if(p->getNom() == "F"){
                            res = 1;
                        }
                        if(p->getNom() == "A"){
                            res = 2;
                        }
                        if(p->getNom() == "C"){
                            res = 3;
                        }
                        //plateau.viderCase((*it.base())->getPos());
                        //ennemi.erase(it);
                    }
                    atq=true;
                }
                it++;
            }
        }
        if (  (ennemi.empty())  &&  ((posCase+portee) >= 12)  &&  !atq){
            B.setPointVie(B.getPointVie()-pointAttaque);
            atq=true;
        }
    }
    else{
        if(ennemi.size() != 0){
            vector<Pion*>::iterator it=ennemi.begin();
            for (Pion* p : ennemi){
                if (  ((portee) >= (posCase-p->getPos() ))  &&  (!atq)){
                    this->attaque(p);
                    if (p->getPointVie()<=0){
                        cout<<"Pion tué par un archer"<<endl;
                        plateau.viderCase(p->getPos());
                        ennemi.erase(it);
                        if(p->getNom() == "F"){
                            res = 1;
                        }
                        if(p->getNom() == "A"){
                            res = 2;
                        }
                        if(p->getNom() == "C"){
                            res = 3;
                        }
                        //plateau.viderCase((*it.base())->getPos());
                        //ennemi.erase(it);
                    }
                    atq=true;
                }
                it++;
            }
        }
        if ( (ennemi.empty()) && ((posCase-portee) <= 0) && !atq){
            B.setPointVie(B.getPointVie()-pointAttaque);
            atq=true;
        }
    }
    return res;
}



//ACTION 2 : AVANCE
void Archer::action2(vector<Pion*> &allie,vector<Pion*> &ennemi, bool droite, Base &B, Plateau &plateau){
    if(droite == true){         //cas du joueur 1
        if(ennemi.size() != 0){
            for(int i=0; i< allie.size(); i++){
                if(this->getNom() != "C"){          //si la pion est une catapulte on passe a la case suivante
                    i++;
                }
                if(this->getPos() != (ennemi.front()->getPos()-1)){
                    plateau.placer(*this, this->getPos()+1);
                    plateau.viderCase(this->getPos()-1);
                    cout<<"j'ai avancer mon pion "<<this->getNom()<<endl;
                }
            }
        }else{
            plateau.placer(*this, this->getPos()+1);
            plateau.viderCase(this->getPos()-1);
            cout<<"j'ai avancer mon pion "<<this->getNom()<<endl;
        }
    }else {
        if(ennemi.size() != 0){
            for (int i = 0; i < allie.size(); i++) {
                if (allie[i]->getNom() != "C") {          //si la pion est une catapulte on passe a la case suivante
                    i++;
                }
                if(this->getPos() != (allie.front()->getPos()+1)){
                    plateau.placer(*this, this->getPos()-1);
                    plateau.viderCase(this->getPos()+1);
                    cout<<"j'ai avancer mon pion "<<this->getNom()<<endl;
                }
            }
        }else{
            plateau.placer(*this, this->getPos()-1);
            plateau.viderCase(this->getPos()+1);
            cout<<"j'ai avancer mon pion "<<this->getNom()<<endl;
        }
    }
}

int Archer::action3(vector<Pion*> &allie, vector<Pion*> &ennemi, bool droite, Base &B, Plateau &plateau){
    atq = false;
    return 0;
}
