#include <iostream>
#include <cstdlib>
#include <list>
#include <set>
#include <vector>
#include <algorithm>
#include "Joueur.hpp"

using namespace std;
   
    

Joueur::Joueur(){
	po=0;
}

void Joueur::setPV(int ppv){
        pv=ppv;
}

void Joueur::setPO(int ppo){
        po=ppo;
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

void Joueur::setListeEquipe(std::vector<Pion*> liste){
	listeEquipe=liste;
}

int Joueur::getPV(){
	return pv;
}

void Joueur::add(Pion *p){
	listeEquipe.push_back(p);	
}
	
// PROBLEME DE STD ?
void Joueur::detruire(Pion* p){
	//if((std::find(listeEquipe.begin(),listeEquipe.end(),p))!=(listeEquipe.end()))
		//Pion* pp;
		auto pp = find(listeEquipe.begin(),listeEquipe.end(),p); //A voir
		// ou alors juste listeEquipe.remove(p)
	//}
	/*else{
		std::cout << "Pièce non présente sur le plateau" ;
	}*/
}


void Joueur::action1(){}


