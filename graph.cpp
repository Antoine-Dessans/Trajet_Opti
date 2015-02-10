# include <iostream>
# include <fstream>
# include "graph.h"


int nbligne (const string & nomf) {
    ifstream f(nomf.c_str());
    string s;
    if(f){
        int line = 0;
        while(getline(f,s)) line++;
        return line;
    }else{
        cout << "Ne peut ouvrir " << nomf << endl;
    }
    f.close();
    return 0;
}

graph::graph(const string & nomf){  //constructeur � partir d'un nom de fichier au format : graphe par liste des ar�tes
	ifstream fs(nomf.c_str());
	int a,b,c;  //repr�sente les 3 entiers d�finissant chaque ar�te
	nbarete=nbligne(nomf.c_str());
	tableau_arete=new arete[nbarete];//cr�ation du tableau de la taille du nombre d'ar�te
	nbsommet=0;
	for (int i=0;i<nbarete;i++) {
		fs>>a;
		fs>>b;
		fs>>c;
		tableau_arete[i]=arete(a,b,c);
		if(a>nbsommet) nbsommet=a;
		if(b>nbsommet) nbsommet=b;
	}
	f = new int [nbsommet];	
	arb = new int [nbsommet];
	fs.close();
}

graph::~graph(){
	delete[] tableau_arete;
}

void graph::dijkstra(int s){ // Algorithme pour trouver les distances depuis le sommet s
	
	f[s-1]=0; arb[s-1]=s; //Choix du sommet de d�part: s sera le premier sommet s�lectionn� car seul � avoir un f(s) < INFTY
	for(int i =0; i<nbsommet; i++) if(i!=s-1) f[i]=arb[i]=INFTY;
	
	// Tableau repr�sentant le sous-ensemble U des sommets � explorer
	bool * U = new bool [nbsommet];
	for(int i =0; i<nbsommet; i++) U[i]=true;
	
/*******  COEUR de L'ALGORITHME **************/
	bool test=true;
	while(test){
		// 1) Trouver un sommet de u de U minimisant f(u) et v�rifier la condition d'ar�t de la boucle while: U est vide
		test=false;
		int u;
		for(int i =0; i<nbsommet; i++){
			if(U[i] && !test){
				u=i;
				test=true;
			}
			if(f[i]<f[u] && U[i]) u=i;
		}
		// 2) Mettre � jour la fonction f(.) et l'arborescence dans le voisinage de u:
		for(int i =0; i<nbarete; i++)
			if(tableau_arete[i].sommet_initial-1==u && f[tableau_arete[i].sommet_terminal-1]>f[u]+tableau_arete[i].poids)
			{
				f[tableau_arete[i].sommet_terminal-1]=f[u]+tableau_arete[i].poids;
				arb[tableau_arete[i].sommet_terminal-1]=u+1;
			}
		// 3) Mettre � jour l'ensemble U (sortir u de U)
		U[u]=false;
	}	
/**************** FIN ALGO *******************************/
}

void graph::affiche_dist(int s, int t){//fonction affichant la distance et le chemin le plus court de s � t
	cout<<"La distance du point "<< s << " au point " << t << " est " << endl;
	dijkstra(s);
	if(f[t-1]<INFTY)
	{
		cout << f[t-1] << endl;
		cout << "par le chemin " << endl;
		int * chemin = new int [nbsommet];  //Au pire cas le chemin  a tous les sommets
		int fin=0, v=t;
		chemin[0]=t;  //chemin[   ]  repr�sente le chemin invers�
		while(chemin[fin] != s) // Remplie les permi�res cases du tableau chemin avec le chemin invers�
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
