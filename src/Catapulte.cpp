#include <iostream>
#include "../header/Catapulte.hpp"
#include <cstdlib>

using namespace std;

Catapulte::Catapulte(){
    nom = "C";
    prix = 22;
    pointVie = 12;
    pointAttaque = 6;
    portee = 4;
    atq = false;
}

Catapulte::~Catapulte(){}

string Catapulte::affiche(){
    return " C ";
}

string Catapulte::getNom(){
    return nom;
}

int Catapulte::action1(vector<Pion *> &allie, vector<Pion *> &ennemi, bool droite, Base &B, Plateau &plateau){
    bool tue = false;
    if (droite){
        vector<Pion*>::iterator it=ennemi.begin();
        for (Pion* p : ennemi){
            if(  ((p->getPos()-posCase) == 2)  && (!atq) ){
                if((p++)->getPos() == 3){                                       //pion dans la case d'a coté
                    this->attaque(p);
                    this->attaque(p++);
                    if ((p->getPointVie()<=0) && ((p++)->getPointVie()<=0)){
                        cout << "2 Pions tués" << endl;
                        if((p->getNom() == "F") && ((p++)->getNom() == "F")){
                            return 4;
                        }
                        if((p->getNom() == "A") && ((p++)->getNom() == "A")){
                            return 5;
                        }
                        if((p->getNom() == "C") && ((p++)->getNom() == "C")){
                            return 6;
                        }
                        if(  ((p->getNom() == "A") && ((p++)->getNom() == "F"))  ||   (((p++)->getNom() == "A") && (p->getNom() == "F")) ){
                            return 7;
                        }
                        if(  ((p->getNom() == "A") && ((p++)->getNom() == "C"))  ||   (((p++)->getNom() == "A") && (p->getNom() == "C")) ){
                            return 8;
                        }
                        if(  ((p->getNom() == "F") && ((p++)->getNom() == "C"))  ||   (((p++)->getNom() == "F") && (p->getNom() == "C")) ){
                            return 9;
                        }
                    }
                    plateau.viderCase((*it.base())->getPos());
                    ennemi.erase(it); //todo : Voir pour changer le deuxieme it
                    ennemi.erase(it++);
                }else{
                    this->attaque(p);
                    if (p->getPointVie()<=0){
                        cout<<"Pion tué";
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
                }
            }else if(  ((p->getPos()-posCase) >= 2) && ((p->getPos()-posCase) <= 4) &&  (!atq)  ){
                if((p++)->getPos() == 4){
                    this->attaque(p);
                    this->attaque(p++);
                    if ((p->getPointVie()<=0) && ((p++)->getPointVie()<=0)){
                        cout << "2 Pions tués" << endl;

                        if((p->getNom() == "F") && ((p++)->getNom() == "F")){
                            return 4;
                        }
                        if((p->getNom() == "A") && ((p++)->getNom() == "A")){
                            return 5;
                        }
                        if((p->getNom() == "C") && ((p++)->getNom() == "C")){
                            return 6;
                        }
                        if(  ((p->getNom() == "A") && ((p++)->getNom() == "F"))  ||   (((p++)->getNom() == "A") && (p->getNom() == "F")) ){
                            return 7;
                        }
                        if(  ((p->getNom() == "A") && ((p++)->getNom() == "C"))  ||   (((p++)->getNom() == "A") && (p->getNom() == "C")) ){
                            return 8;
                        }
                        if(  ((p->getNom() == "F") && ((p++)->getNom() == "C"))  ||   (((p++)->getNom() == "F") && (p->getNom() == "C")) ){
                            return 9;
                        }
                    }
                    ennemi.erase(it);
                    ennemi.erase(it++);
                }else{
                    this->attaque(p);
                    if (p->getPointVie()<=0){
                        cout<<"Pion tué";
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
                }
            }
            atq=true;
            it++;
        }
        if (  (ennemi.empty())  &&  (posCase != 10)  &&  ((posCase+portee) >= 11)  &&  !atq){
            B.setPointVie(B.getPointVie()-pointAttaque);
            atq=true;
        }
    }
    else{
        vector<Pion*>::iterator it=ennemi.begin();
        for (Pion* p : ennemi){
            if(  ((posCase-p->getPos()) == 2)  && (!atq) ){
                if((p--)->getPos() == 3){                                       //pion dans la case d'a coté
                    this->attaque(p);
                    this->attaque(p--);
                    if ((p->getPointVie()<=0) && ((p--)->getPointVie()<=0)){
                        cout << "2 Pions tués" << endl;
                        if((p->getNom() == "F") && ((p--)->getNom() == "F")){
                            return 4;
                        }
                        if((p->getNom() == "A") && ((p--)->getNom() == "A")){
                            return 5;
                        }
                        if((p->getNom() == "C") && ((p--)->getNom() == "C")){
                            return 6;
                        }
                        if(  ((p->getNom() == "A") && ((p--)->getNom() == "F"))  ||   (((p--)->getNom() == "A") && (p->getNom() == "F")) ){
                            return 7;
                        }
                        if(  ((p->getNom() == "A") && ((p--)->getNom() == "C"))  ||   (((p--)->getNom() == "A") && (p->getNom() == "C")) ){
                            return 8;
                        }
                        if(  ((p->getNom() == "F") && ((p--)->getNom() == "C"))  ||   (((p--)->getNom() == "F") && (p->getNom() == "C")) ){
                            return 9;
                        }
                    }
                    ennemi.erase(it);
                    ennemi.erase(it--);
                }else{
                    this->attaque(p);
                    if (p->getPointVie()<=0){
                        cout<<"Pion tué";
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
                }
            }else if(  ((posCase-p->getPos()) >= 2) && ((posCase-p->getPos()) <= 4) &&  (!atq)  ){
                if((p++)->getPos() == 4){
                    this->attaque(p);
                    this->attaque(p--);
                    if ((p->getPointVie()<=0) && ((p--)->getPointVie()<=0)){
                        cout << "2 Pions tués" << endl;

                        if((p->getNom() == "F") && ((p--)->getNom() == "F")){
                            return 4;
                        }
                        if((p->getNom() == "A") && ((p--)->getNom() == "A")){
                            return 5;
                        }
                        if((p->getNom() == "C") && ((p--)->getNom() == "C")){
                            return 6;
                        }
                        if(  ((p->getNom() == "A") && ((p--)->getNom() == "F"))  ||   (((p--)->getNom() == "A") && (p->getNom() == "F")) ){
                            return 7;
                        }
                        if(  ((p->getNom() == "A") && ((p--)->getNom() == "C"))  ||   (((p--)->getNom() == "A") && (p->getNom() == "C")) ){
                            return 8;
                        }
                        if(  ((p->getNom() == "F") && ((p--)->getNom() == "C"))  ||   (((p--)->getNom() == "F") && (p->getNom() == "C")) ){
                            return 9;
                        }
                    }
                    ennemi.erase(it);
                    ennemi.erase(it--);
                }else{
                    this->attaque(p);
                    if (p->getPointVie()<=0){
                        cout<<"Pion tué";
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
                }
            }
            atq=true;
            it++;
        }
        if ( (ennemi.empty()) && (posCase != 1)  &&  ((posCase-portee) >= 0) && !atq){
            B.setPointVie(B.getPointVie()-pointAttaque);
            atq=true;
        }
    }
    return 0;
}


//ACTION 2 : AVANCE
void Catapulte::action2(vector<Pion*> &allie,vector<Pion*> &ennemi, bool droite, Base &B, Plateau &plateau){
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
        for (int i = 0; i < ennemi.size(); i++) {
            if (ennemi[i]->getNom() != "C") {          //si la pion est une catapulte on passe a la case suivante
                i++;
            }
            if(this->getPos() != (ennemi.front()->getPos()-1)){
                plateau.placer(*this, this->getPos()-1);
                plateau.viderCase(allie[i]->getPos()+1);
            }
        }
    }
}


//ACTION 3 : AVANCE
void Catapulte::action3(std::vector<Pion*> &allie,std::vector<Pion*> &ennemi, bool droite, Base &B, Plateau &plateau){
    //avance
}





