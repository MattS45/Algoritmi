#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
// Functia care interclaseaza doua jumatati sortate

void interclasare(int v[], int st, int mij, int dr) {
    int n1 = mij - st + 1;
    int n2 = dr - mij;

    // Vectori temporari
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    // Copiem datele în vectorii temporari
    for (int i = 0; i < n1; i++)
        L[i] = v[st + i];
    for (int j = 0; j < n2; j++)
        R[j] = v[mij + 1 + j];

    // Interclasare
    int i = 0, j = 0, k = st;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k++] = L[i++];
        }
        else {
            v[k++] = R[j++];
        }
    }

    // Adaugam ce a mai ramas (daca e cazul)
    while (i < n1)
        v[k++] = L[i++];
    while (j < n2)
        v[k++] = R[j++];

    free(L);
    free(R);
}

// Functia principala MergeSort (recursiva)
void merge_sort(int v[], int st, int dr) {
    if (st < dr) {
        int mij = (st + dr) / 2;

        // Sortam cele doua jumatati
        merge_sort(v, st, mij);
        merge_sort(v, mij + 1, dr);

        // Le interclasam
        interclasare(v, st, mij, dr);
    }
}

int main() {
    int n;

    printf("Introdu numarul de elemente: ");
    scanf("%d", &n);

    int v[MAX];

    printf("Introdu elementele vectorului:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    merge_sort(v, 0, n - 1);

    printf("Vectorul sortat este:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);

    printf("\n");
    return 0;
}
