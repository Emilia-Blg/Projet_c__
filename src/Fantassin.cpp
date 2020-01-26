#include <iostream>
#include "../header/Fantassin.hpp"
#include "../header/Pion.hpp"
#include "../header/Base.hpp"
#include "../header/SuperSoldat.hpp"

using namespace std;

Fantassin::Fantassin(){
    nom = "F";
    prix = 10;
    pointVie = 10;
    pointAttaque = 4;
    portee = 1;
    //posCase;
    atq = false;
}

Fantassin::~Fantassin(){}

string Fantassin::getNom(){
    return nom;
}

string Fantassin::affiche(){
    return " F ";
}


/** fait l'action 1 associé au fantassin
 * retourn 1 : si tue fantassin
 * retourn 2 : si tue archer
 * retourn 3 : si tue catapulte
 * */
int Fantassin::action1(vector<Pion*> &allie,vector<Pion*> &ennemi, bool droite, Base &B, Plateau &plateau){
    int res = 0;
    if (droite){
        if(ennemi.size() != 0){
            vector<Pion*>::iterator it=ennemi.begin();
            for (Pion* p : ennemi){
                if (((portee) == (p->getPos()-posCase))  &&  (!atq)){
                    cout<<"avant attaque du F allie pv "<< this->getPointVie()<<" F ennemi pv "<<p->getPointVie()<<endl;
                    this->attaque(p);
                    cout<<"apres attaque du F allie pv "<< this->getPointVie()<<" F ennemi pv "<<p->getPointVie()<<endl;
                    if (p->getPointVie()<=0){
                        cout<<"Pion tué par un fantassin"<<endl;
                        plateau.viderCase(p->getPos());
                        ennemi.erase(it);

                        allie.erase(allie.begin());
                        allie.push_back((Pion*)(new SuperSoldat(*this)));

                        //remplacer sur le plateau fantassin par SS
                        plateau.viderCase(allie.back()->getPos());
                        plateau.placer(*allie.back(), allie.back()->getPos());

                        if(p->getNom() == "F"){
                            res = 1;
                        }
                        if(p->getNom() == "A"){
                            res = 2;
                        }
                        if(p->getNom() == "C"){
                            res = 3;
                        }
                    }
                    atq=true;
                }
                it++;
            }
        }
        if ((ennemi.empty())&&(posCase+portee == 12)&&!atq){ //12 à voir
            B.setPointVie(B.getPointVie()-pointAttaque);
            atq=true;
        }
    }
    else{
        if(ennemi.size() != 0){
            vector<Pion*>::iterator it=ennemi.begin();
            for (Pion* p : ennemi){
                if (((portee)==(posCase-p->getPos()))&&(!atq)){
                    cout<<"avant attaque du F allie pv "<< this->getPointVie()<<" F ennemi pv "<<p->getPointVie()<<endl;
                    this->attaque(p);
                    cout<<"apres attaque du F allie pv "<< this->getPointVie()<<" F ennemi pv "<<p->getPointVie()<<endl;
                    if (p->getPointVie()<=0){
                        cout<<"Pion tue par un fantassin"<<endl;
                        plateau.viderCase(p->getPos());
                        ennemi.erase(it);

                        allie.erase(allie.end());
                        allie.push_back((Pion*)(new SuperSoldat(*this)));

                        //remplacer sur le plateau fantassin par SS
                        plateau.viderCase(allie.front()->getPos());
                        plateau.placer(*allie.front(), allie.front()->getPos());

                        if(p->getNom() == "F"){
                            res = 1;
                        }
                        if(p->getNom() == "A"){
                            res = 2;
                        }
                        if(p->getNom() == "C"){
                            res = 3;
                        }
                    }
                    atq=true;
                }
                it++;
            }
        }
        if ((ennemi.empty())&&(posCase-portee == 0)&&!atq){ //1 à voir
            B.setPointVie(B.getPointVie()-pointAttaque);
            atq=true;
        }
    }
    cout<<endl;
    return res;
}


//ACTION 2 : AVANCE
void Fantassin::action2(vector<Pion*> &allie,vector<Pion*> &ennemi, bool droite, Base &B, Plateau &plateau){
    if(droite == true){         //cas du joueur 1
        if(ennemi.size() != 0){
            for(int i=0; i< allie.size(); i++){
                if(this->getNom() != "C"){          //si la pion est une catapulte on passe a la case suivante
                    i++;
                }
                if(this->getPos() != (ennemi.front()->getPos()-1)){
                    plateau.placer(*this, this->getPos()+1);
                    plateau.viderCase(this->getPos()-1);
                    cout<<"j'ai avancer mon pion "<<this->getNom()<<endl;
                }
            }
        }else{
            plateau.placer(*this, this->getPos()+1);
            plateau.viderCase(this->getPos()-1);
            cout<<"j'ai avancer mon pion "<<this->getNom()<<endl;
        }
    }else {
        if(ennemi.size() != 0){
            for (int i = 0; i < allie.size(); i++) {
                if (this->getNom() != "C") {          //si la pion est une catapulte on passe a la case suivante
                    i++;
                }
                if(this->getPos() != (ennemi.front()->getPos()+1)){
                    plateau.placer(*this, this->getPos()-1);
                    plateau.viderCase(this->getPos()+1);
                    cout<<"j'ai avancer mon pion "<<this->getNom()<<endl;
                }
            }
        }else{
            plateau.placer(*this, this->getPos()-1);
            plateau.viderCase(this->getPos()+1);
            cout<<"j'ai avancer mon pion "<<this->getNom()<<endl;
        }
    }
}



/**
 * Action 3 :
 *      if(atq = false)
 *      Fantassin : attaque
 *      atq = false
 * */

int Fantassin::action3(vector<Pion*> &allie,std::vector<Pion*> &ennemi, bool droite, Base &B, Plateau &plateau){
    if(!atq){
        this->action1(allie, ennemi, droite, B, plateau);
    }
    atq = false;
    return 0;
}



	







