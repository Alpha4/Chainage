#include <iostream>
#include "chainage.hpp"

using namespace std;
using namespace chainage;

int main()
{
	Chainage ch;
	int elem, choix, rech, d, f;

	initialisation(ch);

	affichage(ch);

	cout << "Que souhaitez vous faire ?" << endl;

/*	do
	{
		cout << "1 : Insertion" << endl;
		cout << "2 : Suppression" << endl;
		cout << "3 : Recherche" << endl;
		cout << "6 : Afficher le tableau" << endl;
		cout << "10 : Terminer" << endl;
		cin >> choix;

		cout << endl;

		switch(choix)
		{
			case 1:
			cout << "Entrez l'element :" << endl;
			cin >> elem;
			insertion(ptab, elem);
			affichage(ptab);
			break;

			case 2:
			cout << "Quelle case souhaitez vous supprimer :" << endl;
			cin >> elem;
			suppression(ptab, elem-1);
			affichage(ptab);
			break;

			case 3:
			cout << "Quelle element souhaitez vous rechercher :" << endl;
			cin >> elem;
			rech = recherche(ptab, elem);

			if (rech > -1)
				cout << "Votre element est a la position " << rech+1 << endl;
			else
				cout << "Votre element n'existe pas." << endl;
			affichage(ptab);
			break;

			case 4:
			cout << "Quelle element souhaitez vous rechercher (Dichotomique) :" << endl;
			cin >> elem;
			rech = rech_dich(ptab, elem);

			if (rech > -1)
				cout << "Votre element est a la position " << rech+1 << endl;
			else
				cout << "Votre element n'existe pas." << endl;

			affichage(ptab);
			break;

			case 5:
			cout << "Entrez le début et la fin de la partie a extraire :" << endl;
			cin >> d;
			cin >> f;
			selection(ptab, d-1, f-1);
			break;

			case 6:
			affichage(ptab);
			break;

			case 7:
			trifusion(ptab, 0, ptab.nb_elem-1);
			break;
			
			case 8:
			tribulle(ptab);
			break;
			
			case 9:
			triinsertion(ptab);
			break;

			default:
			finalisation(ptab);
			break;
		}
	}while (choix > 0 && choix < 10);*/
}
