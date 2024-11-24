#include <stdio.h>

int busca_ternaria(int v[], int ini, int fim, int x) {
    while (ini <= fim) {
        int um_terco = (ini + fim) / 3;
        int dois_terco = fim - (fim - ini) / 3;

        if (v[um_terco] == x)
            return 1; 

        if (v[dois_terco] == x)
            return 1;
            
        if (v[um_terco] > x)
            fim = um_terco - 1;

        else if (v[dois_terco] < x)
            ini = dois_terco + 1;

        else { //(v[um_terco] < x && v[dois_terco] > x)
            ini = um_terco + 1;
            fim = dois_terco - 1;
        }
    }

    return 0;
}

int main() {
    int v[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(v) / sizeof(v[0]);
    int x = 19;

    int resultado = busca_ternaria(v, 0, n - 1, x);

    if (resultado)
        printf("Valor encontrado\n");
    else
        printf("Valor não encontrado.\n");

    return 0;
}


/*

 VERSÃO QUE MOSTRA ONDE O X FOI ENCONTRADO

int busca_ternaria(int v[], int ini, int fim, int x) {
    while (ini <= fim) {
        int um_terco = (ini + fim) / 3;
        int dois_terco = fim - (fim - ini) / 3;

        if (v[um_terco] == x)
            return um_terco; 

        if (v[dois_terco] == x)
            return dois_terco;
            
        if (v[um_terco] > x)
            fim = um_terco - 1;

        else if (v[dois_terco] < x)
            ini = dois_terco + 1;

        else { //(v[um_terco] < x && v[dois_terco] > x)
            ini = um_terco + 1;
            fim = dois_terco - 1;
        }
    }

    return -1;
}

int main() {
    int v[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(v) / sizeof(v[0]);
    int x = 19;

    int resultado = busca_ternaria(v, 0, n - 1, x);

    if (resultado != -1)
        printf("Valor encontrado no índice %d.\n", resultado);
    else
        printf("Valor não encontrado.\n");

    return 0;
}

*/