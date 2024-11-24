#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    char conteudo;
    struct No *esq;
    struct No *dir;
} No;

No *criarNo(char conteudo);
void preOrdem(No *raiz);


No* espelha(No* r) {
    if (r == NULL) {
        return NULL;
    }

    // Cria o nó espelhado
    No* novo = criarNo(r->conteudo);

    // Espelha as subárvores trocando esquerda pela direita e vice verca
    novo->esq = espelha(r->dir);
    novo->dir = espelha(r->esq);

    return novo;
}

int main() {
    No* raiz = criarNo('A');
    raiz->esq = criarNo('B');
    raiz->dir = criarNo('C');
    raiz->esq->esq = criarNo('D');
    raiz->esq->dir = criarNo('E');
    raiz->dir->esq = criarNo('F');
    raiz->dir->dir = criarNo('G');

    printf("Original: ");
    preOrdem(raiz);
    printf("\n");

    No* espelhada = espelha(raiz);

    printf("Espelhada: ");
    preOrdem(espelhada);
    printf("\n");

    return 0;
}

No *criarNo(char conteudo) {
    No *novo = (No *)malloc(sizeof(No));
    novo->conteudo = conteudo;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

void preOrdem(No *raiz) {
    if (raiz != NULL) {
        printf("%c ", raiz->conteudo);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}