/*Exercice2.cpp Étape 1: Shopping Cart: 
1. Vous construisez un système de shopping cart qui ne vend que des pommes et
des oranges.
2. Les pommes coûtent 0.60$ et les oranges coûtent 1.25$.
3. Construire un système de caisse qui prend une liste d'articles scannés à la
caisse et produit le coût total.
4. Par exemple: [Pomme, Pomme, Orange, Pomme] => 3.05$
5. Faites des hypothèses raisonnables sur les entrées de votre solution, par
exemple, de nombreux candidats prennent une liste de chaînes comme entrée
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

	//Calculer la valeur de l'achat
	cout << "\n" << apples << " pommes = " << apples * 0.60 << "$";
	cout << "\n" << oranges << " oranges = " << oranges * 1.25 << "$";
	cout << "\n" << "Total = " << apples * 0.60 + oranges * 1.25 << "$";
	
	cout << "\n";
	cout << "\n";
	system("pause");
	return 0;
}