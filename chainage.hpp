// Bibliothèque permettant l'utilisation des chainages simples


namespace chainage
{
	using namespace std;
	
	typedef
		struct _maillon
		{
			int elt;
			struct _maillon *succ;
		}Maillon;
		
	typedef
		struct
		{
			int nb_elt;
			Maillon tete;
			Maillon queue;
		}Chainage;

	
		
	void initialisation(Chainage & ch);
	Maillon * conversion(Chainage ch,int pos);
	Maillon* Queue(Chainage ch);
	void reinitialisation(Chainage & ch);
	void finalisation(Chainage & ch);
	
	//Affichages
	void affichage(Chainage ch);
	void afficheRec(Maillon * pm);
	void afficheInverse(Chainage ch);
	
	//Insertions
	void insertion(Chainage & ch, int elem, int pos);
	void insertTete(Chainage & ch, int elt);
	void insertQueue(Chainage & ch, int elt);
	
	//Suppressions
	void suppression(Chainage &  ch, int pos);
	void supprTete(Chainage & ch);
	void supprQueue(Chainage & ch);
	
	//Recherche
	Maillon* recherche(Chainage ch, int x);
	
	//Fonctions autour du plus petit élément
	Maillon* min(Chainage ch);
	void supprMin(Chainage & ch);
	void insert_apres_min(Chainage & ch, int x);
	void insert_avant_min(Chainage & ch, int x);
}
