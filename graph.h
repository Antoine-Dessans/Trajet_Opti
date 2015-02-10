#ifndef _graph_H
#define _graph_H
#include <iostream>
#include "arete.h"
# include <string>

class graph {
public:
	graph(const string & filename); // Constructeur à partir du nom d'un fichier au format : sommet_initial sommet_terminal longueur (pour chaque arc)
	~graph();
	void affiche_dist(int s, int t);  // Fonction affichant la distance et le plus court chemin deu sommet s au sommet t

private:
	int nbsommet;
	int nbarete;
	arete * tableau_arete;
	void dijkstra(int s);  // Instructions pour l'algorithme de Dijsktra
	int * f;  // Fonction f(v) de l'algorithme de Dijkstra maintenant une borme supérieure de la distance de s à v 
	int * arb;  // Tableau modélisant l'arborescence des plus courts chemins: arb(v) est le sommet précedent v dans le plus court chemin de s à v
	static const int INFTY=10000;
};
#endif

