#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    char conteudo;
    struct No *esq;
    struct No *dir;
} No;

No *criarNo(char conteudo);

int numNos(No* r) {
    if (r == NULL) {
        return 0; // Árvore vazia tem 0 nos
    }
    return 1 + numNos(r->esq) + numNos(r->dir);
}


int main() {
    No* raiz = criarNo('A');
    raiz->esq = criarNo('B');
    raiz->dir = criarNo('C');
    raiz->esq->esq = criarNo('D');
    raiz->esq->dir = criarNo('E');
    raiz->dir->esq = criarNo('F');
    raiz->dir->dir = criarNo('G');

    printf("Numero de nos: %d\n", numNos(raiz));

    return 0;
}

No *criarNo(char conteudo) {
    No *novo = (No *)malloc(sizeof(No));
    novo->conteudo = conteudo;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}