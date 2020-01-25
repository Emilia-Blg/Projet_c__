#include <iostream>
#include "../header/Catapulte.hpp"
#include "../header/Pion.hpp"

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


