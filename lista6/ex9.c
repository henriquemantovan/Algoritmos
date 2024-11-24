#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    char conteudo;
    struct No *esq;
    struct No *dir;
} No;

No *criarNo(char conteudo);
void preOrdem(No* r);

void libera(No* *r) {
    if (*r == NULL) { 
        return;
    }

    libera(&(*r)->esq); 
    libera(&(*r)->dir); 

    free(*r); 
    *r = NULL; 
}

int main() {
    No* raiz = criarNo('A');
    raiz->esq = criarNo('B');
    raiz->dir = criarNo('C');
    raiz->esq->esq = criarNo('D');
    raiz->esq->dir = criarNo('E');
    raiz->dir->esq = criarNo('F');
    raiz->dir->dir = criarNo('G');
    
    printf("Árvore original (pré-ordem): ");
    preOrdem(raiz);
    printf("\n");

    libera(&raiz); 

    if (raiz == NULL) {
        printf("A árvore foi liberada com sucesso!\n");
    } else {
        printf("A árvore não foi liberada corretamente.\n");
    }

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