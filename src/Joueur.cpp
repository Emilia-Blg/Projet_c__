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


void Joueur::setPO(int ppo){
    po=ppo;
}

bool Joueur::getBool(){
    return joueur;
}

void Joueur::setBool(bool b){
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

//ajoute un pointeur de pion en fin de liste
void Joueur::add(Pion *p){
    listeEquipe.push_back(p);
}

Pion* Joueur::getPion(int index){
    return listeEquipe[index];
}


void Joueur::action1(vector<Pion *> &allie, vector<Pion*> &ennemi, bool droite, Base &B, Plateau &plateau){
    int a;
    if((allie.size() == 0) && (ennemi.size() == 0)){
            cout<<"Pas de pion en jeu." <<endl;
    }else {

        if (droite) { //alors camp allié : par défaut à gauche
            for (int i = 0; i <allie.size(); i++) {
                a = allie[i]->action1(allie, ennemi, droite,B, plateau);  //pour chaque pion va chercher le bon élément et fait l'action associé

                //cout<<"classe joueur | action 1 | element liste : "<< allie[i]->getNom() << "       "<< allie[i]->getPos()<<endl;

                if (a == 1) {
                    this->setPO(this->getPO() + 5); //si tue fantassin
                    cout << "\t\tFantassin énnemie tué !\n\t +5 Pieces d'Or :  " << this->getPO() << endl;
                }
                if (a == 2) {
                    this->setPO(this->getPO() + 6); //si tue archer
                    cout << "\t\tArcher énnemie tué !\n\t +6 Pieces d'Or :  " << this->getPO() << endl;
                }
                if (a == 3) {
                    this->setPO(this->getPO() + 10); //si tue catapulte
                    cout << "\t\tCatapulte énnemie tué !\n\t +10 Pieces d'Or :  " << this->getPO() << endl;
                }
                if (a == 4) {
                    this->setPO(this->getPO() + 10); //si tue catapulte
                    cout << "\t\t2 Fantassins énnemies tués !\n\t +10 Pieces d'Or :  " << this->getPO() << endl;
                }
                if (a == 5) {
                    this->setPO(this->getPO() + 12); //si tue catapulte
                    cout << "\t\t2 Archers énnemies tués !\n\t +12 Pieces d'Or :  " << this->getPO() << endl;
                }
                if (a == 6) {
                    this->setPO(this->getPO() + 20); //si tue catapulte
                    cout << "\t\t2 Catapultes énnemies tués !\n\t +20 Pieces d'Or :  " << this->getPO() << endl;
                }
                if (a == 7) {
                    this->setPO(this->getPO() + 11); //si tue catapulte
                    cout << "\t\t1 Fantassin & 1 Arché énnemies tués !\n\t +11 Pieces d'Or :  " << this->getPO() << endl;
                }
                if (a == 8) {
                    this->setPO(this->getPO() + 16); //si tue catapulte
                    cout << "\t\t1 Catapulte & 1 Arché énnemies tués !\n\t +16 Pieces d'Or :  " << this->getPO() << endl;
                }
                if (a == 9) {
                    this->setPO(this->getPO() + 15); //si tue catapulte
                    cout << "\t\t1 Fantassin & 1 Catapulte énnemies tués !\n\t +15 Pieces d'Or :  " << this->getPO() << endl;
                }
                if(a == 0){
                    //cout<<"Rien fait !"<<endl;
                }
            }
        } else {
            for (int i = 0; i < allie.size(); i++) {
                a = allie[i]->action1(allie, ennemi, droite,B, plateau);  //pour chaque pion va chercher le bon élément et fait l'action associé

                //cout<<"classe joueur | action 1 | element liste : "<< allie[i]->getNom() << "       "<< allie[i]->getPos()<<endl;


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
                    cout << "\t\t1 Fantassin & 1 Catapulte énnemies tués !\n +15 Pieces d'Or :  " << this->getPO() << endl;
                }
                if(a == 0){
                    //cout<<"Rien fait !"<<endl;
                }
            }
        }
    }
}



void Joueur::action2(vector<Pion*> &allie,vector<Pion*> &ennemi, bool droite, Base &B, Plateau &plateau){
    if(allie.size() != 0){
        for(int l=0; l<allie.size(); l++){
            allie[l]->action2(allie,ennemi,droite,B,plateau);
        }
    }
}



void Joueur::action3(vector<Pion*> &allie,vector<Pion*> &ennemi, bool droite, Base &B, Plateau &plateau){
    for(int l=0; l<allie.size(); l++){
        allie[l]->action3(allie,ennemi,droite,B,plateau);
    }
}



