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
    bool atq = false;
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
int Fantassin::action1(vector<Pion*> &allie,vector<Pion*> &ennemi, bool droite, Base &B){
    bool tue = false;
    if (droite){
        vector<Pion*>::iterator it=ennemi.begin();
        for (Pion* p : ennemi){
            if (((portee) >= (p->getPos()-posCase))  &&  (atq==false)){
                this->attaque(p);
                if (p->getPointVie()<=0){
                    cout<<"Pion tué par un fantassin"<<endl;
                    allie.push_back(new SuperSoldat(*this));
                    allie.erase(allie.end());
                    if(p->getNom() == "F"){
                        return 1;
                    }
                    if(p->getNom() == "A"){
                        return 2;
                    }
                    if(p->getNom() == "C"){
                        return 3;
                    }
                    ennemi.erase(it);
                }
                atq=true;
            }
            it++;
        }
        if ((ennemi.empty())&&(posCase+portee >= 12)&&!atq){ //12 à voir
            B.setPointVie(B.getPointVie()-pointAttaque);
            atq=true;
        }
    }
    else{
        vector<Pion*>::iterator it=ennemi.begin();
        for (Pion* p : ennemi){
            if (((portee)>=(posCase-p->getPos()))&&(atq==false)){
                this->attaque(p);
                if (p->getPointVie()<=0){
                    cout<<"Pion tué par un fantassin"<<endl;
                    allie.push_back(new SuperSoldat(*this));
                    allie.erase(allie.end());        //TODO /** retire au début ou a la fin ... ??  */
                    if(p->getNom() == "F"){
                        return 1;
                    }
                    if(p->getNom() == "A"){
                        return 2;
                    }
                    if(p->getNom() == "C"){
                        return 3;
                    }
                    ennemi.erase(it);
                }
                atq=true;
            }
            it++;
        }
        if ((ennemi.empty())&&(posCase-portee >= 1)&&!atq){ //1 à voir
            B.setPointVie(B.getPointVie()-pointAttaque);
            atq=true;
        }
    }
}


//ACTION 2 : AVANCE
void Fantassin::action2(vector<Pion*> &allie,vector<Pion*> &ennemi, bool droite, Base &B, Plateau plateau){
    if(droite){         //cas du joueur 1
        for(int i=0; i< allie.size(); i++){
            if(this->getNom() != "C"){          //si la pion est une catapulte on passe a la case suivante
                i++;
            }

            if(this->getPos() != (ennemi.front()->getPos()-1)){
                cout << "test6" << endl;

                this->setPos(this->getPos()+1);
                cout << "test7" << endl;

                //plateau.placer(reinterpret_cast<Unite &>(allie[i]), this->getPos());
                plateau.setTab((const Unite &) allie[i], this->getPos());
                cout << "test8" << endl;


                plateau.viderCase(this->getPos()-1);
                cout << "test9" << endl;

            }


            /*while(plateau.getTab(i+2).value() == NULL){
                allie[i]->avancer(droite);             //revient au meme que faire --> allie[i]->getPos()+1 : ancienne position +1 //->setPos(i+2)
                cout << "test6" << endl;
                plateau.placer(reinterpret_cast<Unite &>(allie[i]), i + 2);     //+1 pour pas compter la base +1 pour avancer
                cout << "test7" << endl;
                plateau.viderCase(i+1);
                cout << "test8" << endl;
            }*/
        }
    }else {

        for (int i = 0; i < ennemi.size(); i++) {
            if (ennemi[i]->getNom() != "C") {          //si la pion est une catapulte on passe a la case suivante
                i++;
            }

            if(this->getPos() != (ennemi.front()->getPos()-1)){
                cout << "test66" << endl;

                this->setPos(this->getPos()+1);
                cout << "test77" << endl;

                plateau.setTab(reinterpret_cast<Unite &>(allie[i]), this->getPos());
                cout << "test88" << endl;

                plateau.viderCase(allie[i]->getPos()+1);
                cout << "test99" << endl;

            }


            /*while (plateau.getTab(12 - ennemi.size() - 1).getPos() == NULL) {
                allie[i]->avancer(!droite);             //revient au meme que faire --> ennemie[i]->getPos()-1 : ancienne position -1  //->setPos(i -2)
                plateau.placer(reinterpret_cast<Unite &>(allie[i]),i - 2);     //-1 pour pas compter la base -1 pour avancer
                plateau.viderCase(i-1);
            }*/
        }
    }
}





void Fantassin::action3(std::vector<Pion*> &allie,std::vector<Pion*> &ennemi, bool droite, Base &B){


/**
 * Action 3 :
 *      if(atq = false)
 *      Fantassin : attaque
 *      atq = false
 * */

}



	







