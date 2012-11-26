#include <iostream>
#include "chainage.hpp"

using namespace std;
using namespace chainage;

int main()
{
	Chainage ch;
	int elem, pos, choix, rech, d, f;

	initialisation(ch);

	

	cout << "Que souhaitez vous faire ?" << endl;

	do
	{
		affichage(ch);
		cout << "1 : Insertion" << endl;
		cout << "2 : Suppression" << endl;
		cout << "3 : Recherche" << endl;
		cout << "6 : Afficher le chainage" << endl;
		cout << "10 : Terminer" << endl;
		cin >> choix;

		cout << endl;

		switch(choix)
		{
			case 1:
				cout << "Quel élément souhaitez vous insérer ?" << endl;
				cin >> elem; // Récupération de l'élément
				cout << "En quelle position ? (0 pour insérer en tête)" << endl;
				cin >> pos; // Récupération de la position
				if (pos>=0 && pos<=ch.nb_elt)
				{
					insertion(ch,elem,pos);
				}
				else
				{
					cout << "Insertion impossible" << endl;
				}
			break;

			case 2:
				cout << "Quelle maillon souhaitez vous supprimer :" << endl;
				cin >> pos;
				if (pos>0 && pos<ch.nb_elt)
				{
					suppression(ch,pos);
				}
				else
				{
					cout << "Position inexistante" << endl;
				}
			break;
/*
			case 3:
			cout << "Quelle element souhaitez vous rechercher :" << endl;
			cin >> elt;
			rech = recherche(ptab, elt);

			if (rech > -1)
				cout << "Votre element est a la position " << rech+1 << endl;
			else
				cout << "Votre element n'existe pas." << endl;
			affichage(ptab);
			break;

			case 6:
			affichage(ptab);
			break;

			default:
			finalisation(ptab);
			break;*/
		}
	}while (choix > 0 && choix < 10);
}
