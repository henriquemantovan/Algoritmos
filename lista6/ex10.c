#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int chave;
    int conteudo;
    struct celula *pai;
    struct celula *esq;
    struct celula *dir;
} No;

No* predecessor(No* q) {
    // Se o nó tem filho esquerdo, o predecessor é o máximo na subárvore esquerda
    if (q->esq != NULL) {
        No* atual = q->esq;
        while (atual->dir != NULL) {
            atual = atual->dir;
        }
        return atual;
    }
    
    // Se não tem filho esquerdo, sobe na árvore até encontrar o primeiro ancestral à direita
    No* pai = q->pai;
    while (pai != NULL && q == pai->esq) {
        q = pai;
        pai = pai->pai;
    }
    
    return pai;
}