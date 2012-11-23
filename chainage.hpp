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
	void affichage(Chainage & ch);
	void insertion(Chainage & ch, Maillon pm);
	void suppression(Chainage &  ch, int pos);
	Maillon* recherche(Chainage ch, int x);
	void finalisation(Chainage & ch);
}
