#include <stdio.h>

void removeHeap(int i, int *n, int v[]) {

    v[i] = v[*n];
    (*n)--; 

    int novo = v[i];

    while (2 * i <= *n) {
        int filho = 2 * i;

        if (filho < *n && v[filho] < v[filho + 1]) {
            filho++;
        }

        if (novo >= v[filho]) {
            break;
        }

        v[i] = v[filho];
        i = filho;
    }

    v[i] = novo;
}

