#include <iostream>
#include "chainage.hpp"

using namespace std;
using namespace chainage;

int main()
{
	Chainage ch;
	int elt, pos, choix; // elt : élément recherché ou à insérer ; pos : position à laquelle s'effectue l'action (suppression, insertion, ...) ; choix : utilisé pour le menu
	Maillon * pm; // Pointe vers le maillon recherché

	initialisation(ch);
	do
	{
		cout << endl;
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
		cout << "13 : Réinitialisation du chainage" << endl;		
		cout << "14 : Terminer" << endl;
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
			
			case 5:
				supprTete(ch);
			break;
			
			case 6:
				supprQueue(ch);
			break;
			
			case 7:
				cout << "Quel élément recherchez vous ?" << endl;
				cin >> elt; // Récupération de l'élément
				pm=recherche(ch,elt);
				if (pm!=NULL)
				{
					cout << "L'élément recherché se situe dans le maillon en position " << position(ch,pm) << endl;
				}
				else
				{
					cout << "L'élément n'est pas présent dans le chainage" << endl;
				}
			break;

			case 8:
				afficheInverse(ch);
			break;
			
			case 9:
				pm=min(ch);
				cout << "L'élément recherché se situe dans le maillon en position " << position(ch,pm) << endl;
			break;
			
			case 10:
				supprMin(ch);
				cout << "Minimum supprimé" << endl;
			break;

			case 11:
				cout << "Quel élément souhaitez vous insérer ?" << endl;
				cin >> elt; // Récupération de l'élément
				insert_avant_min(ch,elt);
			break;
			
			case 12:
				cout << "Quel élément souhaitez vous insérer ?" << endl;
				cin >> elt; // Récupération de l'élément
				insert_apres_min(ch,elt);
			break;
			
			case 13:
				reinitialisation(ch);
				cout << "Le chainage a été réinitialisé au vide" << endl;
			break;
			
			default:
				finalisation(ch);
			break;
		}
	}while (choix > 0 && choix < 14);
}
