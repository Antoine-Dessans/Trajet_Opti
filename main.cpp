# include "graph.h"



int main(){
	
	graph G("data/data.txt");
	
	int s,t;	
	cout << "Entrez le point d'origine" << endl;
	cin >> s;
	cout << "Entrez le point destination" << endl;
	cin >> t;
	
	G.affiche_dist(s,t);

	return 0;

}

