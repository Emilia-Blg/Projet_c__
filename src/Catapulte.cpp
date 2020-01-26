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

int Catapulte::action1(vector<Pion *> &allie, vector<Pion *> &ennemi, bool droite, Base &B){

    bool tue = false;
    if (droite){
        vector<Pion*>::iterator it=ennemi.begin();
        for (Pion* p : ennemi){
            if(  ((p->getPos()-posCase) == 2)  && (atq==false) ){
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
            }else if(  ((p->getPos()-posCase) >= 2) && ((p->getPos()-posCase) <= 4) &&  (atq==false)  ){
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
            if(  ((posCase-p->getPos()) == 2)  && (atq==false) ){
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
            }else if(  ((posCase-p->getPos()) >= 2) && ((posCase-p->getPos()) <= 4) &&  (atq==false)  ){
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
}


//ACTION 2 : AVANCE
void Catapulte::action2(vector<Pion*> &allie,vector<Pion*> &ennemi, bool droite, Base &B, Plateau plateau){
    if(droite){         //cas du joueur 1
        for(int i=0; i< allie.size(); i++){
            if(this->getNom() != "C"){          //si la pion est une catapulte on passe a la case suivante
                i++;
            }

            if(this->getPos() != (ennemi.front()->getPos()-1)){
                cout << "test6" << endl;

                this->setPos(this->getPos()+1);
                cout << "test7" << endl;

                //plateau.placer(reinterpret_cast<Unite &>(allie[i]), this->getPos());
                plateau.placer(*(allie[i]), this->getPos());
                cout << "test8" << endl;


                plateau.viderCase(this->getPos()-1);
                cout << "test9" << endl;

            }


            /*while(plateau.getTab(i+2).value() == NULL){
                allie[i]->avancer(droite);             //revient au meme que faire --> allie[i]->getPos()+1 : ancienne position +1 //->setPos(i+2)
                cout << "test6" << endl;
                plateau.placer(reinterpret_cast<Unite &>(allie[i]), i + 2);     //+1 pour pas compter la base +1 pour avancer
                cout << "test7" << endl;
                plateau.viderCase(i+1);
                cout << "test8" << endl;
            }*/
        }
    }else {

        for (int i = 0; i < ennemi.size(); i++) {
            if (ennemi[i]->getNom() != "C") {          //si la pion est une catapulte on passe a la case suivante
                i++;
            }

            if(this->getPos() != (ennemi.front()->getPos()-1)){
                cout << "test66" << endl;

                this->setPos(this->getPos()+1);
                cout << "test77" << endl;

                plateau.placer(*(allie[i]), this->getPos());
                cout << "test88" << endl;

                plateau.viderCase(allie[i]->getPos()+1);
                cout << "test99" << endl;

            }


            /*while (plateau.getTab(12 - ennemi.size() - 1).getPos() == NULL) {
                allie[i]->avancer(!droite);             //revient au meme que faire --> ennemie[i]->getPos()-1 : ancienne position -1  //->setPos(i -2)
                plateau.placer(reinterpret_cast<Unite &>(allie[i]),i - 2);     //-1 pour pas compter la base -1 pour avancer
                plateau.viderCase(i-1);
            }*/
        }
    }
}


/**
 * définir action 2 ici ?
 * **/


