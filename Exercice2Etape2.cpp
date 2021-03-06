/*Exercice2.cpp Étape 2: Offres simples: 
1. Le magasin décide d'introduire deux nouvelles offres
2. Achetez une pomme, obtenez-en une gratuitement
3. Achetez deux Oranges, et obtenez la 3ième gratuitement.
4. Mettez à jour vos fonctions de paiement en conséquence
Auteur: Juan Marmolejo
*/

#include "stdafx.h"
#include<iostream>
#include<string>
#include <vector>
#include <time.h>

using namespace std;

int main()
{
	vector <string> listOfArticles;
	int ran, qty;
	int apples = 0, oranges = 0;
	int quo = 0, res = 0;
	int i = 0;

	//Entrée de données aléatoire
	srand(time(NULL));
	qty = rand() % 20 + 1;
	do {
		ran = rand() % 100 + 1;
		if (ran % 2 == 0) {
			listOfArticles.push_back("Orange");
		}
		else {
			listOfArticles.push_back("Pomme");
		}
		i++;
	} while (i < qty);

	//Comptage des articles dans le panier
	for (i = 0; i < listOfArticles.size(); i++) {
		if (listOfArticles[i] == "Pomme") {
			apples++;
		}
		else {
			oranges++;
		}
	}
	cout << "\nPommes = " << apples;
	cout << "\tOranges = " << oranges;
	//Faire la réduction
	quo = apples / 2;
	res = apples % 2;
	apples = quo + res;

	quo = oranges / 3;
	res = oranges % 3;
	oranges = quo * 2 + res;

	cout << "\n";
	//Calculer la valeur de l'achat
	cout << "\n" << apples << " pommes = " << apples * 0.60 << "$";
	cout << "\n" << oranges << " oranges = " << oranges * 1.25 << "$";
	cout << "\n" << "Total = " << apples * 0.60 + oranges * 1.25 << "$";

	cout << "\n";
	cout << "\n";
	system("pause");
	return 0;
}

