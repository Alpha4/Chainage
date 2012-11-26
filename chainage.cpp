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
	void insertion(Chainage & ch, int pos, int elt)
	{
	}
	void suppression(Chainage &  ch, int pos)
	{
	}
	void insertTete(Chainage & ch, int elt) // Insertion en tête
	{
		insertion(ch, 0, elt);
	}
	void insertQueue(Chainage & ch, int elt) // Insertion en queue
	{
		insertion(ch, nb_elt, elt);
	}
	void supprTete(Chainage & ch) // Suppression en tête
	{
		suppression(ch, 0);
	}
	void supprQueue(Chainage & ch) // Suppression en queue
	{
		suppression(ch, nb_elt);
	}
	Maillon* Queue(Chainage ch) // Fonction qui renvoie un pointeur vers le dernier maillon
	{
		Maillon * pm;
		pm=ch.queue;
		return (pm);
	}
	Maillon* recherche(Chainage ch, int x)
	{
		Maillon * res = new Maillon;
		res=ch.tete;
		while (res != NULL && res->elt != x)
		{
			res=res->succ;
		}
		return res;
	}
	void afficheInverse(Chainage ch)
	{
		afficheRec(ch.tete);
	}
	void afficheRec(Maillon * pm)
	{
		if (pm != NULL)
		{
			afficheRec(pm->succ);
			cout << " | " << pm->elt;
		}
		cout << " |" << endl;
	}
	void reinitialisation(Chainage & ch)
	{
		Maillon * pm;
		while (ch.tete != NULL)
		{
			pm=ch.tete->succ;
			delete ch.tete;
			ch.tete=pm;
		}
		ch.queue=NULL;
		nb_elt=0;
	}
	Maillon* min(Chainage ch)
	{
		Maillon * pm1;
		Maillon * pm2;
		pm1=ch.tete;
		pm2=ch.tete;
		while (pm1 != NULL)
		{
			pm1=pm1->succ;
			if (pm1->elt < pm2->elt)
			{
				pm2=pm1;
			}
		}
		return pm2;
	}
	void supprMin(Chainage & ch)
	{
		Maillon * pmin;
		Maillon * ps; // Le maillon que l'on désallouera
		pmin=min(ch); // On cherche le plus petit élément
		if (pmin->succ = NULL) // Si le plus petit élément est à la fin du chainage
		{
			suppression(ch, ch.nb_elt); // On utilise la procédure supprimer
		}
		else
		{
			ps=pmin->succ;
			pmin->elt=ps->elt; // On commence par copier l'élément du successseur
			pmin->succ=ps->succ; // Puis on l'isole
			delete ps; // Et enfin on le désalloue
	}
	void insert_après_min(Chainage & ch, int x)
	{
		Maillon * pmin;
		Maillon * pm=new Maillon; // Le nouveau maillon
		pmin=min(ch); // On cherche le plus petit élément
		if (pmin->succ = NULL) // Si le plus petit élément est à la fin du chainage
		{
			insertion(ch, nb_elt); // Alors on l'insert à la dernière position
		}
		else // Sinon
		{
			pm->elt=x; // On initialise la valeur du nouveau maillon
			pm->succ=pmin->succ; // Son successeur
			pmin->succ=pm; // Et on met à jour le successeur de pmin
		}
		nb_elt=nb_elt+1; // Mise à jour du nombre d'élément dans le chainage
	}
	void insert_avant_min(Chainage & ch, int x)
	{
		Maillon * pmin;
		pmin=min(ch); // On cherche le plus petit élément
		insert_apres_min(ch, pmin->elt); // On le ré-insert après lui-même
		pmin->elt=x; // On met à jour avec la valeur demandée
	}
	void finalisation(Chainage & ch)
	{
	}
}
