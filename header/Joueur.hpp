#ifndef JOUEUR_HPP
#define JOUEUR_HPP
#include <iostream>
#include <cstdlib>
#include <list>
#include <set>
#include <vector>
#include <algorithm>
#include "Pion.hpp"
#include "Unite.hpp"
#include "Base.hpp"
#include "Plateau.hpp"

using namespace std;

class Joueur{

private:
    int pv;		//points de vie
    int po;		//piece d'or
    vector<Pion*> listeEquipe;  	 //resolution dynamique ----- liste de pions possédés
    vector<Unite> liste;		 //set<Unite,int> liste;  //Pour mémoriser pièces + positions pdt sauvegarde (besoin de parser?)
    bool joueur = false;

public:
    Joueur();
    ~Joueur();

    void setPV(int ppv);
    void setPO(int ppo);
    bool getBool();
    bool setBool(bool b);
    void addPO(int i);
    int getPO();
    Pion* getPion(int index);
    vector<Pion*> getListeEquipe();
    void setListeEquipe(std::vector<Pion*> liste);
    int getPV();
    void add(Pion *p);
    void detruire(Pion* p);
    void action1(vector<Pion *> allie, vector<Pion *> ennemi, bool droite, Base &B);
    void action2(vector<Pion*> allie,vector<Pion*> ennemi, bool droite, Base &B, Plateau plateau);
    void action3(vector<Pion*> allie,vector<Pion*> ennemi, bool droite, Base &B, Plateau plateau);

};
#endif
