# include <iostream>
# include <fstream> 
# include "graph.h"
// On a besoin de iostream et de fstream car on va devoir demander des inputs à l'utilisateur par le terminal de commande (utilisation de iostream) et on va devoir acceder à un fichier (utilisation de fstream pour acceder à data.txt). On a evidemment besoin de graph.h


int nbligne (const string & nomf) { // Fonction annexe permettant de compter le nombre de lignes d'un fichier : dans notre cas c'est utile pour déterminer le nombre d'aretes
    ifstream f(nomf.c_str());
    string s;
    if(f){
        int line = 0;
        while(getline(f,s)) line++; // On parcourt le fichier en partant de la premiere ligne et tant que la ligne existe on implemente l'entier 'line' qui nous donnera en sortant de la boucle while le nombre de lignes du fichier
        return line;
    }else{
        cout << "Ne peut ouvrir " << nomf << endl; // On retourne un message en cas d'erreur
    }
    f.close();
    return 0;
}

graph::graph(const string & nomf){  // Constructeur ‡ partir d'un nom de fichier au format : graphe par liste des aretes
	ifstream fs(nomf.c_str());
	int a,b,c;  // Represente les 3 entiers definissant chaque arete : sommet initial, sommet final et longueur
	nbarete=nbligne(nomf.c_str()); // Utilise la fonction annexe 'nbligne' pour determiner le nombre de lignes du fichier qui correspond au nombre d'arete du graphe oriente
	tableau_arete=new arete[nbarete]; // Creation du tableau dont la taille est le nombre d'aretes du graphe
	nbsommet=0; // On initialise le nombre de sommets à 0
	for (int i=0;i<nbarete;i++) { // On parcourt le fichier de la premiere à la derniere ligne, cela nous permet de remplir le tableau d'aretes et de determiner le nombre de sommets
		fs>>a;
		fs>>b;
		fs>>c;
		tableau_arete[i]=arete(a,b,c);
		if(a>nbsommet) nbsommet=a;
		if(b>nbsommet) nbsommet=b; // De par le format de notre fichier 'data.txt', le nombre de sommets est le plus grand entier contenu dans une des deux premieres colonnes (correspondant aux sommets initiaux et finaux des arcs)
	}
	f = new int [nbsommet];	// Allocation de la memoire pour la fonction
	arb = new int [nbsommet];
	fs.close(); // On ferme le flux
}

graph::~graph(){
	delete[] tableau_arete;
}

void graph::dijkstra(int s){
    
/* Algorithme pour trouver les distances depuis le sommet s d'un graphe orienté G=(V,A) ou V est l'ensemble des sommets de G et A est l'ensemble des aretes de G tel que si (u,v) est dans A alors il existe une arete de sommet initial u et de sommet terminal v.
 
Initialisation: Soit U:=V l'ensemble des sommets à explorer, soit f(v):=infini pour tous les sommets, sauf f(s)=0
Tant que U n'est pas vide:
                    1) Trouver le sommet u minimisant f(u).
                    2) Pour tous les voisins v de u, si f(u)+longueur de l'arc uv < f(v),                            faire f(v):=f(u)+longueur de l'arc uv, et u est le pere de v dans l'arborescence.
                    3) On retire le sommet u de U
*/
     
/******* INITIALISATION **************/
	f[s-1]=0; arb[s-1]=s; // Choix du sommet de depart: s sera le premier sommet selectionne car c'est le seul à avoir un f(s) < INFTY
	for(int i =0; i<nbsommet; i++) if(i!=s-1) f[i]=arb[i]=INFTY; // On initialise tous les sommets (sauf celui de départ) à f(v):=infini
	bool * U = new bool [nbsommet];
	for(int i =0; i<nbsommet; i++) U[i]=true; // Tableau representant le sous-ensemble U des sommets à explorer
	
/*******  BOUCLE TANT QUE DE L'ALGORITHME **************/
	bool test=true;
	while(test){
		// 1) Trouver un sommet de u de U minimisant f(u) et verifier la condition d'arret de la boucle while: U est vide
		test=false;
		int u;
		for(int i =0; i<nbsommet; i++){
			if(U[i] && !test){
				u=i;
				test=true;
			}
			if(f[i]<f[u] && U[i]) u=i;
		}
		// 2) Mettre à jour la fonction f(.) et l'arborescence dans le voisinage de u:
		for(int i =0; i<nbarete; i++)
			if(tableau_arete[i].sommet_initial-1==u && f[tableau_arete[i].sommet_terminal-1]>f[u]+tableau_arete[i].longueur)
			{
				f[tableau_arete[i].sommet_terminal-1]=f[u]+tableau_arete[i].longueur;
				arb[tableau_arete[i].sommet_terminal-1]=u+1;
			}
		// 3) Mettre à jour l'ensemble U (sortir u de U)
		U[u]=false;
	}	
/**************** FIN DE L'ALGORITHME *******************************/
}

void graph::affiche_dist(int s, int t){// Fonction affichant la distance et le plus cours chemin de s à t
	cout<<"La distance du point "<< s << " au point " << t << " est " << endl;
	dijkstra(s); // On affiche la distance minimale du point s au point t
	if(f[t-1]<INFTY)
	{
		cout << f[t-1] << endl;
		cout << "par le chemin " << endl;
		int * chemin = new int [nbsommet];  // Dans le pire des cas le chemin passe par tous les sommets
		int fin=0, v=t;
		chemin[0]=t;  // Chemin[ ]  represente le chemin inverse
		while(chemin[fin] != s) // On remplit les permieres cases du tableau chemin avec le chemin inverse
		{
			chemin[++fin]=arb[v-1];
			v=arb[v-1];
		}
		for(int i=fin; i >=0; i--) cout << chemin[i] << " ";   // Affichage du chemin dans le bon ordre
			cout << endl;
	}
	else
		cout << "infinie" << endl;
}
