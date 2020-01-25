#include <iostream>
#include "../header/Fantassin.hpp"
#include "../header/Pion.hpp"
#include "../header/Base.hpp"
#include "../header/SuperSoldat.hpp"

using namespace std;

Fantassin::Fantassin()
        {
		prix = 10;
		pointVie = 10;
		pointAttaque = 4;
		portee = 1;
		//posCase;
		bool atq = false;
        }

Fantassin::~Fantassin()
        {
		
        }

void Fantassin::action1(vector<Pion*> &allie,vector<Pion*> &ennemi, bool droite, Base &B){
	cout<<"ACTION FANTASSIN"<<endl;
	bool tue = false;
//ACTION 1 : Attaque
	if (droite){
		cout<<"test FANTASSIN!!!"<<endl;
		vector<Pion*>::iterator it=ennemi.begin();
		for (Pion* p : ennemi){
			vector<Pion*>::iterator it=ennemi.begin();
			if (((portee)>=(p->getPos()-posCase))&&(atq==false)){ 
				this->attaque(*p);
				
				if (p->getPointVie()<=0){
					cout<<"Pion tué";
					allie.push_back(new SuperSoldat(*this));
					
					ennemi.erase(it);
					
				}
				atq=true;
					
			}
			it++;
		} 
	if ((droite&&(ennemi.empty())&&(posCase+portee >= 12)&&!atq)){ //12 à voir
		B.setPointVie(B.getPointVie()-pointAttaque);
		atq=true;	
	}		
	}
	else{
		vector<Pion*>::iterator it=ennemi.begin();
		for (Pion* p : ennemi){
			
			if (((portee)>=(posCase-p->getPos()))&&(atq==false)){ 
				this->attaque(*p);
				
				if (p->getPointVie()<=0){
					cout<<"Pion tué";
					allie.push_back(new SuperSoldat(*this));
					ennemi.erase(it);
				}
				atq=true;
					
			}
			it++;
		}
	if (!droite&&(ennemi.empty())&&(posCase-portee >= 1)&&!atq){ //1 à voir
		B.setPointVie(B.getPointVie()-pointAttaque);
		atq=true;	
	}
	}


}

	







