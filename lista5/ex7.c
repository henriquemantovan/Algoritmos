void quickSort(int p, int r, int v[]) {
    if (p < r - 1) {
        int q = separa(p, r, v);
        quickSort(p, q, v);
        quickSort(q + 1, r, v);
    }
}