#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    char conteudo;
    struct No *esq;
    struct No *dir;
} No;

No *criarNo(char conteudo);

No *maximo(No* r) {
    if (r == NULL) {
        return NULL; // Não deve ocorrer, pois a árvore é garantida como não-vazia
    }

    No *maxAtual = r;

    // Verifica as subárvore 
    No *maxEsq = maximo(r->esq);
    if (maxEsq != NULL && maxEsq->conteudo > maxAtual->conteudo) {
        maxAtual = maxEsq;
    }

    No *maxDir = maximo(r->dir);
    if (maxDir != NULL && maxDir->conteudo > maxAtual->conteudo) {
        maxAtual = maxDir;
    }

    return maxAtual;
}

int main() {
    No* raiz = criarNo('A');
    raiz->esq = criarNo('B');
    raiz->dir = criarNo('C');
    raiz->esq->esq = criarNo('D');
    raiz->esq->dir = criarNo('Z');//MAXIMO É O Z
    raiz->dir->esq = criarNo('F');
    raiz->dir->dir = criarNo('E'); 

    No *maxNo = maximo(raiz);
    if (maxNo != NULL) {
        printf("Conteudo maximo: %c\n", maxNo->conteudo);
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
