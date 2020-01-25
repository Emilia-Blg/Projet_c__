#ifndef PION_HPP
#define PION_HPP

#include <iostream>
#include <cstdlib>
#include "Unite.hpp"
#include <vector>

using namespace std;

class Pion : public Unite {

 protected :
        int prix;
	int pointVie;
	int pointAttaque;
	int portee;
	//int posCase;

 public :

Pion();

~Pion();

void setPointVie(int pv);

int getPointVie();

void setPos(int posC);

int getPos();

int getPointAttaque();

virtual string affiche()=0;

virtual void avancer(bool droite);

virtual void attaque(Pion p);

int getPortee();

virtual void action1(vector<Pion*> &allie,vector<Pion*> &ennemi, bool droite);


};

#endif
