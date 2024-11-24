#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int contador = 0;

void peneiria(int i, int m, int v[]) {
    int f = 2 * i + 1, x = v[i];  // Ajustado para arrays com índice 0
    while (f <= m) {
        if (f < m && v[f] < v[f + 1]) f++;
        if (x >= v[f]) break;
        v[i] = v[f];
        i = f;
        f = 2 * i + 1;
    }
    v[i] = x;
}

void heapsort(int v[], int n) {
    int i, x;
    for (i = n / 2 - 1; i >= 0; i--) {
        peneiria(i, n - 1, v);
    }
    for (i = n - 1; i > 0; i--) {
        x = v[i];
        v[i] = v[0];
        v[0] = x;
        peneiria(0, i - 1, v);
    }
}

void intercala(int p,int q,int r,int v[]) {
    int i, j, k, *w;
    w = malloc((r-p)*sizeof(int));

    for (i = 0, k = p; k < q; i++, k++) w[i] = v[k];
    
    for (j = r-p-1; k < r; j--, k++) w[j] = v[k];

    i = 0; j = r-p-1;

    for (k = p; k < r; k++){
    if (w[i] <= w[j])
        v[k] = w[i++];
    else v[k] = w[j--];
    }   
free (w);
}

void mergeSort(int p, int r, int v[]) {
    if (p < r - 1) {
        int q = (p + r) / 2;
        mergeSort(p, q, v);
        mergeSort(q, r, v);
        intercala(p, q, r, v);
    }
}

int separa(int p, int r, int v[]) {
    contador++;
    int i = p - 1, j, x = v[r - 1], t;
    for (j = p; j < r; j++) {
        if (v[j] <= x) {
            t = v[++i];
            v[i] = v[j];
            v[j] = t;
        }
    }
    return i;
}

void quickSort(int p, int r, int v[]) {
    if (p < r - 1) {
        int q = separa(p, r, v);
        quickSort(p, q, v);
        quickSort(q + 1, r, v);
    }
}

void printArray(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {15, 27, 3, 18, 7, 11, 22, 19, 9, 10, 1, 5, 8, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    int *arrCopy = malloc(n * sizeof(int));

    // HeapSort
    for (int i = 0; i < n; i++){
       arrCopy[i] = arr[i]; 
    } 
    
    clock_t start = clock();
    heapsort(arrCopy, n);
    clock_t end = clock();
    printf("\nHeapSort:\n");
    printArray(arrCopy, n);
    printf("Tempo: %f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);

    // QuickSort
    for (int i = 0; i < n; i++){
       arrCopy[i] = arr[i]; 
    } 
    start = clock();
    quickSort(0, n, arrCopy);
    end = clock();
    printf("\nQuickSort:\n");
    printArray(arrCopy, n);
    printf("Tempo: %f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("Contador de separa: %d\n", contador);

    // MergeSort
    for (int i = 0; i < n; i++){
       arrCopy[i] = arr[i]; 
    } 
    start = clock();
    mergeSort(0, n, arrCopy);
    end = clock();
    printf("\nMergeSort:\n");
    printArray(arrCopy, n);
    printf("Tempo: %f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);


    free(arrCopy);
    return 0;
}
