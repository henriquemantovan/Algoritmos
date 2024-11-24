int separa(int p, int r, int v[]) {
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