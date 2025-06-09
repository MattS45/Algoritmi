#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10
/*
EXEMPLU EXPLICAT PE ITERATII PENTRU UN VECTOR DE DE DEMENSIUNE = 3



 Pasul 1: n = 3
→ return v1[2] * v2[2] + produs_scalar(..., 2)
→ 3 * 6 + produs_scalar(..., 2) → 18 + ?

Pasul 2: n = 2
→ return v1[1] * v2[1] + produs_scalar(..., 1)
→ 2 * 5 + produs_scalar(..., 1) → 10 + ?

Pasul 3: n = 1
→ return v1[0] * v2[0] + produs_scalar(..., 0)
→ 1 * 4 + produs_scalar(..., 0) → 4 + ?

Pasul 4: n = 0
→ return 0 (caz de bază)



*/
// Functie recursiva pentru calculul produsului scalar
int produs_scalar(int v1[], int v2[], int n) {
    // Caz de bază: vector de dimensiune 0
    if (n == 0) {
        return 0;
    }

    // Produsul scalar: v1[n-1] * v2[n-1] + produs_scalar(..., n-1)
    return v1[n - 1] * v2[n - 1] + produs_scalar(v1, v2, n - 1);
}

int main() {
    int n;

    // Citirea dimensiunii vectorilor
    printf("Introdu dimensiunea vectorilor: ");
    scanf("%d", &n);

    int v1[MAX], v2[MAX];

    // Citirea elementelor primului vector
    printf("Introdu elementele vectorului 1:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &v1[i]);
    }

    // Citirea elementelor celui de-al doilea vector
    printf("Introdu elementele vectorului 2:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &v2[i]);
    }

    // Calculul produsului scalar
    int rezultat = produs_scalar(v1, v2, n);

    // Afișarea rezultatului
    printf("Produsul scalar este: %d\n", rezultat);

    return 0;
}
