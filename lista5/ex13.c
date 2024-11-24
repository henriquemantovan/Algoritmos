#include <stdio.h>

void alteraChave(int x, int i, int n, int v[]) {
    int antigo = v[i];
    v[i] = x;


    if (x > antigo) {

        while (i > 1 && v[i] > v[i / 2]) {

            int temp = v[i];
            v[i] = v[i / 2];
            v[i / 2] = temp;
            i = i / 2; 
            
        }
    } else {
        while (2 * i <= n) {
            int filho = 2 * i;

            if (filho < n && v[filho] < v[filho + 1]) {
                filho++;
            }

            if (v[i] >= v[filho]) {
                break;
            }

            int temp = v[i];
            v[i] = v[filho];
            v[filho] = temp;

            i = filho;
        }
    }
}
