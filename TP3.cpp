#include <iostream>
#include "chainage.hpp"

using namespace std;
using namespace chainage;

int main()
{
	Chainage ch;
	int elt, pos, choix,;

	initialisation(ch);
	do
	{
		affichage(ch);
		cout << "**********MENU**********" << endl;
		cout << "1 : Insertion" << endl;
		cout << "2 : Insertion en tête" << endl;
		cout << "3 : Insertion en queue" << endl;
		cout << "4 : Suppression" << endl;
		cout << "5 : Suppression en tête" << endl;
		cout << "6 : Suppression en queue" << endl;
		cout << "7 : Recherche" << endl;
		cout << "8 : Afficher le chainage en sens inverse" << endl;
		cout << "9 : Recherche du minimum" << endl;
		cout << "10 : Supprimer le minimum" << endl;
		cout << "11 : Insertion avant le minimum" << endl;
		cout << "12 : Insertion après le minimum" << endl;
		cout << "13 : Terminer" << endl;
		cin >> choix;
		cout << "************************" << endl;

		switch(choix)
		{
			case 1:
				cout << "Quel élément souhaitez vous insérer ?" << endl;
				cin >> elt; // Récupération de l'élément
				cout << "En quelle position ? (0 pour insérer en tête)" << endl;
				cin >> pos; // Récupération de la position
				if (pos>=0 && pos<=ch.nb_elt)
				{
					insertion(ch,elt,pos);
				}
				else
				{
					cout << "Position inexistante" << endl;
				}
			break;
			
			case 2:
				cout << "Quel élément souhaitez vous insérer ?" << endl;
				cin >> elt; // Récupération de l'élément
				insertTete(ch,elt);
			break;
			
			case 3:
				cout << "Quel élément souhaitez vous insérer ?" << endl;
				cin >> elt; // Récupération de l'élément
				insertQueue(ch,elt);
			break;

			case 4:
				cout << "Quelle maillon souhaitez vous supprimer :" << endl;
				cin >> pos; // Récupération de la position
				if (pos>0 && pos<ch.nb_elt)
				{
					suppression(ch,pos);
				}
				else
				{
					cout << "Position inexistante" << endl;
				}
			break;

			case 8:
			affichageInverse(ch));
			break;

			default:
			finalisation(ch);
			break;
		}
	}while (choix > 0 && choix < 13);
}
