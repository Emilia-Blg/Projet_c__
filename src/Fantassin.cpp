#include <iostream>
#include "../header/Fantassin.hpp"
#include "../header/Pion.hpp"
#include "../header/Base.hpp"
#include "../header/SuperSoldat.hpp"

using namespace std;

Fantassin::Fantassin(){
    nom = "F";
    prix = 10;
    pointVie = 10;
    pointAttaque = 4;
    portee = 1;
    //posCase;
    bool atq = false;
}

Fantassin::~Fantassin(){}

string Fantassin::getNom(){
    return nom;
}

string Fantassin::affiche(){
    return " F ";
}


/** fait l'action 1 associé au fantassin
 * retourn 1 : si tue fantassin
 * retourn 2 : si tue archer
 * retourn 3 : si tue catapulte
 * */
int Fantassin::action1(vector<Pion*> &allie,vector<Pion*> &ennemi, bool droite, Base &B){
    bool tue = false;
    if (droite){
        vector<Pion*>::iterator it=ennemi.begin();
        for (Pion* p : ennemi){
            if (((portee) >= (p->getPos()-posCase))  &&  (!atq)){
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
                    ennemi.erase(it);
                }
                atq=true;
            }
            it++;
        }
        if ((ennemi.empty())&&(posCase+portee >= 12)&&!atq){ //12 à voir
            B.setPointVie(B.getPointVie()-pointAttaque);
            atq=true;
        }
    }
    else{
        vector<Pion*>::iterator it=ennemi.begin();
        for (Pion* p : ennemi){
            if (((portee)>=(posCase-p->getPos()))&&(!atq)){
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
                    ennemi.erase(it);
                }
                atq=true;
            }
            it++;
        }
        if ((ennemi.empty())&&(posCase-portee >= 1)&&!atq){ //1 à voir
            B.setPointVie(B.getPointVie()-pointAttaque);
            atq=true;
        }
    }
    return 0;
}


//ACTION 2 : AVANCE
void Fantassin::action2(vector<Pion*> &allie,vector<Pion*> &ennemi, bool droite, Base &B, Plateau &plateau){
    if(droite == true){         //cas du joueur 1
        for(int i=0; i< allie.size(); i++){
            if(this->getNom() != "C"){          //si la pion est une catapulte on passe a la case suivante
                i++;
            }
            if(this->getPos() != (ennemi.front()->getPos()-1)){
                plateau.placer(*this, this->getPos()+1);
                plateau.viderCase(this->getPos()-1);
            }
        }
    }else {
        for (int i = 0; i < allie.size(); i++) {
            if (allie[i]->getNom() != "C") {          //si la pion est une catapulte on passe a la case suivante
                i++;
            }
            if(this->getPos() != (ennemi.front()->getPos()+1)){
                plateau.placer(*this, this->getPos()-1);
                plateau.viderCase(this->getPos()+1);
            }
        }
    }
}





void Fantassin::action3(std::vector<Pion*> &allie,std::vector<Pion*> &ennemi, bool droite, Base &B){


/**
 * Action 3 :
 *      if(atq = false)
 *      Fantassin : attaque
 *      atq = false
 * */

}



	







