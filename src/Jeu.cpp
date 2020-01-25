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


//TODO dans plateau : (dans la fonction placer) attention qu'elle get pas sur une case pleine
//TODO dans plateau : fonction pour vider case

//TODO dans joueur : les fonctions action prennent en paramètre mon plateau
// + dettecter le pion le plus avancer pour le faire jouer en premier puis décrémente/incrémente
// + faire son action (déplacer/attaquer)
//TODO dans chaque pion : redéfinir les actions

//TODO assigner point de dégat 
//TODO qui meurt

//done
//TODO qui gagne !!

//ATTENTION J1 et J2 pas pareil en terme de sens 
//utiliser boolean pour savoir quel joueur joue, adapter le code en fonction

using namespace std;

static int tour;
static int i=0;

//prend en paramètre une liste des pions d'un joueur
//trier selon position MAIS deja trier selon l'ordre d'achat 
vector<Pion*> TriProche(vector<Pion*> listEquip){
    vector<Pion*> res;
    int taille = listEquip.size();
    Pion* first = nullptr  ;
    for (int i=0; i<taille; i++) {
        for (Pion* p : listEquip) {
            first = listEquip.front();
            if (p->getPos() < first->getPos()) {
                first = p;
            }
        }
        res.push_back(first); //On enregistre
        vector<Pion*>::iterator it=find(listEquip.begin(), listEquip.end(), first);
        listEquip.erase(it); //Une fois trié, on efface l'élément
    }
    return res;
}

vector<Pion*> TriLoin(vector<Pion*> listEquip){
    vector<Pion*> res;
    int taille = listEquip.size();
    Pion* first = nullptr  ;
    for (int i=0; i<taille; i++) {
        for (Pion* p : listEquip) {
            first = listEquip.front();
            if (p->getPos() > first->getPos()) {
                first = p;
            }
        }
        res.push_back(first); //On enregistre
        vector<Pion*>::iterator it=find(listEquip.begin(), listEquip.end(), first);
        listEquip.erase(it); //Une fois trié, on efface l'élément
    }
    return res;
}

//choix des pions que le joueur souhaite acheter
bool menu(Joueur &j){
    bool b;
    cout << "Quel pion souhaitez-vous acheter ? \n\t0 : fantassin \n\t1 : archer \n\t2 : catapulte  \n\t3 : Rien" <<  endl;
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
    switch (i){
        case 0 :
            return new Fantassin();
        case 1 :
            return new Archer();
        default :
            return new Catapulte();
    }
}

void action1(Joueur j1, Joueur j2){
    if((tour=1)&&(!j1.getListeEquipe().empty())){
        vector<Pion*> listAllie = TriProche(j1.getListeEquipe());
        vector<Pion*> listEnnemi = TriProche(j2.getListeEquipe());
        vector<Pion*> &plistAllie=listAllie;
        vector<Pion*> &plistEnnemi=listEnnemi;

        for (Pion* p : listAllie){
            Pion* &p2=p;
            p2->action1(plistAllie,plistEnnemi, true);
        }
        j1.setListeEquipe(listAllie); //MAJ des equipes
        j2.setListeEquipe(listEnnemi);
    }

    /*if((tour=2)&&(!j2.getListeEquipe().empty())){
        vector<Pion*> listAllie = TriLoin(j2.getListeEquipe());
        vector<Pion*> listEnnemi = TriLoin(j1.getListeEquipe());
        for (Pion* p : listAllie){
                p->action1(listAllie,listEnnemi, false);
                    }
        j2.setListeEquipe(listAllie); //MAJ des equipes
        j1.setListeEquipe(listEnnemi);
    }*/
    cout<<"Fin Action 1 du joueur";
}
//ACTIONNER LES PIONS EN FONCTION de int = 1 ou =2
//lister toutes les pièces du plateau p dans deux liste (j1 et j2)
//mémoriser leur position dans un tableau de meme dimension (j1 et j2)
//respecter l'odre de jeu (concentrique ou excentrique pour action 3) et effectuer les actions de chaque pion
// switch case : fantassin, catapulte...
// ex du case fantassin : si (il n'y a pas d'allié devant)
//	calculer la distance de chaque pièce ennemie
//	considérer celle à la plus petite distance
//	si portée>=distance(pièce ennemie) : attaquer la pièce cad :
//					pièce.attaquer(ennemi)=ennemi.setPV(ennemi.getPV-pièce.getAttaque);
//					si ennemi.PV<=0 : ennemi.tuer() et j.delete(Pion)
//CAS ACTION 2
//SI p.pos =2, et
// si personne devant
// pièce.avancer()
//CAS ACTION 3 : comme Action1 mais dans ordre inverse
//}

//TODO

