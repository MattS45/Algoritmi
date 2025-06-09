#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_SIZE 100  // dimensiunea maximă a vectorului
#define BASE 10       // bază pentru cifre (0-9)

// Funcție pentru extragerea cifrei de pe poziția exp (unități, zeci, sute...)
int getDigit(int num, int exp) {
    return (num / exp) % BASE;
}

// Counting sort pe baza cifrei exp, fără alocare dinamică
void countingSort(int arr[], int n, int exp) {
    int output[MAX_SIZE];  // vector temporar pentru rezultatul sortării
    int count[BASE] = { 0 }; // contor pentru cifre (0-9)

    // Numărăm frecvența cifrelor pe poziția exp
    for (int i = 0; i < n; i++) {
        int digit = getDigit(arr[i], exp);
        count[digit]++;
    }

    // Transformăm count într-un prefix sum pentru poziții finale
    for (int i = 1; i < BASE; i++) {
        count[i] += count[i - 1];
    }
    /*Practic se gaseste pozitia elementului din arr[] in functie de fiecare cifra a sa
    pentru cifra unitatilor lui n(un nr oarecare)de ex, se observa ca exista X elemente cu o cifra mai mica asadar pozitia pe care se
    va muta n, conform criteriuluin cifrei unitatilor este X+1
    */
 
    // Construim vectorul output de la final la început (pentru stabilitate)
    for (int i = n - 1; i >= 0; i--) {
        int digit = getDigit(arr[i], exp);//se ia pozitia relevanta calcului(zeci, unitati etc), mai exact cifra din arr[i] corespunzatoare
        output[count[digit] - 1] = arr[i];//scade cu 1 pt ca vectorul incepe de la 0
        count[digit]--;//scade count-ul deoarece un element deja a fost introdus
    }

    // Copiem rezultatul sortat în vectorul original
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Radix sort simplu fără alocări dinamice
void radixSort(int arr[], int n) {
    // Găsim maximul pentru a ști câte cifre are
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) maxVal = arr[i];
    }

    // Sortăm cifră cu cifră, începând de la unități
    for (int exp = 1; maxVal / exp > 0; exp *= BASE) {
        countingSort(arr, n, exp);
    }
}

int main() {
    int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Vector initial:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    radixSort(arr, n);

    printf("Vector sortat:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
