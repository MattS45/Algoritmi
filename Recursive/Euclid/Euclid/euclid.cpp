#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Functia recursiva care calculeaza CMMDC
/*
Practic se inlocuieste functia WHILE din algorimul clasic
cu o logica a impartirii repetate intr-un mod recursiv
*/
int cmmdc(int a, int b) {
    // Cazul de bază: când b este 0, CMMDC este a
    if (b == 0) {
        return a;
    }

    // Apel recursiv: cmmdc(b, a % b)
    return cmmdc(b, a % b);
}

int main() {
    int x, y;

    // Citim cele doua numere
    printf("Introdu doua numere intregi pozitive: ");
    scanf("%d %d", &x, &y);

    // Validare simpla
    if (x <= 0 || y <= 0) {
        printf("Numerele trebuie sa fie intregi si pozitive.\n");
        return 1;
    }

    // Calculam CMMDC
    int rezultat = cmmdc(x, y);

    // Afisam rezultatul
    printf("CMMDC(%d, %d) = %d\n", x, y, rezultat);

    return 0;
}
