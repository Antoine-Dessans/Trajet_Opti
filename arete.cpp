#include "arete.h" // Cette commande nous permet d'utiliser arete.h

arete::arete(){} // Constructeur vide

arete::arete(int u,int v,int w){ // Constructeur à partir de 3 entiers qui sont le sommet initial de l'arete, le sommet terminal de l'arete et la longueur qui es separe
	sommet_initial=u;
	sommet_terminal=v;
	longueur=w;
}
arete::~arete(){}
