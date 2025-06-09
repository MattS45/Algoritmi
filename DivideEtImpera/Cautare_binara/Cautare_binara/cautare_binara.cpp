#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int v[100];

int cautare_binara(int st, int dr, int target) {
	printf("\n%d %d", st, dr);
	int i = (st + dr) / 2;
	if (target < v[i])
		dr = v[i] - 1;
	if (target > v[i])
		st = v[i] + 1;
	printf("\n%d", i);
	if (v[i] == target)
		return i;
	else {
		if (st == dr) {
			return 0;
		}
		cautare_binara(st, dr, target);
	}
	
}

int main() {
	int n;
	int element = 0;
	printf("Introduceti numarul de elemente: ");
	scanf("%d", &n);
	printf("Introduceti elementele: ");
	for(int i = 0; i < n; i++) {
		scanf("%d",&v[i]);
	}
	printf("Introdu elementul cautat: ");
	scanf("%d", &element);
	int rez = cautare_binara(0, n, element);
	if (rez != 0) {
		printf("\nRezultat : %d", rez);
	}
	else {
		printf("Nu exista in mortii mei!!!");
	}

	return 0;
}