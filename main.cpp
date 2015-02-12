# include "graph.h" // On a besoin de graph.h( et implicitement de tout ce qui precede)



int main(){
	
	graph G("data/data.txt"); // On appelle le constructeur graph, celui-ci va ensuite construire l'objet graph à partir de ce qu'il lit dans le fichier
	
	int s,t;	
	cout << "Entrez le point d'origine" << endl;
	cin >> s;
	cout << "Entrez le point destination" << endl;
	cin >> t; // On demande à l'utilisateur le trajet qu'il cherche à optimiser (point d'origine et destination)
	
	G.affiche_dist(s,t); // On applique la fonction affiche_dist à notre graphe entre notre point d'origine et notre destination et on obtient la distance et le plus court chemin entre ces 2 points

	return 0; // On retourne 0 en cas d'erreur

}

