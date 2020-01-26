#include <iostream>
#include <cstdlib>

#include "../header/Archer.hpp"
#include "../header/Fantassin.hpp"
#include "../header/SuperSoldat.hpp"
#include "../header/Catapulte.hpp"
#include "../header/Joueur.hpp"
#include "../header/Plateau.hpp"
#include "../header/Base.hpp"
#include <vector>
#include <iterator>
#include <algorithm>


//TODO problème remplissage de mon plateau et de ma listeEquipe


//TODO dans joueur : les fonctions action prennent en paramètre mon plateau
// + dettecter le pion le plus avancer pour le faire jouer en premier puis décrémente/incrémente
// + faire son action (déplacer/attaquer)
// TODO action 3



using namespace std;

static int i=0;



//choix des pions que le joueur souhaite acheter
bool menu(Joueur &j){
    bool b;
    cout << "Quel pion souhaitez-vous acheter ? \n\t0 : fantassin (10 pieces) \t1 : archer (12 pieces) \t2 : catapulte (22 pieces) \t3 : Rien" <<  endl;
    cout << "PIECES DISPONIBLES : " << j.getPO()<<endl;
    cin >> i;

    switch(i){
        case 0 :
            if(j.getPO() >= 10){
                j.setPO(j.getPO()-10);
                b = true;
            }else{
                menu(j);
            }break;

        case 1 :
            if(j.getPO() >= 12){
                j.setPO(j.getPO()-12);
                b = true;
            }else{
                menu(j);
            }break;

        case 2 :
            if(j.getPO() >= 22){
                j.setPO(j.getPO()-22);
                b = true;
            }else{
                menu(j);
            }break;

        default :
            b = false;
    }
    return b;
}

//le pion acheter
Pion* achat(){
    Pion* p = nullptr;
    switch (i){
        case 0 :
            p =  new Fantassin();
            break;

        case 1 :
            p = new Archer();
            break;
        default :
            p = new Catapulte();
            break;
    }
    return p;
}





int main (int argc, char *argv[]){
    //const int addPO = 8;
    int TOURMAX = 20;
    int modeJeu; //Pour selectionner vsIA ou vsJ2

//Affichage du menu & Selection mode
    do{
        cout<<"MODE DE JEU" << endl <<"1- J1 vs J2" << endl <<"2- J1 vs IA"<< endl;
        cin>> modeJeu;
    }while((modeJeu != 1) && (modeJeu != 2));

//n=1 : J1 vs J2
//n=2 : J1 vs IA

//Selectionner nb de tour :
    cout<<"Nombre de tours maximums";
    cin>> TOURMAX;


//LANCEMENT DU JEU
    cout<<"____________________________________________________________________"<< endl <<"____________________________________________________________________"<< endl<<"____________________________________________________________________\n\n"<< endl;


/**--Mode de jeu J1 vs J2*/

//Initialisation : 
    int nbTour=1;

//Création des 2 joueurs j1 et j2
    Joueur j1;
    j1.setPV(100);
    j1.setPO(0);
    j1.setBool(true);

    Joueur j2;
    j2.setPV(100);
    j2.setPO(0);
    j2.setBool(false);

//Création du plateau
    Plateau plateau = Plateau();

//Création des bases t0
    Base b1;
    Base b2;

//placer les unités by Emilia
     b1.setPos(0);
     plateau.placer(b1,0);//Placement de b1
     b2.setPos(11);
     plateau.placer(b2,11);//Placement de b2


//Boucle de jeu (Tant que nbTour<TOURMAX && j1.nbPV>0 && j2.nbPV >0)
    while (nbTour<=TOURMAX){            //manque la seconde condition


//Chaque joueur recoit 8 Pièces d'or
        j1.addPO(8);
        j2.addPO(8);

//TOUR DE JEU J1



//PERIODE D'ACHATS J1
        cout << "\n\n\n\n\t Joueur 1"<<  " \n"<< endl;
        bool a = menu(j1);

		if (a) {
			Pion* pionAchete = achat();
			pionAchete->setPos(1);
			j1.add(pionAchete);
			plateau.placer(*pionAchete,1);
            //affiche liste des pion de J1
			cout<<"\n"<<endl;
            for(int i=0; i<j1.getListeEquipe().size(); i++){
                cout<< j1.getPion(i)->getNom() <<"      "<<j1.getPion(i)->getPos();
                cout<<""<<endl;

            }

			a =false;
		}

//PERIODE D'ACHATS J2
        cout << "\n\n\n\n\t Joueur 2"<<  " \n"<< endl;
        bool b = menu(j2);

        if (b) {
            Pion* pionAchete = achat();
            pionAchete->setPos(10);
            j2.add(pionAchete);
            plateau.placer(*pionAchete,10);
            //affiche liste des pion de J2
            cout<<"\n"<<endl;
            for(int i=0; i<j2.getListeEquipe().size(); i++){
                cout<< j2.getPion(i)->getNom() <<"      "<<j2.getPion(i)->getPos();
                cout<<""<<endl;

            }

            b =false;
        }

        plateau.affiche();

        vector<Pion*> j1Equipe = j1.getListeEquipe(), j2Equipe = j2.getListeEquipe();

        j1.action1(j1Equipe, j2Equipe, j1.getBool(), b1, plateau);
        cout << "ACTION 1 | JOUEUR 1" << endl;
        j2.action1(j2Equipe, j1Equipe, j2.getBool(), b2, plateau);
        cout << "ACTION 1 | JOUEUR 2" << endl;


        j1.action2(j1Equipe, j2Equipe, j1.getBool(), b1, plateau);
        cout << "ACTION 2 | JOUEUR 1" << endl;
        j2.action2(j2Equipe, j1Equipe, j2.getBool(), b2, plateau);
        cout << "ACTION 2 | JOUEUR 2" << endl;

        //j1.action3(j1.getListeEquipe(), j2.getListeEquipe(), j1.getBool(), b1, plateau);
        //cout << "ACTION 3 | JOUEUR 1" << endl;
        //j2.action3(j2.getListeEquipe(), j1.getListeEquipe(), j2.getBool(), b2, plateau);
        //cout << "ACTION 3 | JOUEUR 2" << endl;



/*------------------Quand tout fonctionne----------------------- */
//Si commande de sauvegarde, stopper le jeu
//Si commande de chargement, reprendre le jeu dans la boucle
/* ------------------------------------------------------------- */


        nbTour+=1;
    }
    //Fin de Boucle

    if((b1.getPointVie() == 0) && (nbTour != TOURMAX)){
        cout << " JOUEUR 2 À GAGNER !!!! " << endl;
    }

    if((b2.getPointVie() == 0) && (nbTour != TOURMAX)){
        cout << " JOUEUR 1 À GAGNER !!!! " << endl;
    }

    if(nbTour == TOURMAX){
        cout << " EGALITE " << endl;
    }

//Fin du jeu
}

