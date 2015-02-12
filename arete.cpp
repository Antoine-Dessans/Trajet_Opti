#include "arete.h" // Cette commande permet de continuer le code 'à la suite' du code de arete.h

arete::arete(){} // Constructeur vide

arete::arete(int u,int v,int w){
	sommet_initial=u;
	sommet_terminal=v;
	longueur=w;
}
arete::~arete(){}
