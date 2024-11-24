#include <stdio.h>
#include <stdlib.h>


int maximo (int v[], int ini, int fim) {
    if (ini == fim) {
        return v[ini];
    }

    int meio = (ini+fim)/2;

    if (maximo(v, ini, meio) > maximo(v, meio + 1, fim)) 
        return maximo(v, ini, meio);
    
    else 
        return maximo(v, meio + 1, fim);
}

int main() {
    int v[] = {7, 3, 9, 2, 1, 5, 6, 4};
    int n = sizeof(v) / sizeof(v[0]);
    
    int max = maximo(v, 0, n - 1);
    
    printf("O maior valor no vetor é: %d\n", max);
    
    return 0;
}
