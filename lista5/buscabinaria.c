int busca_binaria(int v[], int n, int x) {
    int inicio = 0;
    int fim = n - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (v[meio] == x)
            return meio;  
        else if (v[meio] < x)
            inicio = meio + 1;  
        else
            fim = meio - 1; 
    }

    return -1; 
}

int buscaBinariaR(int x, int e, int d, int v[]) {
    int m;
    
    if (d < e) return -1;

    m = (e + d)/2;

    if (v[m] == x) return m;

    if (v[m] < x) return buscaBinariaR(x, m, d, v);

    return buscaBinariaR(x, e, m-1, v);
}


int main() {
    int v[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(v) / sizeof(v[0]);
    int x = 19;

    int resultado = busca_binaria(v, n, x);

    if (resultado != -1)
        printf("Valor encontrado no índice %d.\n", resultado);
    else
        printf("Valor não encontrado.\n");

    return 0;
}