#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    char conteudo;
    struct No *esq;
    struct No *dir;
} No;

void inOrdem(No *r);
No *criarNo(char conteudo);


void inOrdemNaoRecursiva(No *r) {
    No *pilha[100];  
    int topo = -1;   
    No *atual = r;

    while (atual != NULL || topo != -1) {

        // Vai para a esquerda o máximo possível
        while (atual != NULL) {
            pilha[++topo] = atual;  
            atual = atual->esq;    
        }

        atual = pilha[topo--];
        printf("%c ", atual->conteudo);  

        // Vai para o filho à direita
        atual = atual->dir;
    }
}

int main() {
    No *raiz = criarNo('A');
    raiz->esq = criarNo('B');
    raiz->dir = criarNo('C');
    raiz->esq->esq = criarNo('D');
    raiz->esq->dir = criarNo('E');
    raiz->dir->esq = criarNo('F');
    raiz->dir->dir = criarNo('G');

    printf("Recursiva:\n");
    inOrdem(raiz);
    printf("\n");
    printf("Nao-recursiva:\n");
    inOrdemNaoRecursiva(raiz);
    printf("\n");


    return 0;
}

void inOrdem(No* r) {
    if (r != NULL) {
        inOrdem(r->esq);
        printf("%c ", r->conteudo);
        inOrdem(r->dir);
    }
}

No *criarNo(char conteudo) {
    No *novo = (No *)malloc(sizeof(No));
    novo->conteudo = conteudo;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}
