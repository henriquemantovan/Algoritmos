#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    char conteudo;
    struct No *esq;
    struct No *dir;
} No;

No *criarNo(char conteudo);
void preOrdem(No* r);

No* copia(No* r) {
    if (r == NULL) {
        return NULL;
    }

    // Cria o nó copiado
    No* novo = criarNo(r->conteudo);

    // Copia as subárvores 
    novo->esq = copia(r->esq);
    novo->dir = copia(r->dir);

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

    No* copiada = copia(raiz);

    printf("Copiada: ");
    preOrdem(copiada);
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

void preOrdem(No* r) {
    if (r != NULL) {
        printf("%c ", r->conteudo);
        preOrdem(r->esq);
        preOrdem(r->dir);
    }
}