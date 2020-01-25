#include <iostream>
#include "Catapulte.hpp"
#include "Pion.hpp"

using namespace std;

Catapulte::Catapulte()
        {
		prix = 22;
		pointVie = 12;
		pointAttaque = 6;
		portee = 4;
        }

Catapulte::~Catapulte()
        {
		
        }
void Catapulte::action1(vector<Pion*> &allie,vector<Pion*> &ennemi, bool droite){std::cout<<"SALUT";}


