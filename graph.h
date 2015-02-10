#ifndef _graph_H
#define _graph_H
#include <iostream>
#include "arete.h"
# include <string>

class graph {
public:
	graph(const string & filename); // Constructeur � partir du nom d'un fichier au format : sommet_initial sommet_terminal longueur (pour chaque arc)
	~graph();
	void affiche_dist(int s, int t);  // Fonction affichant la distance et le plus court chemin deu sommet s au sommet t

private:
	int nbsommet;
	int nbarete;
	arete * tableau_arete;
	void dijkstra(int s);  // Instructions pour l'algorithme de Dijsktra
	int * f;  // Fonction f(v) de l'algorithme de Dijkstra maintenant une borme sup�rieure de la distance de s � v 
	int * arb;  // Tableau mod�lisant l'arborescence des plus courts chemins: arb(v) est le sommet pr�cedent v dans le plus court chemin de s � v
	static const int INFTY=10000;
};
#endif

