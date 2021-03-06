/*Exercice1.cpp : Permettre à un utilisateur d’entrer un nombre, trouvez le nombre supérieur suivant en
utilisant seulement les chiffres du nombre donné.
Par exemple, si le nombre donné est 1234, le nombre supérieur suivant avec les
mêmes chiffres est 1243..
Auteur: Juan Marmolejo
*/

#include "stdafx.h"
#include<iostream>
#include<string>

using namespace std;

void to_array(int num, int arr[], int * n);
void swap(int * n1, int * n2);

int main() {

	int read_number, change_number, lower;
	int number[10];
	int n, k;
	bool flag = true;

	cout << "Entrez un nombre: ";
	cin >> read_number;

	to_array(read_number, number, &n);

	//Est-ce qu'un plus grand nombre est possible?
	for (int i = 0; i < n-1; i++) {
		if (number[i] > number[i+1]) {
			flag = false;
			k = i;
			break;
		}
	}

	if (flag) {
		cout << "Le prochain numéro n'est pas possible.";
		cout << "\n";
		system("pause");
		return 0;
	}

	change_number = number[k+1];
	lower = k;
	
	//On cherche les numéros à échanger.
	for (int i = 0; i <= k; i++) {
		if (number[i] > change_number && number[i] < number[lower]) {
			lower = i;
		}
	}
	swap(number[k + 1], number[lower]);

	//Les numéros restants sont triés.
	for (int i = 0; i <= k; i++) {
		for (int j = 0; j <= k - 1; j++) {
			if (number[i] > number[j]) {
				swap(number[i], number[j]);
			}
		}
	}

	//Le résultat inversé est affiché.
	cout << "\nLe prochain numéro est: ";
	for (int i = n - 1; i >= 0; i--) {
		cout << number[i];
	}
	cout << "\n";
	system("pause");
}

//Fonction pour convertir un nombre entier en un vecteur de nombres.
void to_array(int num, int arr[], int * n) {

	int i = 0;

	while (num/10 > 0) {
		arr[i] = num % 10;
		num = num / 10;
		i++;
	}
	arr[i] = num;
	*n = i + 1;
}

//Fonction pour échanger deux nombres.
void swap(int * n1, int * n2){
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}