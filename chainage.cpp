// Bibliothèque permettant l'utilisation des chainages simples

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
	
	/***************************************/
	//Fonction d'initialisation du chainage
	void initialisation(Chainage & ch)
	{
		cout << "Combien de maillons souhaitez vous créer ?" << endl;
		cin >> ch.nb_elt;
		Maillon * pred;
		if (ch.nb_elt!=0)
		{
			for (int i = 0; i<ch.nb_elt; i++)
			{
				int elt;
				Maillon * pm= new Maillon; // Allocation du nouveau maillon
				cout  << "Elément du maillon " << (i+1) << " : " ;
				cin >> elt; //Récupération de l'élément
				pm->elt=elt; 
				
				if (i==0) // cas du premier maillon
				{
					ch.tete=pm; // mise à jour de la tête
				}
				else if (i==ch.nb_elt-1) // cas du dernier maillon
				{
					ch.queue=pm; //mise à jour de la queue
					pred->succ=pm; // cas global nécessaire
				}
				else  // cas global
				{
					pred->succ=pm; // le pointeur succ du précédent maillon 	initialisé est mis à jour avec le pointeur pm
				}
				pred=pm; // on stocke le pointeur du maillon créé pour mettre à jour son successeur au passage suivant dnas la boucle.
			}
		}
		else
		{
			ch.tete=NULL;
			ch.queue=NULL;
		}
		cout << "Initialisation effectuée." << endl;
	}
	
	/***************************************/
	//Fonction d'affichage classique du chainage
	void affichage(Chainage ch)
	{
		int pos=1; //position
		while (pos<ch.nb_elt+1) 
			{
				cout << " | " << pos;
				pos=pos+1;
			}
		cout << " |" << endl;
		if (ch.tete==NULL) // Vérification que le chainage n'est pas vide
		{
			cout << "Le chaînage est vide" << endl;
		}
		else
		{
			Maillon * pm; // Allocation d'un pointeur pour parcourir et afficher les différents maillons
			pm=ch.tete; // On l'initialise en tête du chainage
			while (pm != NULL) // On parcourt la chaine en partant de la tête
			{
				cout << " | " << pm->elt; // On affiche l'élément
				pm=pm->succ; // Puis on passe au suivant
			}
			cout << " |"<< endl;
		}
	}
	
	/***************************************/
	/*Cette fonction va nous permettre de convertir une position donnée par l'utilisateur en pointeur vers le maillon correspondant.
	Elle est utilisée dans les procédures insertion, suppression, recherche
	*/
	
	Maillon * conversion(Chainage ch,int pos)
	{
		Maillon * pm; // Allocation d'un pointeur vers maillon
		pm=ch.tete; // Initialisation au maillon de tete
		for (int i = 1; i<pos; i++) // On parcourt jusqu'au maillon correspondant
		{
			pm=pm->succ;
		}
		return pm; // On renvoie l'adresse du maillon correspondant à la position
	}
	
	/***************************************/
	// Cette fonction renvoie la position dans le chainage du maillon donné
	int position(Chainage ch, Maillon * pm)
	{
		int pos=1;
		Maillon * pm1=ch.tete;
		while (pm1!=pm)
		{
			pos=pos+1;
			pm1=pm1->succ;
		}
		return pos;
	}
	
	/***************************************/
	// Cette fonction insert un élément après la position donnée
	void insertion(Chainage & ch, int elem, int pos)
	{
		Maillon * nouveau=new Maillon; // Allocation du nouveau maillon
		nouveau->elt=elem; // Récupération de l'élément dans le maillon
		if (pos==0) // Insertion en tête
		{
			nouveau->succ=ch.tete;
			ch.tete=nouveau;
			if (nb_elt==0)
			{
				ch.queue=nouveau;
			}
		}
		else
		{
			Maillon * pm; //Allocation d'un nouveau pointeur
			pm=conversion(ch,pos);
			nouveau->succ=pm->succ;
			pm->succ=nouveau;
			if (pm==ch.queue)
			{
				ch.queue=nouveau;
			}
		}
		ch.nb_elt=ch.nb_elt+1;
	}
	
	/***************************************/
	//Fonction de suppression du maillon à la position donnée
	void suppression(Chainage &  ch, int pos)
	{
		if (ch.tete!=NULL) // on test si le chainage n'est pas vide
		{
			Maillon * pm;
			if(pos==1) //suppression en tête
			{
				pm=ch.tete;
				ch.tete=ch.tete->succ;
			}
			else
			{
				Maillon * pred=conversion(ch,pos-1);
				pm=pred->succ;
				pred->succ=pm->succ;
				if (pm==ch.queue)
				{
					ch.queue=pred;
				}
			}
			delete pm;
			ch.nb_elt-=1;	
		}
		else
		{
			cout << "Suppression impossible dans un chainage vide" << endl;
		}
	}
	
	/***************************************/
	// Insertion en tête
	void insertTete(Chainage & ch, int elt)
	{
		insertion(ch,elt,0);
	}
	
	/***************************************/
	// Insertion en queue
	void insertQueue(Chainage & ch, int elt)
	{
		insertion(ch,elt,ch.nb_elt);
	}
	
	/***************************************/
	// Suppression en tête
	void supprTete(Chainage & ch)
	{
		suppression(ch,1);
	}
	
	/***************************************/
	// Suppression en queue
	void supprQueue(Chainage & ch)
	{
		suppression(ch,ch.nb_elt);
	}
	
	/***************************************/
	// Fonction qui renvoie un pointeur vers le dernier maillon
	Maillon* Queue(Chainage ch)
	{
		Maillon * pm;
		pm=ch.queue;
		return (pm);
	}
	
	/***************************************/
	//Fonction renvoyant le premier maillon dans lequel se situe l'élément donné
	Maillon* recherche(Chainage ch, int x)
	{
		Maillon * res;
		res=ch.tete;
		while (res != NULL && res->elt != x)
		{
		
			res=res->succ;
		}
		return res;
	}
	
	/***************************************/
	//Fonction récursive d'affichage inverse à partir d'un maillon
	void afficheRec(Maillon * pm)
	{
		if (pm != NULL)
		{
			afficheRec(pm->succ);
			cout << " | " << pm->elt;
		}
	}
	
	/***************************************/
	//Fonction d'affichage inverse
	void afficheInverse(Chainage ch)
	{
		if (ch.nb_elt==0)
		{
			cout << "Le chaînage est vide" << endl;
		}
		else
		{
			int pos=ch.nb_elt; //position
			while (pos>0) 
			{
				cout << " | " << pos;
				pos=pos-1;
			}
			cout << " | " << endl;
			afficheRec(ch.tete);
			cout << " |" << endl;
		}
	}
	
	/***************************************/
	//Fonction de reinitialisation du chainage
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
		ch.nb_elt=0;
	}
	
	/***************************************/
	// Fonction de recherche du minimum
	Maillon* min(Chainage ch)
	{
		Maillon * pm;
		Maillon * pmin;
		pm=ch.tete;
		pmin=ch.tete;
		while (pm != NULL)
		{
			if (pm->elt < pmin->elt)
			{
				pmin=pm;
			}
			pm=pm->succ;
		}
		return pmin;
	}
	
	/***************************************/
	//Suppression du minimum
	void supprMin(Chainage & ch)
	{
		Maillon * pmin;
		Maillon * ps; // Le maillon que l'on désallouera
		pmin=min(ch); // On cherche le plus petit élément
		if (pmin->succ == NULL) // Si le plus petit élément est à la fin du chainage
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
	}
	
	/***************************************/
	//Insertion d'un maillon après le maillon contenant l'élément minimal
	void insert_apres_min(Chainage & ch, int x)
	{
		Maillon * pmin;
		Maillon * pm=new Maillon; // Le nouveau maillon
		pmin=min(ch); // On cherche le plus petit élément
		if (pmin->succ == NULL) // Si le plus petit élément est à la fin du chainage
		{
			insertQueue(ch,x); // Alors on l'insert à la dernière position
		}
		else // Sinon
		{
			pm->elt=x; // On initialise la valeur du nouveau maillon
			pm->succ=pmin->succ; // Son successeur
			pmin->succ=pm; // Et on met à jour le successeur de pmin
		}
		ch.nb_elt=ch.nb_elt+1; // Mise à jour du nombre d'élément dans le chainage
	}
	
	/***************************************/
	//Insertion d'un maillon avant le maillon contenant l'élément minimal
	void insert_avant_min(Chainage & ch, int x)
	{
		Maillon * pmin;
		pmin=min(ch); // On cherche le plus petit élément
		insert_apres_min(ch, pmin->elt); // On le ré-insert après lui-même
		pmin->elt=x; // On met à jour avec la valeur demandée
	}
	
	/***************************************/
	// Fonction finale
	void finalisation(Chainage & ch)
	{
	}
}