/*
void action2(Joueur j1, Joueur j2){
   if((tour=1)&&(!j1->getListeEquipe().empty())){
       vector<Pion*> listAllie = TriLoin(j1.getListeEquipe());
       vector<Pion*> listEnnemi = TriLoin(j2.getListeEquipe());
       for (Pion* p : listAllie){
               p->action2(listAllie,listEnnemi, true);
                   }
       j1.setListEquipe(listAllie); //MAJ des equipes
       j2.setListEquipe(listEnnemi);
   }

   if((tour=2)&&(!j2->getListeEquipe().empty())){
       vector<Pion*> listAllie = TriProche(j2.getListeEquipe());
       vector<Pion*> listEnnemi = TriProche(j1.getListeEquipe());
       for (Pion* p : listAllie){
               p->action2(listAllie,listEnnemi, false);
                   }
       j2.setListEquipe(listAllie); //MAJ des equipes
       j1.setListEquipe(listEnnemi);
   }
}
void action3(Joueur j1, Joueur j2){
   if((tour=1)&&(!j1.getListeEquipe().empty())){
       vector<Pion*> listAllie = TriProche(j1.getListeEquipe());
       vector<Pion*> listEnnemi = TriProche(j2.getListeEquipe());
       for (Pion* p : listAllie){
               p->action3(listAllie,listEnnemi, true);
                   }
       j1.setListEquipe(listAllie); //MAJ des equipes
       j2.setListEquipe(listEnnemi);
   }

   if((tour=2)&&(!j2.getListeEquipe().empty())){
       vector<Pion*> listAllie = TriLoin(j2.getListeEquipe());
       vector<Pion*> listEnnemi = TriLoin(j1.getListeEquipe());
       for (Pion* p : listAllie){
               p->action3(listAllie,listEnnemi, false);
                   }
       j2.setListEquipe(listAllie); //MAJ des equipes
       j1.setListEquipe(listEnnemi);
   }
}
*/

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


//--Mode de jeu J1 vs J2

//Initialisation : 
    int nbTour=1;

//Création des 2 joueurs j1 et j2

    Joueur j1;
    j1.setPV(100);
    j1.setPO(0);
    //Joueur &jj1=j1;

    Joueur j2;
    j2.setPV(100);
    j2.setPO(0);
    //Joueur &jj2=j2;

//Création du plateau
    Plateau plateau = Plateau();

//Création des unités t0 : la base -
    Base b1; //on met les bases hors de la liste des unités
    Base b2;

//Placement des unités t0
    //Placement des unités t0 (by Fabien)
    /*b1.setPos(1); //Champ-position à zero
    plateau.placer(b1,0);//Placement de b1
    b2.setPos(12);
    plateau.placer(b2,13);//Placement de b2*/

//placer les unités by Emilia
     b1.setPos(0); //Champ-position à zero
     plateau.placer(b1,0);//Placement de b1
     b2.setPos(11);
     plateau.placer(b2,11);//Placement de b2

     cout << "base 1 : " << b1.getPos() << endl;
     cout << "base 2 : " << b2.getPos() << endl;

//Boucle de jeu (Tant que nbTour<TOURMAX && j1.nbPV>0 && j2.nbPV >0)


    while (nbTour<=TOURMAX){

//Chaque joueur recoit 8 PO
        j1.addPO(8);
        j2.addPO(8);


//TOUR DE JEU J1
        tour =1;
        action1(j1,j2);

/*
action2(j1,j2);
action3(j1,j2);
*/

//PERIODE D'ACHATS
        cout << "\n\n\n\n\t Joueur 1"<<  " \n"<< endl;
        bool a = menu(j1);

		if (a) {
			Pion* pionAchete = achat(); 
			pionAchete->setPos(1);
			j1.add(pionAchete);
			plateau.placer(*pionAchete,1);
			a =false;
		}

        for(int y=0; y < j1.getListeEquipe().size(); y++){
            cout << "J1 enregistre perso " << j1.getListeEquipe()[y]->affiche() << endl;
        }

	    cout << "nbTour : " << nbTour << endl;


//TOUR DE JEU J2
        tour =2;
        //action1(j2,j1);
/*
action2(j2,j1);
action3(j2,j1);
*/

//PERIODE D'ACHATS
        cout << "\n\n\n\n\t Joueur 2"<<  " \n"<< endl;
        bool b = menu(j2);

        if (b) {
            Pion* pionAchete = achat();
            pionAchete->setPos(10);
            j2.add(pionAchete);
            plateau.placer(*pionAchete,10);
            b =false;
        }

		for(int y=0; y < j2.getListeEquipe().size(); y++){
            cout << "J2 enregistre perso " << j2.getListeEquipe()[y]->affiche() << endl;
        }


/*------------------Quand tout fonctionne----------------------- */
//Si commande de sauvegarde, stopper le jeu
//Si commande de chargement, reprendre le jeu dans la boucle
/* ------------------------------------------------------------- */


        if(b1.getPointVie() == 0){
            cout << " Joueur 2 à gagner !!!! " << endl;
        }else if(b2.getPointVie() == 0){
            cout << " Joueur 1 à gagner !!!! " << endl;
        }


        nbTour+=1;
    }

//Fin de Boucle


//Fin du jeu
//Si j1.pv=0 ou j2.pv=0
}

