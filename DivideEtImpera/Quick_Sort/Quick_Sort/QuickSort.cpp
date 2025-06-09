#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100
/*
Se dă un vector cu n numere reale. 
Sortează elementele vectorului în ordine crescătoare folosind algoritmul QuickSort
*/
void swap(float* a, float* b) {
	float temp = *a;
	*a = *b;
	*b = temp;
}
int partitie(float v[], int st, int dr) {
	float pivot = v[dr];
	int i = st - 1;
	for (int j = st; j < dr; j++) {
		if (v[j] <= pivot) {
			i++;
			//daca o valoare din partea stanga este mai mica decat pivotul atunci se muta in fata
			//se schimba valorile de pe pozitia i cu cea de pe pozitia j
			swap(&v[i], &v[j]);
		}
	}
	//valoarea de pe i se schimba cu cea de pe dr
	//Motivul? Au fost interschimbate deja valorile mai mici de dr pana la pozitia i
	//asadar locul lui v[dr] este pe pozitia i+1
	swap(&v[i + 1], &v[dr]);
	return i + 1;
}
void QuickSort(float v[], int st, int dr) {
	if (st < dr) {

		int pi = partitie(v, st, dr);
		QuickSort(v, st, pi - 1);//Sortam partea stanga
		QuickSort(v, pi + 1, dr);//Sortam partea dreapta
	}
}
int main() {
	int n;
	float v[MAX]{};
	printf("Introdu numarul de elemente: ");
	scanf("%d", &n);
	printf("Introdu elementele vectorului: ");
	for (int i = 0; i < n; i++) {
		scanf("%f", &v[i]);
	}
	QuickSort(v, 0, n);
	printf("Vectorul sortat este:\n");
	for (int i = 0; i < n; i++) {
		printf("%2.f ", v[i]);
	}
	return 0;
}