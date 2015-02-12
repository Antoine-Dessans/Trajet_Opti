# include <iostream>
# include "arete.h"
# include <string>
// On a besoin de iostream et de string. On a evidemment besoin de graph.h

class graph {
public:
	graph(const string & filename); // Constructeur ‡ partir du nom d'un fichier au format : sommet_initial sommet_terminal longueur (pour chaque arc)
	~graph();
	void affiche_dist(int s, int t);  // Fonction affichant la distance et le plus court chemin entre le sommet s et le sommet t

private:
	int nbsommet;
	int nbarete;
	arete * tableau_arete; // Representation du graphe
	void dijkstra(int s);  // Instructions pour l'algorithme de Dijsktra : construit la fonction f(.) des distances depuis s, ainsi que l'arborescence
	int * f;  // Fonction f(v) de l'algorithme de Dijkstra maintenant une borne superieure de la distance de s ‡ v
	int * arb;  // Tableau modelisant l'arborescence des plus courts chemins: arb(v) est le sommet precedent v dans le plus court chemin de s ‡ v
	static const int INFTY=10000; // On définit le meme infini pour tout les objets de type graph
};