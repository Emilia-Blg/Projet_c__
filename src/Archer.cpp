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

int Archer::action1(vector<Pion *> &allie, vector<Pion *> &ennemi, bool droite, Base &B) {

    bool tue = false;
    if (droite){
        vector<Pion*>::iterator it=ennemi.begin();
        for (Pion* p : ennemi){
            if (    ((portee)>=(p->getPos()-posCase))  &&  (atq==false)    ){       //si position ennemie + proche - position actuel <= 3 alors attaque
                this->attaque(p);
                if (p->getPointVie()<=0){
                    cout<<"Pion tué"<<endl;
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
        if (  (ennemi.empty())  &&  ((posCase+portee) >= 11)  &&  !atq){ //12 à voir
            B.setPointVie(B.getPointVie()-pointAttaque);
            atq=true;
        }
    }
    else{
        vector<Pion*>::iterator it=ennemi.begin();
        for (Pion* p : ennemi){
            if (  ((portee) >= (posCase-p->getPos() ))  &&  (atq==false)){
                this->attaque(p);
                if (p->getPointVie()<=0){
                    cout<<"Pion tué"<<endl;
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
        if ( (ennemi.empty()) && ((posCase-portee) >= 0) && !atq){ //1 à voir
            B.setPointVie(B.getPointVie()-pointAttaque);
            atq=true;
        }
    }
    return 0;
}



//ACTION 2 : AVANCE
void Archer::action2(vector<Pion*> &allie,vector<Pion*> &ennemi, bool droite, Base &B, Plateau plateau){
    if(droite){         //cas du joueur 1
        for(int i=0; i< allie.size(); i++){
            if(this->getNom() != "C"){          //si la pion est une catapulte on passe a la case suivante
                i++;
            }

            if(this->getPos() != (ennemi.front()->getPos()-1)){
                cout << "test6" << endl;

                plateau.placer(*this, this->getPos()+1);
                cout << "test8" << endl;

                plateau.viderCase(this->getPos()-1);
                cout << "test9" << endl;
            }
        }
    }else {

        for (int i = 0; i < ennemi.size(); i++) {
            if (ennemi[i]->getNom() != "C") {          //si la pion est une catapulte on passe a la case suivante
                i++;
            }
            if(this->getPos() != (ennemi.front()->getPos()-1)){
                cout << "test66" << endl;

                plateau.placer(*this, this->getPos()-1);
                cout << "test88" << endl;

                plateau.viderCase(allie[i]->getPos()+1);
                cout << "test99" << endl;
            }
        }
    }
}



void action3(std::vector<Pion*> &allie,std::vector<Pion*> &ennemi, bool droite, Base &B){

}
