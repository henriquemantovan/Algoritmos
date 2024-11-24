#include <stdio.h>

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