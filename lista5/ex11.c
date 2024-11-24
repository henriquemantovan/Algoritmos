#include <stdio.h>

void mover_As(char v[], int n) {
    int j = 0; 

    for (int i = 0; i < n; i++) {
        if (v[i] == 'A') {
            char aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            j++;
        }
    }
}

int main() {
    char v[] = {'B', 'A', 'B', 'A', 'B', 'A'};
    int n = sizeof(v) / sizeof(v[0]);

    mover_As(v, n);

    printf("Vetor arrumado: ");
    for (int i = 0; i < n; i++) {
        printf("%c ", v[i]);
    }
    printf("\n");

    return 0;
}
