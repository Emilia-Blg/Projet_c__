#include <iostream>
#include "../header/Pion.hpp"
#include "../header/Unite.hpp"

using namespace std;

Pion::Pion()
        {
	    
        }

Pion::~Pion()
        {

        }

void Pion :: setPointVie(int pv)
	{
		pointVie = pv;
	}

int Pion :: getPointVie()
	{
		return pointVie;
	}

void Pion :: setPos(int posC)
	{
            posCase = posC;
	}

int Pion :: getPos()
	{
		return posCase;
	}

int Pion :: getPointAttaque()
	{
		return pointAttaque;
	}

void Pion::avancer(bool droite)
	{
		if(droite){setPos(this->getPos() + 1);}
		else{setPos(this->getPos() -1);}
	}

 void Pion::attaque(Pion p) 
 {
		p.setPointVie(p.getPointVie() - (this->getPointAttaque()));
 }

int Pion :: getPortee()
{
    return portee;
}

void Pion::action1(vector<Pion*> &allie,vector<Pion*> &ennemi, bool droite)
{
    std::cout<<"Action 1 du pion";
}




