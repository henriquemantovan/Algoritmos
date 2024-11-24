#include <stdio.h>

void peneira(int i, int m, int v[]) {
    int f = 2 * i + 1, x = v[i];  
    while (f <= m) {
        if (f < m && v[f] < v[f + 1]) f++;
        if (x >= v[f]) break;
        v[i] = v[f];
        i = f;
        f = 2 * i + 1;
    }
    v[i] = x;
}

void constroiHeap(int v[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--) {
        peneira(i, n, v);
    }
}

int main() {
    int v[] = {4, 10, 3, 5, 1};
    int n = sizeof(v) / sizeof(v[0]);

    constroiHeap(v, n);

    printf("Array transformado em heap: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}