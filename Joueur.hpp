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

using namespace std;

class Joueur{

	private:

		int pv;		//points de vie
		int po;		//piece d'or
		vector<Pion*> listeEquipe;  	 //resolution dynamique ----- liste de pions possédés
		vector<Unite> liste;		 //set<Unite,int> liste;  //Pour mémoriser pièces + positions pdt sauvegarde (besoin de parser?)


	public:

		Joueur();

		~Joueur();

	void setPV(int ppv);
	void setPO(int ppo);
	void addPO(int i);
	int getPO();
	vector<Pion*> getListeEquipe();
	void setListeEquipe(std::vector<Pion*> liste);
	int getPV();
	void add(Pion *p);
	void detruire(Pion* p);
	void action1();



				
};
#endif
