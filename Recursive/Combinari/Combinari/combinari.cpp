#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Functia recursiva care calculeaza combinari C(n, k)
int combinari(int n, int k) {
    // Caz de baza: C(n, 0) = C(n, n) = 1
    if (k == 0 || k == n) {
        return 1;
    }

    // Formula recursiva: C(n, k) = C(n-1, k-1) + C(n-1, k)
    return combinari(n - 1, k - 1) + combinari(n - 1, k);
}

int main() {
    int n, k;

    // Citirea valorilor pentru n si k
    printf("Introdu valoarea lui n: ");
    scanf("%d", &n);

    printf("Introdu valoarea lui k: ");
    scanf("%d", &k);

    // Validare de baza
    if (k < 0 || k > n) {
        printf("Valori invalide: trebuie sa fie 0 <= k <= n\n");
        return 1;
    }

    // Afisarea rezultatului
    int rezultat = combinari(n, k);
    printf("C(%d, %d) = %d\n", n, k, rezultat);

    return 0;
}