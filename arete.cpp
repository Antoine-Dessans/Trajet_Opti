#include "arete.h"

arete::arete(){} //constructeur vide

arete::arete(int u,int v,int w){
	sommet_initial=u;
	sommet_terminal=v;
	poids=w;
}
arete::~arete(){}
