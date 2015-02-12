using namespace std; // Toutes les fonctions de la librairie std s'appellent en fait std::cin, std:cout... Cette commande nous permet d'utiliser les noms reduits des fonctions ('nomdelafonction') plutot que les noms complets ('std::nomdelafonction)


class arete{
public:
	arete(); // Pour la declaration du tableau
	arete(int u,int v,int w);
	~arete();

private:
	int sommet_initial;
	int sommet_terminal;
	int longueur;
	
friend class graph; // Cette commande permet ˆ la classe graph c'etre consideree comme amie de la classe arete. La classe graph peut donc acceder aux attributs prives de la classe arete
}; 
