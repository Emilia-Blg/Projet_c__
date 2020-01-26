#include <iostream>
#include <cstdlib>
#include <list>
#include <set>
#include <vector>
#include <algorithm>
#include "../header/Joueur.hpp"
#include "../header/Base.hpp"


using namespace std;



Joueur::Joueur(){
    po=0;
}

Joueur::~Joueur(){}


void Joueur::setPV(int ppv){
    pv=ppv;
}

void Joueur::setPO(int ppo){
    po=ppo;
}

bool Joueur::getBool(){
    return joueur;
}

bool Joueur::setBool(bool b){
     joueur=b;
}

void Joueur::addPO(int i){
    po+=i;
}

int Joueur::getPO(){
    return po;
}

vector<Pion*> Joueur::getListeEquipe(){
    return listeEquipe;
}

void Joueur::setListeEquipe(vector<Pion*> liste){
    listeEquipe=liste;
}

int Joueur::getPV(){
    return pv;
}

//ajoute un pointeur de pion en fin de liste
void Joueur::add(Pion *p){
    listeEquipe.push_back(p);
}

Pion* Joueur::getPion(int index){
    return listeEquipe[index];
}


// PROBLEME DE STD ?
void Joueur::detruire(Pion* p){
    //if((find(listeEquipe.begin(),listeEquipe.end(),p))!=(listeEquipe.end()))
    //Pion* pp;
    //auto pp = find(listeEquipe.begin(),listeEquipe.end(),p); //A voir
    // ou alors juste listeEquipe.remove(p)
    //}
    /*else{
        cout << "Pièce non présente sur le plateau" ;
    }*/
}


void Joueur::action1(vector<Pion *> allie, vector<Pion*> ennemi, bool droite, Base &B){
    int a;
    if((allie.size() == 0) && (ennemi.size() == 0)){
            cout<<"Pas de pion en jeu." <<endl;
    }else {

        if (droite) { //alors camp allié : par défaut à gauche
            for (int i = 0; i <allie.size(); i++) {
                a = allie[i]->action1(allie, ennemi, true,B);  //pour chaque pion va chercher le bon élément et fait l'action associé
                if (a == 1) {
                    this->setPO(this->getPO() + 5); //si tue fantassin
                    cout << "\t\tFantassin énnemie tué !\n +5 Pieces d'Or :  " << this->getPO() << endl;
                }
                if (a == 2) {
                    this->setPO(this->getPO() + 6); //si tue archer
                    cout << "\t\tArcher énnemie tué !\n +6 Pieces d'Or :  " << this->getPO() << endl;
                }
                if (a == 3) {
                    this->setPO(this->getPO() + 10); //si tue catapulte
                    cout << "\t\tCatapulte énnemie tué !\n +10 Pieces d'Or :  " << this->getPO() << endl;
                }
                if (a == 4) {
                    this->setPO(this->getPO() + 10); //si tue catapulte
                    cout << "\t\t2 Fantassins énnemies tués !\n +10 Pieces d'Or :  " << this->getPO() << endl;
                }
                if (a == 5) {
                    this->setPO(this->getPO() + 12); //si tue catapulte
                    cout << "\t\t2 Archers énnemies tués !\n +12 Pieces d'Or :  " << this->getPO() << endl;
                }
                if (a == 6) {
                    this->setPO(this->getPO() + 20); //si tue catapulte
                    cout << "\t\t2 Catapultes énnemies tués !\n +20 Pieces d'Or :  " << this->getPO() << endl;
                }
                if (a == 7) {
                    this->setPO(this->getPO() + 11); //si tue catapulte
                    cout << "\t\t1 Fantassin & 1 Arché énnemies tués !\n +11 Pieces d'Or :  " << this->getPO() << endl;
                }
                if (a == 8) {
                    this->setPO(this->getPO() + 16); //si tue catapulte
                    cout << "\t\t1 Catapulte & 1 Arché énnemies tués !\n +16 Pieces d'Or :  " << this->getPO() << endl;
                }
                if (a == 9) {
                    this->setPO(this->getPO() + 15); //si tue catapulte
                    cout << "\t\t1 Fantassin & 1 Catapulte énnemies tués !\n +15 Pieces d'Or :  " << this->getPO()
                         << endl;
                }
            }
        } else {
            for (int i = 0; i < allie.size(); i++) {
                a = allie[i]->action1(allie, ennemi, true,B);  //pour chaque pion va chercher le bon élément et fait l'action associé
                if (a == 1) {
                    this->setPO(this->getPO() + 5); //si tue fantassin
                    cout << "\t\tFantassin énnemie tué !\n +5 Pieces d'Or :  " << this->getPO() << endl;
                }
                if (a == 2) {
                    this->setPO(this->getPO() + 6); //si tue archer
                    cout << "\t\tArcher énnemie tué !\n +6 Pieces d'Or :  " << this->getPO() << endl;
                }
                if (a == 3) {
                    this->setPO(this->getPO() + 10); //si tue catapulte
                    cout << "\t\tCatapulte énnemie tué !\n +10 Pieces d'Or :  " << this->getPO() << endl;
                }
                if (a == 4) {
                    this->setPO(this->getPO() + 10); //si tue catapulte
                    cout << "\t\t2 Fantassins énnemies tués !\n +10 Pieces d'Or :  " << this->getPO() << endl;
                }
                if (a == 5) {
                    this->setPO(this->getPO() + 12); //si tue catapulte
                    cout << "\t\t2 Archers énnemies tués !\n +12 Pieces d'Or :  " << this->getPO() << endl;
                }
                if (a == 6) {
                    this->setPO(this->getPO() + 20); //si tue catapulte
                    cout << "\t\t2 Catapultes énnemies tués !\n +20 Pieces d'Or :  " << this->getPO() << endl;
                }
                if (a == 7) {
                    this->setPO(this->getPO() + 11); //si tue catapulte
                    cout << "\t\t1 Fantassin & 1 Arché énnemies tués !\n +11 Pieces d'Or :  " << this->getPO() << endl;
                }
                if (a == 8) {
                    this->setPO(this->getPO() + 16); //si tue catapulte
                    cout << "\t\t1 Catapulte & 1 Arché énnemies tués !\n +16 Pieces d'Or :  " << this->getPO() << endl;
                }
                if (a == 9) {
                    this->setPO(this->getPO() + 15); //si tue catapulte
                    cout << "\t\t1 Fantassin & 1 Catapulte énnemies tués !\n +15 Pieces d'Or :  " << this->getPO()
                         << endl;
                }
            }
        }
    }
}



