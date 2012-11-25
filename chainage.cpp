#include <iostream>
namespace chainage
{
	using namespace std;
	
	typedef
		struct _maillon
		{
			int elt;
			struct _maillon * succ;
		}Maillon;
	
	typedef
		struct
		{
			int nb_elt;
			Maillon * tete;
			Maillon * queue;
		}Chainage;
	
	
	void initialisation(Chainage & ch)
	{
		cout << "Combien de maillons souhaitez vous créer ?" << endl;
		cin >> ch.nb_elt;
		Maillon *pred;
		for (int i = 0; i<ch.nb_elt; i++)
		{
			int elt;
			Maillon *pm= new Maillon;
			cin >> elt;
			pm->elt=elt;
			if (i==0)
			{
				ch.tete=&*pm;
			}
			else if (i==ch.nb_elt-1)
			{
				ch.queue=&*pm;
				pred->succ=&*pm;
			}
			else
			{
				pred->succ=&*pm;
			}
			pred=&*pm;
		}
		cout << "Initialisation effectuee." << endl;
	}
	void affichage(Chainage & ch)
	{
		if (ch.tete==NULL)
		{
			cout << "Le chaînage est vide" << endl;
		}
		else
		{
			Maillon * pm;
			pm=ch.tete;
			while (pm != NULL)
			{
				cout << " | " << pm->elt;
				pm=pm->succ;
			}
			cout << " |" << endl;
		}
	}
	void insertion(Chainage & ch, Maillon pm)
	{
	}
	void suppression(Chainage &  ch, int pos)
	{
	}
	Maillon* recherche(Chainage ch, int x)
	{
		Maillon * res = new Maillon;
		res=ch.tete;
		While (res != NULL && res->elt != x)
		{
			res=res->succ;
		}
		return res;
	}
	
	void finalisation(Chainage & ch)
	{
	}
}
