#ifndef _arete_H
#define _arete_H

using namespace std;


class arete{
public:
	arete(); // Pour la déclaration du tableau
	arete(int u,int v,int w);
	~arete();

private:
	int sommet_initial;
	int sommet_terminal;
	int poids;
	
friend class graph;
};

#endif 