void Joueur::action2(vector<Pion*> allie,vector<Pion*> ennemi, bool droite, Base &B, Plateau plateau){

    for(int l=0; l<allie.size(); l++){
        allie[l]->action2(allie,ennemi,true,B,plateau);
    }

    /**if(droite){         //cas du joueur 1
        for(int i=0; i< allie.size(); i++){
            if(allie[i]->getNom() != "C"){          //si la pion est une catapulte on passe a la case suivante
                i++;
            }

            while(allie[i]->getPos() != (ennemi.front()->getPos()-1)){
                cout << "test6" << endl;

                allie[i]->setPos(allie[i]->getPos()+1);
                cout << "test7" << endl;

                plateau.placer(reinterpret_cast<Unite &>(allie[i]), allie[i]->getPos());
                cout << "test8" << endl;

                plateau.viderCase(allie[i]->getPos()-1);
                cout << "test9" << endl;

            }


            //while(plateau.getTab(i+2).value() == NULL){
                //allie[i]->avancer(droite);             //revient au meme que faire --> allie[i]->getPos()+1 : ancienne position +1 //->setPos(i+2)
                //cout << "test6" << endl;
                //plateau.placer(reinterpret_cast<Unite &>(allie[i]), i + 2);     //+1 pour pas compter la base +1 pour avancer
                //cout << "test7" << endl;
                //plateau.viderCase(i+1);
                //cout << "test8" << endl;
            //}
        }
    }else {

        for (int i = 0; i < ennemi.size(); i++) {
            if (ennemi[i]->getNom() != "C") {          //si la pion est une catapulte on passe a la case suivante
                i++;
            }

            while(allie[i]->getPos() != (ennemi.front()->getPos()-1)){
                cout << "test66" << endl;

                allie[i]->setPos(allie[i]->getPos()+1);
                cout << "test77" << endl;

                plateau.placer(reinterpret_cast<Unite &>(allie[i]), allie[i]->getPos());
                cout << "test88" << endl;

                plateau.viderCase(allie[i]->getPos()+1);
                cout << "test99" << endl;

            }


            //while (plateau.getTab(12 - ennemi.size() - 1).getPos() == NULL) {
                //allie[i]->avancer(!droite);             //revient au meme que faire --> ennemie[i]->getPos()-1 : ancienne position -1  //->setPos(i -2)
                //plateau.placer(reinterpret_cast<Unite &>(allie[i]),i - 2);     //-1 pour pas compter la base -1 pour avancer
                //plateau.viderCase(i-1);
            //}
        }
    }*/
}




void Joueur::action3(vector<Pion*> allie,vector<Pion*> ennemi, bool droite, Base &B, Plateau plateau){
    //TODO si atq = false pour fantassin et catapulte alors
    // fantassin attaque
    // catapulte avance
}



